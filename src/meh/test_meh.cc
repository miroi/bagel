//
// BAGEL - Parallel electron correlation program.
// Filename: test_meh.cc
// Copyright (C) 2013 Toru Shiozaki
//
// Author: Shane Parker <shane.parker@u.northwestern.edu>
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


#include <src/meh/meh.h>
#include <src/dimer/dimer.h>

double meh_energy(std::string inp) {

  auto ofs = std::make_shared<std::ofstream>(inp + ".testout", std::ios::trunc);
  std::streambuf* backup_stream = std::cout.rdbuf(ofs->rdbuf());

  // a bit ugly to hardwire an input file, but anyway...
  std::stringstream ss; ss << "../../test/" << inp << ".in";
  boost::property_tree::ptree idata;
  boost::property_tree::json_parser::read_json(ss.str(), idata);
  auto keys = idata.get_child("bagel");
  std::shared_ptr<Geometry> geom;

  std::shared_ptr<Reference> ref;
  std::shared_ptr<Dimer> dimer;

  for (auto iter = keys.begin(); iter != keys.end(); ++iter) {
    std::string method = iter->second.get<std::string>("title", "");
    std::transform(method.begin(), method.end(), method.begin(), ::tolower);

    if (method == "molecule") {
      geom = std::make_shared<Geometry>(iter->second);

    } else if (method == "df-hf") {
      auto scf = std::make_shared<SCF<1>>(iter->second, geom);
      scf->compute();
      ref = scf->conv_to_ref();
    } else if (method == "dimerize") { // dimerize forms the dimer object, does a scf calculation, and then localizes
      boost::property_tree::ptree dimdata = iter->second;

      std::string form = dimdata.get<std::string>("form", "displace");
      if (form == "d" || form == "disp" || form == "displace") {
        double scale = (dimdata.get<bool>("angstrom",false) ? ang2bohr__ : 1.0 ) ; 

        double dx = dimdata.get<double>("dx",0.0) * scale;
        double dy = dimdata.get<double>("dy",0.0) * scale;
        double dz = dimdata.get<double>("dz",0.0) * scale;
        std::array<double,3> disp = {{dx,dy,dz}};

        if (static_cast<bool>(ref)) {
          dimer = std::make_shared<Dimer>(ref,disp);
        }   
        else {
          throw std::runtime_error("dimerize needs a reference calculation (for now)");
        }   
      }   
      dimer->scf(iter->second);

      *geom = *dimer->sgeom();
      ref = dimer->sref();
    } else if (method == "meh") {
      std::shared_ptr<DimerCISpace> cispace = dimer->compute_cispace(iter->second);

      auto meh = std::make_shared<MultiExcitonHamiltonian>(iter->second, dimer, cispace);
      meh->compute();

      std::cout.rdbuf(backup_stream);
      return meh->energy(0);
    }
  }
  assert(false);
  return 0.0;
}

BOOST_AUTO_TEST_SUITE(TEST_MEH)

BOOST_AUTO_TEST_CASE(MEH_GROUND_STATE) {
    BOOST_CHECK(compare(meh_energy("benzene_sto3g_meh"), -459.319548355058));
}

BOOST_AUTO_TEST_SUITE_END()