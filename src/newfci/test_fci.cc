//
// BAGEL - Parallel electron correlation program.
// Filename: test_fci.cc
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


#include <src/newfci/harrison.h>
#include <src/newfci/knowles.h>

std::vector<double> newfci_energy(std::string inp) {

  std::shared_ptr<std::ofstream> ofs(new std::ofstream(inp + ".testout", std::ios::trunc));
  std::streambuf* backup_stream = std::cout.rdbuf(ofs->rdbuf());

  // a bit ugly to hardwire an input file, but anyway...
  std::shared_ptr<InputData> idata(new InputData("../../test/" + inp + ".in"));
  std::shared_ptr<Geometry> geom(new Geometry(idata->get_input("molecule")));
  std::list<std::pair<std::string, std::multimap<std::string, std::string> > > keys = idata->data();

  std::shared_ptr<Reference> ref;

  for (auto iter = keys.begin(); iter != keys.end(); ++iter) {
    if (iter->first == "df-hf") {
      std::shared_ptr<SCF<1> > scf(new SCF<1>(iter->second, geom));
      scf->compute();
      ref = scf->conv_to_ref();
    } else if (iter->first == "df-rohf"){
      std::shared_ptr<ROHF> scf(new ROHF(iter->second, geom));
      scf->compute();
      ref = scf->conv_to_ref();
    } else if (iter->first == "newfci") {
      std::shared_ptr<NewFCI> fci;
      std::string algorithm = read_input<std::string>(iter->second, "algorithm", "");
      if (algorithm == "harrison") fci = std::shared_ptr<NewFCI>(new HarrisonZarrabian(iter->second, ref));
      else if (algorithm == "knowles") fci = std::shared_ptr<NewFCI>(new KnowlesHandy(iter->second,ref));
      else assert(false);
     
      fci->compute();
      std::cout.rdbuf(backup_stream);
      return fci->energy();
    }
  }
  assert(false);
  return std::vector<double>();
}

std::vector<double> reference_newfci_energy() {
  std::vector<double> out(2);
  out[0] = -98.56280393;
  out[1] = -98.36567235;
  return out;
}
std::vector<double> reference_newfci_energy2() {
  std::vector<double> out(2);
  out[0] = -3.30315793;
  out[1] = -2.78407879;
  return out;
}


BOOST_AUTO_TEST_SUITE(TEST_NEWFCI)

BOOST_AUTO_TEST_CASE(NEWFCI_2STATE) {
    BOOST_CHECK(compare(newfci_energy("hf_sto3g_newfci_hz"), reference_newfci_energy()));
    BOOST_CHECK(compare(newfci_energy("hf_sto3g_newfci_kh"), reference_newfci_energy()));
    BOOST_CHECK(compare(newfci_energy("hhe_svp_newfci_hz_trip"), reference_newfci_energy2()));
    BOOST_CHECK(compare(newfci_energy("hhe_svp_newfci_kh_trip"), reference_newfci_energy2()));
}

BOOST_AUTO_TEST_SUITE_END()
