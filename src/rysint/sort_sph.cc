//
// Newint - Parallel electron correlation program.
// Filename: sort_sph.cc
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


#include <cassert>
#include <string.h>
#include <src/rysint/sortlist.h>

using namespace std;

void SortList::sort_indices_00_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 1;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 1 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 1;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 1 * (c3 + c3end * c2);
          const int toffset = 1 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
        }
      }

    }
  } else {
    ::memcpy(target, source, c3end*c2end*loopsize*sizeof(double));
  }

}


void SortList::sort_indices_01_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 3;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 3 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 3;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 3 * (c3 + c3end * c2);
          const int toffset = 1 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 1 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 1;
          const int soffset = 3 * (c3 + c3end * c2);
          const int toffset = 3 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 2];
        }
      }

    }
  }

}


void SortList::sort_indices_11_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 9;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 3 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 3;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 9 * (c3 + c3end * c2);
          const int toffset = 3 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset +                  1] = current_source[soffset + 3];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 4];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 5];
          current_target[toffset +                  2] = current_source[soffset + 6];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 7];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 8];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 3 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 3;
          const int soffset = 9 * (c3 + c3end * c2);
          const int toffset = 3 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 3];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 4];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 5];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 6];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 7];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 8];
        }
      }

    }
  }

}


void SortList::sort_indices_02_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 5;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 5 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 5;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 5 * (c3 + c3end * c2);
          const int toffset = 1 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 1 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 1;
          const int soffset = 5 * (c3 + c3end * c2);
          const int toffset = 5 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 4];
        }
      }

    }
  }

}


void SortList::sort_indices_12_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 15;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 5 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 5;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 15 * (c3 + c3end * c2);
          const int toffset = 3 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset +                  1] = current_source[soffset + 3];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 4];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 5];
          current_target[toffset +                  2] = current_source[soffset + 6];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 7];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 8];
          current_target[toffset +                  3] = current_source[soffset + 9];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 10];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 11];
          current_target[toffset +                  4] = current_source[soffset + 12];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 13];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 14];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 3 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 3;
          const int soffset = 15 * (c3 + c3end * c2);
          const int toffset = 5 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 3];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 4];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 5];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 6];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 7];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 8];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 9];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 10];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 11];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 12];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 13];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 14];
        }
      }

    }
  }

}


void SortList::sort_indices_22_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 25;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 5 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 5;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 25 * (c3 + c3end * c2);
          const int toffset = 5 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset +                  1] = current_source[soffset + 5];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 6];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 7];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 8];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 9];
          current_target[toffset +                  2] = current_source[soffset + 10];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 11];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 12];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 13];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 14];
          current_target[toffset +                  3] = current_source[soffset + 15];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 16];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 17];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 18];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 19];
          current_target[toffset +                  4] = current_source[soffset + 20];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 21];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 22];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 23];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 24];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 5 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 5;
          const int soffset = 25 * (c3 + c3end * c2);
          const int toffset = 5 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 5];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 6];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 7];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 8];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 9];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 10];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 11];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 12];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 13];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 14];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 15];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 16];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 17];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 18];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 19];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 20];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 21];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 22];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 23];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 24];
        }
      }

    }
  }

}


void SortList::sort_indices_03_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 7;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 7 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 7;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 7 * (c3 + c3end * c2);
          const int toffset = 1 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 1 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 1;
          const int soffset = 7 * (c3 + c3end * c2);
          const int toffset = 7 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 6];
        }
      }

    }
  }

}


void SortList::sort_indices_13_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 21;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 7 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 7;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 21 * (c3 + c3end * c2);
          const int toffset = 3 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset +                  1] = current_source[soffset + 3];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 4];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 5];
          current_target[toffset +                  2] = current_source[soffset + 6];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 7];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 8];
          current_target[toffset +                  3] = current_source[soffset + 9];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 10];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 11];
          current_target[toffset +                  4] = current_source[soffset + 12];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 13];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 14];
          current_target[toffset +                  5] = current_source[soffset + 15];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 16];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 17];
          current_target[toffset +                  6] = current_source[soffset + 18];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 19];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 20];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 3 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 3;
          const int soffset = 21 * (c3 + c3end * c2);
          const int toffset = 7 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 3];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 4];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 5];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 6];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 7];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 8];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 9];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 10];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 11];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 12];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 13];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 14];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 15];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 16];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 17];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 18];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 19];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 20];
        }
      }

    }
  }

}


void SortList::sort_indices_23_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 35;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 7 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 7;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 35 * (c3 + c3end * c2);
          const int toffset = 5 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset +                  1] = current_source[soffset + 5];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 6];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 7];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 8];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 9];
          current_target[toffset +                  2] = current_source[soffset + 10];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 11];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 12];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 13];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 14];
          current_target[toffset +                  3] = current_source[soffset + 15];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 16];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 17];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 18];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 19];
          current_target[toffset +                  4] = current_source[soffset + 20];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 21];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 22];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 23];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 24];
          current_target[toffset +                  5] = current_source[soffset + 25];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 26];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 27];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 28];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 29];
          current_target[toffset +                  6] = current_source[soffset + 30];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 31];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 32];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 33];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 34];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 5 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 5;
          const int soffset = 35 * (c3 + c3end * c2);
          const int toffset = 7 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 5];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 6];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 7];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 8];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 9];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 10];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 11];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 12];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 13];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 14];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 15];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 16];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 17];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 18];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 19];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 20];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 21];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 22];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 23];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 24];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 25];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 26];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 27];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 28];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 29];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 30];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 31];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 32];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 33];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 34];
        }
      }

    }
  }

}


void SortList::sort_indices_33_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 49;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 7 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 7;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 49 * (c3 + c3end * c2);
          const int toffset = 7 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset +                  1] = current_source[soffset + 7];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 8];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 9];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 10];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 11];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 12];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 13];
          current_target[toffset +                  2] = current_source[soffset + 14];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 15];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 16];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 17];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 18];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 19];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 20];
          current_target[toffset +                  3] = current_source[soffset + 21];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 22];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 23];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 24];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 25];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 26];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 27];
          current_target[toffset +                  4] = current_source[soffset + 28];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 29];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 30];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 31];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 32];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 33];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 34];
          current_target[toffset +                  5] = current_source[soffset + 35];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 36];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 37];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 38];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 39];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 40];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 41];
          current_target[toffset +                  6] = current_source[soffset + 42];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 43];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 44];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 45];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 46];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 47];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 48];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 7 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 7;
          const int soffset = 49 * (c3 + c3end * c2);
          const int toffset = 7 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 7];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 8];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 9];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 10];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 11];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 12];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 13];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 14];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 15];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 16];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 17];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 18];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 19];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 20];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 21];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 22];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 23];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 24];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 25];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 26];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 27];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 28];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 29];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 30];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 31];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 32];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 33];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 34];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 35];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 36];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 37];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 38];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 39];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 40];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 41];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 42];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 43];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 44];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 45];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 46];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 47];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 48];
        }
      }

    }
  }

}


void SortList::sort_indices_04_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 9;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 9 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 9;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 9 * (c3 + c3end * c2);
          const int toffset = 1 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +                  7] = current_source[soffset + 7];
          current_target[toffset +                  8] = current_source[soffset + 8];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 1 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 1;
          const int soffset = 9 * (c3 + c3end * c2);
          const int toffset = 9 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 6];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 7];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 8];
        }
      }

    }
  }

}


void SortList::sort_indices_14_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 27;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 9 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 9;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 27 * (c3 + c3end * c2);
          const int toffset = 3 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset +                  1] = current_source[soffset + 3];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 4];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 5];
          current_target[toffset +                  2] = current_source[soffset + 6];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 7];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 8];
          current_target[toffset +                  3] = current_source[soffset + 9];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 10];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 11];
          current_target[toffset +                  4] = current_source[soffset + 12];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 13];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 14];
          current_target[toffset +                  5] = current_source[soffset + 15];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 16];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 17];
          current_target[toffset +                  6] = current_source[soffset + 18];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 19];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 20];
          current_target[toffset +                  7] = current_source[soffset + 21];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 22];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 23];
          current_target[toffset +                  8] = current_source[soffset + 24];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 25];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 26];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 3 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 3;
          const int soffset = 27 * (c3 + c3end * c2);
          const int toffset = 9 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 3];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 4];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 5];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 6];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 7];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 8];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 9];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 10];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 11];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 12];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 13];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 14];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 15];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 16];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 17];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 18];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 19];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 20];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 21];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 22];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 23];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 24];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 25];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 26];
        }
      }

    }
  }

}


void SortList::sort_indices_24_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 45;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 9 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 9;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 45 * (c3 + c3end * c2);
          const int toffset = 5 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset +                  1] = current_source[soffset + 5];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 6];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 7];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 8];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 9];
          current_target[toffset +                  2] = current_source[soffset + 10];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 11];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 12];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 13];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 14];
          current_target[toffset +                  3] = current_source[soffset + 15];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 16];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 17];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 18];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 19];
          current_target[toffset +                  4] = current_source[soffset + 20];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 21];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 22];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 23];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 24];
          current_target[toffset +                  5] = current_source[soffset + 25];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 26];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 27];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 28];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 29];
          current_target[toffset +                  6] = current_source[soffset + 30];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 31];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 32];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 33];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 34];
          current_target[toffset +                  7] = current_source[soffset + 35];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 36];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 37];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 38];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 39];
          current_target[toffset +                  8] = current_source[soffset + 40];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 41];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 42];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 43];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 44];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 5 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 5;
          const int soffset = 45 * (c3 + c3end * c2);
          const int toffset = 9 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 5];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 6];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 7];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 8];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 9];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 10];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 11];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 12];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 13];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 14];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 15];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 16];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 17];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 18];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 19];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 20];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 21];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 22];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 23];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 24];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 25];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 26];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 27];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 28];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 29];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 30];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 31];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 32];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 33];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 34];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 35];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 36];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 37];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 38];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 39];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 40];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 41];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 42];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 43];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 44];
        }
      }

    }
  }

}


void SortList::sort_indices_34_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 63;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 9 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 9;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 63 * (c3 + c3end * c2);
          const int toffset = 7 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset +                  1] = current_source[soffset + 7];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 8];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 9];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 10];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 11];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 12];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 13];
          current_target[toffset +                  2] = current_source[soffset + 14];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 15];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 16];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 17];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 18];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 19];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 20];
          current_target[toffset +                  3] = current_source[soffset + 21];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 22];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 23];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 24];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 25];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 26];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 27];
          current_target[toffset +                  4] = current_source[soffset + 28];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 29];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 30];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 31];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 32];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 33];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 34];
          current_target[toffset +                  5] = current_source[soffset + 35];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 36];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 37];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 38];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 39];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 40];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 41];
          current_target[toffset +                  6] = current_source[soffset + 42];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 43];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 44];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 45];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 46];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 47];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 48];
          current_target[toffset +                  7] = current_source[soffset + 49];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 50];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 51];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 52];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 53];
          current_target[toffset + 5 * cont2csize + 7] = current_source[soffset + 54];
          current_target[toffset + 6 * cont2csize + 7] = current_source[soffset + 55];
          current_target[toffset +                  8] = current_source[soffset + 56];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 57];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 58];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 59];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 60];
          current_target[toffset + 5 * cont2csize + 8] = current_source[soffset + 61];
          current_target[toffset + 6 * cont2csize + 8] = current_source[soffset + 62];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 7 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 7;
          const int soffset = 63 * (c3 + c3end * c2);
          const int toffset = 9 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 7];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 8];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 9];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 10];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 11];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 12];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 13];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 14];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 15];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 16];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 17];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 18];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 19];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 20];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 21];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 22];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 23];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 24];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 25];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 26];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 27];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 28];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 29];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 30];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 31];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 32];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 33];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 34];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 35];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 36];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 37];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 38];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 39];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 40];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 41];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 42];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 43];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 44];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 45];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 46];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 47];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 48];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 49];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 50];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 51];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 52];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 53];
          current_target[toffset + 7 * cont3csize + 5] = current_source[soffset + 54];
          current_target[toffset + 7 * cont3csize + 6] = current_source[soffset + 55];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 56];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 57];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 58];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 59];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 60];
          current_target[toffset + 8 * cont3csize + 5] = current_source[soffset + 61];
          current_target[toffset + 8 * cont3csize + 6] = current_source[soffset + 62];
        }
      }

    }
  }

}


