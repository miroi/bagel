//
// BAGEL - Parallel electron correlation program.
// Filename: asd_rdm12.cc
// Copyright (C) 2014 Toru Shiozaki
//
// Author: Inkoo Kim <inkoo.kim@northwestern.edu>
// Maintainer: Shiozaki Group
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

#include <src/asd/asd_base.h>
#include <src/smith/prim_op.h>

using namespace std;
using namespace bagel;

tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> ASD_base::couple_blocks_RDM(const DimerSubspace_base& AB, const DimerSubspace_base& ApBp) const {

  Coupling term_type = coupling_type(AB, ApBp);

  const DimerSubspace_base* space1 = &AB;
  const DimerSubspace_base* space2 = &ApBp;

  bool flip = (static_cast<int>(term_type) < 0);
  if (flip) {
    term_type = Coupling(-1*static_cast<int>(term_type));
    std::swap(space1,space2);
  }
  
  tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> out;
  std::array<MonomerKey,4> keys {{space1->template monomerkey<0>(), space1->template monomerkey<1>(), space2->template monomerkey<0>(), space2->template monomerkey<1>()}};

  switch(term_type) {
    case Coupling::none :
      out = make_tuple(nullptr,nullptr); break;
    case Coupling::diagonal :
      out = compute_inter_2e_RDM(keys, /*subspace diagonal*/false); break;
    case Coupling::aET :
      out = compute_aET_RDM(keys); break;
    case Coupling::bET :
      out = compute_bET_RDM(keys); break;
    case Coupling::abFlip :
      out = compute_abFlip_RDM(keys); break;
    case Coupling::abET :
      out = compute_abET_RDM(keys); break;
    case Coupling::aaET :
      out = compute_aaET_RDM(keys); break;
    case Coupling::bbET :
      out = compute_bbET_RDM(keys); break;
    default :
      throw std::logic_error("Asking for a coupling type that has not been written.");
  }
  
  return out;
}

//***************************************************************************************************************

tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> 
ASD_base::compute_diagonal_block_RDM(const DimerSubspace_base& subspace) const {
// 1e is not considered (TODO maybe there is contribution?)
//***************************************************************************************************************

  array<MonomerKey,4> keys {{ subspace.monomerkey<0>(), subspace.monomerkey<1>(), subspace.monomerkey<0>(), subspace.monomerkey<1>() }};
  auto out = compute_inter_2e_RDM(keys, /*subspace diagonal*/true);

  return out;
}


