//
// BAGEL - Parallel electron correlation program.
// Filename: denom.h
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

#ifndef __SRC_SMITH_DENOM_H
#define __SRC_SMITH_DENOM_H

#include <src/wfn/rdm.h>
#include <src/util/math/matrix.h>

namespace bagel {
namespace SMITH {

class Denom {
  protected:
    std::shared_ptr<const Matrix> fock_;
    const double thresh_;

    std::shared_ptr<Matrix> shalf_x_;
    std::shared_ptr<Matrix> shalf_h_;
    std::shared_ptr<Matrix> shalf_xx_;
    std::shared_ptr<Matrix> shalf_hh_;
    std::shared_ptr<Matrix> shalf_xh_;
    std::shared_ptr<Matrix> shalf_xhh_;
    std::shared_ptr<Matrix> shalf_xxh_;

    std::shared_ptr<Matrix> work_x_;
    std::shared_ptr<Matrix> work_h_;
    std::shared_ptr<Matrix> work_xx_;
    std::shared_ptr<Matrix> work_hh_;
    std::shared_ptr<Matrix> work_xh_;
    std::shared_ptr<Matrix> work_xhh_;
    std::shared_ptr<Matrix> work_xxh_;

    VectorB denom_x_;
    VectorB denom_h_;
    VectorB denom_xx_;
    VectorB denom_hh_;
    VectorB denom_xh_;
    VectorB denom_xhh_;
    VectorB denom_xxh_;

    // init functions
    void init_x_(const int, const int, std::shared_ptr<const RDM<1>>, std::shared_ptr<const RDM<2>>, std::shared_ptr<const RDM<3>>, std::shared_ptr<const RDM<4>>);
    void init_h_(const int, const int, std::shared_ptr<const RDM<1>>, std::shared_ptr<const RDM<2>>, std::shared_ptr<const RDM<3>>, std::shared_ptr<const RDM<4>>);
    void init_xx_(const int, const int, std::shared_ptr<const RDM<1>>, std::shared_ptr<const RDM<2>>, std::shared_ptr<const RDM<3>>, std::shared_ptr<const RDM<4>>);
    void init_hh_(const int, const int, std::shared_ptr<const RDM<1>>, std::shared_ptr<const RDM<2>>, std::shared_ptr<const RDM<3>>, std::shared_ptr<const RDM<4>>);
    void init_xh_(const int, const int, std::shared_ptr<const RDM<1>>, std::shared_ptr<const RDM<2>>, std::shared_ptr<const RDM<3>>, std::shared_ptr<const RDM<4>>);
    void init_xhh_(const int, const int, std::shared_ptr<const RDM<1>>, std::shared_ptr<const RDM<2>>, std::shared_ptr<const RDM<3>>, std::shared_ptr<const RDM<4>>);
    void init_xxh_(const int, const int, std::shared_ptr<const RDM<1>>, std::shared_ptr<const RDM<2>>, std::shared_ptr<const RDM<3>>, std::shared_ptr<const RDM<4>>);

  public:
    Denom(std::shared_ptr<const Matrix> fock, const int nstates, const double th);

    // add RDMs
    void append(const int jst, const int ist, std::shared_ptr<const RDM<1>>, std::shared_ptr<const RDM<2>>, std::shared_ptr<const RDM<3>>, std::shared_ptr<const RDM<4>>);
    // diagonalize and set to shalf and denom
    void compute();

    std::shared_ptr<const Matrix> shalf_x() const { return shalf_x_; }
    std::shared_ptr<const Matrix> shalf_h() const { return shalf_h_; }
    std::shared_ptr<const Matrix> shalf_xx() const { return shalf_xx_; }
    std::shared_ptr<const Matrix> shalf_hh() const { return shalf_hh_; }
    std::shared_ptr<const Matrix> shalf_xh() const { return shalf_xh_; }
    std::shared_ptr<const Matrix> shalf_xhh() const { return shalf_xhh_; }
    std::shared_ptr<const Matrix> shalf_xxh() const { return shalf_xxh_; }

    const double& denom_x(const size_t i) const { return denom_x_(i); }
    const double& denom_h(const size_t i) const { return denom_h_(i); }
    const double& denom_xx(const size_t i) const { return denom_xx_(i); }
    const double& denom_hh(const size_t i) const { return denom_hh_(i); }
    const double& denom_xh(const size_t i) const { return denom_xh_(i); }
    const double& denom_xhh(const size_t i) const { return denom_xhh_(i); }
    const double& denom_xxh(const size_t i) const { return denom_xxh_(i); }

};

}
}

#endif