void SortList::sort_indices_44_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 81;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 9 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 9;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 81 * (c3 + c3end * c2);
          const int toffset = 9 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset + 7 * cont2csize    ] = current_source[soffset + 7];
          current_target[toffset + 8 * cont2csize    ] = current_source[soffset + 8];
          current_target[toffset +                  1] = current_source[soffset + 9];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 10];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 11];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 12];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 13];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 14];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 15];
          current_target[toffset + 7 * cont2csize + 1] = current_source[soffset + 16];
          current_target[toffset + 8 * cont2csize + 1] = current_source[soffset + 17];
          current_target[toffset +                  2] = current_source[soffset + 18];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 19];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 20];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 21];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 22];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 23];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 24];
          current_target[toffset + 7 * cont2csize + 2] = current_source[soffset + 25];
          current_target[toffset + 8 * cont2csize + 2] = current_source[soffset + 26];
          current_target[toffset +                  3] = current_source[soffset + 27];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 28];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 29];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 30];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 31];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 32];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 33];
          current_target[toffset + 7 * cont2csize + 3] = current_source[soffset + 34];
          current_target[toffset + 8 * cont2csize + 3] = current_source[soffset + 35];
          current_target[toffset +                  4] = current_source[soffset + 36];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 37];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 38];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 39];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 40];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 41];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 42];
          current_target[toffset + 7 * cont2csize + 4] = current_source[soffset + 43];
          current_target[toffset + 8 * cont2csize + 4] = current_source[soffset + 44];
          current_target[toffset +                  5] = current_source[soffset + 45];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 46];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 47];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 48];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 49];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 50];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 51];
          current_target[toffset + 7 * cont2csize + 5] = current_source[soffset + 52];
          current_target[toffset + 8 * cont2csize + 5] = current_source[soffset + 53];
          current_target[toffset +                  6] = current_source[soffset + 54];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 55];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 56];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 57];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 58];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 59];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 60];
          current_target[toffset + 7 * cont2csize + 6] = current_source[soffset + 61];
          current_target[toffset + 8 * cont2csize + 6] = current_source[soffset + 62];
          current_target[toffset +                  7] = current_source[soffset + 63];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 64];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 65];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 66];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 67];
          current_target[toffset + 5 * cont2csize + 7] = current_source[soffset + 68];
          current_target[toffset + 6 * cont2csize + 7] = current_source[soffset + 69];
          current_target[toffset + 7 * cont2csize + 7] = current_source[soffset + 70];
          current_target[toffset + 8 * cont2csize + 7] = current_source[soffset + 71];
          current_target[toffset +                  8] = current_source[soffset + 72];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 73];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 74];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 75];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 76];
          current_target[toffset + 5 * cont2csize + 8] = current_source[soffset + 77];
          current_target[toffset + 6 * cont2csize + 8] = current_source[soffset + 78];
          current_target[toffset + 7 * cont2csize + 8] = current_source[soffset + 79];
          current_target[toffset + 8 * cont2csize + 8] = current_source[soffset + 80];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 9 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 9;
          const int soffset = 81 * (c3 + c3end * c2);
          const int toffset = 9 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +                  7] = current_source[soffset + 7];
          current_target[toffset +                  8] = current_source[soffset + 8];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 9];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 10];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 11];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 12];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 13];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 14];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 15];
          current_target[toffset +     cont3csize + 7] = current_source[soffset + 16];
          current_target[toffset +     cont3csize + 8] = current_source[soffset + 17];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 18];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 19];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 20];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 21];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 22];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 23];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 24];
          current_target[toffset + 2 * cont3csize + 7] = current_source[soffset + 25];
          current_target[toffset + 2 * cont3csize + 8] = current_source[soffset + 26];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 27];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 28];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 29];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 30];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 31];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 32];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 33];
          current_target[toffset + 3 * cont3csize + 7] = current_source[soffset + 34];
          current_target[toffset + 3 * cont3csize + 8] = current_source[soffset + 35];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 36];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 37];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 38];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 39];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 40];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 41];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 42];
          current_target[toffset + 4 * cont3csize + 7] = current_source[soffset + 43];
          current_target[toffset + 4 * cont3csize + 8] = current_source[soffset + 44];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 45];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 46];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 47];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 48];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 49];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 50];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 51];
          current_target[toffset + 5 * cont3csize + 7] = current_source[soffset + 52];
          current_target[toffset + 5 * cont3csize + 8] = current_source[soffset + 53];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 54];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 55];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 56];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 57];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 58];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 59];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 60];
          current_target[toffset + 6 * cont3csize + 7] = current_source[soffset + 61];
          current_target[toffset + 6 * cont3csize + 8] = current_source[soffset + 62];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 63];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 64];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 65];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 66];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 67];
          current_target[toffset + 7 * cont3csize + 5] = current_source[soffset + 68];
          current_target[toffset + 7 * cont3csize + 6] = current_source[soffset + 69];
          current_target[toffset + 7 * cont3csize + 7] = current_source[soffset + 70];
          current_target[toffset + 7 * cont3csize + 8] = current_source[soffset + 71];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 72];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 73];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 74];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 75];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 76];
          current_target[toffset + 8 * cont3csize + 5] = current_source[soffset + 77];
          current_target[toffset + 8 * cont3csize + 6] = current_source[soffset + 78];
          current_target[toffset + 8 * cont3csize + 7] = current_source[soffset + 79];
          current_target[toffset + 8 * cont3csize + 8] = current_source[soffset + 80];
        }
      }

    }
  }

}


void SortList::sort_indices_05_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 11;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 11 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 11;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 11 * (c3 + c3end * c2);
          const int toffset = 1 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +                  7] = current_source[soffset + 7];
          current_target[toffset +                  8] = current_source[soffset + 8];
          current_target[toffset +                  9] = current_source[soffset + 9];
          current_target[toffset +                  10] = current_source[soffset + 10];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 1 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 1;
          const int soffset = 11 * (c3 + c3end * c2);
          const int toffset = 11 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 6];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 7];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 8];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 9];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 10];
        }
      }

    }
  }

}


void SortList::sort_indices_15_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 33;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 11 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 11;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 33 * (c3 + c3end * c2);
          const int toffset = 3 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset +                  1] = current_source[soffset + 3];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 4];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 5];
          current_target[toffset +                  2] = current_source[soffset + 6];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 7];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 8];
          current_target[toffset +                  3] = current_source[soffset + 9];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 10];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 11];
          current_target[toffset +                  4] = current_source[soffset + 12];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 13];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 14];
          current_target[toffset +                  5] = current_source[soffset + 15];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 16];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 17];
          current_target[toffset +                  6] = current_source[soffset + 18];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 19];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 20];
          current_target[toffset +                  7] = current_source[soffset + 21];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 22];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 23];
          current_target[toffset +                  8] = current_source[soffset + 24];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 25];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 26];
          current_target[toffset +                  9] = current_source[soffset + 27];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 28];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 29];
          current_target[toffset +                  10] = current_source[soffset + 30];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 31];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 32];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 3 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 3;
          const int soffset = 33 * (c3 + c3end * c2);
          const int toffset = 11 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 3];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 4];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 5];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 6];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 7];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 8];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 9];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 10];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 11];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 12];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 13];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 14];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 15];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 16];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 17];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 18];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 19];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 20];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 21];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 22];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 23];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 24];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 25];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 26];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 27];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 28];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 29];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 30];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 31];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 32];
        }
      }

    }
  }

}


void SortList::sort_indices_25_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 55;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 11 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 11;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 55 * (c3 + c3end * c2);
          const int toffset = 5 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset +                  1] = current_source[soffset + 5];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 6];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 7];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 8];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 9];
          current_target[toffset +                  2] = current_source[soffset + 10];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 11];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 12];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 13];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 14];
          current_target[toffset +                  3] = current_source[soffset + 15];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 16];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 17];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 18];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 19];
          current_target[toffset +                  4] = current_source[soffset + 20];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 21];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 22];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 23];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 24];
          current_target[toffset +                  5] = current_source[soffset + 25];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 26];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 27];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 28];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 29];
          current_target[toffset +                  6] = current_source[soffset + 30];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 31];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 32];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 33];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 34];
          current_target[toffset +                  7] = current_source[soffset + 35];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 36];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 37];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 38];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 39];
          current_target[toffset +                  8] = current_source[soffset + 40];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 41];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 42];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 43];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 44];
          current_target[toffset +                  9] = current_source[soffset + 45];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 46];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 47];
          current_target[toffset + 3 * cont2csize + 9] = current_source[soffset + 48];
          current_target[toffset + 4 * cont2csize + 9] = current_source[soffset + 49];
          current_target[toffset +                  10] = current_source[soffset + 50];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 51];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 52];
          current_target[toffset + 3 * cont2csize + 10] = current_source[soffset + 53];
          current_target[toffset + 4 * cont2csize + 10] = current_source[soffset + 54];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 5 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 5;
          const int soffset = 55 * (c3 + c3end * c2);
          const int toffset = 11 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 5];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 6];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 7];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 8];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 9];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 10];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 11];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 12];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 13];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 14];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 15];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 16];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 17];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 18];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 19];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 20];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 21];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 22];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 23];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 24];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 25];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 26];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 27];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 28];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 29];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 30];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 31];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 32];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 33];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 34];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 35];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 36];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 37];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 38];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 39];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 40];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 41];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 42];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 43];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 44];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 45];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 46];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 47];
          current_target[toffset + 9 * cont3csize + 3] = current_source[soffset + 48];
          current_target[toffset + 9 * cont3csize + 4] = current_source[soffset + 49];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 50];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 51];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 52];
          current_target[toffset + 10 * cont3csize + 3] = current_source[soffset + 53];
          current_target[toffset + 10 * cont3csize + 4] = current_source[soffset + 54];
        }
      }

    }
  }

}


void SortList::sort_indices_35_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 77;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 11 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 11;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 77 * (c3 + c3end * c2);
          const int toffset = 7 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset +                  1] = current_source[soffset + 7];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 8];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 9];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 10];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 11];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 12];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 13];
          current_target[toffset +                  2] = current_source[soffset + 14];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 15];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 16];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 17];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 18];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 19];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 20];
          current_target[toffset +                  3] = current_source[soffset + 21];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 22];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 23];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 24];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 25];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 26];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 27];
          current_target[toffset +                  4] = current_source[soffset + 28];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 29];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 30];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 31];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 32];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 33];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 34];
          current_target[toffset +                  5] = current_source[soffset + 35];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 36];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 37];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 38];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 39];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 40];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 41];
          current_target[toffset +                  6] = current_source[soffset + 42];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 43];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 44];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 45];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 46];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 47];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 48];
          current_target[toffset +                  7] = current_source[soffset + 49];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 50];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 51];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 52];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 53];
          current_target[toffset + 5 * cont2csize + 7] = current_source[soffset + 54];
          current_target[toffset + 6 * cont2csize + 7] = current_source[soffset + 55];
          current_target[toffset +                  8] = current_source[soffset + 56];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 57];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 58];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 59];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 60];
          current_target[toffset + 5 * cont2csize + 8] = current_source[soffset + 61];
          current_target[toffset + 6 * cont2csize + 8] = current_source[soffset + 62];
          current_target[toffset +                  9] = current_source[soffset + 63];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 64];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 65];
          current_target[toffset + 3 * cont2csize + 9] = current_source[soffset + 66];
          current_target[toffset + 4 * cont2csize + 9] = current_source[soffset + 67];
          current_target[toffset + 5 * cont2csize + 9] = current_source[soffset + 68];
          current_target[toffset + 6 * cont2csize + 9] = current_source[soffset + 69];
          current_target[toffset +                  10] = current_source[soffset + 70];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 71];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 72];
          current_target[toffset + 3 * cont2csize + 10] = current_source[soffset + 73];
          current_target[toffset + 4 * cont2csize + 10] = current_source[soffset + 74];
          current_target[toffset + 5 * cont2csize + 10] = current_source[soffset + 75];
          current_target[toffset + 6 * cont2csize + 10] = current_source[soffset + 76];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 7 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 7;
          const int soffset = 77 * (c3 + c3end * c2);
          const int toffset = 11 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 7];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 8];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 9];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 10];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 11];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 12];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 13];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 14];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 15];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 16];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 17];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 18];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 19];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 20];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 21];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 22];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 23];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 24];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 25];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 26];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 27];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 28];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 29];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 30];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 31];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 32];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 33];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 34];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 35];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 36];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 37];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 38];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 39];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 40];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 41];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 42];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 43];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 44];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 45];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 46];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 47];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 48];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 49];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 50];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 51];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 52];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 53];
          current_target[toffset + 7 * cont3csize + 5] = current_source[soffset + 54];
          current_target[toffset + 7 * cont3csize + 6] = current_source[soffset + 55];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 56];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 57];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 58];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 59];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 60];
          current_target[toffset + 8 * cont3csize + 5] = current_source[soffset + 61];
          current_target[toffset + 8 * cont3csize + 6] = current_source[soffset + 62];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 63];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 64];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 65];
          current_target[toffset + 9 * cont3csize + 3] = current_source[soffset + 66];
          current_target[toffset + 9 * cont3csize + 4] = current_source[soffset + 67];
          current_target[toffset + 9 * cont3csize + 5] = current_source[soffset + 68];
          current_target[toffset + 9 * cont3csize + 6] = current_source[soffset + 69];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 70];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 71];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 72];
          current_target[toffset + 10 * cont3csize + 3] = current_source[soffset + 73];
          current_target[toffset + 10 * cont3csize + 4] = current_source[soffset + 74];
          current_target[toffset + 10 * cont3csize + 5] = current_source[soffset + 75];
          current_target[toffset + 10 * cont3csize + 6] = current_source[soffset + 76];
        }
      }

    }
  }

}