//***************************************************************************************************************
tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> 
ASD_base::compute_inter_2e_RDM(const array<MonomerKey,4>& keys, const bool subdia) const {
//***************************************************************************************************************
  auto& B  = keys[1]; 
  auto& Bp = keys[3];

  const int nactA = dimer_->embedded_refs().first->nact();
  const int nactB = dimer_->embedded_refs().second->nact();
  const int nactT = nactA+nactB;
  auto out = make_shared<RDM<2>>(nactA+nactB);

  // alpha-alpha
  auto gamma_AA_alpha = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha, GammaSQ::AnnihilateAlpha});
  auto gamma_BB_alpha = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha, GammaSQ::AnnihilateAlpha});

  // beta-beta
  auto gamma_AA_beta = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta, GammaSQ::AnnihilateBeta});
  auto gamma_BB_beta = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta, GammaSQ::AnnihilateBeta});

  auto rdmAA = make_shared<Matrix>(gamma_AA_alpha % gamma_BB_alpha);
  auto rdmBB = make_shared<Matrix>(gamma_AA_beta  % gamma_BB_beta);

  auto rdmAB = make_shared<Matrix>(gamma_AA_alpha % gamma_BB_beta);
  auto rdmBA = make_shared<Matrix>(gamma_AA_beta  % gamma_BB_alpha);

  {// P(p,q',r',s) : p15
    auto rdmt = rdmAA->clone();
    SMITH::sort_indices<0,3,2,1, 0,1, -1,1>(rdmAA->data(), rdmt->data(), nactA, nactA, nactB, nactB); //aa
    SMITH::sort_indices<0,3,2,1, 1,1, -1,1>(rdmBB->data(), rdmt->data(), nactA, nactA, nactB, nactB); //bb
    if (!subdia) {
      SMITH::sort_indices<1,2,3,0, 1,1, -1,1>(rdmAA->data(), rdmt->data(), nactA, nactA, nactB, nactB); //aa of (N,M)
      SMITH::sort_indices<1,2,3,0, 1,1, -1,1>(rdmBB->data(), rdmt->data(), nactA, nactA, nactB, nactB); //bb of (N,M)
    }
    auto low = {    0, nactA, nactA,     0};
    auto up  = {nactA, nactT, nactT, nactA};
    auto outv = make_rwview(out->range().slice(low, up), out->storage());
    copy(rdmt->begin(), rdmt->end(), outv.begin());
  }

  {// d_pqr's' : p19
    auto rdmt = rdmAA->clone();
    SMITH::sort_indices<0,1,2,3, 0,1, 1,1>(rdmAA->data(), rdmt->data(), nactA, nactA, nactB, nactB); //aa
    SMITH::sort_indices<0,1,2,3, 1,1, 1,1>(rdmBB->data(), rdmt->data(), nactA, nactA, nactB, nactB); //bb
    SMITH::sort_indices<0,1,2,3, 1,1, 1,1>(rdmAB->data(), rdmt->data(), nactA, nactA, nactB, nactB); //aa bb
    SMITH::sort_indices<0,1,2,3, 1,1, 1,1>(rdmBA->data(), rdmt->data(), nactA, nactA, nactB, nactB); //bb aa
    if (!subdia) {
      SMITH::sort_indices<1,0,3,2, 1,1, 1,1>(rdmAA->data(), rdmt->data(), nactA, nactA, nactB, nactB); //aa of (N,M)
      SMITH::sort_indices<1,0,3,2, 1,1, 1,1>(rdmBB->data(), rdmt->data(), nactA, nactA, nactB, nactB); //bb of (N,M)
      SMITH::sort_indices<1,0,3,2, 1,1, 1,1>(rdmAB->data(), rdmt->data(), nactA, nactA, nactB, nactB); //bb of (N,M)
      SMITH::sort_indices<1,0,3,2, 1,1, 1,1>(rdmBA->data(), rdmt->data(), nactA, nactA, nactB, nactB); //bb of (N,M)
    }
    auto low = {    0,     0, nactA, nactA};
    auto up  = {nactA, nactA, nactT, nactT};
    auto outv = make_rwview(out->range().slice(low, up), out->storage());
    copy(rdmt->begin(), rdmt->end(), outv.begin());
  }

  return make_tuple(nullptr,out);
}




