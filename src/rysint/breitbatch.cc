//
// BAGEL - Parallel electron correlation program.
// Filename: breitbatch.cc
// Copyright (C) 2012 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// The BAGEL package is free software; you can redistribute it and\/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
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

#include <src/slater/svrrlist.h>
#include <src/rysint/breitbatch.h>

using namespace std;
using namespace bagel;


BreitBatch::BreitBatch(const array<shared_ptr<const Shell>,4>& _info, const double max_density, const double dummy, const bool dum)
:  ERIBatch_base(_info, max_density, 1) {

  // Since #root is larger by 1/2 as compared to ERI, we use Slater VRR functions 
  vrr_ = shared_ptr<VRRListBase>(new SVRRList());

}


void BreitBatch::compute() {}