void SortList::sort_indices_45_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 99;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 11 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 11;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 99 * (c3 + c3end * c2);
          const int toffset = 9 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset + 7 * cont2csize    ] = current_source[soffset + 7];
          current_target[toffset + 8 * cont2csize    ] = current_source[soffset + 8];
          current_target[toffset +                  1] = current_source[soffset + 9];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 10];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 11];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 12];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 13];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 14];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 15];
          current_target[toffset + 7 * cont2csize + 1] = current_source[soffset + 16];
          current_target[toffset + 8 * cont2csize + 1] = current_source[soffset + 17];
          current_target[toffset +                  2] = current_source[soffset + 18];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 19];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 20];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 21];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 22];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 23];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 24];
          current_target[toffset + 7 * cont2csize + 2] = current_source[soffset + 25];
          current_target[toffset + 8 * cont2csize + 2] = current_source[soffset + 26];
          current_target[toffset +                  3] = current_source[soffset + 27];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 28];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 29];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 30];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 31];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 32];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 33];
          current_target[toffset + 7 * cont2csize + 3] = current_source[soffset + 34];
          current_target[toffset + 8 * cont2csize + 3] = current_source[soffset + 35];
          current_target[toffset +                  4] = current_source[soffset + 36];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 37];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 38];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 39];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 40];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 41];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 42];
          current_target[toffset + 7 * cont2csize + 4] = current_source[soffset + 43];
          current_target[toffset + 8 * cont2csize + 4] = current_source[soffset + 44];
          current_target[toffset +                  5] = current_source[soffset + 45];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 46];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 47];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 48];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 49];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 50];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 51];
          current_target[toffset + 7 * cont2csize + 5] = current_source[soffset + 52];
          current_target[toffset + 8 * cont2csize + 5] = current_source[soffset + 53];
          current_target[toffset +                  6] = current_source[soffset + 54];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 55];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 56];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 57];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 58];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 59];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 60];
          current_target[toffset + 7 * cont2csize + 6] = current_source[soffset + 61];
          current_target[toffset + 8 * cont2csize + 6] = current_source[soffset + 62];
          current_target[toffset +                  7] = current_source[soffset + 63];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 64];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 65];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 66];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 67];
          current_target[toffset + 5 * cont2csize + 7] = current_source[soffset + 68];
          current_target[toffset + 6 * cont2csize + 7] = current_source[soffset + 69];
          current_target[toffset + 7 * cont2csize + 7] = current_source[soffset + 70];
          current_target[toffset + 8 * cont2csize + 7] = current_source[soffset + 71];
          current_target[toffset +                  8] = current_source[soffset + 72];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 73];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 74];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 75];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 76];
          current_target[toffset + 5 * cont2csize + 8] = current_source[soffset + 77];
          current_target[toffset + 6 * cont2csize + 8] = current_source[soffset + 78];
          current_target[toffset + 7 * cont2csize + 8] = current_source[soffset + 79];
          current_target[toffset + 8 * cont2csize + 8] = current_source[soffset + 80];
          current_target[toffset +                  9] = current_source[soffset + 81];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 82];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 83];
          current_target[toffset + 3 * cont2csize + 9] = current_source[soffset + 84];
          current_target[toffset + 4 * cont2csize + 9] = current_source[soffset + 85];
          current_target[toffset + 5 * cont2csize + 9] = current_source[soffset + 86];
          current_target[toffset + 6 * cont2csize + 9] = current_source[soffset + 87];
          current_target[toffset + 7 * cont2csize + 9] = current_source[soffset + 88];
          current_target[toffset + 8 * cont2csize + 9] = current_source[soffset + 89];
          current_target[toffset +                  10] = current_source[soffset + 90];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 91];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 92];
          current_target[toffset + 3 * cont2csize + 10] = current_source[soffset + 93];
          current_target[toffset + 4 * cont2csize + 10] = current_source[soffset + 94];
          current_target[toffset + 5 * cont2csize + 10] = current_source[soffset + 95];
          current_target[toffset + 6 * cont2csize + 10] = current_source[soffset + 96];
          current_target[toffset + 7 * cont2csize + 10] = current_source[soffset + 97];
          current_target[toffset + 8 * cont2csize + 10] = current_source[soffset + 98];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 9 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 9;
          const int soffset = 99 * (c3 + c3end * c2);
          const int toffset = 11 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +                  7] = current_source[soffset + 7];
          current_target[toffset +                  8] = current_source[soffset + 8];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 9];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 10];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 11];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 12];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 13];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 14];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 15];
          current_target[toffset +     cont3csize + 7] = current_source[soffset + 16];
          current_target[toffset +     cont3csize + 8] = current_source[soffset + 17];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 18];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 19];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 20];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 21];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 22];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 23];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 24];
          current_target[toffset + 2 * cont3csize + 7] = current_source[soffset + 25];
          current_target[toffset + 2 * cont3csize + 8] = current_source[soffset + 26];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 27];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 28];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 29];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 30];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 31];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 32];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 33];
          current_target[toffset + 3 * cont3csize + 7] = current_source[soffset + 34];
          current_target[toffset + 3 * cont3csize + 8] = current_source[soffset + 35];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 36];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 37];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 38];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 39];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 40];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 41];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 42];
          current_target[toffset + 4 * cont3csize + 7] = current_source[soffset + 43];
          current_target[toffset + 4 * cont3csize + 8] = current_source[soffset + 44];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 45];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 46];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 47];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 48];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 49];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 50];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 51];
          current_target[toffset + 5 * cont3csize + 7] = current_source[soffset + 52];
          current_target[toffset + 5 * cont3csize + 8] = current_source[soffset + 53];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 54];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 55];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 56];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 57];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 58];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 59];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 60];
          current_target[toffset + 6 * cont3csize + 7] = current_source[soffset + 61];
          current_target[toffset + 6 * cont3csize + 8] = current_source[soffset + 62];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 63];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 64];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 65];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 66];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 67];
          current_target[toffset + 7 * cont3csize + 5] = current_source[soffset + 68];
          current_target[toffset + 7 * cont3csize + 6] = current_source[soffset + 69];
          current_target[toffset + 7 * cont3csize + 7] = current_source[soffset + 70];
          current_target[toffset + 7 * cont3csize + 8] = current_source[soffset + 71];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 72];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 73];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 74];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 75];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 76];
          current_target[toffset + 8 * cont3csize + 5] = current_source[soffset + 77];
          current_target[toffset + 8 * cont3csize + 6] = current_source[soffset + 78];
          current_target[toffset + 8 * cont3csize + 7] = current_source[soffset + 79];
          current_target[toffset + 8 * cont3csize + 8] = current_source[soffset + 80];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 81];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 82];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 83];
          current_target[toffset + 9 * cont3csize + 3] = current_source[soffset + 84];
          current_target[toffset + 9 * cont3csize + 4] = current_source[soffset + 85];
          current_target[toffset + 9 * cont3csize + 5] = current_source[soffset + 86];
          current_target[toffset + 9 * cont3csize + 6] = current_source[soffset + 87];
          current_target[toffset + 9 * cont3csize + 7] = current_source[soffset + 88];
          current_target[toffset + 9 * cont3csize + 8] = current_source[soffset + 89];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 90];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 91];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 92];
          current_target[toffset + 10 * cont3csize + 3] = current_source[soffset + 93];
          current_target[toffset + 10 * cont3csize + 4] = current_source[soffset + 94];
          current_target[toffset + 10 * cont3csize + 5] = current_source[soffset + 95];
          current_target[toffset + 10 * cont3csize + 6] = current_source[soffset + 96];
          current_target[toffset + 10 * cont3csize + 7] = current_source[soffset + 97];
          current_target[toffset + 10 * cont3csize + 8] = current_source[soffset + 98];
        }
      }

    }
  }

}


void SortList::sort_indices_55_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 121;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 11 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 11;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 121 * (c3 + c3end * c2);
          const int toffset = 11 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset + 7 * cont2csize    ] = current_source[soffset + 7];
          current_target[toffset + 8 * cont2csize    ] = current_source[soffset + 8];
          current_target[toffset + 9 * cont2csize    ] = current_source[soffset + 9];
          current_target[toffset + 10 * cont2csize    ] = current_source[soffset + 10];
          current_target[toffset +                  1] = current_source[soffset + 11];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 12];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 13];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 14];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 15];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 16];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 17];
          current_target[toffset + 7 * cont2csize + 1] = current_source[soffset + 18];
          current_target[toffset + 8 * cont2csize + 1] = current_source[soffset + 19];
          current_target[toffset + 9 * cont2csize + 1] = current_source[soffset + 20];
          current_target[toffset + 10 * cont2csize + 1] = current_source[soffset + 21];
          current_target[toffset +                  2] = current_source[soffset + 22];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 23];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 24];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 25];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 26];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 27];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 28];
          current_target[toffset + 7 * cont2csize + 2] = current_source[soffset + 29];
          current_target[toffset + 8 * cont2csize + 2] = current_source[soffset + 30];
          current_target[toffset + 9 * cont2csize + 2] = current_source[soffset + 31];
          current_target[toffset + 10 * cont2csize + 2] = current_source[soffset + 32];
          current_target[toffset +                  3] = current_source[soffset + 33];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 34];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 35];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 36];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 37];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 38];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 39];
          current_target[toffset + 7 * cont2csize + 3] = current_source[soffset + 40];
          current_target[toffset + 8 * cont2csize + 3] = current_source[soffset + 41];
          current_target[toffset + 9 * cont2csize + 3] = current_source[soffset + 42];
          current_target[toffset + 10 * cont2csize + 3] = current_source[soffset + 43];
          current_target[toffset +                  4] = current_source[soffset + 44];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 45];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 46];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 47];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 48];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 49];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 50];
          current_target[toffset + 7 * cont2csize + 4] = current_source[soffset + 51];
          current_target[toffset + 8 * cont2csize + 4] = current_source[soffset + 52];
          current_target[toffset + 9 * cont2csize + 4] = current_source[soffset + 53];
          current_target[toffset + 10 * cont2csize + 4] = current_source[soffset + 54];
          current_target[toffset +                  5] = current_source[soffset + 55];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 56];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 57];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 58];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 59];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 60];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 61];
          current_target[toffset + 7 * cont2csize + 5] = current_source[soffset + 62];
          current_target[toffset + 8 * cont2csize + 5] = current_source[soffset + 63];
          current_target[toffset + 9 * cont2csize + 5] = current_source[soffset + 64];
          current_target[toffset + 10 * cont2csize + 5] = current_source[soffset + 65];
          current_target[toffset +                  6] = current_source[soffset + 66];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 67];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 68];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 69];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 70];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 71];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 72];
          current_target[toffset + 7 * cont2csize + 6] = current_source[soffset + 73];
          current_target[toffset + 8 * cont2csize + 6] = current_source[soffset + 74];
          current_target[toffset + 9 * cont2csize + 6] = current_source[soffset + 75];
          current_target[toffset + 10 * cont2csize + 6] = current_source[soffset + 76];
          current_target[toffset +                  7] = current_source[soffset + 77];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 78];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 79];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 80];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 81];
          current_target[toffset + 5 * cont2csize + 7] = current_source[soffset + 82];
          current_target[toffset + 6 * cont2csize + 7] = current_source[soffset + 83];
          current_target[toffset + 7 * cont2csize + 7] = current_source[soffset + 84];
          current_target[toffset + 8 * cont2csize + 7] = current_source[soffset + 85];
          current_target[toffset + 9 * cont2csize + 7] = current_source[soffset + 86];
          current_target[toffset + 10 * cont2csize + 7] = current_source[soffset + 87];
          current_target[toffset +                  8] = current_source[soffset + 88];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 89];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 90];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 91];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 92];
          current_target[toffset + 5 * cont2csize + 8] = current_source[soffset + 93];
          current_target[toffset + 6 * cont2csize + 8] = current_source[soffset + 94];
          current_target[toffset + 7 * cont2csize + 8] = current_source[soffset + 95];
          current_target[toffset + 8 * cont2csize + 8] = current_source[soffset + 96];
          current_target[toffset + 9 * cont2csize + 8] = current_source[soffset + 97];
          current_target[toffset + 10 * cont2csize + 8] = current_source[soffset + 98];
          current_target[toffset +                  9] = current_source[soffset + 99];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 100];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 101];
          current_target[toffset + 3 * cont2csize + 9] = current_source[soffset + 102];
          current_target[toffset + 4 * cont2csize + 9] = current_source[soffset + 103];
          current_target[toffset + 5 * cont2csize + 9] = current_source[soffset + 104];
          current_target[toffset + 6 * cont2csize + 9] = current_source[soffset + 105];
          current_target[toffset + 7 * cont2csize + 9] = current_source[soffset + 106];
          current_target[toffset + 8 * cont2csize + 9] = current_source[soffset + 107];
          current_target[toffset + 9 * cont2csize + 9] = current_source[soffset + 108];
          current_target[toffset + 10 * cont2csize + 9] = current_source[soffset + 109];
          current_target[toffset +                  10] = current_source[soffset + 110];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 111];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 112];
          current_target[toffset + 3 * cont2csize + 10] = current_source[soffset + 113];
          current_target[toffset + 4 * cont2csize + 10] = current_source[soffset + 114];
          current_target[toffset + 5 * cont2csize + 10] = current_source[soffset + 115];
          current_target[toffset + 6 * cont2csize + 10] = current_source[soffset + 116];
          current_target[toffset + 7 * cont2csize + 10] = current_source[soffset + 117];
          current_target[toffset + 8 * cont2csize + 10] = current_source[soffset + 118];
          current_target[toffset + 9 * cont2csize + 10] = current_source[soffset + 119];
          current_target[toffset + 10 * cont2csize + 10] = current_source[soffset + 120];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 11 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 11;
          const int soffset = 121 * (c3 + c3end * c2);
          const int toffset = 11 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +                  7] = current_source[soffset + 7];
          current_target[toffset +                  8] = current_source[soffset + 8];
          current_target[toffset +                  9] = current_source[soffset + 9];
          current_target[toffset +                  10] = current_source[soffset + 10];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 11];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 12];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 13];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 14];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 15];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 16];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 17];
          current_target[toffset +     cont3csize + 7] = current_source[soffset + 18];
          current_target[toffset +     cont3csize + 8] = current_source[soffset + 19];
          current_target[toffset +     cont3csize + 9] = current_source[soffset + 20];
          current_target[toffset +     cont3csize + 10] = current_source[soffset + 21];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 22];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 23];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 24];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 25];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 26];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 27];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 28];
          current_target[toffset + 2 * cont3csize + 7] = current_source[soffset + 29];
          current_target[toffset + 2 * cont3csize + 8] = current_source[soffset + 30];
          current_target[toffset + 2 * cont3csize + 9] = current_source[soffset + 31];
          current_target[toffset + 2 * cont3csize + 10] = current_source[soffset + 32];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 33];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 34];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 35];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 36];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 37];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 38];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 39];
          current_target[toffset + 3 * cont3csize + 7] = current_source[soffset + 40];
          current_target[toffset + 3 * cont3csize + 8] = current_source[soffset + 41];
          current_target[toffset + 3 * cont3csize + 9] = current_source[soffset + 42];
          current_target[toffset + 3 * cont3csize + 10] = current_source[soffset + 43];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 44];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 45];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 46];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 47];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 48];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 49];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 50];
          current_target[toffset + 4 * cont3csize + 7] = current_source[soffset + 51];
          current_target[toffset + 4 * cont3csize + 8] = current_source[soffset + 52];
          current_target[toffset + 4 * cont3csize + 9] = current_source[soffset + 53];
          current_target[toffset + 4 * cont3csize + 10] = current_source[soffset + 54];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 55];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 56];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 57];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 58];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 59];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 60];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 61];
          current_target[toffset + 5 * cont3csize + 7] = current_source[soffset + 62];
          current_target[toffset + 5 * cont3csize + 8] = current_source[soffset + 63];
          current_target[toffset + 5 * cont3csize + 9] = current_source[soffset + 64];
          current_target[toffset + 5 * cont3csize + 10] = current_source[soffset + 65];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 66];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 67];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 68];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 69];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 70];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 71];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 72];
          current_target[toffset + 6 * cont3csize + 7] = current_source[soffset + 73];
          current_target[toffset + 6 * cont3csize + 8] = current_source[soffset + 74];
          current_target[toffset + 6 * cont3csize + 9] = current_source[soffset + 75];
          current_target[toffset + 6 * cont3csize + 10] = current_source[soffset + 76];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 77];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 78];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 79];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 80];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 81];
          current_target[toffset + 7 * cont3csize + 5] = current_source[soffset + 82];
          current_target[toffset + 7 * cont3csize + 6] = current_source[soffset + 83];
          current_target[toffset + 7 * cont3csize + 7] = current_source[soffset + 84];
          current_target[toffset + 7 * cont3csize + 8] = current_source[soffset + 85];
          current_target[toffset + 7 * cont3csize + 9] = current_source[soffset + 86];
          current_target[toffset + 7 * cont3csize + 10] = current_source[soffset + 87];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 88];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 89];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 90];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 91];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 92];
          current_target[toffset + 8 * cont3csize + 5] = current_source[soffset + 93];
          current_target[toffset + 8 * cont3csize + 6] = current_source[soffset + 94];
          current_target[toffset + 8 * cont3csize + 7] = current_source[soffset + 95];
          current_target[toffset + 8 * cont3csize + 8] = current_source[soffset + 96];
          current_target[toffset + 8 * cont3csize + 9] = current_source[soffset + 97];
          current_target[toffset + 8 * cont3csize + 10] = current_source[soffset + 98];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 99];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 100];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 101];
          current_target[toffset + 9 * cont3csize + 3] = current_source[soffset + 102];
          current_target[toffset + 9 * cont3csize + 4] = current_source[soffset + 103];
          current_target[toffset + 9 * cont3csize + 5] = current_source[soffset + 104];
          current_target[toffset + 9 * cont3csize + 6] = current_source[soffset + 105];
          current_target[toffset + 9 * cont3csize + 7] = current_source[soffset + 106];
          current_target[toffset + 9 * cont3csize + 8] = current_source[soffset + 107];
          current_target[toffset + 9 * cont3csize + 9] = current_source[soffset + 108];
          current_target[toffset + 9 * cont3csize + 10] = current_source[soffset + 109];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 110];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 111];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 112];
          current_target[toffset + 10 * cont3csize + 3] = current_source[soffset + 113];
          current_target[toffset + 10 * cont3csize + 4] = current_source[soffset + 114];
          current_target[toffset + 10 * cont3csize + 5] = current_source[soffset + 115];
          current_target[toffset + 10 * cont3csize + 6] = current_source[soffset + 116];
          current_target[toffset + 10 * cont3csize + 7] = current_source[soffset + 117];
          current_target[toffset + 10 * cont3csize + 8] = current_source[soffset + 118];
          current_target[toffset + 10 * cont3csize + 9] = current_source[soffset + 119];
          current_target[toffset + 10 * cont3csize + 10] = current_source[soffset + 120];
        }
      }

    }
  }

}