//***************************************************************************************************************
tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> 
ASD_base::compute_aET_RDM(const array<MonomerKey,4>& keys) const {
//***************************************************************************************************************

  auto& Ap = keys[2];

  auto& B  = keys[1];
  auto& Bp = keys[3];

  const int nactA = dimer_->embedded_refs().first->nact();
  const int nactB = dimer_->embedded_refs().second->nact();
  const int nactT = nactA+nactB;
  auto out1 = make_shared<RDM<1>>(nactA+nactB);
  auto out2 = make_shared<RDM<2>>(nactA+nactB);

  const int neleA = Ap.nelea() + Ap.neleb();


  //1RDM
  {
    auto gamma_A = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha});
    auto gamma_B = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::AnnihilateAlpha});
    
    auto rdm = make_shared<Matrix>(gamma_A % gamma_B);
    auto rdmt = rdm->clone();

    // P(p,q') : p10
    int fac = {neleA%2 == 0 ? 1 : -1};
    SMITH::sort_indices<0,1, 0,1, 1,1>(rdm->data(), rdmt->data(), nactA, nactB);
    rdmt->scale(fac);
 
    auto low = {    0, nactA};
    auto up  = {nactA, nactT};
    auto outv = make_rwview(out1->range().slice(low, up), out1->storage());
    copy(rdmt->begin(), rdmt->end(), outv.begin());
  }

  //2RDM
  {
    auto gamma_A  = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha});
    auto gamma_B1 = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha, GammaSQ::AnnihilateAlpha, GammaSQ::AnnihilateAlpha});
    auto gamma_B2 = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta, GammaSQ::AnnihilateAlpha, GammaSQ::AnnihilateBeta});

    auto rdm1 = make_shared<Matrix>(gamma_A % gamma_B1);
    auto rdm2 = make_shared<Matrix>(gamma_A % gamma_B2);
    auto rdmt = rdm1->clone();

    // P(p,q',r',s') : p15
    int fac = {neleA%2 == 0 ? 1 : -1};
    SMITH::sort_indices<0,3,1,2, 0,1,  1,1>(rdm1->data(), rdmt->data(), nactA, nactB, nactB, nactB);
    SMITH::sort_indices<0,2,1,3, 1,1, -1,1>(rdm2->data(), rdmt->data(), nactA, nactB, nactB, nactB);
    rdmt->scale(fac);

    auto low = {    0, nactA, nactA, nactA};
    auto up  = {nactA, nactT, nactT, nactT};
    auto outv = make_rwview(out2->range().slice(low, up), out2->storage());
    copy(rdmt->begin(), rdmt->end(), outv.begin());
  }
  {
    auto gamma_A1 = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha, GammaSQ::CreateAlpha, GammaSQ::AnnihilateAlpha});
    auto gamma_A2 = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha, GammaSQ::CreateBeta, GammaSQ::AnnihilateBeta});
    auto gamma_B  = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::AnnihilateAlpha});

    auto rdm1 = make_shared<Matrix>(gamma_A1 % gamma_B);
    auto rdm2 = make_shared<Matrix>(gamma_A2 % gamma_B);
    auto rdmt = rdm1->clone();

    //P(p,q',r,s) : p15
    int fac = {neleA%2 == 0 ? 1 : -1};
    SMITH::sort_indices<0,3,1,2, 0,1,  1,1>(rdm1->data(), rdmt->data(), nactA, nactA, nactA, nactB);
    SMITH::sort_indices<0,3,1,2, 1,1,  1,1>(rdm2->data(), rdmt->data(), nactA, nactA, nactA, nactB);
    rdmt->scale(fac);

    auto low = {    0, nactA,     0,     0};
    auto up  = {nactA, nactT, nactA, nactA};
    auto outv = make_rwview(out2->range().slice(low, up), out2->storage());
    copy(rdmt->begin(), rdmt->end(), outv.begin());
  }
  
  return make_tuple(out1,out2);
}





