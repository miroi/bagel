//
// Newint - Parallel electron correlation program.
// Filename: contraction.cc
// Copyright (C) 2009 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the Newint package (to be renamed).
//
// The Newint package is free software; you can redistribute it and\/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// The Newint package is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public License
// along with the Newint package; see COPYING.  If not, write to
// the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//


#include <src/util/f77.h>
#include <src/rysint/eribatch.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <src/stackmem.h>

using namespace std;

// This object lives in main.cc
extern StackMem* stack;

void ERIBatch::perform_contraction_new_outer(const int nsize, const double* prim, const int pdim0, const int pdim1, double* cont, 
                       const vector<vector<double> >& coeff0, const vector<int>& upper0, const vector<int>& lower0, const int cdim0, 
                       const vector<vector<double> >& coeff1, const vector<int>& upper1, const vector<int>& lower1, const int cdim1) {
  const int unit = 1;
  const int zeroint = 0;
  const double zero = 0.0;
  const int worksize = nsize * pdim1; 
  double* work = stack->get(worksize);
  double* current_cont = cont;

  for (int i = 0; i != cdim0; ++i) {
    const int begin0 = lower0[i];
    const int end0   = upper0[i];
    fill(work, work + worksize, zero);
    for (int j = begin0; j != end0; ++j) 
      daxpy_(&worksize, &coeff0[i][j], &prim[j * worksize], &unit, work, &unit); 

    for (int k = 0; k != cdim1; ++k, current_cont += nsize) {
      const int begin1 = lower1[k];
      const int end1   = upper1[k];
      fill(current_cont, current_cont + nsize, 0.0); 
      for (int j = begin1; j != end1; ++j)
        daxpy_(&nsize, &coeff1[k][j], &work[j * nsize], &unit, current_cont, &unit); 
    }
  }

  stack->release(worksize);
}


void ERIBatch::perform_contraction_new_inner(const int nsize, const double* prim, const int pdim0, const int pdim1, double* cont, 
                       const vector<vector<double> >& coeff0, const vector<int>& upper0, const vector<int>& lower0, const int cdim0, 
                       const vector<vector<double> >& coeff1, const vector<int>& upper1, const vector<int>& lower1, const int cdim1) {
  // transformation of index1
  const int unit = 1;
  const double zero = 0.0;
  const int zeroint = 0;
  const int ac = asize_ * csize_;
  const int worksize = pdim1 * ac;
  double* work = stack->get(worksize);
  double* current_cont = cont;

  for (int n = 0; n != nsize; ++n) { // loop of cdim * cdim
    const double* current_prim = &prim[ac * pdim1 * pdim0 * n];

    for (int i = 0; i != cdim0; ++i) {

      const int begin0 = lower0[i];
      const int end0   = upper0[i];
      fill(work, work + worksize, zero);
      for (int j = begin0; j != end0; ++j) 
        daxpy_(&worksize, &coeff0[i][j], &current_prim[j * worksize], &unit, work, &unit); 

      for (int k = 0; k != cdim1; ++k, current_cont += ac) {
        const int begin1 = lower1[k];
        const int end1   = upper1[k];
        fill(current_cont, current_cont + ac, 0.0); 
        for (int j = begin1; j != end1; ++j) {
          daxpy_(&ac, &coeff1[k][j], &work[j * ac], &unit, current_cont, &unit); 
        }
      }
    }
  } 
  stack->release(worksize);
}