void SortList::sort_indices_06_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 13;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 13 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 13;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 13 * (c3 + c3end * c2);
          const int toffset = 1 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +                  7] = current_source[soffset + 7];
          current_target[toffset +                  8] = current_source[soffset + 8];
          current_target[toffset +                  9] = current_source[soffset + 9];
          current_target[toffset +                  10] = current_source[soffset + 10];
          current_target[toffset +                  11] = current_source[soffset + 11];
          current_target[toffset +                  12] = current_source[soffset + 12];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 1 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 1;
          const int soffset = 13 * (c3 + c3end * c2);
          const int toffset = 13 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 6];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 7];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 8];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 9];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 10];
          current_target[toffset + 11 * cont3csize    ] = current_source[soffset + 11];
          current_target[toffset + 12 * cont3csize    ] = current_source[soffset + 12];
        }
      }

    }
  }

}


void SortList::sort_indices_16_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 39;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 13 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 13;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 39 * (c3 + c3end * c2);
          const int toffset = 3 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset +                  1] = current_source[soffset + 3];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 4];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 5];
          current_target[toffset +                  2] = current_source[soffset + 6];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 7];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 8];
          current_target[toffset +                  3] = current_source[soffset + 9];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 10];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 11];
          current_target[toffset +                  4] = current_source[soffset + 12];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 13];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 14];
          current_target[toffset +                  5] = current_source[soffset + 15];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 16];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 17];
          current_target[toffset +                  6] = current_source[soffset + 18];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 19];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 20];
          current_target[toffset +                  7] = current_source[soffset + 21];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 22];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 23];
          current_target[toffset +                  8] = current_source[soffset + 24];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 25];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 26];
          current_target[toffset +                  9] = current_source[soffset + 27];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 28];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 29];
          current_target[toffset +                  10] = current_source[soffset + 30];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 31];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 32];
          current_target[toffset +                  11] = current_source[soffset + 33];
          current_target[toffset +     cont2csize + 11] = current_source[soffset + 34];
          current_target[toffset + 2 * cont2csize + 11] = current_source[soffset + 35];
          current_target[toffset +                  12] = current_source[soffset + 36];
          current_target[toffset +     cont2csize + 12] = current_source[soffset + 37];
          current_target[toffset + 2 * cont2csize + 12] = current_source[soffset + 38];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 3 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 3;
          const int soffset = 39 * (c3 + c3end * c2);
          const int toffset = 13 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 3];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 4];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 5];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 6];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 7];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 8];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 9];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 10];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 11];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 12];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 13];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 14];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 15];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 16];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 17];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 18];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 19];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 20];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 21];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 22];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 23];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 24];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 25];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 26];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 27];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 28];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 29];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 30];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 31];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 32];
          current_target[toffset + 11 * cont3csize    ] = current_source[soffset + 33];
          current_target[toffset + 11 * cont3csize + 1] = current_source[soffset + 34];
          current_target[toffset + 11 * cont3csize + 2] = current_source[soffset + 35];
          current_target[toffset + 12 * cont3csize    ] = current_source[soffset + 36];
          current_target[toffset + 12 * cont3csize + 1] = current_source[soffset + 37];
          current_target[toffset + 12 * cont3csize + 2] = current_source[soffset + 38];
        }
      }

    }
  }

}


void SortList::sort_indices_26_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 65;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 13 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 13;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 65 * (c3 + c3end * c2);
          const int toffset = 5 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset +                  1] = current_source[soffset + 5];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 6];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 7];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 8];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 9];
          current_target[toffset +                  2] = current_source[soffset + 10];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 11];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 12];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 13];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 14];
          current_target[toffset +                  3] = current_source[soffset + 15];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 16];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 17];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 18];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 19];
          current_target[toffset +                  4] = current_source[soffset + 20];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 21];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 22];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 23];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 24];
          current_target[toffset +                  5] = current_source[soffset + 25];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 26];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 27];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 28];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 29];
          current_target[toffset +                  6] = current_source[soffset + 30];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 31];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 32];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 33];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 34];
          current_target[toffset +                  7] = current_source[soffset + 35];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 36];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 37];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 38];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 39];
          current_target[toffset +                  8] = current_source[soffset + 40];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 41];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 42];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 43];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 44];
          current_target[toffset +                  9] = current_source[soffset + 45];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 46];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 47];
          current_target[toffset + 3 * cont2csize + 9] = current_source[soffset + 48];
          current_target[toffset + 4 * cont2csize + 9] = current_source[soffset + 49];
          current_target[toffset +                  10] = current_source[soffset + 50];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 51];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 52];
          current_target[toffset + 3 * cont2csize + 10] = current_source[soffset + 53];
          current_target[toffset + 4 * cont2csize + 10] = current_source[soffset + 54];
          current_target[toffset +                  11] = current_source[soffset + 55];
          current_target[toffset +     cont2csize + 11] = current_source[soffset + 56];
          current_target[toffset + 2 * cont2csize + 11] = current_source[soffset + 57];
          current_target[toffset + 3 * cont2csize + 11] = current_source[soffset + 58];
          current_target[toffset + 4 * cont2csize + 11] = current_source[soffset + 59];
          current_target[toffset +                  12] = current_source[soffset + 60];
          current_target[toffset +     cont2csize + 12] = current_source[soffset + 61];
          current_target[toffset + 2 * cont2csize + 12] = current_source[soffset + 62];
          current_target[toffset + 3 * cont2csize + 12] = current_source[soffset + 63];
          current_target[toffset + 4 * cont2csize + 12] = current_source[soffset + 64];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 5 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 5;
          const int soffset = 65 * (c3 + c3end * c2);
          const int toffset = 13 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 5];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 6];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 7];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 8];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 9];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 10];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 11];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 12];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 13];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 14];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 15];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 16];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 17];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 18];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 19];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 20];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 21];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 22];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 23];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 24];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 25];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 26];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 27];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 28];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 29];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 30];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 31];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 32];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 33];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 34];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 35];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 36];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 37];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 38];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 39];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 40];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 41];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 42];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 43];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 44];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 45];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 46];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 47];
          current_target[toffset + 9 * cont3csize + 3] = current_source[soffset + 48];
          current_target[toffset + 9 * cont3csize + 4] = current_source[soffset + 49];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 50];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 51];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 52];
          current_target[toffset + 10 * cont3csize + 3] = current_source[soffset + 53];
          current_target[toffset + 10 * cont3csize + 4] = current_source[soffset + 54];
          current_target[toffset + 11 * cont3csize    ] = current_source[soffset + 55];
          current_target[toffset + 11 * cont3csize + 1] = current_source[soffset + 56];
          current_target[toffset + 11 * cont3csize + 2] = current_source[soffset + 57];
          current_target[toffset + 11 * cont3csize + 3] = current_source[soffset + 58];
          current_target[toffset + 11 * cont3csize + 4] = current_source[soffset + 59];
          current_target[toffset + 12 * cont3csize    ] = current_source[soffset + 60];
          current_target[toffset + 12 * cont3csize + 1] = current_source[soffset + 61];
          current_target[toffset + 12 * cont3csize + 2] = current_source[soffset + 62];
          current_target[toffset + 12 * cont3csize + 3] = current_source[soffset + 63];
          current_target[toffset + 12 * cont3csize + 4] = current_source[soffset + 64];
        }
      }

    }
  }

}


void SortList::sort_indices_36_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 91;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 13 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 13;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 91 * (c3 + c3end * c2);
          const int toffset = 7 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset +                  1] = current_source[soffset + 7];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 8];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 9];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 10];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 11];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 12];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 13];
          current_target[toffset +                  2] = current_source[soffset + 14];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 15];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 16];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 17];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 18];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 19];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 20];
          current_target[toffset +                  3] = current_source[soffset + 21];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 22];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 23];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 24];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 25];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 26];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 27];
          current_target[toffset +                  4] = current_source[soffset + 28];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 29];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 30];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 31];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 32];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 33];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 34];
          current_target[toffset +                  5] = current_source[soffset + 35];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 36];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 37];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 38];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 39];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 40];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 41];
          current_target[toffset +                  6] = current_source[soffset + 42];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 43];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 44];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 45];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 46];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 47];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 48];
          current_target[toffset +                  7] = current_source[soffset + 49];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 50];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 51];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 52];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 53];
          current_target[toffset + 5 * cont2csize + 7] = current_source[soffset + 54];
          current_target[toffset + 6 * cont2csize + 7] = current_source[soffset + 55];
          current_target[toffset +                  8] = current_source[soffset + 56];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 57];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 58];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 59];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 60];
          current_target[toffset + 5 * cont2csize + 8] = current_source[soffset + 61];
          current_target[toffset + 6 * cont2csize + 8] = current_source[soffset + 62];
          current_target[toffset +                  9] = current_source[soffset + 63];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 64];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 65];
          current_target[toffset + 3 * cont2csize + 9] = current_source[soffset + 66];
          current_target[toffset + 4 * cont2csize + 9] = current_source[soffset + 67];
          current_target[toffset + 5 * cont2csize + 9] = current_source[soffset + 68];
          current_target[toffset + 6 * cont2csize + 9] = current_source[soffset + 69];
          current_target[toffset +                  10] = current_source[soffset + 70];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 71];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 72];
          current_target[toffset + 3 * cont2csize + 10] = current_source[soffset + 73];
          current_target[toffset + 4 * cont2csize + 10] = current_source[soffset + 74];
          current_target[toffset + 5 * cont2csize + 10] = current_source[soffset + 75];
          current_target[toffset + 6 * cont2csize + 10] = current_source[soffset + 76];
          current_target[toffset +                  11] = current_source[soffset + 77];
          current_target[toffset +     cont2csize + 11] = current_source[soffset + 78];
          current_target[toffset + 2 * cont2csize + 11] = current_source[soffset + 79];
          current_target[toffset + 3 * cont2csize + 11] = current_source[soffset + 80];
          current_target[toffset + 4 * cont2csize + 11] = current_source[soffset + 81];
          current_target[toffset + 5 * cont2csize + 11] = current_source[soffset + 82];
          current_target[toffset + 6 * cont2csize + 11] = current_source[soffset + 83];
          current_target[toffset +                  12] = current_source[soffset + 84];
          current_target[toffset +     cont2csize + 12] = current_source[soffset + 85];
          current_target[toffset + 2 * cont2csize + 12] = current_source[soffset + 86];
          current_target[toffset + 3 * cont2csize + 12] = current_source[soffset + 87];
          current_target[toffset + 4 * cont2csize + 12] = current_source[soffset + 88];
          current_target[toffset + 5 * cont2csize + 12] = current_source[soffset + 89];
          current_target[toffset + 6 * cont2csize + 12] = current_source[soffset + 90];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 7 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 7;
          const int soffset = 91 * (c3 + c3end * c2);
          const int toffset = 13 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 7];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 8];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 9];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 10];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 11];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 12];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 13];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 14];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 15];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 16];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 17];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 18];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 19];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 20];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 21];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 22];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 23];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 24];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 25];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 26];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 27];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 28];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 29];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 30];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 31];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 32];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 33];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 34];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 35];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 36];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 37];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 38];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 39];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 40];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 41];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 42];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 43];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 44];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 45];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 46];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 47];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 48];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 49];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 50];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 51];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 52];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 53];
          current_target[toffset + 7 * cont3csize + 5] = current_source[soffset + 54];
          current_target[toffset + 7 * cont3csize + 6] = current_source[soffset + 55];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 56];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 57];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 58];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 59];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 60];
          current_target[toffset + 8 * cont3csize + 5] = current_source[soffset + 61];
          current_target[toffset + 8 * cont3csize + 6] = current_source[soffset + 62];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 63];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 64];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 65];
          current_target[toffset + 9 * cont3csize + 3] = current_source[soffset + 66];
          current_target[toffset + 9 * cont3csize + 4] = current_source[soffset + 67];
          current_target[toffset + 9 * cont3csize + 5] = current_source[soffset + 68];
          current_target[toffset + 9 * cont3csize + 6] = current_source[soffset + 69];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 70];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 71];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 72];
          current_target[toffset + 10 * cont3csize + 3] = current_source[soffset + 73];
          current_target[toffset + 10 * cont3csize + 4] = current_source[soffset + 74];
          current_target[toffset + 10 * cont3csize + 5] = current_source[soffset + 75];
          current_target[toffset + 10 * cont3csize + 6] = current_source[soffset + 76];
          current_target[toffset + 11 * cont3csize    ] = current_source[soffset + 77];
          current_target[toffset + 11 * cont3csize + 1] = current_source[soffset + 78];
          current_target[toffset + 11 * cont3csize + 2] = current_source[soffset + 79];
          current_target[toffset + 11 * cont3csize + 3] = current_source[soffset + 80];
          current_target[toffset + 11 * cont3csize + 4] = current_source[soffset + 81];
          current_target[toffset + 11 * cont3csize + 5] = current_source[soffset + 82];
          current_target[toffset + 11 * cont3csize + 6] = current_source[soffset + 83];
          current_target[toffset + 12 * cont3csize    ] = current_source[soffset + 84];
          current_target[toffset + 12 * cont3csize + 1] = current_source[soffset + 85];
          current_target[toffset + 12 * cont3csize + 2] = current_source[soffset + 86];
          current_target[toffset + 12 * cont3csize + 3] = current_source[soffset + 87];
          current_target[toffset + 12 * cont3csize + 4] = current_source[soffset + 88];
          current_target[toffset + 12 * cont3csize + 5] = current_source[soffset + 89];
          current_target[toffset + 12 * cont3csize + 6] = current_source[soffset + 90];
        }
      }

    }
  }

}