//***************************************************************************************************************
tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> 
ASD_base::compute_bET_RDM(const array<MonomerKey,4>& keys) const {
//***************************************************************************************************************
  auto& Ap = keys[2];

  auto& B  = keys[1];
  auto& Bp = keys[3];

  const int nactA = dimer_->embedded_refs().first->nact();
  const int nactB = dimer_->embedded_refs().second->nact();
  const int nactT = nactA+nactB;
  auto out1 = make_shared<RDM<1>>(nactA+nactB);
  auto out2 = make_shared<RDM<2>>(nactA+nactB);

  const int neleA = Ap.nelea() + Ap.neleb();
  //RDM1
  {
    auto gamma_A = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta});
    auto gamma_B = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::AnnihilateBeta});
    
    auto rdm = make_shared<Matrix>(gamma_A % gamma_B);
    auto rdmt = rdm->clone();
    
    // P(p,q') : p10
    int fac = {neleA%2 == 0 ? 1 : -1};
    SMITH::sort_indices<0,1, 0,1, 1,1>(rdm->data(), rdmt->data(), nactA, nactB);
    rdmt->scale(fac);
    
    auto low = {    0, nactA};
    auto up  = {nactA, nactT};
    auto outv = make_rwview(out1->range().slice(low, up), out1->storage());
    copy(rdmt->begin(), rdmt->end(), outv.begin());
  }

  //RDM2
  {
    auto gamma_A  = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta});
    auto gamma_B1 = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha, GammaSQ::AnnihilateBeta, GammaSQ::AnnihilateAlpha});
    auto gamma_B2 = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta, GammaSQ::AnnihilateBeta, GammaSQ::AnnihilateBeta});

    auto rdm1 = make_shared<Matrix>(gamma_A % gamma_B1);
    auto rdm2 = make_shared<Matrix>(gamma_A % gamma_B2);
    auto rdmt = rdm1->clone();

    // P(p,q',r',s') : p15
    int fac = {neleA%2 == 0 ? 1 : -1};
    SMITH::sort_indices<0,2,1,3, 0,1, -1,1>(rdm1->data(), rdmt->data(), nactA, nactB, nactB, nactB);
    SMITH::sort_indices<0,3,1,2, 1,1,  1,1>(rdm2->data(), rdmt->data(), nactA, nactB, nactB, nactB);
    rdmt->scale(fac);

    auto low = {    0, nactA, nactA, nactA};
    auto up  = {nactA, nactT, nactT, nactT};
    auto outv = make_rwview(out2->range().slice(low, up), out2->storage());
    copy(rdmt->begin(), rdmt->end(), outv.begin());
  }
  {
    auto gamma_A1 = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta, GammaSQ::CreateAlpha, GammaSQ::AnnihilateAlpha});
    auto gamma_A2 = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta, GammaSQ::CreateBeta, GammaSQ::AnnihilateBeta});
    auto gamma_B  = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::AnnihilateBeta});

    auto rdm1 = make_shared<Matrix>(gamma_A1 % gamma_B);
    auto rdm2 = make_shared<Matrix>(gamma_A2 % gamma_B);
    auto rdmt = rdm1->clone();

    // P(p,q',r,s) : p15
    int fac = {neleA%2 == 0 ? 1 : -1};
    SMITH::sort_indices<0,3,1,2, 0,1,  1,1>(rdm1->data(), rdmt->data(), nactA, nactA, nactA, nactB);
    SMITH::sort_indices<0,3,1,2, 1,1,  1,1>(rdm2->data(), rdmt->data(), nactA, nactA, nactA, nactB);
    rdmt->scale(fac);

    auto low = {    0, nactA,     0,     0};
    auto up  = {nactA, nactT, nactA, nactA};
    auto outv = make_rwview(out2->range().slice(low, up), out2->storage());
    copy(rdmt->begin(), rdmt->end(), outv.begin());
  }

  return make_tuple(out1,out2);
}



//***************************************************************************************************************
tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> 
ASD_base::compute_abFlip_RDM(const array<MonomerKey,4>& keys) const {
// if ab-flip, account ba-flip arising from (N,M)
// if(M,N) is ba-flip then (N,M) is ab-flip and this will include ba-flip of (M,N) too.
//***************************************************************************************************************
  auto& B = keys[1];
  auto& Bp = keys[3];

  assert(gammatensor_[0]->exist(keys[0], keys[2], {GammaSQ::CreateBeta, GammaSQ::AnnihilateAlpha}));

  const int nactA = dimer_->embedded_refs().first->nact();
  const int nactB = dimer_->embedded_refs().second->nact();
  const int nactT = nactA+nactB;

  auto out = make_shared<RDM<2>>(nactA+nactB);

  auto gamma_A = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta, GammaSQ::AnnihilateAlpha});
  auto gamma_B = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha, GammaSQ::AnnihilateBeta});

  auto rdm = make_shared<Matrix>(gamma_A % gamma_B);
  auto rdmt = rdm->clone();

  // P(p,q',r',s) : p4  ab-flip of (M,N)
  SMITH::sort_indices<0,3,2,1, 0,1, -1,1>(rdm->data(), rdmt->data(), nactA, nactA, nactB, nactB); //ab-flip
  SMITH::sort_indices<1,2,3,0, 1,1, -1,1>(rdm->data(), rdmt->data(), nactA, nactA, nactB, nactB); //ba-flip of (N,M) p15B

  auto low = {    0, nactA, nactA,     0};
  auto up  = {nactA, nactT, nactT, nactA};
  auto outv = make_rwview(out->range().slice(low, up), out->storage());
  assert(rdmt->size() == outv.size());
  copy(rdmt->begin(), rdmt->end(), outv.begin());

  return make_tuple(nullptr,out);
}




