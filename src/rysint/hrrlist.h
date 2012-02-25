//
// Newint - Parallel electron correlation program.
// Filename: hrrlist.h
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

//
// stand alone class for HRR functions.
// can be called from outside through hrrfunc_call.
//
  
#ifndef __rysint_hrrlist_h
#define __rysint_hrrlist_h

#include <src/rysint/macros.h>
 
struct HRRList {
  HRRList();
  ~HRRList();
     
  static void perform_HRR_20_11(const int, const double*, const double*, double*);
  static void perform_HRR_30_21(const int, const double*, const double*, double*);
  static void perform_HRR_40_22(const int, const double*, const double*, double*);
  static void perform_HRR_40_31(const int, const double*, const double*, double*);
  static void perform_HRR_50_32(const int, const double*, const double*, double*);
  static void perform_HRR_50_41(const int, const double*, const double*, double*);
  static void perform_HRR_60_33(const int, const double*, const double*, double*);
  static void perform_HRR_60_42(const int, const double*, const double*, double*);
  static void perform_HRR_60_51(const int, const double*, const double*, double*);
  static void perform_HRR_70_43(const int, const double*, const double*, double*);
  static void perform_HRR_70_52(const int, const double*, const double*, double*);
  static void perform_HRR_70_61(const int, const double*, const double*, double*);
  static void perform_HRR_80_44(const int, const double*, const double*, double*);
  static void perform_HRR_80_53(const int, const double*, const double*, double*);
  static void perform_HRR_80_62(const int, const double*, const double*, double*);
  static void perform_HRR_90_54(const int, const double*, const double*, double*);
  static void perform_HRR_90_63(const int, const double*, const double*, double*);
  static void perform_HRR_a0_55(const int, const double*, const double*, double*);
  static void perform_HRR_a0_64(const int, const double*, const double*, double*);
  static void perform_HRR_b0_65(const int, const double*, const double*, double*);
  static void perform_HRR_c0_66(const int, const double*, const double*, double*);

  void hrrfunc_call(const unsigned int i, const int a0, const double* a1, const double* a2, double* a3) {
    return (hrrfunc[i])(a0, a1, a2, a3);
  };

  void (*hrrfunc[ANG_HRR_END * ANG_HRR_END])(const int, const double*, const double*, double*);
};

#endif