void SortList::sort_indices_46_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 117;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 13 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 13;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 117 * (c3 + c3end * c2);
          const int toffset = 9 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset + 7 * cont2csize    ] = current_source[soffset + 7];
          current_target[toffset + 8 * cont2csize    ] = current_source[soffset + 8];
          current_target[toffset +                  1] = current_source[soffset + 9];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 10];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 11];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 12];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 13];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 14];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 15];
          current_target[toffset + 7 * cont2csize + 1] = current_source[soffset + 16];
          current_target[toffset + 8 * cont2csize + 1] = current_source[soffset + 17];
          current_target[toffset +                  2] = current_source[soffset + 18];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 19];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 20];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 21];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 22];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 23];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 24];
          current_target[toffset + 7 * cont2csize + 2] = current_source[soffset + 25];
          current_target[toffset + 8 * cont2csize + 2] = current_source[soffset + 26];
          current_target[toffset +                  3] = current_source[soffset + 27];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 28];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 29];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 30];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 31];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 32];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 33];
          current_target[toffset + 7 * cont2csize + 3] = current_source[soffset + 34];
          current_target[toffset + 8 * cont2csize + 3] = current_source[soffset + 35];
          current_target[toffset +                  4] = current_source[soffset + 36];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 37];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 38];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 39];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 40];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 41];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 42];
          current_target[toffset + 7 * cont2csize + 4] = current_source[soffset + 43];
          current_target[toffset + 8 * cont2csize + 4] = current_source[soffset + 44];
          current_target[toffset +                  5] = current_source[soffset + 45];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 46];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 47];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 48];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 49];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 50];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 51];
          current_target[toffset + 7 * cont2csize + 5] = current_source[soffset + 52];
          current_target[toffset + 8 * cont2csize + 5] = current_source[soffset + 53];
          current_target[toffset +                  6] = current_source[soffset + 54];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 55];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 56];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 57];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 58];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 59];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 60];
          current_target[toffset + 7 * cont2csize + 6] = current_source[soffset + 61];
          current_target[toffset + 8 * cont2csize + 6] = current_source[soffset + 62];
          current_target[toffset +                  7] = current_source[soffset + 63];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 64];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 65];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 66];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 67];
          current_target[toffset + 5 * cont2csize + 7] = current_source[soffset + 68];
          current_target[toffset + 6 * cont2csize + 7] = current_source[soffset + 69];
          current_target[toffset + 7 * cont2csize + 7] = current_source[soffset + 70];
          current_target[toffset + 8 * cont2csize + 7] = current_source[soffset + 71];
          current_target[toffset +                  8] = current_source[soffset + 72];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 73];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 74];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 75];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 76];
          current_target[toffset + 5 * cont2csize + 8] = current_source[soffset + 77];
          current_target[toffset + 6 * cont2csize + 8] = current_source[soffset + 78];
          current_target[toffset + 7 * cont2csize + 8] = current_source[soffset + 79];
          current_target[toffset + 8 * cont2csize + 8] = current_source[soffset + 80];
          current_target[toffset +                  9] = current_source[soffset + 81];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 82];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 83];
          current_target[toffset + 3 * cont2csize + 9] = current_source[soffset + 84];
          current_target[toffset + 4 * cont2csize + 9] = current_source[soffset + 85];
          current_target[toffset + 5 * cont2csize + 9] = current_source[soffset + 86];
          current_target[toffset + 6 * cont2csize + 9] = current_source[soffset + 87];
          current_target[toffset + 7 * cont2csize + 9] = current_source[soffset + 88];
          current_target[toffset + 8 * cont2csize + 9] = current_source[soffset + 89];
          current_target[toffset +                  10] = current_source[soffset + 90];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 91];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 92];
          current_target[toffset + 3 * cont2csize + 10] = current_source[soffset + 93];
          current_target[toffset + 4 * cont2csize + 10] = current_source[soffset + 94];
          current_target[toffset + 5 * cont2csize + 10] = current_source[soffset + 95];
          current_target[toffset + 6 * cont2csize + 10] = current_source[soffset + 96];
          current_target[toffset + 7 * cont2csize + 10] = current_source[soffset + 97];
          current_target[toffset + 8 * cont2csize + 10] = current_source[soffset + 98];
          current_target[toffset +                  11] = current_source[soffset + 99];
          current_target[toffset +     cont2csize + 11] = current_source[soffset + 100];
          current_target[toffset + 2 * cont2csize + 11] = current_source[soffset + 101];
          current_target[toffset + 3 * cont2csize + 11] = current_source[soffset + 102];
          current_target[toffset + 4 * cont2csize + 11] = current_source[soffset + 103];
          current_target[toffset + 5 * cont2csize + 11] = current_source[soffset + 104];
          current_target[toffset + 6 * cont2csize + 11] = current_source[soffset + 105];
          current_target[toffset + 7 * cont2csize + 11] = current_source[soffset + 106];
          current_target[toffset + 8 * cont2csize + 11] = current_source[soffset + 107];
          current_target[toffset +                  12] = current_source[soffset + 108];
          current_target[toffset +     cont2csize + 12] = current_source[soffset + 109];
          current_target[toffset + 2 * cont2csize + 12] = current_source[soffset + 110];
          current_target[toffset + 3 * cont2csize + 12] = current_source[soffset + 111];
          current_target[toffset + 4 * cont2csize + 12] = current_source[soffset + 112];
          current_target[toffset + 5 * cont2csize + 12] = current_source[soffset + 113];
          current_target[toffset + 6 * cont2csize + 12] = current_source[soffset + 114];
          current_target[toffset + 7 * cont2csize + 12] = current_source[soffset + 115];
          current_target[toffset + 8 * cont2csize + 12] = current_source[soffset + 116];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 9 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 9;
          const int soffset = 117 * (c3 + c3end * c2);
          const int toffset = 13 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +                  7] = current_source[soffset + 7];
          current_target[toffset +                  8] = current_source[soffset + 8];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 9];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 10];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 11];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 12];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 13];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 14];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 15];
          current_target[toffset +     cont3csize + 7] = current_source[soffset + 16];
          current_target[toffset +     cont3csize + 8] = current_source[soffset + 17];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 18];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 19];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 20];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 21];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 22];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 23];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 24];
          current_target[toffset + 2 * cont3csize + 7] = current_source[soffset + 25];
          current_target[toffset + 2 * cont3csize + 8] = current_source[soffset + 26];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 27];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 28];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 29];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 30];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 31];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 32];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 33];
          current_target[toffset + 3 * cont3csize + 7] = current_source[soffset + 34];
          current_target[toffset + 3 * cont3csize + 8] = current_source[soffset + 35];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 36];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 37];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 38];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 39];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 40];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 41];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 42];
          current_target[toffset + 4 * cont3csize + 7] = current_source[soffset + 43];
          current_target[toffset + 4 * cont3csize + 8] = current_source[soffset + 44];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 45];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 46];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 47];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 48];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 49];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 50];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 51];
          current_target[toffset + 5 * cont3csize + 7] = current_source[soffset + 52];
          current_target[toffset + 5 * cont3csize + 8] = current_source[soffset + 53];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 54];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 55];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 56];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 57];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 58];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 59];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 60];
          current_target[toffset + 6 * cont3csize + 7] = current_source[soffset + 61];
          current_target[toffset + 6 * cont3csize + 8] = current_source[soffset + 62];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 63];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 64];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 65];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 66];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 67];
          current_target[toffset + 7 * cont3csize + 5] = current_source[soffset + 68];
          current_target[toffset + 7 * cont3csize + 6] = current_source[soffset + 69];
          current_target[toffset + 7 * cont3csize + 7] = current_source[soffset + 70];
          current_target[toffset + 7 * cont3csize + 8] = current_source[soffset + 71];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 72];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 73];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 74];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 75];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 76];
          current_target[toffset + 8 * cont3csize + 5] = current_source[soffset + 77];
          current_target[toffset + 8 * cont3csize + 6] = current_source[soffset + 78];
          current_target[toffset + 8 * cont3csize + 7] = current_source[soffset + 79];
          current_target[toffset + 8 * cont3csize + 8] = current_source[soffset + 80];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 81];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 82];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 83];
          current_target[toffset + 9 * cont3csize + 3] = current_source[soffset + 84];
          current_target[toffset + 9 * cont3csize + 4] = current_source[soffset + 85];
          current_target[toffset + 9 * cont3csize + 5] = current_source[soffset + 86];
          current_target[toffset + 9 * cont3csize + 6] = current_source[soffset + 87];
          current_target[toffset + 9 * cont3csize + 7] = current_source[soffset + 88];
          current_target[toffset + 9 * cont3csize + 8] = current_source[soffset + 89];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 90];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 91];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 92];
          current_target[toffset + 10 * cont3csize + 3] = current_source[soffset + 93];
          current_target[toffset + 10 * cont3csize + 4] = current_source[soffset + 94];
          current_target[toffset + 10 * cont3csize + 5] = current_source[soffset + 95];
          current_target[toffset + 10 * cont3csize + 6] = current_source[soffset + 96];
          current_target[toffset + 10 * cont3csize + 7] = current_source[soffset + 97];
          current_target[toffset + 10 * cont3csize + 8] = current_source[soffset + 98];
          current_target[toffset + 11 * cont3csize    ] = current_source[soffset + 99];
          current_target[toffset + 11 * cont3csize + 1] = current_source[soffset + 100];
          current_target[toffset + 11 * cont3csize + 2] = current_source[soffset + 101];
          current_target[toffset + 11 * cont3csize + 3] = current_source[soffset + 102];
          current_target[toffset + 11 * cont3csize + 4] = current_source[soffset + 103];
          current_target[toffset + 11 * cont3csize + 5] = current_source[soffset + 104];
          current_target[toffset + 11 * cont3csize + 6] = current_source[soffset + 105];
          current_target[toffset + 11 * cont3csize + 7] = current_source[soffset + 106];
          current_target[toffset + 11 * cont3csize + 8] = current_source[soffset + 107];
          current_target[toffset + 12 * cont3csize    ] = current_source[soffset + 108];
          current_target[toffset + 12 * cont3csize + 1] = current_source[soffset + 109];
          current_target[toffset + 12 * cont3csize + 2] = current_source[soffset + 110];
          current_target[toffset + 12 * cont3csize + 3] = current_source[soffset + 111];
          current_target[toffset + 12 * cont3csize + 4] = current_source[soffset + 112];
          current_target[toffset + 12 * cont3csize + 5] = current_source[soffset + 113];
          current_target[toffset + 12 * cont3csize + 6] = current_source[soffset + 114];
          current_target[toffset + 12 * cont3csize + 7] = current_source[soffset + 115];
          current_target[toffset + 12 * cont3csize + 8] = current_source[soffset + 116];
        }
      }

    }
  }

}