//***************************************************************************************************************
tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> 
ASD_base::compute_abET_RDM(const array<MonomerKey,4>& keys) const {
// for (M,N)
// if inverse ab-ET / compute (N,M)
//***************************************************************************************************************
  auto& B = keys[1]; auto& Bp = keys[3];

  assert(gammatensor_[0]->exist(keys[0], keys[2], {GammaSQ::CreateAlpha, GammaSQ::CreateBeta}));

  auto gamma_A = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha, GammaSQ::CreateBeta});
  auto gamma_B = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::AnnihilateAlpha, GammaSQ::AnnihilateBeta});

  auto rdm  = make_shared<Matrix>(gamma_A % gamma_B);
  auto rdmt = rdm->clone();

  const int nactA = dimer_->embedded_refs().first->nact();
  const int nactB = dimer_->embedded_refs().second->nact();
  const int nactT = nactA+nactB;

  // P(p,q',r,s') : p14B
  SMITH::sort_indices<0,2,1,3, 0,1, -1,1>(rdm->data(), rdmt->data(), nactA, nactA, nactB, nactB);
  SMITH::sort_indices<1,3,0,2, 1,1, -1,1>(rdm->data(), rdmt->data(), nactA, nactA, nactB, nactB);

  auto out = make_shared<RDM<2>>(nactA+nactB);
  auto low = {    0, nactA,     0, nactA};
  auto up  = {nactA, nactT, nactA, nactT};
  auto outv = make_rwview(out->range().slice(low, up), out->storage());
  assert(rdmt->size() == outv.size());
  copy(rdmt->begin(), rdmt->end(), outv.begin());

  return make_tuple(nullptr,out);
}



//***************************************************************************************************************
tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> 
ASD_base::compute_aaET_RDM(const array<MonomerKey,4>& keys) const {
//off-diagonal subspaces only!
// if(M,N) is inverse-aa-ET, swap M,N as (N,M) will be aa-ET and contribute to 2RDM
//***************************************************************************************************************
  auto& B = keys[1]; auto& Bp = keys[3];

  assert(gammatensor_[0]->exist(keys[0], keys[2], {GammaSQ::CreateAlpha, GammaSQ::CreateAlpha}));

  auto gamma_A = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateAlpha, GammaSQ::CreateAlpha});
  auto gamma_B = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::AnnihilateAlpha, GammaSQ::AnnihilateAlpha});

  auto rdm  = make_shared<Matrix>(gamma_A % gamma_B);
  auto rdmt = rdm->clone();

  const int nactA = dimer_->embedded_refs().first->nact();
  const int nactB = dimer_->embedded_refs().second->nact();
  const int nactT = nactA+nactB;

  // P(p,q',r,s') : p1B
  SMITH::sort_indices<0,3,1,2, 0,1, 1,1>(rdm->data(), rdmt->data(), nactA, nactA, nactB, nactB);

  auto out = make_shared<RDM<2>>(nactA+nactB);
  auto low = {    0, nactA,     0, nactA};
  auto up  = {nactA, nactT, nactA, nactT};
  auto outv = make_rwview(out->range().slice(low, up), out->storage());
  assert(rdmt->size() == outv.size());
  copy(rdmt->begin(), rdmt->end(), outv.begin());

  return make_tuple(nullptr,out);
}



