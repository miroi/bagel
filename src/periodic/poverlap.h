//
// BAGEL - Parallel electron correlation program.
// Filename: poverlap.h
// Copyright (C) 2014 Toru Shiozaki
//
// Author: Hai-Anh Le <anh@u.northwestern.edu>
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


#ifndef __SRC_PERIODIC_POVERLAP_H
#define __SRC_PERIODIC_POVERLAP_H

#include <src/periodic/pmatrix1e.h>

namespace bagel {

class POverlap : public PMatrix1e {
  protected:
    void computebatch(const std::array<std::shared_ptr<const Shell>,2>&, const int, const int, std::shared_ptr<const Lattice>, const int) override;

  private:
    // serialization
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int) {
      ar & boost::serialization::base_object<PMatrix1e>(*this);
    }

  public:
    POverlap() { }
    POverlap(const std::shared_ptr<const Lattice>);

    ~POverlap() { }

};

}

#include <src/util/archive.h>
BOOST_CLASS_EXPORT_KEY(bagel::POverlap)

#endif