void SortList::sort_indices_56_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 143;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 13 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 13;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 143 * (c3 + c3end * c2);
          const int toffset = 11 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset + 7 * cont2csize    ] = current_source[soffset + 7];
          current_target[toffset + 8 * cont2csize    ] = current_source[soffset + 8];
          current_target[toffset + 9 * cont2csize    ] = current_source[soffset + 9];
          current_target[toffset + 10 * cont2csize    ] = current_source[soffset + 10];
          current_target[toffset +                  1] = current_source[soffset + 11];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 12];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 13];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 14];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 15];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 16];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 17];
          current_target[toffset + 7 * cont2csize + 1] = current_source[soffset + 18];
          current_target[toffset + 8 * cont2csize + 1] = current_source[soffset + 19];
          current_target[toffset + 9 * cont2csize + 1] = current_source[soffset + 20];
          current_target[toffset + 10 * cont2csize + 1] = current_source[soffset + 21];
          current_target[toffset +                  2] = current_source[soffset + 22];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 23];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 24];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 25];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 26];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 27];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 28];
          current_target[toffset + 7 * cont2csize + 2] = current_source[soffset + 29];
          current_target[toffset + 8 * cont2csize + 2] = current_source[soffset + 30];
          current_target[toffset + 9 * cont2csize + 2] = current_source[soffset + 31];
          current_target[toffset + 10 * cont2csize + 2] = current_source[soffset + 32];
          current_target[toffset +                  3] = current_source[soffset + 33];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 34];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 35];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 36];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 37];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 38];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 39];
          current_target[toffset + 7 * cont2csize + 3] = current_source[soffset + 40];
          current_target[toffset + 8 * cont2csize + 3] = current_source[soffset + 41];
          current_target[toffset + 9 * cont2csize + 3] = current_source[soffset + 42];
          current_target[toffset + 10 * cont2csize + 3] = current_source[soffset + 43];
          current_target[toffset +                  4] = current_source[soffset + 44];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 45];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 46];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 47];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 48];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 49];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 50];
          current_target[toffset + 7 * cont2csize + 4] = current_source[soffset + 51];
          current_target[toffset + 8 * cont2csize + 4] = current_source[soffset + 52];
          current_target[toffset + 9 * cont2csize + 4] = current_source[soffset + 53];
          current_target[toffset + 10 * cont2csize + 4] = current_source[soffset + 54];
          current_target[toffset +                  5] = current_source[soffset + 55];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 56];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 57];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 58];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 59];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 60];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 61];
          current_target[toffset + 7 * cont2csize + 5] = current_source[soffset + 62];
          current_target[toffset + 8 * cont2csize + 5] = current_source[soffset + 63];
          current_target[toffset + 9 * cont2csize + 5] = current_source[soffset + 64];
          current_target[toffset + 10 * cont2csize + 5] = current_source[soffset + 65];
          current_target[toffset +                  6] = current_source[soffset + 66];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 67];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 68];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 69];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 70];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 71];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 72];
          current_target[toffset + 7 * cont2csize + 6] = current_source[soffset + 73];
          current_target[toffset + 8 * cont2csize + 6] = current_source[soffset + 74];
          current_target[toffset + 9 * cont2csize + 6] = current_source[soffset + 75];
          current_target[toffset + 10 * cont2csize + 6] = current_source[soffset + 76];
          current_target[toffset +                  7] = current_source[soffset + 77];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 78];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 79];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 80];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 81];
          current_target[toffset + 5 * cont2csize + 7] = current_source[soffset + 82];
          current_target[toffset + 6 * cont2csize + 7] = current_source[soffset + 83];
          current_target[toffset + 7 * cont2csize + 7] = current_source[soffset + 84];
          current_target[toffset + 8 * cont2csize + 7] = current_source[soffset + 85];
          current_target[toffset + 9 * cont2csize + 7] = current_source[soffset + 86];
          current_target[toffset + 10 * cont2csize + 7] = current_source[soffset + 87];
          current_target[toffset +                  8] = current_source[soffset + 88];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 89];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 90];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 91];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 92];
          current_target[toffset + 5 * cont2csize + 8] = current_source[soffset + 93];
          current_target[toffset + 6 * cont2csize + 8] = current_source[soffset + 94];
          current_target[toffset + 7 * cont2csize + 8] = current_source[soffset + 95];
          current_target[toffset + 8 * cont2csize + 8] = current_source[soffset + 96];
          current_target[toffset + 9 * cont2csize + 8] = current_source[soffset + 97];
          current_target[toffset + 10 * cont2csize + 8] = current_source[soffset + 98];
          current_target[toffset +                  9] = current_source[soffset + 99];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 100];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 101];
          current_target[toffset + 3 * cont2csize + 9] = current_source[soffset + 102];
          current_target[toffset + 4 * cont2csize + 9] = current_source[soffset + 103];
          current_target[toffset + 5 * cont2csize + 9] = current_source[soffset + 104];
          current_target[toffset + 6 * cont2csize + 9] = current_source[soffset + 105];
          current_target[toffset + 7 * cont2csize + 9] = current_source[soffset + 106];
          current_target[toffset + 8 * cont2csize + 9] = current_source[soffset + 107];
          current_target[toffset + 9 * cont2csize + 9] = current_source[soffset + 108];
          current_target[toffset + 10 * cont2csize + 9] = current_source[soffset + 109];
          current_target[toffset +                  10] = current_source[soffset + 110];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 111];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 112];
          current_target[toffset + 3 * cont2csize + 10] = current_source[soffset + 113];
          current_target[toffset + 4 * cont2csize + 10] = current_source[soffset + 114];
          current_target[toffset + 5 * cont2csize + 10] = current_source[soffset + 115];
          current_target[toffset + 6 * cont2csize + 10] = current_source[soffset + 116];
          current_target[toffset + 7 * cont2csize + 10] = current_source[soffset + 117];
          current_target[toffset + 8 * cont2csize + 10] = current_source[soffset + 118];
          current_target[toffset + 9 * cont2csize + 10] = current_source[soffset + 119];
          current_target[toffset + 10 * cont2csize + 10] = current_source[soffset + 120];
          current_target[toffset +                  11] = current_source[soffset + 121];
          current_target[toffset +     cont2csize + 11] = current_source[soffset + 122];
          current_target[toffset + 2 * cont2csize + 11] = current_source[soffset + 123];
          current_target[toffset + 3 * cont2csize + 11] = current_source[soffset + 124];
          current_target[toffset + 4 * cont2csize + 11] = current_source[soffset + 125];
          current_target[toffset + 5 * cont2csize + 11] = current_source[soffset + 126];
          current_target[toffset + 6 * cont2csize + 11] = current_source[soffset + 127];
          current_target[toffset + 7 * cont2csize + 11] = current_source[soffset + 128];
          current_target[toffset + 8 * cont2csize + 11] = current_source[soffset + 129];
          current_target[toffset + 9 * cont2csize + 11] = current_source[soffset + 130];
          current_target[toffset + 10 * cont2csize + 11] = current_source[soffset + 131];
          current_target[toffset +                  12] = current_source[soffset + 132];
          current_target[toffset +     cont2csize + 12] = current_source[soffset + 133];
          current_target[toffset + 2 * cont2csize + 12] = current_source[soffset + 134];
          current_target[toffset + 3 * cont2csize + 12] = current_source[soffset + 135];
          current_target[toffset + 4 * cont2csize + 12] = current_source[soffset + 136];
          current_target[toffset + 5 * cont2csize + 12] = current_source[soffset + 137];
          current_target[toffset + 6 * cont2csize + 12] = current_source[soffset + 138];
          current_target[toffset + 7 * cont2csize + 12] = current_source[soffset + 139];
          current_target[toffset + 8 * cont2csize + 12] = current_source[soffset + 140];
          current_target[toffset + 9 * cont2csize + 12] = current_source[soffset + 141];
          current_target[toffset + 10 * cont2csize + 12] = current_source[soffset + 142];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 11 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 11;
          const int soffset = 143 * (c3 + c3end * c2);
          const int toffset = 13 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +                  7] = current_source[soffset + 7];
          current_target[toffset +                  8] = current_source[soffset + 8];
          current_target[toffset +                  9] = current_source[soffset + 9];
          current_target[toffset +                  10] = current_source[soffset + 10];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 11];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 12];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 13];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 14];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 15];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 16];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 17];
          current_target[toffset +     cont3csize + 7] = current_source[soffset + 18];
          current_target[toffset +     cont3csize + 8] = current_source[soffset + 19];
          current_target[toffset +     cont3csize + 9] = current_source[soffset + 20];
          current_target[toffset +     cont3csize + 10] = current_source[soffset + 21];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 22];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 23];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 24];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 25];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 26];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 27];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 28];
          current_target[toffset + 2 * cont3csize + 7] = current_source[soffset + 29];
          current_target[toffset + 2 * cont3csize + 8] = current_source[soffset + 30];
          current_target[toffset + 2 * cont3csize + 9] = current_source[soffset + 31];
          current_target[toffset + 2 * cont3csize + 10] = current_source[soffset + 32];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 33];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 34];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 35];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 36];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 37];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 38];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 39];
          current_target[toffset + 3 * cont3csize + 7] = current_source[soffset + 40];
          current_target[toffset + 3 * cont3csize + 8] = current_source[soffset + 41];
          current_target[toffset + 3 * cont3csize + 9] = current_source[soffset + 42];
          current_target[toffset + 3 * cont3csize + 10] = current_source[soffset + 43];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 44];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 45];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 46];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 47];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 48];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 49];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 50];
          current_target[toffset + 4 * cont3csize + 7] = current_source[soffset + 51];
          current_target[toffset + 4 * cont3csize + 8] = current_source[soffset + 52];
          current_target[toffset + 4 * cont3csize + 9] = current_source[soffset + 53];
          current_target[toffset + 4 * cont3csize + 10] = current_source[soffset + 54];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 55];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 56];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 57];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 58];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 59];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 60];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 61];
          current_target[toffset + 5 * cont3csize + 7] = current_source[soffset + 62];
          current_target[toffset + 5 * cont3csize + 8] = current_source[soffset + 63];
          current_target[toffset + 5 * cont3csize + 9] = current_source[soffset + 64];
          current_target[toffset + 5 * cont3csize + 10] = current_source[soffset + 65];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 66];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 67];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 68];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 69];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 70];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 71];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 72];
          current_target[toffset + 6 * cont3csize + 7] = current_source[soffset + 73];
          current_target[toffset + 6 * cont3csize + 8] = current_source[soffset + 74];
          current_target[toffset + 6 * cont3csize + 9] = current_source[soffset + 75];
          current_target[toffset + 6 * cont3csize + 10] = current_source[soffset + 76];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 77];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 78];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 79];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 80];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 81];
          current_target[toffset + 7 * cont3csize + 5] = current_source[soffset + 82];
          current_target[toffset + 7 * cont3csize + 6] = current_source[soffset + 83];
          current_target[toffset + 7 * cont3csize + 7] = current_source[soffset + 84];
          current_target[toffset + 7 * cont3csize + 8] = current_source[soffset + 85];
          current_target[toffset + 7 * cont3csize + 9] = current_source[soffset + 86];
          current_target[toffset + 7 * cont3csize + 10] = current_source[soffset + 87];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 88];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 89];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 90];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 91];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 92];
          current_target[toffset + 8 * cont3csize + 5] = current_source[soffset + 93];
          current_target[toffset + 8 * cont3csize + 6] = current_source[soffset + 94];
          current_target[toffset + 8 * cont3csize + 7] = current_source[soffset + 95];
          current_target[toffset + 8 * cont3csize + 8] = current_source[soffset + 96];
          current_target[toffset + 8 * cont3csize + 9] = current_source[soffset + 97];
          current_target[toffset + 8 * cont3csize + 10] = current_source[soffset + 98];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 99];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 100];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 101];
          current_target[toffset + 9 * cont3csize + 3] = current_source[soffset + 102];
          current_target[toffset + 9 * cont3csize + 4] = current_source[soffset + 103];
          current_target[toffset + 9 * cont3csize + 5] = current_source[soffset + 104];
          current_target[toffset + 9 * cont3csize + 6] = current_source[soffset + 105];
          current_target[toffset + 9 * cont3csize + 7] = current_source[soffset + 106];
          current_target[toffset + 9 * cont3csize + 8] = current_source[soffset + 107];
          current_target[toffset + 9 * cont3csize + 9] = current_source[soffset + 108];
          current_target[toffset + 9 * cont3csize + 10] = current_source[soffset + 109];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 110];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 111];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 112];
          current_target[toffset + 10 * cont3csize + 3] = current_source[soffset + 113];
          current_target[toffset + 10 * cont3csize + 4] = current_source[soffset + 114];
          current_target[toffset + 10 * cont3csize + 5] = current_source[soffset + 115];
          current_target[toffset + 10 * cont3csize + 6] = current_source[soffset + 116];
          current_target[toffset + 10 * cont3csize + 7] = current_source[soffset + 117];
          current_target[toffset + 10 * cont3csize + 8] = current_source[soffset + 118];
          current_target[toffset + 10 * cont3csize + 9] = current_source[soffset + 119];
          current_target[toffset + 10 * cont3csize + 10] = current_source[soffset + 120];
          current_target[toffset + 11 * cont3csize    ] = current_source[soffset + 121];
          current_target[toffset + 11 * cont3csize + 1] = current_source[soffset + 122];
          current_target[toffset + 11 * cont3csize + 2] = current_source[soffset + 123];
          current_target[toffset + 11 * cont3csize + 3] = current_source[soffset + 124];
          current_target[toffset + 11 * cont3csize + 4] = current_source[soffset + 125];
          current_target[toffset + 11 * cont3csize + 5] = current_source[soffset + 126];
          current_target[toffset + 11 * cont3csize + 6] = current_source[soffset + 127];
          current_target[toffset + 11 * cont3csize + 7] = current_source[soffset + 128];
          current_target[toffset + 11 * cont3csize + 8] = current_source[soffset + 129];
          current_target[toffset + 11 * cont3csize + 9] = current_source[soffset + 130];
          current_target[toffset + 11 * cont3csize + 10] = current_source[soffset + 131];
          current_target[toffset + 12 * cont3csize    ] = current_source[soffset + 132];
          current_target[toffset + 12 * cont3csize + 1] = current_source[soffset + 133];
          current_target[toffset + 12 * cont3csize + 2] = current_source[soffset + 134];
          current_target[toffset + 12 * cont3csize + 3] = current_source[soffset + 135];
          current_target[toffset + 12 * cont3csize + 4] = current_source[soffset + 136];
          current_target[toffset + 12 * cont3csize + 5] = current_source[soffset + 137];
          current_target[toffset + 12 * cont3csize + 6] = current_source[soffset + 138];
          current_target[toffset + 12 * cont3csize + 7] = current_source[soffset + 139];
          current_target[toffset + 12 * cont3csize + 8] = current_source[soffset + 140];
          current_target[toffset + 12 * cont3csize + 9] = current_source[soffset + 141];
          current_target[toffset + 12 * cont3csize + 10] = current_source[soffset + 142];
        }
      }

    }
  }

}