//***************************************************************************************************************
tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> 
ASD_base::compute_bbET_RDM(const array<MonomerKey,4>& keys) const {
// cf. aaET
//***************************************************************************************************************
  auto& B = keys[1]; auto& Bp = keys[3];

  assert(gammatensor_[0]->exist(keys[0], keys[2], {GammaSQ::CreateBeta, GammaSQ::CreateBeta}));

  auto gamma_A = worktensor_->get_block_as_matview(B, Bp, {GammaSQ::CreateBeta, GammaSQ::CreateBeta});
  auto gamma_B = gammatensor_[1]->get_block_as_matview(B, Bp, {GammaSQ::AnnihilateBeta, GammaSQ::AnnihilateBeta});

  auto rdm  = make_shared<Matrix>(gamma_A % gamma_B);
  auto rdmt = rdm->clone();

  const int nactA = dimer_->embedded_refs().first->nact();
  const int nactB = dimer_->embedded_refs().second->nact();
  const int nactT = nactA+nactB;

  // P(p,q',r,s') : p14B
  SMITH::sort_indices<0,3,1,2, 0,1, 1,1>(rdm->data(), rdmt->data(), nactA, nactA, nactB, nactB);

  auto out = make_shared<RDM<2>>(nactA+nactB);
  auto low = {    0, nactA,     0, nactA};
  auto up  = {nactA, nactT, nactA, nactT};
  auto outv = make_rwview(out->range().slice(low, up), out->storage());
  assert(rdmt->size() == outv.size());
  copy(rdmt->begin(), rdmt->end(), outv.begin());

  return make_tuple(nullptr,out);
}


