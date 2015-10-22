//
// BAGEL - Parallel electron correlation program.
// Filename: tatensor.h
// Copyright (C) 2015 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// The BAGEL package is free software; you can redistribute it and/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// The BAGEL package is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public License
// along with the BAGEL package; see COPYING.  If not, write to
// the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef __SRC_SMITH_TATENSOR_H
#define __SRC_SMITH_TATENSOR_H

#include <tiledarray.h>
#include <src/smith/indexrange.h>

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 9
#include <regex>
#else
#include <boost/regex.hpp>
#endif

namespace bagel {
namespace SMITH {

// wrapper class for TiledArray Tensor
template<typename DataType, int N>
class TATensor : public TiledArray::Array<DataType,N> {
  public:
    using TiledArray::Array<DataType,N>::begin;
    using TiledArray::Array<DataType,N>::end;
    using TiledArray::Array<DataType,N>::trange;

  protected:
    std::vector<IndexRange> range_;

//TODO do something for symmetry
//  std::map<std::vector<int>, std::pair<double,bool>> perm_;

    static std::shared_ptr<TiledArray::TiledRange> make_trange(const std::vector<IndexRange>& r) {
      std::vector<TiledArray::TiledRange1> ranges;
      for (auto it = r.rbegin(); it != r.rend(); ++it) {
        std::vector<size_t> tile_boundaries;
        for (auto& j : *it)
          tile_boundaries.push_back(j.offset());
        tile_boundaries.push_back(it->back().offset()+it->back().size());
        ranges.emplace_back(tile_boundaries.begin(), tile_boundaries.end());
      }
      return std::make_shared<TiledArray::TiledRange>(ranges.begin(), ranges.end());
    }

  public:
    TATensor(const std::vector<IndexRange>& r, /*toggle for symmetry*/const bool dummy = false)
      : TiledArray::Array<DataType,N>(madness::World::get_default(), *make_trange(r)), range_(r) {
      assert(r.size() == N);
    }

    TATensor(const TATensor<DataType,N>& o) : TiledArray::Array<DataType,N>(o), range_(o.range_) {
    }

    TATensor(TATensor<DataType,N>&& o) : TiledArray::Array<DataType,N>(std::move(o)), range_(o.range_) {
    }

    auto local(const std::vector<Index>& index) -> decltype(std::make_pair(true,begin())) {
      assert(index.size() == N);
      bool out = false;
      auto it = begin();
      for ( ; it != end(); ++it) {
        const TiledArray::Range range = trange().make_tile_range(it.ordinal());
        auto lo = range.lobound();
        assert(lo.size() == N);
        bool found = true;
        auto j = index.rbegin();
        for (auto& i : lo) {
          found &= i == j->offset();
          ++j;
        }
        out = found;
        if (found) break;
      }
      return std::make_pair(out, it);
    }

    std::vector<IndexRange> indexrange() const { return range_; }

    auto operator()(const std::string& vars) -> decltype(TiledArray::Array<DataType,N>::operator()(vars).block(std::array<size_t,N>(), std::array<size_t, N>())) {
#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 9
      using std::regex;
      using std::smatch;
      using std::regex_search;
      using std::sregex_token_iterator;
#else
      using boost::regex;
      using boost::smatch;
      using boost::regex_search;
      using boost::sregex_token_iterator;
#endif
      regex re(",");
      sregex_token_iterator p(vars.begin(), vars.end(), re, -1);
      sregex_token_iterator end;
      std::vector<std::string> ss;
      while (p != end)
        ss.push_back(*p++);
      assert(ss.size() == N);

      std::string revvars;
      for (auto i = ss.rbegin(); i != ss.rend(); ++i) {
        if (i != ss.rbegin()) revvars += ",";
        revvars += *i;
      }

      std::array<size_t, N> low, high;
      auto riter = range_.rbegin();
      int n = 0;
      for (auto i = ss.rbegin(); i != ss.rend(); ++i, ++riter, ++n) {
        regex re2("[a-z]+");
        smatch m;
        regex_search(*i, m, re2);
        std::string label = m[0]; // c, x, a, ci

        bool find = false;
        low[n] = 0;
        high[n] = 0;
        for (int j = 0; j != riter->nblock(); ++j) {
          const bool matches = riter->range(j).label() == label;
          find |= matches;
          if (!find) low[n] += 1;
          if (!find || matches) high[n] += 1;
        }
      }
      return TiledArray::Array<DataType,N>::operator()(revvars).block(low, high);
    }
};

}}

#endif