void SortList::sort_indices_66_sph(double* target, const double* source, const int c3end, const int c2end, const int loopsize, const bool swap23) {
  const int innerloopsize = c2end * c3end * 169;
  if (!swap23) {
    int offset = 0;
    const int cont2csize = 13 * c2end; 
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        const int c2x2end = c2 * 13;
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int soffset = 169 * (c3 + c3end * c2);
          const int toffset = 13 * c3 * cont2csize + c2x2end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +     cont2csize    ] = current_source[soffset + 1];
          current_target[toffset + 2 * cont2csize    ] = current_source[soffset + 2];
          current_target[toffset + 3 * cont2csize    ] = current_source[soffset + 3];
          current_target[toffset + 4 * cont2csize    ] = current_source[soffset + 4];
          current_target[toffset + 5 * cont2csize    ] = current_source[soffset + 5];
          current_target[toffset + 6 * cont2csize    ] = current_source[soffset + 6];
          current_target[toffset + 7 * cont2csize    ] = current_source[soffset + 7];
          current_target[toffset + 8 * cont2csize    ] = current_source[soffset + 8];
          current_target[toffset + 9 * cont2csize    ] = current_source[soffset + 9];
          current_target[toffset + 10 * cont2csize    ] = current_source[soffset + 10];
          current_target[toffset + 11 * cont2csize    ] = current_source[soffset + 11];
          current_target[toffset + 12 * cont2csize    ] = current_source[soffset + 12];
          current_target[toffset +                  1] = current_source[soffset + 13];
          current_target[toffset +     cont2csize + 1] = current_source[soffset + 14];
          current_target[toffset + 2 * cont2csize + 1] = current_source[soffset + 15];
          current_target[toffset + 3 * cont2csize + 1] = current_source[soffset + 16];
          current_target[toffset + 4 * cont2csize + 1] = current_source[soffset + 17];
          current_target[toffset + 5 * cont2csize + 1] = current_source[soffset + 18];
          current_target[toffset + 6 * cont2csize + 1] = current_source[soffset + 19];
          current_target[toffset + 7 * cont2csize + 1] = current_source[soffset + 20];
          current_target[toffset + 8 * cont2csize + 1] = current_source[soffset + 21];
          current_target[toffset + 9 * cont2csize + 1] = current_source[soffset + 22];
          current_target[toffset + 10 * cont2csize + 1] = current_source[soffset + 23];
          current_target[toffset + 11 * cont2csize + 1] = current_source[soffset + 24];
          current_target[toffset + 12 * cont2csize + 1] = current_source[soffset + 25];
          current_target[toffset +                  2] = current_source[soffset + 26];
          current_target[toffset +     cont2csize + 2] = current_source[soffset + 27];
          current_target[toffset + 2 * cont2csize + 2] = current_source[soffset + 28];
          current_target[toffset + 3 * cont2csize + 2] = current_source[soffset + 29];
          current_target[toffset + 4 * cont2csize + 2] = current_source[soffset + 30];
          current_target[toffset + 5 * cont2csize + 2] = current_source[soffset + 31];
          current_target[toffset + 6 * cont2csize + 2] = current_source[soffset + 32];
          current_target[toffset + 7 * cont2csize + 2] = current_source[soffset + 33];
          current_target[toffset + 8 * cont2csize + 2] = current_source[soffset + 34];
          current_target[toffset + 9 * cont2csize + 2] = current_source[soffset + 35];
          current_target[toffset + 10 * cont2csize + 2] = current_source[soffset + 36];
          current_target[toffset + 11 * cont2csize + 2] = current_source[soffset + 37];
          current_target[toffset + 12 * cont2csize + 2] = current_source[soffset + 38];
          current_target[toffset +                  3] = current_source[soffset + 39];
          current_target[toffset +     cont2csize + 3] = current_source[soffset + 40];
          current_target[toffset + 2 * cont2csize + 3] = current_source[soffset + 41];
          current_target[toffset + 3 * cont2csize + 3] = current_source[soffset + 42];
          current_target[toffset + 4 * cont2csize + 3] = current_source[soffset + 43];
          current_target[toffset + 5 * cont2csize + 3] = current_source[soffset + 44];
          current_target[toffset + 6 * cont2csize + 3] = current_source[soffset + 45];
          current_target[toffset + 7 * cont2csize + 3] = current_source[soffset + 46];
          current_target[toffset + 8 * cont2csize + 3] = current_source[soffset + 47];
          current_target[toffset + 9 * cont2csize + 3] = current_source[soffset + 48];
          current_target[toffset + 10 * cont2csize + 3] = current_source[soffset + 49];
          current_target[toffset + 11 * cont2csize + 3] = current_source[soffset + 50];
          current_target[toffset + 12 * cont2csize + 3] = current_source[soffset + 51];
          current_target[toffset +                  4] = current_source[soffset + 52];
          current_target[toffset +     cont2csize + 4] = current_source[soffset + 53];
          current_target[toffset + 2 * cont2csize + 4] = current_source[soffset + 54];
          current_target[toffset + 3 * cont2csize + 4] = current_source[soffset + 55];
          current_target[toffset + 4 * cont2csize + 4] = current_source[soffset + 56];
          current_target[toffset + 5 * cont2csize + 4] = current_source[soffset + 57];
          current_target[toffset + 6 * cont2csize + 4] = current_source[soffset + 58];
          current_target[toffset + 7 * cont2csize + 4] = current_source[soffset + 59];
          current_target[toffset + 8 * cont2csize + 4] = current_source[soffset + 60];
          current_target[toffset + 9 * cont2csize + 4] = current_source[soffset + 61];
          current_target[toffset + 10 * cont2csize + 4] = current_source[soffset + 62];
          current_target[toffset + 11 * cont2csize + 4] = current_source[soffset + 63];
          current_target[toffset + 12 * cont2csize + 4] = current_source[soffset + 64];
          current_target[toffset +                  5] = current_source[soffset + 65];
          current_target[toffset +     cont2csize + 5] = current_source[soffset + 66];
          current_target[toffset + 2 * cont2csize + 5] = current_source[soffset + 67];
          current_target[toffset + 3 * cont2csize + 5] = current_source[soffset + 68];
          current_target[toffset + 4 * cont2csize + 5] = current_source[soffset + 69];
          current_target[toffset + 5 * cont2csize + 5] = current_source[soffset + 70];
          current_target[toffset + 6 * cont2csize + 5] = current_source[soffset + 71];
          current_target[toffset + 7 * cont2csize + 5] = current_source[soffset + 72];
          current_target[toffset + 8 * cont2csize + 5] = current_source[soffset + 73];
          current_target[toffset + 9 * cont2csize + 5] = current_source[soffset + 74];
          current_target[toffset + 10 * cont2csize + 5] = current_source[soffset + 75];
          current_target[toffset + 11 * cont2csize + 5] = current_source[soffset + 76];
          current_target[toffset + 12 * cont2csize + 5] = current_source[soffset + 77];
          current_target[toffset +                  6] = current_source[soffset + 78];
          current_target[toffset +     cont2csize + 6] = current_source[soffset + 79];
          current_target[toffset + 2 * cont2csize + 6] = current_source[soffset + 80];
          current_target[toffset + 3 * cont2csize + 6] = current_source[soffset + 81];
          current_target[toffset + 4 * cont2csize + 6] = current_source[soffset + 82];
          current_target[toffset + 5 * cont2csize + 6] = current_source[soffset + 83];
          current_target[toffset + 6 * cont2csize + 6] = current_source[soffset + 84];
          current_target[toffset + 7 * cont2csize + 6] = current_source[soffset + 85];
          current_target[toffset + 8 * cont2csize + 6] = current_source[soffset + 86];
          current_target[toffset + 9 * cont2csize + 6] = current_source[soffset + 87];
          current_target[toffset + 10 * cont2csize + 6] = current_source[soffset + 88];
          current_target[toffset + 11 * cont2csize + 6] = current_source[soffset + 89];
          current_target[toffset + 12 * cont2csize + 6] = current_source[soffset + 90];
          current_target[toffset +                  7] = current_source[soffset + 91];
          current_target[toffset +     cont2csize + 7] = current_source[soffset + 92];
          current_target[toffset + 2 * cont2csize + 7] = current_source[soffset + 93];
          current_target[toffset + 3 * cont2csize + 7] = current_source[soffset + 94];
          current_target[toffset + 4 * cont2csize + 7] = current_source[soffset + 95];
          current_target[toffset + 5 * cont2csize + 7] = current_source[soffset + 96];
          current_target[toffset + 6 * cont2csize + 7] = current_source[soffset + 97];
          current_target[toffset + 7 * cont2csize + 7] = current_source[soffset + 98];
          current_target[toffset + 8 * cont2csize + 7] = current_source[soffset + 99];
          current_target[toffset + 9 * cont2csize + 7] = current_source[soffset + 100];
          current_target[toffset + 10 * cont2csize + 7] = current_source[soffset + 101];
          current_target[toffset + 11 * cont2csize + 7] = current_source[soffset + 102];
          current_target[toffset + 12 * cont2csize + 7] = current_source[soffset + 103];
          current_target[toffset +                  8] = current_source[soffset + 104];
          current_target[toffset +     cont2csize + 8] = current_source[soffset + 105];
          current_target[toffset + 2 * cont2csize + 8] = current_source[soffset + 106];
          current_target[toffset + 3 * cont2csize + 8] = current_source[soffset + 107];
          current_target[toffset + 4 * cont2csize + 8] = current_source[soffset + 108];
          current_target[toffset + 5 * cont2csize + 8] = current_source[soffset + 109];
          current_target[toffset + 6 * cont2csize + 8] = current_source[soffset + 110];
          current_target[toffset + 7 * cont2csize + 8] = current_source[soffset + 111];
          current_target[toffset + 8 * cont2csize + 8] = current_source[soffset + 112];
          current_target[toffset + 9 * cont2csize + 8] = current_source[soffset + 113];
          current_target[toffset + 10 * cont2csize + 8] = current_source[soffset + 114];
          current_target[toffset + 11 * cont2csize + 8] = current_source[soffset + 115];
          current_target[toffset + 12 * cont2csize + 8] = current_source[soffset + 116];
          current_target[toffset +                  9] = current_source[soffset + 117];
          current_target[toffset +     cont2csize + 9] = current_source[soffset + 118];
          current_target[toffset + 2 * cont2csize + 9] = current_source[soffset + 119];
          current_target[toffset + 3 * cont2csize + 9] = current_source[soffset + 120];
          current_target[toffset + 4 * cont2csize + 9] = current_source[soffset + 121];
          current_target[toffset + 5 * cont2csize + 9] = current_source[soffset + 122];
          current_target[toffset + 6 * cont2csize + 9] = current_source[soffset + 123];
          current_target[toffset + 7 * cont2csize + 9] = current_source[soffset + 124];
          current_target[toffset + 8 * cont2csize + 9] = current_source[soffset + 125];
          current_target[toffset + 9 * cont2csize + 9] = current_source[soffset + 126];
          current_target[toffset + 10 * cont2csize + 9] = current_source[soffset + 127];
          current_target[toffset + 11 * cont2csize + 9] = current_source[soffset + 128];
          current_target[toffset + 12 * cont2csize + 9] = current_source[soffset + 129];
          current_target[toffset +                  10] = current_source[soffset + 130];
          current_target[toffset +     cont2csize + 10] = current_source[soffset + 131];
          current_target[toffset + 2 * cont2csize + 10] = current_source[soffset + 132];
          current_target[toffset + 3 * cont2csize + 10] = current_source[soffset + 133];
          current_target[toffset + 4 * cont2csize + 10] = current_source[soffset + 134];
          current_target[toffset + 5 * cont2csize + 10] = current_source[soffset + 135];
          current_target[toffset + 6 * cont2csize + 10] = current_source[soffset + 136];
          current_target[toffset + 7 * cont2csize + 10] = current_source[soffset + 137];
          current_target[toffset + 8 * cont2csize + 10] = current_source[soffset + 138];
          current_target[toffset + 9 * cont2csize + 10] = current_source[soffset + 139];
          current_target[toffset + 10 * cont2csize + 10] = current_source[soffset + 140];
          current_target[toffset + 11 * cont2csize + 10] = current_source[soffset + 141];
          current_target[toffset + 12 * cont2csize + 10] = current_source[soffset + 142];
          current_target[toffset +                  11] = current_source[soffset + 143];
          current_target[toffset +     cont2csize + 11] = current_source[soffset + 144];
          current_target[toffset + 2 * cont2csize + 11] = current_source[soffset + 145];
          current_target[toffset + 3 * cont2csize + 11] = current_source[soffset + 146];
          current_target[toffset + 4 * cont2csize + 11] = current_source[soffset + 147];
          current_target[toffset + 5 * cont2csize + 11] = current_source[soffset + 148];
          current_target[toffset + 6 * cont2csize + 11] = current_source[soffset + 149];
          current_target[toffset + 7 * cont2csize + 11] = current_source[soffset + 150];
          current_target[toffset + 8 * cont2csize + 11] = current_source[soffset + 151];
          current_target[toffset + 9 * cont2csize + 11] = current_source[soffset + 152];
          current_target[toffset + 10 * cont2csize + 11] = current_source[soffset + 153];
          current_target[toffset + 11 * cont2csize + 11] = current_source[soffset + 154];
          current_target[toffset + 12 * cont2csize + 11] = current_source[soffset + 155];
          current_target[toffset +                  12] = current_source[soffset + 156];
          current_target[toffset +     cont2csize + 12] = current_source[soffset + 157];
          current_target[toffset + 2 * cont2csize + 12] = current_source[soffset + 158];
          current_target[toffset + 3 * cont2csize + 12] = current_source[soffset + 159];
          current_target[toffset + 4 * cont2csize + 12] = current_source[soffset + 160];
          current_target[toffset + 5 * cont2csize + 12] = current_source[soffset + 161];
          current_target[toffset + 6 * cont2csize + 12] = current_source[soffset + 162];
          current_target[toffset + 7 * cont2csize + 12] = current_source[soffset + 163];
          current_target[toffset + 8 * cont2csize + 12] = current_source[soffset + 164];
          current_target[toffset + 9 * cont2csize + 12] = current_source[soffset + 165];
          current_target[toffset + 10 * cont2csize + 12] = current_source[soffset + 166];
          current_target[toffset + 11 * cont2csize + 12] = current_source[soffset + 167];
          current_target[toffset + 12 * cont2csize + 12] = current_source[soffset + 168];
        }
      }

    }
  } else {
    int offset = 0;
    const int cont3csize = 13 * c3end;
    for (int i = 0; i != loopsize; ++i, offset += innerloopsize) {
      double* current_target = &target[offset];
      const double* current_source = &source[offset];

      for (int c2 = 0; c2 != c2end; ++c2) {
        for (int c3 = 0; c3 != c3end; ++c3) {
          const int c3x3end = c3 * 13;
          const int soffset = 169 * (c3 + c3end * c2);
          const int toffset = 13 * c2 * cont3csize + c3x3end;
          current_target[toffset                     ] = current_source[soffset];
          current_target[toffset +                  1] = current_source[soffset + 1];
          current_target[toffset +                  2] = current_source[soffset + 2];
          current_target[toffset +                  3] = current_source[soffset + 3];
          current_target[toffset +                  4] = current_source[soffset + 4];
          current_target[toffset +                  5] = current_source[soffset + 5];
          current_target[toffset +                  6] = current_source[soffset + 6];
          current_target[toffset +                  7] = current_source[soffset + 7];
          current_target[toffset +                  8] = current_source[soffset + 8];
          current_target[toffset +                  9] = current_source[soffset + 9];
          current_target[toffset +                  10] = current_source[soffset + 10];
          current_target[toffset +                  11] = current_source[soffset + 11];
          current_target[toffset +                  12] = current_source[soffset + 12];
          current_target[toffset +     cont3csize    ] = current_source[soffset + 13];
          current_target[toffset +     cont3csize + 1] = current_source[soffset + 14];
          current_target[toffset +     cont3csize + 2] = current_source[soffset + 15];
          current_target[toffset +     cont3csize + 3] = current_source[soffset + 16];
          current_target[toffset +     cont3csize + 4] = current_source[soffset + 17];
          current_target[toffset +     cont3csize + 5] = current_source[soffset + 18];
          current_target[toffset +     cont3csize + 6] = current_source[soffset + 19];
          current_target[toffset +     cont3csize + 7] = current_source[soffset + 20];
          current_target[toffset +     cont3csize + 8] = current_source[soffset + 21];
          current_target[toffset +     cont3csize + 9] = current_source[soffset + 22];
          current_target[toffset +     cont3csize + 10] = current_source[soffset + 23];
          current_target[toffset +     cont3csize + 11] = current_source[soffset + 24];
          current_target[toffset +     cont3csize + 12] = current_source[soffset + 25];
          current_target[toffset + 2 * cont3csize    ] = current_source[soffset + 26];
          current_target[toffset + 2 * cont3csize + 1] = current_source[soffset + 27];
          current_target[toffset + 2 * cont3csize + 2] = current_source[soffset + 28];
          current_target[toffset + 2 * cont3csize + 3] = current_source[soffset + 29];
          current_target[toffset + 2 * cont3csize + 4] = current_source[soffset + 30];
          current_target[toffset + 2 * cont3csize + 5] = current_source[soffset + 31];
          current_target[toffset + 2 * cont3csize + 6] = current_source[soffset + 32];
          current_target[toffset + 2 * cont3csize + 7] = current_source[soffset + 33];
          current_target[toffset + 2 * cont3csize + 8] = current_source[soffset + 34];
          current_target[toffset + 2 * cont3csize + 9] = current_source[soffset + 35];
          current_target[toffset + 2 * cont3csize + 10] = current_source[soffset + 36];
          current_target[toffset + 2 * cont3csize + 11] = current_source[soffset + 37];
          current_target[toffset + 2 * cont3csize + 12] = current_source[soffset + 38];
          current_target[toffset + 3 * cont3csize    ] = current_source[soffset + 39];
          current_target[toffset + 3 * cont3csize + 1] = current_source[soffset + 40];
          current_target[toffset + 3 * cont3csize + 2] = current_source[soffset + 41];
          current_target[toffset + 3 * cont3csize + 3] = current_source[soffset + 42];
          current_target[toffset + 3 * cont3csize + 4] = current_source[soffset + 43];
          current_target[toffset + 3 * cont3csize + 5] = current_source[soffset + 44];
          current_target[toffset + 3 * cont3csize + 6] = current_source[soffset + 45];
          current_target[toffset + 3 * cont3csize + 7] = current_source[soffset + 46];
          current_target[toffset + 3 * cont3csize + 8] = current_source[soffset + 47];
          current_target[toffset + 3 * cont3csize + 9] = current_source[soffset + 48];
          current_target[toffset + 3 * cont3csize + 10] = current_source[soffset + 49];
          current_target[toffset + 3 * cont3csize + 11] = current_source[soffset + 50];
          current_target[toffset + 3 * cont3csize + 12] = current_source[soffset + 51];
          current_target[toffset + 4 * cont3csize    ] = current_source[soffset + 52];
          current_target[toffset + 4 * cont3csize + 1] = current_source[soffset + 53];
          current_target[toffset + 4 * cont3csize + 2] = current_source[soffset + 54];
          current_target[toffset + 4 * cont3csize + 3] = current_source[soffset + 55];
          current_target[toffset + 4 * cont3csize + 4] = current_source[soffset + 56];
          current_target[toffset + 4 * cont3csize + 5] = current_source[soffset + 57];
          current_target[toffset + 4 * cont3csize + 6] = current_source[soffset + 58];
          current_target[toffset + 4 * cont3csize + 7] = current_source[soffset + 59];
          current_target[toffset + 4 * cont3csize + 8] = current_source[soffset + 60];
          current_target[toffset + 4 * cont3csize + 9] = current_source[soffset + 61];
          current_target[toffset + 4 * cont3csize + 10] = current_source[soffset + 62];
          current_target[toffset + 4 * cont3csize + 11] = current_source[soffset + 63];
          current_target[toffset + 4 * cont3csize + 12] = current_source[soffset + 64];
          current_target[toffset + 5 * cont3csize    ] = current_source[soffset + 65];
          current_target[toffset + 5 * cont3csize + 1] = current_source[soffset + 66];
          current_target[toffset + 5 * cont3csize + 2] = current_source[soffset + 67];
          current_target[toffset + 5 * cont3csize + 3] = current_source[soffset + 68];
          current_target[toffset + 5 * cont3csize + 4] = current_source[soffset + 69];
          current_target[toffset + 5 * cont3csize + 5] = current_source[soffset + 70];
          current_target[toffset + 5 * cont3csize + 6] = current_source[soffset + 71];
          current_target[toffset + 5 * cont3csize + 7] = current_source[soffset + 72];
          current_target[toffset + 5 * cont3csize + 8] = current_source[soffset + 73];
          current_target[toffset + 5 * cont3csize + 9] = current_source[soffset + 74];
          current_target[toffset + 5 * cont3csize + 10] = current_source[soffset + 75];
          current_target[toffset + 5 * cont3csize + 11] = current_source[soffset + 76];
          current_target[toffset + 5 * cont3csize + 12] = current_source[soffset + 77];
          current_target[toffset + 6 * cont3csize    ] = current_source[soffset + 78];
          current_target[toffset + 6 * cont3csize + 1] = current_source[soffset + 79];
          current_target[toffset + 6 * cont3csize + 2] = current_source[soffset + 80];
          current_target[toffset + 6 * cont3csize + 3] = current_source[soffset + 81];
          current_target[toffset + 6 * cont3csize + 4] = current_source[soffset + 82];
          current_target[toffset + 6 * cont3csize + 5] = current_source[soffset + 83];
          current_target[toffset + 6 * cont3csize + 6] = current_source[soffset + 84];
          current_target[toffset + 6 * cont3csize + 7] = current_source[soffset + 85];
          current_target[toffset + 6 * cont3csize + 8] = current_source[soffset + 86];
          current_target[toffset + 6 * cont3csize + 9] = current_source[soffset + 87];
          current_target[toffset + 6 * cont3csize + 10] = current_source[soffset + 88];
          current_target[toffset + 6 * cont3csize + 11] = current_source[soffset + 89];
          current_target[toffset + 6 * cont3csize + 12] = current_source[soffset + 90];
          current_target[toffset + 7 * cont3csize    ] = current_source[soffset + 91];
          current_target[toffset + 7 * cont3csize + 1] = current_source[soffset + 92];
          current_target[toffset + 7 * cont3csize + 2] = current_source[soffset + 93];
          current_target[toffset + 7 * cont3csize + 3] = current_source[soffset + 94];
          current_target[toffset + 7 * cont3csize + 4] = current_source[soffset + 95];
          current_target[toffset + 7 * cont3csize + 5] = current_source[soffset + 96];
          current_target[toffset + 7 * cont3csize + 6] = current_source[soffset + 97];
          current_target[toffset + 7 * cont3csize + 7] = current_source[soffset + 98];
          current_target[toffset + 7 * cont3csize + 8] = current_source[soffset + 99];
          current_target[toffset + 7 * cont3csize + 9] = current_source[soffset + 100];
          current_target[toffset + 7 * cont3csize + 10] = current_source[soffset + 101];
          current_target[toffset + 7 * cont3csize + 11] = current_source[soffset + 102];
          current_target[toffset + 7 * cont3csize + 12] = current_source[soffset + 103];
          current_target[toffset + 8 * cont3csize    ] = current_source[soffset + 104];
          current_target[toffset + 8 * cont3csize + 1] = current_source[soffset + 105];
          current_target[toffset + 8 * cont3csize + 2] = current_source[soffset + 106];
          current_target[toffset + 8 * cont3csize + 3] = current_source[soffset + 107];
          current_target[toffset + 8 * cont3csize + 4] = current_source[soffset + 108];
          current_target[toffset + 8 * cont3csize + 5] = current_source[soffset + 109];
          current_target[toffset + 8 * cont3csize + 6] = current_source[soffset + 110];
          current_target[toffset + 8 * cont3csize + 7] = current_source[soffset + 111];
          current_target[toffset + 8 * cont3csize + 8] = current_source[soffset + 112];
          current_target[toffset + 8 * cont3csize + 9] = current_source[soffset + 113];
          current_target[toffset + 8 * cont3csize + 10] = current_source[soffset + 114];
          current_target[toffset + 8 * cont3csize + 11] = current_source[soffset + 115];
          current_target[toffset + 8 * cont3csize + 12] = current_source[soffset + 116];
          current_target[toffset + 9 * cont3csize    ] = current_source[soffset + 117];
          current_target[toffset + 9 * cont3csize + 1] = current_source[soffset + 118];
          current_target[toffset + 9 * cont3csize + 2] = current_source[soffset + 119];
          current_target[toffset + 9 * cont3csize + 3] = current_source[soffset + 120];
          current_target[toffset + 9 * cont3csize + 4] = current_source[soffset + 121];
          current_target[toffset + 9 * cont3csize + 5] = current_source[soffset + 122];
          current_target[toffset + 9 * cont3csize + 6] = current_source[soffset + 123];
          current_target[toffset + 9 * cont3csize + 7] = current_source[soffset + 124];
          current_target[toffset + 9 * cont3csize + 8] = current_source[soffset + 125];
          current_target[toffset + 9 * cont3csize + 9] = current_source[soffset + 126];
          current_target[toffset + 9 * cont3csize + 10] = current_source[soffset + 127];
          current_target[toffset + 9 * cont3csize + 11] = current_source[soffset + 128];
          current_target[toffset + 9 * cont3csize + 12] = current_source[soffset + 129];
          current_target[toffset + 10 * cont3csize    ] = current_source[soffset + 130];
          current_target[toffset + 10 * cont3csize + 1] = current_source[soffset + 131];
          current_target[toffset + 10 * cont3csize + 2] = current_source[soffset + 132];
          current_target[toffset + 10 * cont3csize + 3] = current_source[soffset + 133];
          current_target[toffset + 10 * cont3csize + 4] = current_source[soffset + 134];
          current_target[toffset + 10 * cont3csize + 5] = current_source[soffset + 135];
          current_target[toffset + 10 * cont3csize + 6] = current_source[soffset + 136];
          current_target[toffset + 10 * cont3csize + 7] = current_source[soffset + 137];
          current_target[toffset + 10 * cont3csize + 8] = current_source[soffset + 138];
          current_target[toffset + 10 * cont3csize + 9] = current_source[soffset + 139];
          current_target[toffset + 10 * cont3csize + 10] = current_source[soffset + 140];
          current_target[toffset + 10 * cont3csize + 11] = current_source[soffset + 141];
          current_target[toffset + 10 * cont3csize + 12] = current_source[soffset + 142];
          current_target[toffset + 11 * cont3csize    ] = current_source[soffset + 143];
          current_target[toffset + 11 * cont3csize + 1] = current_source[soffset + 144];
          current_target[toffset + 11 * cont3csize + 2] = current_source[soffset + 145];
          current_target[toffset + 11 * cont3csize + 3] = current_source[soffset + 146];
          current_target[toffset + 11 * cont3csize + 4] = current_source[soffset + 147];
          current_target[toffset + 11 * cont3csize + 5] = current_source[soffset + 148];
          current_target[toffset + 11 * cont3csize + 6] = current_source[soffset + 149];
          current_target[toffset + 11 * cont3csize + 7] = current_source[soffset + 150];
          current_target[toffset + 11 * cont3csize + 8] = current_source[soffset + 151];
          current_target[toffset + 11 * cont3csize + 9] = current_source[soffset + 152];
          current_target[toffset + 11 * cont3csize + 10] = current_source[soffset + 153];
          current_target[toffset + 11 * cont3csize + 11] = current_source[soffset + 154];
          current_target[toffset + 11 * cont3csize + 12] = current_source[soffset + 155];
          current_target[toffset + 12 * cont3csize    ] = current_source[soffset + 156];
          current_target[toffset + 12 * cont3csize + 1] = current_source[soffset + 157];
          current_target[toffset + 12 * cont3csize + 2] = current_source[soffset + 158];
          current_target[toffset + 12 * cont3csize + 3] = current_source[soffset + 159];
          current_target[toffset + 12 * cont3csize + 4] = current_source[soffset + 160];
          current_target[toffset + 12 * cont3csize + 5] = current_source[soffset + 161];
          current_target[toffset + 12 * cont3csize + 6] = current_source[soffset + 162];
          current_target[toffset + 12 * cont3csize + 7] = current_source[soffset + 163];
          current_target[toffset + 12 * cont3csize + 8] = current_source[soffset + 164];
          current_target[toffset + 12 * cont3csize + 9] = current_source[soffset + 165];
          current_target[toffset + 12 * cont3csize + 10] = current_source[soffset + 166];
          current_target[toffset + 12 * cont3csize + 11] = current_source[soffset + 167];
          current_target[toffset + 12 * cont3csize + 12] = current_source[soffset + 168];
        }
      }

    }
  }

}