//***************************************************************************************************************
void
ASD_base::symmetrize_RDM() const {
//***************************************************************************************************************

  cout << "!@# Unsymmetrized 1RDM" << endl;
  onerdm_->print(1.0e-6);

  const int nactA = dimer_->active_refs().first->nact();
  const int nactB = dimer_->active_refs().second->nact();
  const int nactT = nactA + nactB;  

  //Symmetrize: D_AB (calculated) D_BA (uncalc.& symmetrized here)
  auto matBA = std::make_shared<Matrix>(nactB,nactA); //D_BA empty
  {
    auto low = {0, nactA};
    auto up  = {nactA, nactT};
    auto view = btas::make_view(onerdm_->range().slice(low,up), onerdm_->storage()); //D_AB sector of D (read ptr)
    auto matAB = std::make_shared<Matrix>(nactA,nactB); //D_AB empty
    std::copy(view.begin(), view.end(), matAB->begin()); //D_AB filled
    SMITH::sort_indices<1,0, 0,1, 1,1>(matAB->data(), matBA->data(), nactA, nactB); // transpose and fill D_BA
  }
  {
    auto low = {nactA, 0};
    auto up  = {nactT, nactA};
    auto outv = btas::make_rwview(onerdm_->range().slice(low,up), onerdm_->storage()); //D_BA sector of D (read & write ptr)
    std::copy(matBA->begin(), matBA->end(), outv.begin()); //copy D_BA -> D_BA sector of D
  }

  cout << "!@# Symmetrized 1RDM" << endl;
  onerdm_->print(1.0e-6);

  //Symmetrize: d(ABAA) note p18B, 19B
  {
    auto low = {0,nactA,0,0};
    auto up  = {nactA,nactT,nactA,nactA};
    auto view = btas::make_view(twordm_->range().slice(low,up), twordm_->storage()); //d_ABAA sector of d
    auto inmat = make_shared<Matrix>(nactA*nactB,nactA*nactA); //empty d_ABAA
    copy(view.begin(), view.end(), inmat->begin()); //d_ABAA filled
    { //d(AAAB)
      auto outmat = make_shared<Matrix>(nactA*nactA,nactA*nactB); //empty d_AAAB
      SMITH::sort_indices<2,3,0,1, 0,1, 1,1>(inmat->data(), outmat->data(), nactA, nactB, nactA, nactA); //reorder and fill d_AAAB
      auto low = {0,0,0,nactA};
      auto up  = {nactA,nactA,nactA,nactT};
      auto outv = btas::make_rwview(twordm_->range().slice(low,up), twordm_->storage()); //d_AAAB sector of d
      copy(outmat->begin(), outmat->end(), outv.begin()); //copy d_AAAB into d_AAAB sector of d
    } 
    { //d(BAAA)
      auto outmat = make_shared<Matrix>(nactB*nactA,nactA*nactA); //empty d_BAAA
      SMITH::sort_indices<1,0,3,2, 0,1, 1,1>(inmat->data(), outmat->data(), nactA, nactB, nactA, nactA); //reorder and fill d_BAAA
      auto low = {nactA,0,0,0};
      auto up  = {nactT,nactA,nactA,nactA};
      auto outv = btas::make_rwview(twordm_->range().slice(low,up), twordm_->storage()); //d_BAAA sector of d
      copy(outmat->begin(), outmat->end(), outv.begin()); //copy d_BAAA into d_BAAA sector of d
    } 
    { //d(AABA)
      auto outmat = make_shared<Matrix>(nactA*nactA,nactB*nactA); //empty d_AABA
      SMITH::sort_indices<3,2,1,0, 0,1, 1,1>(inmat->data(), outmat->data(), nactA, nactB, nactA, nactA); //reorder and fill d_AABA
      auto low = {0,0,nactA,0};
      auto up  = {nactA,nactA,nactT,nactA};
      auto outv = btas::make_rwview(twordm_->range().slice(low,up), twordm_->storage()); //d_AABA sector of d
      copy(outmat->begin(), outmat->end(), outv.begin()); //copy d_AABA into d_AABA sector of d
    } 
  }
 
  //Symmetrize: d(ABBB) note p18B, 19B
  {
    auto low = {0,nactA,nactA,nactA};
    auto up  = {nactA,nactT,nactT,nactT};
    auto view = btas::make_view(twordm_->range().slice(low,up), twordm_->storage()); //d_ABBB sector of d
    auto inmat = make_shared<Matrix>(nactA*nactB,nactB*nactB); //empty d_ABBB
    copy(view.begin(), view.end(), inmat->begin()); //d_ABBB filled
    { //d(BBAB)
      auto outmat = make_shared<Matrix>(nactB*nactB,nactA*nactB); //empty d_BBAB
      SMITH::sort_indices<2,3,0,1, 0,1, 1,1>(inmat->data(), outmat->data(), nactA, nactB, nactB, nactB); //reorder and fill d_BBAB
      auto low = {nactA,nactA,0,nactA};
      auto up  = {nactT,nactT,nactA,nactT};
      auto outv = btas::make_rwview(twordm_->range().slice(low,up), twordm_->storage()); //d_BBAB sector of d
      copy(outmat->begin(), outmat->end(), outv.begin()); //copy d_BBAB into d_BBAB sector of d
    } 
    { //d(BABB)
      auto outmat = make_shared<Matrix>(nactB*nactA,nactB*nactB); //empty d_BABB
      SMITH::sort_indices<1,0,3,2, 0,1, 1,1>(inmat->data(), outmat->data(), nactA, nactB, nactB, nactB); //reorder and fill d_BABB
      auto low = {nactA,0,nactA,nactA};
      auto up  = {nactT,nactA,nactT,nactT};
      auto outv = btas::make_rwview(twordm_->range().slice(low,up), twordm_->storage()); //d_BABB sector of d
      copy(outmat->begin(), outmat->end(), outv.begin()); //copy d_BABB into d_BABB sector of d
    } 
    { //d(BBBA)
      auto outmat = make_shared<Matrix>(nactB*nactB,nactB*nactA); //empty d_BBBA
      SMITH::sort_indices<3,2,1,0, 0,1, 1,1>(inmat->data(), outmat->data(), nactA, nactB, nactB, nactB); //reorder and fill d_BBBA
      auto low = {nactA,nactA,nactA,0};
      auto up  = {nactT,nactT,nactT,nactA};
      auto outv = btas::make_rwview(twordm_->range().slice(low,up), twordm_->storage()); //d_BBBA sector of d
      copy(outmat->begin(), outmat->end(), outv.begin()); //copy d_BBBA into d_BBBA sector of d
    } 
  }


  //Symmetrize: d(ABBA) note p19
  {
    auto low = {0,nactA,nactA,0};
    auto up  = {nactA,nactT,nactT,nactA};
    auto view = btas::make_view(twordm_->range().slice(low,up), twordm_->storage()); //d_ABBA sector of d
    auto inmat = make_shared<Matrix>(nactA*nactB,nactB*nactA); //empty d_ABBA
    copy(view.begin(), view.end(), inmat->begin()); //d_ABBA filled
    { //d(BAAB)
      auto outmat = make_shared<Matrix>(nactB*nactA,nactA*nactB); //empty d_BAAB
      SMITH::sort_indices<2,3,0,1, 0,1, 1,1>(inmat->data(), outmat->data(), nactA, nactB, nactB, nactA); //reorder and fill d_BAAB
      auto low = {nactA,0,0,nactA};
      auto up  = {nactT,nactA,nactA,nactT};
      auto outv = btas::make_rwview(twordm_->range().slice(low,up), twordm_->storage()); //d_BAAB sector of d
      copy(outmat->begin(), outmat->end(), outv.begin()); //copy d_BAAB into d_BAAB sector of d
    } 
  }

  //Symmetrize: d(AABB) note 19
  { //d(AABB)
    auto low = {0,0,nactA,nactA};
    auto up  = {nactA,nactA,nactT,nactT};
    auto view = btas::make_view(twordm_->range().slice(low,up), twordm_->storage()); //d_AABB sector of d
    auto inmat = make_shared<Matrix>(nactA*nactA*nactB*nactB,1); //empty d_AABB
    copy(view.begin(), view.end(), inmat->begin()); //d_AABB filled
    { //d(BBAA)
      auto outmat = make_shared<Matrix>(nactB*nactB*nactA*nactA,1); //empty d_BBAA
      SMITH::sort_indices<2,3,0,1, 0,1, 1,1>(inmat->data(), outmat->data(), nactA, nactA, nactB, nactB); //reorder and fill d_BBAA
      auto low = {nactA,nactA,0,0};
      auto up  = {nactT,nactT,nactA,nactA};
      auto outv = btas::make_rwview(twordm_->range().slice(low,up), twordm_->storage()); //d_BBAA sector of d
      copy(outmat->begin(), outmat->end(), outv.begin()); //copy d_BBAA into d_BBAA sector of d
    } 
  }

  //Symmetrize: d(ABAB) note p19
  {
    auto low = {0,nactA,0,nactA};
    auto up  = {nactA,nactT,nactA,nactT};
    auto view = btas::make_view(twordm_->range().slice(low,up), twordm_->storage()); //d_ABAB sector of d
    auto inmat = make_shared<Matrix>(nactA*nactB,nactA*nactB); //empty d_ABAB
    copy(view.begin(), view.end(), inmat->begin()); //d_ABAB filled
    { //d(BABA)
      auto outmat = make_shared<Matrix>(nactB*nactA,nactB*nactA); //empty d_BABA
      SMITH::sort_indices<1,0,3,2, 0,1, 1,1>(inmat->data(), outmat->data(), nactA, nactB, nactA, nactB); //reorder and fill d_BABA
      auto low = {nactA,0,nactA,0};
      auto up  = {nactT,nactA,nactT,nactA};
      auto outv = btas::make_rwview(twordm_->range().slice(low,up), twordm_->storage()); //d_BABA sector of d
      copy(outmat->begin(), outmat->end(), outv.begin()); //copy d_BBBA into d_BABA sector of d
    } 
  }

}

