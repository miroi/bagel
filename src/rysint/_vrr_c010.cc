//
// Newint - Parallel electron correlation program.
// Filename: _vrr_c010.cc
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


#include "vrrlist.h"

// returns double array of length 182
void VRRList::_vrr_c010(double* data_, const double* C00_, const double* D00_, const double* B00_, const double* B01_, const double* B10_) {
  data_[0] = 1.0;
  data_[1] = 1.0;
  data_[2] = 1.0;
  data_[3] = 1.0;
  data_[4] = 1.0;
  data_[5] = 1.0;
  data_[6] = 1.0;

  data_[7] = C00_[0];
  data_[8] = C00_[1];
  data_[9] = C00_[2];
  data_[10] = C00_[3];
  data_[11] = C00_[4];
  data_[12] = C00_[5];
  data_[13] = C00_[6];

  double B10_current[7];
  B10_current[0] = B10_[0];
  B10_current[1] = B10_[1];
  B10_current[2] = B10_[2];
  B10_current[3] = B10_[3];
  B10_current[4] = B10_[4];
  B10_current[5] = B10_[5];
  B10_current[6] = B10_[6];

  data_[14] = C00_[0] * data_[7] + B10_current[0];
  data_[15] = C00_[1] * data_[8] + B10_current[1];
  data_[16] = C00_[2] * data_[9] + B10_current[2];
  data_[17] = C00_[3] * data_[10] + B10_current[3];
  data_[18] = C00_[4] * data_[11] + B10_current[4];
  data_[19] = C00_[5] * data_[12] + B10_current[5];
  data_[20] = C00_[6] * data_[13] + B10_current[6];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[21] = C00_[0] * data_[14] + B10_current[0] * data_[7];
  data_[22] = C00_[1] * data_[15] + B10_current[1] * data_[8];
  data_[23] = C00_[2] * data_[16] + B10_current[2] * data_[9];
  data_[24] = C00_[3] * data_[17] + B10_current[3] * data_[10];
  data_[25] = C00_[4] * data_[18] + B10_current[4] * data_[11];
  data_[26] = C00_[5] * data_[19] + B10_current[5] * data_[12];
  data_[27] = C00_[6] * data_[20] + B10_current[6] * data_[13];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[28] = C00_[0] * data_[21] + B10_current[0] * data_[14];
  data_[29] = C00_[1] * data_[22] + B10_current[1] * data_[15];
  data_[30] = C00_[2] * data_[23] + B10_current[2] * data_[16];
  data_[31] = C00_[3] * data_[24] + B10_current[3] * data_[17];
  data_[32] = C00_[4] * data_[25] + B10_current[4] * data_[18];
  data_[33] = C00_[5] * data_[26] + B10_current[5] * data_[19];
  data_[34] = C00_[6] * data_[27] + B10_current[6] * data_[20];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[35] = C00_[0] * data_[28] + B10_current[0] * data_[21];
  data_[36] = C00_[1] * data_[29] + B10_current[1] * data_[22];
  data_[37] = C00_[2] * data_[30] + B10_current[2] * data_[23];
  data_[38] = C00_[3] * data_[31] + B10_current[3] * data_[24];
  data_[39] = C00_[4] * data_[32] + B10_current[4] * data_[25];
  data_[40] = C00_[5] * data_[33] + B10_current[5] * data_[26];
  data_[41] = C00_[6] * data_[34] + B10_current[6] * data_[27];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[42] = C00_[0] * data_[35] + B10_current[0] * data_[28];
  data_[43] = C00_[1] * data_[36] + B10_current[1] * data_[29];
  data_[44] = C00_[2] * data_[37] + B10_current[2] * data_[30];
  data_[45] = C00_[3] * data_[38] + B10_current[3] * data_[31];
  data_[46] = C00_[4] * data_[39] + B10_current[4] * data_[32];
  data_[47] = C00_[5] * data_[40] + B10_current[5] * data_[33];
  data_[48] = C00_[6] * data_[41] + B10_current[6] * data_[34];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[49] = C00_[0] * data_[42] + B10_current[0] * data_[35];
  data_[50] = C00_[1] * data_[43] + B10_current[1] * data_[36];
  data_[51] = C00_[2] * data_[44] + B10_current[2] * data_[37];
  data_[52] = C00_[3] * data_[45] + B10_current[3] * data_[38];
  data_[53] = C00_[4] * data_[46] + B10_current[4] * data_[39];
  data_[54] = C00_[5] * data_[47] + B10_current[5] * data_[40];
  data_[55] = C00_[6] * data_[48] + B10_current[6] * data_[41];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[56] = C00_[0] * data_[49] + B10_current[0] * data_[42];
  data_[57] = C00_[1] * data_[50] + B10_current[1] * data_[43];
  data_[58] = C00_[2] * data_[51] + B10_current[2] * data_[44];
  data_[59] = C00_[3] * data_[52] + B10_current[3] * data_[45];
  data_[60] = C00_[4] * data_[53] + B10_current[4] * data_[46];
  data_[61] = C00_[5] * data_[54] + B10_current[5] * data_[47];
  data_[62] = C00_[6] * data_[55] + B10_current[6] * data_[48];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[63] = C00_[0] * data_[56] + B10_current[0] * data_[49];
  data_[64] = C00_[1] * data_[57] + B10_current[1] * data_[50];
  data_[65] = C00_[2] * data_[58] + B10_current[2] * data_[51];
  data_[66] = C00_[3] * data_[59] + B10_current[3] * data_[52];
  data_[67] = C00_[4] * data_[60] + B10_current[4] * data_[53];
  data_[68] = C00_[5] * data_[61] + B10_current[5] * data_[54];
  data_[69] = C00_[6] * data_[62] + B10_current[6] * data_[55];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[70] = C00_[0] * data_[63] + B10_current[0] * data_[56];
  data_[71] = C00_[1] * data_[64] + B10_current[1] * data_[57];
  data_[72] = C00_[2] * data_[65] + B10_current[2] * data_[58];
  data_[73] = C00_[3] * data_[66] + B10_current[3] * data_[59];
  data_[74] = C00_[4] * data_[67] + B10_current[4] * data_[60];
  data_[75] = C00_[5] * data_[68] + B10_current[5] * data_[61];
  data_[76] = C00_[6] * data_[69] + B10_current[6] * data_[62];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[77] = C00_[0] * data_[70] + B10_current[0] * data_[63];
  data_[78] = C00_[1] * data_[71] + B10_current[1] * data_[64];
  data_[79] = C00_[2] * data_[72] + B10_current[2] * data_[65];
  data_[80] = C00_[3] * data_[73] + B10_current[3] * data_[66];
  data_[81] = C00_[4] * data_[74] + B10_current[4] * data_[67];
  data_[82] = C00_[5] * data_[75] + B10_current[5] * data_[68];
  data_[83] = C00_[6] * data_[76] + B10_current[6] * data_[69];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[84] = C00_[0] * data_[77] + B10_current[0] * data_[70];
  data_[85] = C00_[1] * data_[78] + B10_current[1] * data_[71];
  data_[86] = C00_[2] * data_[79] + B10_current[2] * data_[72];
  data_[87] = C00_[3] * data_[80] + B10_current[3] * data_[73];
  data_[88] = C00_[4] * data_[81] + B10_current[4] * data_[74];
  data_[89] = C00_[5] * data_[82] + B10_current[5] * data_[75];
  data_[90] = C00_[6] * data_[83] + B10_current[6] * data_[76];

  data_[91] = D00_[0];
  data_[92] = D00_[1];
  data_[93] = D00_[2];
  data_[94] = D00_[3];
  data_[95] = D00_[4];
  data_[96] = D00_[5];
  data_[97] = D00_[6];

  data_[98] = C00_[0] * data_[91] + B00_[0];
  data_[99] = C00_[1] * data_[92] + B00_[1];
  data_[100] = C00_[2] * data_[93] + B00_[2];
  data_[101] = C00_[3] * data_[94] + B00_[3];
  data_[102] = C00_[4] * data_[95] + B00_[4];
  data_[103] = C00_[5] * data_[96] + B00_[5];
  data_[104] = C00_[6] * data_[97] + B00_[6];

  B10_current[0] = B10_[0];
  B10_current[1] = B10_[1];
  B10_current[2] = B10_[2];
  B10_current[3] = B10_[3];
  B10_current[4] = B10_[4];
  B10_current[5] = B10_[5];
  B10_current[6] = B10_[6];

  data_[105] = C00_[0] * data_[98] + B10_current[0] * data_[91] + B00_[0] * data_[7];
  data_[106] = C00_[1] * data_[99] + B10_current[1] * data_[92] + B00_[1] * data_[8];
  data_[107] = C00_[2] * data_[100] + B10_current[2] * data_[93] + B00_[2] * data_[9];
  data_[108] = C00_[3] * data_[101] + B10_current[3] * data_[94] + B00_[3] * data_[10];
  data_[109] = C00_[4] * data_[102] + B10_current[4] * data_[95] + B00_[4] * data_[11];
  data_[110] = C00_[5] * data_[103] + B10_current[5] * data_[96] + B00_[5] * data_[12];
  data_[111] = C00_[6] * data_[104] + B10_current[6] * data_[97] + B00_[6] * data_[13];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[112] = C00_[0] * data_[105] + B10_current[0] * data_[98] + B00_[0] * data_[14];
  data_[113] = C00_[1] * data_[106] + B10_current[1] * data_[99] + B00_[1] * data_[15];
  data_[114] = C00_[2] * data_[107] + B10_current[2] * data_[100] + B00_[2] * data_[16];
  data_[115] = C00_[3] * data_[108] + B10_current[3] * data_[101] + B00_[3] * data_[17];
  data_[116] = C00_[4] * data_[109] + B10_current[4] * data_[102] + B00_[4] * data_[18];
  data_[117] = C00_[5] * data_[110] + B10_current[5] * data_[103] + B00_[5] * data_[19];
  data_[118] = C00_[6] * data_[111] + B10_current[6] * data_[104] + B00_[6] * data_[20];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[119] = C00_[0] * data_[112] + B10_current[0] * data_[105] + B00_[0] * data_[21];
  data_[120] = C00_[1] * data_[113] + B10_current[1] * data_[106] + B00_[1] * data_[22];
  data_[121] = C00_[2] * data_[114] + B10_current[2] * data_[107] + B00_[2] * data_[23];
  data_[122] = C00_[3] * data_[115] + B10_current[3] * data_[108] + B00_[3] * data_[24];
  data_[123] = C00_[4] * data_[116] + B10_current[4] * data_[109] + B00_[4] * data_[25];
  data_[124] = C00_[5] * data_[117] + B10_current[5] * data_[110] + B00_[5] * data_[26];
  data_[125] = C00_[6] * data_[118] + B10_current[6] * data_[111] + B00_[6] * data_[27];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[126] = C00_[0] * data_[119] + B10_current[0] * data_[112] + B00_[0] * data_[28];
  data_[127] = C00_[1] * data_[120] + B10_current[1] * data_[113] + B00_[1] * data_[29];
  data_[128] = C00_[2] * data_[121] + B10_current[2] * data_[114] + B00_[2] * data_[30];
  data_[129] = C00_[3] * data_[122] + B10_current[3] * data_[115] + B00_[3] * data_[31];
  data_[130] = C00_[4] * data_[123] + B10_current[4] * data_[116] + B00_[4] * data_[32];
  data_[131] = C00_[5] * data_[124] + B10_current[5] * data_[117] + B00_[5] * data_[33];
  data_[132] = C00_[6] * data_[125] + B10_current[6] * data_[118] + B00_[6] * data_[34];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[133] = C00_[0] * data_[126] + B10_current[0] * data_[119] + B00_[0] * data_[35];
  data_[134] = C00_[1] * data_[127] + B10_current[1] * data_[120] + B00_[1] * data_[36];
  data_[135] = C00_[2] * data_[128] + B10_current[2] * data_[121] + B00_[2] * data_[37];
  data_[136] = C00_[3] * data_[129] + B10_current[3] * data_[122] + B00_[3] * data_[38];
  data_[137] = C00_[4] * data_[130] + B10_current[4] * data_[123] + B00_[4] * data_[39];
  data_[138] = C00_[5] * data_[131] + B10_current[5] * data_[124] + B00_[5] * data_[40];
  data_[139] = C00_[6] * data_[132] + B10_current[6] * data_[125] + B00_[6] * data_[41];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[140] = C00_[0] * data_[133] + B10_current[0] * data_[126] + B00_[0] * data_[42];
  data_[141] = C00_[1] * data_[134] + B10_current[1] * data_[127] + B00_[1] * data_[43];
  data_[142] = C00_[2] * data_[135] + B10_current[2] * data_[128] + B00_[2] * data_[44];
  data_[143] = C00_[3] * data_[136] + B10_current[3] * data_[129] + B00_[3] * data_[45];
  data_[144] = C00_[4] * data_[137] + B10_current[4] * data_[130] + B00_[4] * data_[46];
  data_[145] = C00_[5] * data_[138] + B10_current[5] * data_[131] + B00_[5] * data_[47];
  data_[146] = C00_[6] * data_[139] + B10_current[6] * data_[132] + B00_[6] * data_[48];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[147] = C00_[0] * data_[140] + B10_current[0] * data_[133] + B00_[0] * data_[49];
  data_[148] = C00_[1] * data_[141] + B10_current[1] * data_[134] + B00_[1] * data_[50];
  data_[149] = C00_[2] * data_[142] + B10_current[2] * data_[135] + B00_[2] * data_[51];
  data_[150] = C00_[3] * data_[143] + B10_current[3] * data_[136] + B00_[3] * data_[52];
  data_[151] = C00_[4] * data_[144] + B10_current[4] * data_[137] + B00_[4] * data_[53];
  data_[152] = C00_[5] * data_[145] + B10_current[5] * data_[138] + B00_[5] * data_[54];
  data_[153] = C00_[6] * data_[146] + B10_current[6] * data_[139] + B00_[6] * data_[55];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[154] = C00_[0] * data_[147] + B10_current[0] * data_[140] + B00_[0] * data_[56];
  data_[155] = C00_[1] * data_[148] + B10_current[1] * data_[141] + B00_[1] * data_[57];
  data_[156] = C00_[2] * data_[149] + B10_current[2] * data_[142] + B00_[2] * data_[58];
  data_[157] = C00_[3] * data_[150] + B10_current[3] * data_[143] + B00_[3] * data_[59];
  data_[158] = C00_[4] * data_[151] + B10_current[4] * data_[144] + B00_[4] * data_[60];
  data_[159] = C00_[5] * data_[152] + B10_current[5] * data_[145] + B00_[5] * data_[61];
  data_[160] = C00_[6] * data_[153] + B10_current[6] * data_[146] + B00_[6] * data_[62];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[161] = C00_[0] * data_[154] + B10_current[0] * data_[147] + B00_[0] * data_[63];
  data_[162] = C00_[1] * data_[155] + B10_current[1] * data_[148] + B00_[1] * data_[64];
  data_[163] = C00_[2] * data_[156] + B10_current[2] * data_[149] + B00_[2] * data_[65];
  data_[164] = C00_[3] * data_[157] + B10_current[3] * data_[150] + B00_[3] * data_[66];
  data_[165] = C00_[4] * data_[158] + B10_current[4] * data_[151] + B00_[4] * data_[67];
  data_[166] = C00_[5] * data_[159] + B10_current[5] * data_[152] + B00_[5] * data_[68];
  data_[167] = C00_[6] * data_[160] + B10_current[6] * data_[153] + B00_[6] * data_[69];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[168] = C00_[0] * data_[161] + B10_current[0] * data_[154] + B00_[0] * data_[70];
  data_[169] = C00_[1] * data_[162] + B10_current[1] * data_[155] + B00_[1] * data_[71];
  data_[170] = C00_[2] * data_[163] + B10_current[2] * data_[156] + B00_[2] * data_[72];
  data_[171] = C00_[3] * data_[164] + B10_current[3] * data_[157] + B00_[3] * data_[73];
  data_[172] = C00_[4] * data_[165] + B10_current[4] * data_[158] + B00_[4] * data_[74];
  data_[173] = C00_[5] * data_[166] + B10_current[5] * data_[159] + B00_[5] * data_[75];
  data_[174] = C00_[6] * data_[167] + B10_current[6] * data_[160] + B00_[6] * data_[76];

  B10_current[0] += B10_[0];
  B10_current[1] += B10_[1];
  B10_current[2] += B10_[2];
  B10_current[3] += B10_[3];
  B10_current[4] += B10_[4];
  B10_current[5] += B10_[5];
  B10_current[6] += B10_[6];

  data_[175] = C00_[0] * data_[168] + B10_current[0] * data_[161] + B00_[0] * data_[77];
  data_[176] = C00_[1] * data_[169] + B10_current[1] * data_[162] + B00_[1] * data_[78];
  data_[177] = C00_[2] * data_[170] + B10_current[2] * data_[163] + B00_[2] * data_[79];
  data_[178] = C00_[3] * data_[171] + B10_current[3] * data_[164] + B00_[3] * data_[80];
  data_[179] = C00_[4] * data_[172] + B10_current[4] * data_[165] + B00_[4] * data_[81];
  data_[180] = C00_[5] * data_[173] + B10_current[5] * data_[166] + B00_[5] * data_[82];
  data_[181] = C00_[6] * data_[174] + B10_current[6] * data_[167] + B00_[6] * data_[83];
}

