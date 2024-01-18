#include "call_libraries.h"
// jet nchtrk bin
const int nch_bin = 9;
//double nch_binedge[nch_bin+1] = {0., 25., 35., 45., 55., 65., 75., 85., 97., 110. 200.};
//double nch_binedge[nch_bin+1] = {0., 10., 20., 30., 40., 50., 60., 70., 80., 90., 100., 200.};
double nch_binedge[nch_bin+1] = {0., 10., 20., 30., 40., 50., 60., 72., 85., 200.};
//double nch_binedge[nch_bin+1] = {0., 20., 30., 40., 50., 60., 70., 80., 92., 200.};
TH1D* hnch_bin_hist = new TH1D("hnch_bin_hist", "", nch_bin, nch_binedge);

// chtrk trigger pt bin
const int trgpt_bin = 3;
double trgpt_binedge[nch_bin+1] = {0., 0.5, 1., 2., 3.1};
TH1D* htrgpt_bin_hist = new TH1D("htrgpt_bin_hist", "", trgpt_bin, trgpt_binedge);

// event histo
TH1D* hntrkTotal = new TH1D("hntrkTotal", "", 100, 0, 1000);
TH1D* hpthat = new TH1D("hpthat", "", 180, 400, 4000);
TH1D* hpthatw = new TH1D("hpthatw", "", 1000, 0, 1);
TH1D* hsubprocessid = new TH1D("hsubprocessid", "", 30, 100, 130);
TH1D* hnjets = new TH1D("hnjets", "", 20, 0, 20);
TH1D* hnjets_afterCut = new TH1D("hnjets_afterCut", "", 20, 0, 20);

// jet histo
TH1D* hjet_pt = new TH1D("hjet_pt", "", 180, 400, 4000);
TH1D* hjet_eta = new TH1D("hjet_eta", "", 40, -2., 2.);
TH1D* hjet_phi = new TH1D("hjet_phi", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hJet_ntrk = new TH1D("hJet_ntrk", "", 300, 0, 300);
TH1D* hJet_nchtrk = new TH1D("hJet_nchtrk", "", 150, 0, 150);
TH2D* hJet_nchtrk_pT = new TH2D("hJet_nchtrk_pT", "", 150, 0, 150, 150, 500, 4100);
TH1D* hJet_nchtrk_[nch_bin];

// track histo
// all tracks
TH1D* halltrk_pt = new TH1D("halltrk_pt", "", 200, 0., 2000.);
TH1D* halltrk_eta = new TH1D("halltrk_eta", "", 48, -2.4, 2.4);
TH1D* halltrk_phi = new TH1D("halltrk_phi", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* halltrk_pt_jetaxis = new TH1D("halltrk_pt_jetaxis", "", 500, 0., 50.);
TH1D* halltrk_eta_jetaxis = new TH1D("halltrk_eta_jetaxis", "", 150, 0., 15.);
TH1D* halltrk_phi_jetaxis = new TH1D("halltrk_phi_jetaxis", "", 64, -TMath::Pi(), TMath::Pi());
//charge tracks
TH1D* hchtrk_pt = new TH1D("hchtrk_pt", "", 200, 0., 2000.);
TH1D* hchtrk_eta = new TH1D("hchtrk_eta", "", 48, -2.4, 2.4);
TH1D* hchtrk_phi = new TH1D("hchtrk_phi", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hchtrk_pt_jetaxis = new TH1D("hchtrk_pt_jetaxis", "", 500, 0., 50.);
TH1D* hchtrk_eta_jetaxis = new TH1D("hchtrk_eta_jetaxis", "", 150, 0., 15.);
TH1D* hchtrk_phi_jetaxis = new TH1D("hchtrk_phi_jetaxis", "", 64, -TMath::Pi(), TMath::Pi());

// +ve charge tracks
TH1D* hchtrk_pt_p = new TH1D("hchtrk_pt_p", "", 200, 0., 2000.);
TH1D* hchtrk_eta_p = new TH1D("hchtrk_eta_p", "", 48, -2.4, 2.4);
TH1D* hchtrk_phi_p = new TH1D("hchtrk_phi_p", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hchtrk_pt_jetaxis_p = new TH1D("hchtrk_pt_jetaxis_p", "", 500, 0., 50.);
TH1D* hchtrk_eta_jetaxis_p = new TH1D("hchtrk_eta_jetaxis_p", "", 150, 0., 15.);
TH1D* hchtrk_phi_jetaxis_p = new TH1D("hchtrk_phi_jetaxis_p", "", 64, -TMath::Pi(), TMath::Pi());

// -ve charge tracks
TH1D* hchtrk_pt_m = new TH1D("hchtrk_pt_m", "", 200, 0., 2000.);
TH1D* hchtrk_eta_m = new TH1D("hchtrk_eta_m", "", 48, -2.4, 2.4);
TH1D* hchtrk_phi_m = new TH1D("hchtrk_phi_m", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hchtrk_pt_jetaxis_m = new TH1D("hchtrk_pt_jetaxis_m", "", 500, 0., 50.);
TH1D* hchtrk_eta_jetaxis_m = new TH1D("hchtrk_eta_jetaxis_m", "", 150, 0., 15.);
TH1D* hchtrk_phi_jetaxis_m = new TH1D("hchtrk_phi_jetaxis_m", "", 64, -TMath::Pi(), TMath::Pi());

// pion
TH1D* hpion_pt = new TH1D("hpion_pt", "", 200, 0., 2000.);
TH1D* hpion_eta = new TH1D("hpion_eta", "", 48, -2.4, 2.4);
TH1D* hpion_phi = new TH1D("hpion_phi", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hpion_pt_jetaxis = new TH1D("hpion_pt_jetaxis", "", 500, 0., 50.);
TH1D* hpion_eta_jetaxis = new TH1D("hpion_eta_jetaxis", "", 150, 0., 15.);
TH1D* hpion_phi_jetaxis = new TH1D("hpion_phi_jetaxis", "", 64, -TMath::Pi(), TMath::Pi());

// +ve pion
TH1D* hpion_pt_p = new TH1D("hpion_pt_p", "", 200, 0., 2000.);
TH1D* hpion_eta_p = new TH1D("hpion_eta_p", "", 48, -2.4, 2.4);
TH1D* hpion_phi_p = new TH1D("hpion_phi_p", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hpion_pt_jetaxis_p = new TH1D("hpion_pt_jetaxis_p", "", 500, 0., 50.);
TH1D* hpion_eta_jetaxis_p = new TH1D("hpion_eta_jetaxis_p", "", 150, 0., 15.);
TH1D* hpion_phi_jetaxis_p = new TH1D("hpion_phi_jetaxis_p", "", 64, -TMath::Pi(), TMath::Pi());

// -ve pion
TH1D* hpion_pt_m = new TH1D("hpion_pt_m", "", 200, 0., 2000.);
TH1D* hpion_eta_m = new TH1D("hpion_eta_m", "", 48, -2.4, 2.4);
TH1D* hpion_phi_m = new TH1D("hpion_phi_m", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hpion_pt_jetaxis_m = new TH1D("hpion_pt_jetaxis_m", "", 500, 0., 50.);
TH1D* hpion_eta_jetaxis_m = new TH1D("hpion_eta_jetaxis_m", "", 150, 0., 15.);
TH1D* hpion_phi_jetaxis_m = new TH1D("hpion_phi_jetaxis_m", "", 64, -TMath::Pi(), TMath::Pi());

//kaon
TH1D* hkaon_pt = new TH1D("hkaon_pt", "", 200, 0., 2000.);
TH1D* hkaon_eta = new TH1D("hkaon_eta", "", 48, -2.4, 2.4);
TH1D* hkaon_phi = new TH1D("hkaon_phi", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hkaon_pt_jetaxis = new TH1D("hkaon_pt_jetaxis", "", 500, 0., 50.);
TH1D* hkaon_eta_jetaxis = new TH1D("hkaon_eta_jetaxis", "", 150, 0., 15.);
TH1D* hkaon_phi_jetaxis = new TH1D("hkaon_phi_jetaxis", "", 64, -TMath::Pi(), TMath::Pi());

// +ve kaon
TH1D* hkaon_pt_p = new TH1D("hkaon_pt_p", "", 200, 0., 2000.);
TH1D* hkaon_eta_p = new TH1D("hkaon_eta_p", "", 48, -2.4, 2.4);
TH1D* hkaon_phi_p = new TH1D("hkaon_phi_p", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hkaon_pt_jetaxis_p = new TH1D("hkaon_pt_jetaxis_p", "", 500, 0., 50.);
TH1D* hkaon_eta_jetaxis_p = new TH1D("hkaon_eta_jetaxis_p", "", 150, 0., 15.);
TH1D* hkaon_phi_jetaxis_p = new TH1D("hkaon_phi_jetaxis_p", "", 64, -TMath::Pi(), TMath::Pi());

// -ve kaon
TH1D* hkaon_pt_m = new TH1D("hkaon_pt_m", "", 200, 0., 2000.);
TH1D* hkaon_eta_m = new TH1D("hkaon_eta_m", "", 48, -2.4, 2.4);
TH1D* hkaon_phi_m = new TH1D("hkaon_phi_m", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hkaon_pt_jetaxis_m = new TH1D("hkaon_pt_jetaxis_m", "", 500, 0., 50.);
TH1D* hkaon_eta_jetaxis_m = new TH1D("hkaon_eta_jetaxis_m", "", 150, 0., 15.);
TH1D* hkaon_phi_jetaxis_m = new TH1D("hkaon_phi_jetaxis_m", "", 64, -TMath::Pi(), TMath::Pi());

//proton
TH1D* hproton_pt = new TH1D("hproton_pt", "", 200, 0., 2000.);
TH1D* hproton_eta = new TH1D("hproton_eta", "", 48, -2.4, 2.4);
TH1D* hproton_phi = new TH1D("hproton_phi", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hproton_pt_jetaxis = new TH1D("hproton_pt_jetaxis", "", 500, 0., 50.);
TH1D* hproton_eta_jetaxis = new TH1D("hproton_eta_jetaxis", "", 150, 0., 15.);
TH1D* hproton_phi_jetaxis = new TH1D("hproton_phi_jetaxis", "", 64, -TMath::Pi(), TMath::Pi());

// +ve proton
TH1D* hproton_pt_p = new TH1D("hproton_pt_p", "", 200, 0., 2000.);
TH1D* hproton_eta_p = new TH1D("hproton_eta_p", "", 48, -2.4, 2.4);
TH1D* hproton_phi_p = new TH1D("hproton_phi_p", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hproton_pt_jetaxis_p = new TH1D("hproton_pt_jetaxis_p", "", 500, 0., 50.);
TH1D* hproton_eta_jetaxis_p = new TH1D("hproton_eta_jetaxis_p", "", 150, 0., 15.);
TH1D* hproton_phi_jetaxis_p = new TH1D("hproton_phi_jetaxis_p", "", 64, -TMath::Pi(), TMath::Pi());

// -ve proton
TH1D* hproton_pt_m = new TH1D("hproton_pt_m", "", 200, 0., 2000.);
TH1D* hproton_eta_m = new TH1D("hproton_eta_m", "", 48, -2.4, 2.4);
TH1D* hproton_phi_m = new TH1D("hproton_phi_m", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hproton_pt_jetaxis_m = new TH1D("hproton_pt_jetaxis_m", "", 500, 0., 50.);
TH1D* hproton_eta_jetaxis_m = new TH1D("hproton_eta_jetaxis_m", "", 150, 0., 15.);
TH1D* hproton_phi_jetaxis_m = new TH1D("hproton_phi_jetaxis_m", "", 64, -TMath::Pi(), TMath::Pi());

//lambda                                                                                                                                              
TH1D* hlambda_pt = new TH1D("hlambda_pt", "", 200, 0., 2000.);
TH1D* hlambda_eta = new TH1D("hlambda_eta", "", 48, -2.4, 2.4);
TH1D* hlambda_phi = new TH1D("hlambda_phi", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hlambda_pt_jetaxis = new TH1D("hlambda_pt_jetaxis", "", 500, 0., 50.);
TH1D* hlambda_eta_jetaxis = new TH1D("hlambda_eta_jetaxis", "", 150, 0., 15.);
TH1D* hlambda_phi_jetaxis = new TH1D("hlambda_phi_jetaxis", "", 64, -TMath::Pi(), TMath::Pi());

// +ve lambda
TH1D* hlambda_pt_p = new TH1D("hlambda_pt_p", "", 200, 0., 2000.);
TH1D* hlambda_eta_p = new TH1D("hlambda_eta_p", "", 48, -2.4, 2.4);
TH1D* hlambda_phi_p = new TH1D("hlambda_phi_p", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hlambda_pt_jetaxis_p = new TH1D("hlambda_pt_jetaxis_p", "", 500, 0., 50.);
TH1D* hlambda_eta_jetaxis_p = new TH1D("hlambda_eta_jetaxis_p", "", 150, 0., 15.);
TH1D* hlambda_phi_jetaxis_p = new TH1D("hlambda_phi_jetaxis_p", "", 64, -TMath::Pi(), TMath::Pi());

// -ve lambda
TH1D* hlambda_pt_m = new TH1D("hlambda_pt_m", "", 200, 0., 2000.);
TH1D* hlambda_eta_m = new TH1D("hlambda_eta_m", "", 48, -2.4, 2.4);
TH1D* hlambda_phi_m = new TH1D("hlambda_phi_m", "", 64, -TMath::Pi(), TMath::Pi());
TH1D* hlambda_pt_jetaxis_m = new TH1D("hlambda_pt_jetaxis_m", "", 500, 0., 50.);
TH1D* hlambda_eta_jetaxis_m = new TH1D("hlambda_eta_jetaxis_m", "", 150, 0., 15.);
TH1D* hlambda_phi_jetaxis_m = new TH1D("hlambda_phi_jetaxis_m", "", 64, -TMath::Pi(), TMath::Pi());


// signal histo
TH1D* hnchtrk_jt03 = new TH1D("hnchtrk_jt03", "", 1, 0., 1.);
TH1D* hnchtrk_jt0p33 = new TH1D("hnchtrk_jt0p33", "", 1, 0., 1.);
TH1D* hnchtrk_jt0p53 = new TH1D("hnchtrk_jt0p53", "", 1, 0., 1.);
TH2D* hsignal_newchtrk_jt03 = new TH2D("hsignal_newchtrk_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p33 = new TH2D("hsignal_newchtrk_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p53 = new TH2D("hsignal_newchtrk_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH1D* hnchtrk_jt03_[nch_bin];
TH1D* hnchtrk_jt0p33_[nch_bin];
TH1D* hnchtrk_jt0p53_[nch_bin];
TH2D* hsignal_newchtrk_jt03_[nch_bin];
TH2D* hsignal_newchtrk_jt0p33_[nch_bin];
TH2D* hsignal_newchtrk_jt0p53_[nch_bin];

// +ve and +ve charge tracks
TH1D* hnchtrk_jt03_pm = new TH1D("hnchtrk_jt03_pm", "", 2, 0., 2.);
TH1D* hnchtrk_jt0p33_pm = new TH1D("hnchtrk_jt0p33_pm", "", 2, 0., 2.);
TH1D* hnchtrk_jt0p53_pm = new TH1D("hnchtrk_jt0p53_pm", "", 2, 0., 2.);
TH1D* hnchtrk_jt03_pm_[nch_bin];
TH1D* hnchtrk_jt0p33_pm_[nch_bin];
TH1D* hnchtrk_jt0p53_pm_[nch_bin];

TH2D* hsignal_newchtrk_jt03_pp = new TH2D("hsignal_newchtrk_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt03_mm = new TH2D("hsignal_newchtrk_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt03_pm = new TH2D("hsignal_newchtrk_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt03_mp = new TH2D("hsignal_newchtrk_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt03_pp_[nch_bin];
TH2D* hsignal_newchtrk_jt03_mm_[nch_bin];
TH2D* hsignal_newchtrk_jt03_pm_[nch_bin];
TH2D* hsignal_newchtrk_jt03_mp_[nch_bin];

TH2D* hsignal_newchtrk_jt0p33_pp = new TH2D("hsignal_newchtrk_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p33_mm = new TH2D("hsignal_newchtrk_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p33_pm = new TH2D("hsignal_newchtrk_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p33_mp = new TH2D("hsignal_newchtrk_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p33_pp_[nch_bin];
TH2D* hsignal_newchtrk_jt0p33_mm_[nch_bin];
TH2D* hsignal_newchtrk_jt0p33_pm_[nch_bin];
TH2D* hsignal_newchtrk_jt0p33_mp_[nch_bin];

TH2D* hsignal_newchtrk_jt0p53_pp = new TH2D("hsignal_newchtrk_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p53_mm = new TH2D("hsignal_newchtrk_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p53_pm = new TH2D("hsignal_newchtrk_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p53_mp = new TH2D("hsignal_newchtrk_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newchtrk_jt0p53_pp_[nch_bin];
TH2D* hsignal_newchtrk_jt0p53_mm_[nch_bin];
TH2D* hsignal_newchtrk_jt0p53_pm_[nch_bin];
TH2D* hsignal_newchtrk_jt0p53_mp_[nch_bin];

//pion
TH1D* hnpion_jt03 = new TH1D("hnpion_jt03", "", 1, 0., 1.);
TH1D* hnpion_jt0p33 = new TH1D("hnpion_jt0p33", "", 1, 0., 1.);
TH1D* hnpion_jt0p53 = new TH1D("hnpion_jt0p53", "", 1, 0., 1.);
TH2D* hsignal_newpion_jt03 = new TH2D("hsignal_newpion_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p33 = new TH2D("hsignal_newpion_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p53 = new TH2D("hsignal_newpion_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH1D* hnpion_jt03_[nch_bin];
TH1D* hnpion_jt0p33_[nch_bin];
TH1D* hnpion_jt0p53_[nch_bin];
TH2D* hsignal_newpion_jt03_[nch_bin];
TH2D* hsignal_newpion_jt0p33_[nch_bin];
TH2D* hsignal_newpion_jt0p53_[nch_bin];

// +ve and +ve pion
TH1D* hnpion_jt03_pm = new TH1D("hnpion_jt03_pm", "", 2, 0., 2.);
TH1D* hnpion_jt0p33_pm = new TH1D("hnpion_jt0p33_pm", "", 2, 0., 2.);
TH1D* hnpion_jt0p53_pm = new TH1D("hnpion_jt0p53_pm", "", 2, 0., 2.);
TH1D* hnpion_jt03_pm_[nch_bin];
TH1D* hnpion_jt0p33_pm_[nch_bin];
TH1D* hnpion_jt0p53_pm_[nch_bin];

TH2D* hsignal_newpion_jt03_pp = new TH2D("hsignal_newpion_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt03_mm = new TH2D("hsignal_newpion_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt03_pm = new TH2D("hsignal_newpion_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt03_mp = new TH2D("hsignal_newpion_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt03_pp_[nch_bin];
TH2D* hsignal_newpion_jt03_mm_[nch_bin];
TH2D* hsignal_newpion_jt03_pm_[nch_bin];
TH2D* hsignal_newpion_jt03_mp_[nch_bin];

TH2D* hsignal_newpion_jt0p33_pp = new TH2D("hsignal_newpion_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p33_mm = new TH2D("hsignal_newpion_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p33_pm = new TH2D("hsignal_newpion_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p33_mp = new TH2D("hsignal_newpion_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p33_pp_[nch_bin];
TH2D* hsignal_newpion_jt0p33_mm_[nch_bin];
TH2D* hsignal_newpion_jt0p33_pm_[nch_bin];
TH2D* hsignal_newpion_jt0p33_mp_[nch_bin];

TH2D* hsignal_newpion_jt0p53_pp = new TH2D("hsignal_newpion_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p53_mm = new TH2D("hsignal_newpion_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p53_pm = new TH2D("hsignal_newpion_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p53_mp = new TH2D("hsignal_newpion_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newpion_jt0p53_pp_[nch_bin];
TH2D* hsignal_newpion_jt0p53_mm_[nch_bin];
TH2D* hsignal_newpion_jt0p53_pm_[nch_bin];
TH2D* hsignal_newpion_jt0p53_mp_[nch_bin];

//kaon
TH1D* hnkaon_jt03 = new TH1D("hnkaon_jt03", "", 1, 0., 1.);
TH1D* hnkaon_jt0p33 = new TH1D("hnkaon_jt0p33", "", 1, 0., 1.);
TH1D* hnkaon_jt0p53 = new TH1D("hnkaon_jt0p53", "", 1, 0., 1.);
TH2D* hsignal_newkaon_jt03 = new TH2D("hsignal_newkaon_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p33 = new TH2D("hsignal_newkaon_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p53 = new TH2D("hsignal_newkaon_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH1D* hnkaon_jt03_[nch_bin];
TH1D* hnkaon_jt0p33_[nch_bin];
TH1D* hnkaon_jt0p53_[nch_bin];
TH2D* hsignal_newkaon_jt03_[nch_bin];
TH2D* hsignal_newkaon_jt0p33_[nch_bin];
TH2D* hsignal_newkaon_jt0p53_[nch_bin];

// +ve and +ve kaon
TH1D* hnkaon_jt03_pm = new TH1D("hnkaon_jt03_pm", "", 2, 0., 2.);
TH1D* hnkaon_jt0p33_pm = new TH1D("hnkaon_jt0p33_pm", "", 2, 0., 2.);
TH1D* hnkaon_jt0p53_pm = new TH1D("hnkaon_jt0p53_pm", "", 2, 0., 2.);
TH1D* hnkaon_jt03_pm_[nch_bin];
TH1D* hnkaon_jt0p33_pm_[nch_bin];
TH1D* hnkaon_jt0p53_pm_[nch_bin];

TH2D* hsignal_newkaon_jt03_pp = new TH2D("hsignal_newkaon_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt03_mm = new TH2D("hsignal_newkaon_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt03_pm = new TH2D("hsignal_newkaon_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt03_mp = new TH2D("hsignal_newkaon_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt03_pp_[nch_bin];
TH2D* hsignal_newkaon_jt03_mm_[nch_bin];
TH2D* hsignal_newkaon_jt03_pm_[nch_bin];
TH2D* hsignal_newkaon_jt03_mp_[nch_bin];

TH2D* hsignal_newkaon_jt0p33_pp = new TH2D("hsignal_newkaon_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p33_mm = new TH2D("hsignal_newkaon_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p33_pm = new TH2D("hsignal_newkaon_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p33_mp = new TH2D("hsignal_newkaon_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p33_pp_[nch_bin];
TH2D* hsignal_newkaon_jt0p33_mm_[nch_bin];
TH2D* hsignal_newkaon_jt0p33_pm_[nch_bin];
TH2D* hsignal_newkaon_jt0p33_mp_[nch_bin];

TH2D* hsignal_newkaon_jt0p53_pp = new TH2D("hsignal_newkaon_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p53_mm = new TH2D("hsignal_newkaon_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p53_pm = new TH2D("hsignal_newkaon_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p53_mp = new TH2D("hsignal_newkaon_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newkaon_jt0p53_pp_[nch_bin];
TH2D* hsignal_newkaon_jt0p53_mm_[nch_bin];
TH2D* hsignal_newkaon_jt0p53_pm_[nch_bin];
TH2D* hsignal_newkaon_jt0p53_mp_[nch_bin];

//proton
TH1D* hnproton_jt03 = new TH1D("hnproton_jt03", "", 1, 0., 1.);
TH1D* hnproton_jt0p33 = new TH1D("hnproton_jt0p33", "", 1, 0., 1.);
TH1D* hnproton_jt0p53 = new TH1D("hnproton_jt0p53", "", 1, 0., 1.);
TH2D* hsignal_newproton_jt03 = new TH2D("hsignal_newproton_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p33 = new TH2D("hsignal_newproton_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p53 = new TH2D("hsignal_newproton_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH1D* hnproton_jt03_[nch_bin];
TH1D* hnproton_jt0p33_[nch_bin];
TH1D* hnproton_jt0p53_[nch_bin];
TH2D* hsignal_newproton_jt03_[nch_bin];
TH2D* hsignal_newproton_jt0p33_[nch_bin];
TH2D* hsignal_newproton_jt0p53_[nch_bin];

// +ve and +ve proton
TH1D* hnproton_jt03_pm = new TH1D("hnproton_jt03_pm", "", 2, 0., 2.);
TH1D* hnproton_jt0p33_pm = new TH1D("hnproton_jt0p33_pm", "", 2, 0., 2.);
TH1D* hnproton_jt0p53_pm = new TH1D("hnproton_jt0p53_pm", "", 2, 0., 2.);
TH1D* hnproton_jt03_pm_[nch_bin];
TH1D* hnproton_jt0p33_pm_[nch_bin];
TH1D* hnproton_jt0p53_pm_[nch_bin];

TH2D* hsignal_newproton_jt03_pp = new TH2D("hsignal_newproton_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt03_mm = new TH2D("hsignal_newproton_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt03_pm = new TH2D("hsignal_newproton_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt03_mp = new TH2D("hsignal_newproton_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt03_pp_[nch_bin];
TH2D* hsignal_newproton_jt03_mm_[nch_bin];
TH2D* hsignal_newproton_jt03_pm_[nch_bin];
TH2D* hsignal_newproton_jt03_mp_[nch_bin];

TH2D* hsignal_newproton_jt0p33_pp = new TH2D("hsignal_newproton_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p33_mm = new TH2D("hsignal_newproton_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p33_pm = new TH2D("hsignal_newproton_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p33_mp = new TH2D("hsignal_newproton_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p33_pp_[nch_bin];
TH2D* hsignal_newproton_jt0p33_mm_[nch_bin];
TH2D* hsignal_newproton_jt0p33_pm_[nch_bin];
TH2D* hsignal_newproton_jt0p33_mp_[nch_bin];

TH2D* hsignal_newproton_jt0p53_pp = new TH2D("hsignal_newproton_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p53_mm = new TH2D("hsignal_newproton_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p53_pm = new TH2D("hsignal_newproton_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p53_mp = new TH2D("hsignal_newproton_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newproton_jt0p53_pp_[nch_bin];
TH2D* hsignal_newproton_jt0p53_mm_[nch_bin];
TH2D* hsignal_newproton_jt0p53_pm_[nch_bin];
TH2D* hsignal_newproton_jt0p53_mp_[nch_bin];

//lambda                                                                                                                                                
TH1D* hnlambda_jt03 = new TH1D("hnlambda_jt03", "", 1, 0., 1.);
TH1D* hnlambda_jt0p33 = new TH1D("hnlambda_jt0p33", "", 1, 0., 1.);
TH1D* hnlambda_jt0p53 = new TH1D("hnlambda_jt0p53", "", 1, 0., 1.);
TH2D* hsignal_newlambda_jt03 = new TH2D("hsignal_newlambda_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p33 = new TH2D("hsignal_newlambda_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p53 = new TH2D("hsignal_newlambda_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH1D* hnlambda_jt03_[nch_bin];
TH1D* hnlambda_jt0p33_[nch_bin];
TH1D* hnlambda_jt0p53_[nch_bin];
TH2D* hsignal_newlambda_jt03_[nch_bin];
TH2D* hsignal_newlambda_jt0p33_[nch_bin];
TH2D* hsignal_newlambda_jt0p53_[nch_bin];

// +ve and +ve lambda
TH1D* hnlambda_jt03_pm = new TH1D("hnlambda_jt03_pm", "", 2, 0., 2.);
TH1D* hnlambda_jt0p33_pm = new TH1D("hnlambda_jt0p33_pm", "", 2, 0., 2.);
TH1D* hnlambda_jt0p53_pm = new TH1D("hnlambda_jt0p53_pm", "", 2, 0., 2.);
TH1D* hnlambda_jt03_pm_[nch_bin];
TH1D* hnlambda_jt0p33_pm_[nch_bin];
TH1D* hnlambda_jt0p53_pm_[nch_bin];

TH2D* hsignal_newlambda_jt03_pp = new TH2D("hsignal_newlambda_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt03_mm = new TH2D("hsignal_newlambda_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt03_pm = new TH2D("hsignal_newlambda_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt03_mp = new TH2D("hsignal_newlambda_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt03_pp_[nch_bin];
TH2D* hsignal_newlambda_jt03_mm_[nch_bin];
TH2D* hsignal_newlambda_jt03_pm_[nch_bin];
TH2D* hsignal_newlambda_jt03_mp_[nch_bin];

TH2D* hsignal_newlambda_jt0p33_pp = new TH2D("hsignal_newlambda_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p33_mm = new TH2D("hsignal_newlambda_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p33_pm = new TH2D("hsignal_newlambda_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p33_mp = new TH2D("hsignal_newlambda_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p33_pp_[nch_bin];
TH2D* hsignal_newlambda_jt0p33_mm_[nch_bin];
TH2D* hsignal_newlambda_jt0p33_pm_[nch_bin];
TH2D* hsignal_newlambda_jt0p33_mp_[nch_bin];

TH2D* hsignal_newlambda_jt0p53_pp = new TH2D("hsignal_newlambda_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p53_mm = new TH2D("hsignal_newlambda_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p53_pm = new TH2D("hsignal_newlambda_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p53_mp = new TH2D("hsignal_newlambda_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hsignal_newlambda_jt0p53_pp_[nch_bin];
TH2D* hsignal_newlambda_jt0p53_mm_[nch_bin];
TH2D* hsignal_newlambda_jt0p53_pm_[nch_bin];
TH2D* hsignal_newlambda_jt0p53_mp_[nch_bin];

// mixing histo
TH2D* hmixing_newchtrk_jt03 = new TH2D("hmixing_newchtrk_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt0p33 = new TH2D("hmixing_newchtrk_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt0p53 = new TH2D("hmixing_newchtrk_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt03_[nch_bin];
TH2D* hmixing_newchtrk_jt0p33_[nch_bin];
TH2D* hmixing_newchtrk_jt0p53_[nch_bin];

// +ve and -ve charge tracks
TH2D* hmixing_newchtrk_jt03_pp = new TH2D("hmixing_newchtrk_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt03_mm = new TH2D("hmixing_newchtrk_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt03_pm = new TH2D("hmixing_newchtrk_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt03_mp = new TH2D("hmixing_newchtrk_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newchtrk_jt0p33_pp = new TH2D("hmixing_newchtrk_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt0p33_mm = new TH2D("hmixing_newchtrk_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt0p33_pm = new TH2D("hmixing_newchtrk_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt0p33_mp = new TH2D("hmixing_newchtrk_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newchtrk_jt0p53_pp = new TH2D("hmixing_newchtrk_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt0p53_mm = new TH2D("hmixing_newchtrk_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt0p53_pm = new TH2D("hmixing_newchtrk_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newchtrk_jt0p53_mp = new TH2D("hmixing_newchtrk_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newchtrk_jt03_pp_[nch_bin];
TH2D* hmixing_newchtrk_jt03_mm_[nch_bin];
TH2D* hmixing_newchtrk_jt03_pm_[nch_bin];
TH2D* hmixing_newchtrk_jt03_mp_[nch_bin];

TH2D* hmixing_newchtrk_jt0p33_pp_[nch_bin];
TH2D* hmixing_newchtrk_jt0p33_mm_[nch_bin];
TH2D* hmixing_newchtrk_jt0p33_pm_[nch_bin];
TH2D* hmixing_newchtrk_jt0p33_mp_[nch_bin];

TH2D* hmixing_newchtrk_jt0p53_pp_[nch_bin];
TH2D* hmixing_newchtrk_jt0p53_mm_[nch_bin];
TH2D* hmixing_newchtrk_jt0p53_pm_[nch_bin];
TH2D* hmixing_newchtrk_jt0p53_mp_[nch_bin];

//pion
TH2D* hmixing_newpion_jt03 = new TH2D("hmixing_newpion_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt0p33 = new TH2D("hmixing_newpion_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt0p53 = new TH2D("hmixing_newpion_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt03_[nch_bin];
TH2D* hmixing_newpion_jt0p33_[nch_bin];
TH2D* hmixing_newpion_jt0p53_[nch_bin];

// +ve and -ve pion
TH2D* hmixing_newpion_jt03_pp = new TH2D("hmixing_newpion_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt03_mm = new TH2D("hmixing_newpion_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt03_pm = new TH2D("hmixing_newpion_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt03_mp = new TH2D("hmixing_newpion_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newpion_jt0p33_pp = new TH2D("hmixing_newpion_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt0p33_mm = new TH2D("hmixing_newpion_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt0p33_pm = new TH2D("hmixing_newpion_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt0p33_mp = new TH2D("hmixing_newpion_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newpion_jt0p53_pp = new TH2D("hmixing_newpion_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt0p53_mm = new TH2D("hmixing_newpion_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt0p53_pm = new TH2D("hmixing_newpion_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newpion_jt0p53_mp = new TH2D("hmixing_newpion_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newpion_jt03_pp_[nch_bin];
TH2D* hmixing_newpion_jt03_mm_[nch_bin];
TH2D* hmixing_newpion_jt03_pm_[nch_bin];
TH2D* hmixing_newpion_jt03_mp_[nch_bin];

TH2D* hmixing_newpion_jt0p33_pp_[nch_bin];
TH2D* hmixing_newpion_jt0p33_mm_[nch_bin];
TH2D* hmixing_newpion_jt0p33_pm_[nch_bin];
TH2D* hmixing_newpion_jt0p33_mp_[nch_bin];

TH2D* hmixing_newpion_jt0p53_pp_[nch_bin];
TH2D* hmixing_newpion_jt0p53_mm_[nch_bin];
TH2D* hmixing_newpion_jt0p53_pm_[nch_bin];
TH2D* hmixing_newpion_jt0p53_mp_[nch_bin];

//kaon
TH2D* hmixing_newkaon_jt03 = new TH2D("hmixing_newkaon_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt0p33 = new TH2D("hmixing_newkaon_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt0p53 = new TH2D("hmixing_newkaon_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt03_[nch_bin];
TH2D* hmixing_newkaon_jt0p33_[nch_bin];
TH2D* hmixing_newkaon_jt0p53_[nch_bin];

// +ve and -ve kaon
TH2D* hmixing_newkaon_jt03_pp = new TH2D("hmixing_newkaon_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt03_mm = new TH2D("hmixing_newkaon_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt03_pm = new TH2D("hmixing_newkaon_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt03_mp = new TH2D("hmixing_newkaon_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newkaon_jt0p33_pp = new TH2D("hmixing_newkaon_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt0p33_mm = new TH2D("hmixing_newkaon_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt0p33_pm = new TH2D("hmixing_newkaon_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt0p33_mp = new TH2D("hmixing_newkaon_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newkaon_jt0p53_pp = new TH2D("hmixing_newkaon_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt0p53_mm = new TH2D("hmixing_newkaon_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt0p53_pm = new TH2D("hmixing_newkaon_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newkaon_jt0p53_mp = new TH2D("hmixing_newkaon_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newkaon_jt03_pp_[nch_bin];
TH2D* hmixing_newkaon_jt03_mm_[nch_bin];
TH2D* hmixing_newkaon_jt03_pm_[nch_bin];
TH2D* hmixing_newkaon_jt03_mp_[nch_bin];

TH2D* hmixing_newkaon_jt0p33_pp_[nch_bin];
TH2D* hmixing_newkaon_jt0p33_mm_[nch_bin];
TH2D* hmixing_newkaon_jt0p33_pm_[nch_bin];
TH2D* hmixing_newkaon_jt0p33_mp_[nch_bin];

TH2D* hmixing_newkaon_jt0p53_pp_[nch_bin];
TH2D* hmixing_newkaon_jt0p53_mm_[nch_bin];
TH2D* hmixing_newkaon_jt0p53_pm_[nch_bin];
TH2D* hmixing_newkaon_jt0p53_mp_[nch_bin];


//proton
TH2D* hmixing_newproton_jt03 = new TH2D("hmixing_newproton_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt0p33 = new TH2D("hmixing_newproton_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt0p53 = new TH2D("hmixing_newproton_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt03_[nch_bin];
TH2D* hmixing_newproton_jt0p33_[nch_bin];
TH2D* hmixing_newproton_jt0p53_[nch_bin];

// +ve and -ve proton
TH2D* hmixing_newproton_jt03_pp = new TH2D("hmixing_newproton_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt03_mm = new TH2D("hmixing_newproton_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt03_pm = new TH2D("hmixing_newproton_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt03_mp = new TH2D("hmixing_newproton_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newproton_jt0p33_pp = new TH2D("hmixing_newproton_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt0p33_mm = new TH2D("hmixing_newproton_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt0p33_pm = new TH2D("hmixing_newproton_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt0p33_mp = new TH2D("hmixing_newproton_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newproton_jt0p53_pp = new TH2D("hmixing_newproton_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt0p53_mm = new TH2D("hmixing_newproton_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt0p53_pm = new TH2D("hmixing_newproton_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newproton_jt0p53_mp = new TH2D("hmixing_newproton_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newproton_jt03_pp_[nch_bin];
TH2D* hmixing_newproton_jt03_mm_[nch_bin];
TH2D* hmixing_newproton_jt03_pm_[nch_bin];
TH2D* hmixing_newproton_jt03_mp_[nch_bin];

TH2D* hmixing_newproton_jt0p33_pp_[nch_bin];
TH2D* hmixing_newproton_jt0p33_mm_[nch_bin];
TH2D* hmixing_newproton_jt0p33_pm_[nch_bin];
TH2D* hmixing_newproton_jt0p33_mp_[nch_bin];

TH2D* hmixing_newproton_jt0p53_pp_[nch_bin];
TH2D* hmixing_newproton_jt0p53_mm_[nch_bin];
TH2D* hmixing_newproton_jt0p53_pm_[nch_bin];
TH2D* hmixing_newproton_jt0p53_mp_[nch_bin];


//lambda
TH2D* hmixing_newlambda_jt03 = new TH2D("hmixing_newlambda_jt03", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt0p33 = new TH2D("hmixing_newlambda_jt0p33", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt0p53 = new TH2D("hmixing_newlambda_jt0p53", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt03_[nch_bin];
TH2D* hmixing_newlambda_jt0p33_[nch_bin];
TH2D* hmixing_newlambda_jt0p53_[nch_bin];

// +ve and -ve lambda
TH2D* hmixing_newlambda_jt03_pp = new TH2D("hmixing_newlambda_jt03_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt03_mm = new TH2D("hmixing_newlambda_jt03_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt03_pm = new TH2D("hmixing_newlambda_jt03_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt03_mp = new TH2D("hmixing_newlambda_jt03_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newlambda_jt0p33_pp = new TH2D("hmixing_newlambda_jt0p33_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt0p33_mm = new TH2D("hmixing_newlambda_jt0p33_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt0p33_pm = new TH2D("hmixing_newlambda_jt0p33_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt0p33_mp = new TH2D("hmixing_newlambda_jt0p33_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newlambda_jt0p53_pp = new TH2D("hmixing_newlambda_jt0p53_pp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt0p53_mm = new TH2D("hmixing_newlambda_jt0p53_mm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt0p53_pm = new TH2D("hmixing_newlambda_jt0p53_pm", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
TH2D* hmixing_newlambda_jt0p53_mp = new TH2D("hmixing_newlambda_jt0p53_mp", "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

TH2D* hmixing_newlambda_jt03_pp_[nch_bin];
TH2D* hmixing_newlambda_jt03_mm_[nch_bin];
TH2D* hmixing_newlambda_jt03_pm_[nch_bin];
TH2D* hmixing_newlambda_jt03_mp_[nch_bin];

TH2D* hmixing_newlambda_jt0p33_pp_[nch_bin];
TH2D* hmixing_newlambda_jt0p33_mm_[nch_bin];
TH2D* hmixing_newlambda_jt0p33_pm_[nch_bin];
TH2D* hmixing_newlambda_jt0p33_mp_[nch_bin];

TH2D* hmixing_newlambda_jt0p53_pp_[nch_bin];
TH2D* hmixing_newlambda_jt0p53_mm_[nch_bin];
TH2D* hmixing_newlambda_jt0p53_pm_[nch_bin];
TH2D* hmixing_newlambda_jt0p53_mp_[nch_bin];

void array_hist_def()
{
  for(int inchbin = 0; inchbin < nch_bin; inchbin++)
    {
      // jet histo
      hJet_nchtrk_[inchbin] = new TH1D(Form("hJet_nchtrk_%d", inchbin), "", 200, 0, 200);
      
      // coorelation histo
      //signal
      hnchtrk_jt03_[inchbin] = new TH1D(Form("hnchtrk_jt03_%d", inchbin), "", 1, 0., 1.);
      hnchtrk_jt0p33_[inchbin] = new TH1D(Form("hnchtrk_jt0p33_%d", inchbin), "", 1, 0., 1.);
      hnchtrk_jt0p53_[inchbin] = new TH1D(Form("hnchtrk_jt0p53_%d", inchbin), "", 1, 0., 1.);
      hsignal_newchtrk_jt03_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt0p33_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt0p53_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve charge tracks
      hnchtrk_jt03_pm_[inchbin] = new TH1D(Form("hnchtrk_jt03_pm_%d", inchbin), "", 2, 0., 2.);
      hnchtrk_jt0p33_pm_[inchbin] = new TH1D(Form("hnchtrk_jt0p33_pm_%d", inchbin), "", 2, 0., 2.);
      hnchtrk_jt0p53_pm_[inchbin] = new TH1D(Form("hnchtrk_jt0p53_pm_%d", inchbin), "", 2, 0., 2.);

      hsignal_newchtrk_jt03_pp_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt03_mm_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt03_pm_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt03_mp_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newchtrk_jt0p33_pp_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt0p33_mm_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt0p33_pm_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt0p33_mp_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newchtrk_jt0p53_pp_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt0p53_mm_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt0p53_pm_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newchtrk_jt0p53_mp_[inchbin] = new TH2D(Form("hsignal_newchtrk_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
            
      //pion
      hnpion_jt03_[inchbin] = new TH1D(Form("hnpion_jt03_%d", inchbin), "", 1, 0., 1.);
      hnpion_jt0p33_[inchbin] = new TH1D(Form("hnpion_jt0p33_%d", inchbin), "", 1, 0., 1.);
      hnpion_jt0p53_[inchbin] = new TH1D(Form("hnpion_jt0p53_%d", inchbin), "", 1, 0., 1.);
      hsignal_newpion_jt03_[inchbin] = new TH2D(Form("hsignal_newpion_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt0p33_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt0p53_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve pion
      hnpion_jt03_pm_[inchbin] = new TH1D(Form("hnpion_jt03_pm_%d", inchbin), "", 2, 0., 2.);
      hnpion_jt0p33_pm_[inchbin] = new TH1D(Form("hnpion_jt0p33_pm_%d", inchbin), "", 2, 0., 2.);
      hnpion_jt0p53_pm_[inchbin] = new TH1D(Form("hnpion_jt0p53_pm_%d", inchbin), "", 2, 0., 2.);

      hsignal_newpion_jt03_pp_[inchbin] = new TH2D(Form("hsignal_newpion_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt03_mm_[inchbin] = new TH2D(Form("hsignal_newpion_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt03_pm_[inchbin] = new TH2D(Form("hsignal_newpion_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt03_mp_[inchbin] = new TH2D(Form("hsignal_newpion_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newpion_jt0p33_pp_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt0p33_mm_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt0p33_pm_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt0p33_mp_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newpion_jt0p53_pp_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt0p53_mm_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt0p53_pm_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newpion_jt0p53_mp_[inchbin] = new TH2D(Form("hsignal_newpion_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      //kaon
      hnkaon_jt03_[inchbin] = new TH1D(Form("hnkaon_jt03_%d", inchbin), "", 1, 0., 1.);
      hnkaon_jt0p33_[inchbin] = new TH1D(Form("hnkaon_jt0p33_%d", inchbin), "", 1, 0., 1.);
      hnkaon_jt0p53_[inchbin] = new TH1D(Form("hnkaon_jt0p53_%d", inchbin), "", 1, 0., 1.);
      hsignal_newkaon_jt03_[inchbin] = new TH2D(Form("hsignal_newkaon_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt0p33_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt0p53_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve kaon
      hnkaon_jt03_pm_[inchbin] = new TH1D(Form("hnkaon_jt03_pm_%d", inchbin), "", 2, 0., 2.);
      hnkaon_jt0p33_pm_[inchbin] = new TH1D(Form("hnkaon_jt0p33_pm_%d", inchbin), "", 2, 0., 2.);
      hnkaon_jt0p53_pm_[inchbin] = new TH1D(Form("hnkaon_jt0p53_pm_%d", inchbin), "", 2, 0., 2.);

      hsignal_newkaon_jt03_pp_[inchbin] = new TH2D(Form("hsignal_newkaon_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt03_mm_[inchbin] = new TH2D(Form("hsignal_newkaon_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt03_pm_[inchbin] = new TH2D(Form("hsignal_newkaon_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt03_mp_[inchbin] = new TH2D(Form("hsignal_newkaon_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newkaon_jt0p33_pp_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt0p33_mm_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt0p33_pm_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt0p33_mp_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newkaon_jt0p53_pp_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt0p53_mm_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt0p53_pm_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newkaon_jt0p53_mp_[inchbin] = new TH2D(Form("hsignal_newkaon_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      //proton
      hnproton_jt03_[inchbin] = new TH1D(Form("hnproton_jt03_%d", inchbin), "", 1, 0., 1.);
      hnproton_jt0p33_[inchbin] = new TH1D(Form("hnproton_jt0p33_%d", inchbin), "", 1, 0., 1.);
      hnproton_jt0p53_[inchbin] = new TH1D(Form("hnproton_jt0p53_%d", inchbin), "", 1, 0., 1.);
      hsignal_newproton_jt03_[inchbin] = new TH2D(Form("hsignal_newproton_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt0p33_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt0p53_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve proton
      hnproton_jt03_pm_[inchbin] = new TH1D(Form("hnproton_jt03_pm_%d", inchbin), "", 2, 0., 2.);
      hnproton_jt0p33_pm_[inchbin] = new TH1D(Form("hnproton_jt0p33_pm_%d", inchbin), "", 2, 0., 2.);
      hnproton_jt0p53_pm_[inchbin] = new TH1D(Form("hnproton_jt0p53_pm_%d", inchbin), "", 2, 0., 2.);

      hsignal_newproton_jt03_pp_[inchbin] = new TH2D(Form("hsignal_newproton_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt03_mm_[inchbin] = new TH2D(Form("hsignal_newproton_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt03_pm_[inchbin] = new TH2D(Form("hsignal_newproton_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt03_mp_[inchbin] = new TH2D(Form("hsignal_newproton_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newproton_jt0p33_pp_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt0p33_mm_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt0p33_pm_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt0p33_mp_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newproton_jt0p53_pp_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt0p53_mm_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt0p53_pm_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newproton_jt0p53_mp_[inchbin] = new TH2D(Form("hsignal_newproton_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());


      //lambda
      hnlambda_jt03_[inchbin] = new TH1D(Form("hnlambda_jt03_%d", inchbin), "", 1, 0., 1.);
      hnlambda_jt0p33_[inchbin] = new TH1D(Form("hnlambda_jt0p33_%d", inchbin), "", 1, 0., 1.);
      hnlambda_jt0p53_[inchbin] = new TH1D(Form("hnlambda_jt0p53_%d", inchbin), "", 1, 0., 1.);
      hsignal_newlambda_jt03_[inchbin] = new TH2D(Form("hsignal_newlambda_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt0p33_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt0p53_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve lambda
      hnlambda_jt03_pm_[inchbin] = new TH1D(Form("hnlambda_jt03_pm_%d", inchbin), "", 2, 0., 2.);
      hnlambda_jt0p33_pm_[inchbin] = new TH1D(Form("hnlambda_jt0p33_pm_%d", inchbin), "", 2, 0., 2.);
      hnlambda_jt0p53_pm_[inchbin] = new TH1D(Form("hnlambda_jt0p53_pm_%d", inchbin), "", 2, 0., 2.);

      hsignal_newlambda_jt03_pp_[inchbin] = new TH2D(Form("hsignal_newlambda_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt03_mm_[inchbin] = new TH2D(Form("hsignal_newlambda_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt03_pm_[inchbin] = new TH2D(Form("hsignal_newlambda_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt03_mp_[inchbin] = new TH2D(Form("hsignal_newlambda_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newlambda_jt0p33_pp_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt0p33_mm_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt0p33_pm_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt0p33_mp_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hsignal_newlambda_jt0p53_pp_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt0p53_mm_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt0p53_pm_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hsignal_newlambda_jt0p53_mp_[inchbin] = new TH2D(Form("hsignal_newlambda_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      // mixing
      hmixing_newchtrk_jt03_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt0p33_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt0p53_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve charge tracks
      hmixing_newchtrk_jt03_pp_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt03_mm_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt03_pm_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt03_mp_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newchtrk_jt0p33_pp_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt0p33_mm_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt0p33_pm_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt0p33_mp_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newchtrk_jt0p53_pp_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt0p53_mm_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt0p53_pm_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newchtrk_jt0p53_mp_[inchbin] = new TH2D(Form("hmixing_newchtrk_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      

      //pion
      hmixing_newpion_jt03_[inchbin] = new TH2D(Form("hmixing_newpion_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt0p33_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt0p53_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve pion
      hmixing_newpion_jt03_pp_[inchbin] = new TH2D(Form("hmixing_newpion_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt03_mm_[inchbin] = new TH2D(Form("hmixing_newpion_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt03_pm_[inchbin] = new TH2D(Form("hmixing_newpion_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt03_mp_[inchbin] = new TH2D(Form("hmixing_newpion_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newpion_jt0p33_pp_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt0p33_mm_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt0p33_pm_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt0p33_mp_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newpion_jt0p53_pp_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt0p53_mm_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt0p53_pm_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newpion_jt0p53_mp_[inchbin] = new TH2D(Form("hmixing_newpion_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      //kaon
      hmixing_newkaon_jt03_[inchbin] = new TH2D(Form("hmixing_newkaon_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt0p33_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt0p53_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve kaon
      hmixing_newkaon_jt03_pp_[inchbin] = new TH2D(Form("hmixing_newkaon_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt03_mm_[inchbin] = new TH2D(Form("hmixing_newkaon_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt03_pm_[inchbin] = new TH2D(Form("hmixing_newkaon_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt03_mp_[inchbin] = new TH2D(Form("hmixing_newkaon_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newkaon_jt0p33_pp_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt0p33_mm_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt0p33_pm_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt0p33_mp_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newkaon_jt0p53_pp_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt0p53_mm_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt0p53_pm_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newkaon_jt0p53_mp_[inchbin] = new TH2D(Form("hmixing_newkaon_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      //proton
      hmixing_newproton_jt03_[inchbin] = new TH2D(Form("hmixing_newproton_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt0p33_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt0p53_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve proton
      hmixing_newproton_jt03_pp_[inchbin] = new TH2D(Form("hmixing_newproton_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt03_mm_[inchbin] = new TH2D(Form("hmixing_newproton_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt03_pm_[inchbin] = new TH2D(Form("hmixing_newproton_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt03_mp_[inchbin] = new TH2D(Form("hmixing_newproton_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newproton_jt0p33_pp_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt0p33_mm_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt0p33_pm_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt0p33_mp_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newproton_jt0p53_pp_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt0p53_mm_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt0p53_pm_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newproton_jt0p53_mp_[inchbin] = new TH2D(Form("hmixing_newproton_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      //lambda
      hmixing_newlambda_jt03_[inchbin] = new TH2D(Form("hmixing_newlambda_jt03_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt0p33_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p33_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt0p53_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p53_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());

      // +ve and -ve lambda
      hmixing_newlambda_jt03_pp_[inchbin] = new TH2D(Form("hmixing_newlambda_jt03_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt03_mm_[inchbin] = new TH2D(Form("hmixing_newlambda_jt03_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt03_pm_[inchbin] = new TH2D(Form("hmixing_newlambda_jt03_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt03_mp_[inchbin] = new TH2D(Form("hmixing_newlambda_jt03_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newlambda_jt0p33_pp_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p33_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt0p33_mm_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p33_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt0p33_pm_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p33_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt0p33_mp_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p33_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      
      hmixing_newlambda_jt0p53_pp_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p53_pp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt0p53_mm_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p53_mm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt0p53_pm_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p53_pm_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
      hmixing_newlambda_jt0p53_mp_[inchbin] = new TH2D(Form("hmixing_newlambda_jt0p53_mp_%d", inchbin), "", 79, -12, 12, 33, -0.5*TMath::Pi(), 1.5*TMath::Pi());
    }
}

void sumw2()
{
  // event histo
  hntrkTotal->Sumw2();
  hpthat->Sumw2();
  hpthatw->Sumw2();
  hsubprocessid->Sumw2();
  hnjets->Sumw2();
  hnjets_afterCut->Sumw2();

  // Jets histo
  hjet_pt->Sumw2();
  hjet_eta->Sumw2();
  hjet_phi->Sumw2();
  hJet_ntrk->Sumw2();
  hJet_nchtrk->Sumw2();
  hJet_nchtrk_pT->Sumw2();
  for(int inchbin = 0; inchbin < nch_bin; inchbin++)
    {
      hJet_nchtrk_[inchbin]->Sumw2();
    }
  
  // track histo
  //all tracks
  halltrk_pt->Sumw2();
  halltrk_eta->Sumw2();
  halltrk_phi->Sumw2();
  halltrk_pt_jetaxis->Sumw2();
  halltrk_eta_jetaxis->Sumw2();
  halltrk_phi_jetaxis->Sumw2();
  //charge tracks
  hchtrk_pt->Sumw2();
  hchtrk_eta->Sumw2();
  hchtrk_phi->Sumw2();
  hchtrk_pt_jetaxis->Sumw2();
  hchtrk_eta_jetaxis->Sumw2();
  hchtrk_phi_jetaxis->Sumw2();

  // +ve charge tracks
  hchtrk_pt_p->Sumw2();
  hchtrk_eta_p->Sumw2();
  hchtrk_phi_p->Sumw2();
  hchtrk_pt_jetaxis_p->Sumw2();
  hchtrk_eta_jetaxis_p->Sumw2();
  hchtrk_phi_jetaxis_p->Sumw2();

  // -ve charge tracks
  hchtrk_pt_m->Sumw2();
  hchtrk_eta_m->Sumw2();
  hchtrk_phi_m->Sumw2();
  hchtrk_pt_jetaxis_m->Sumw2();
  hchtrk_eta_jetaxis_m->Sumw2();
  hchtrk_phi_jetaxis_m->Sumw2();
  
  //pion
  hpion_pt->Sumw2();
  hpion_eta->Sumw2();
  hpion_phi->Sumw2();
  hpion_pt_jetaxis->Sumw2();
  hpion_eta_jetaxis->Sumw2();
  hpion_phi_jetaxis->Sumw2();

  // +ve pion
  hpion_pt_p->Sumw2();
  hpion_eta_p->Sumw2();
  hpion_phi_p->Sumw2();
  hpion_pt_jetaxis_p->Sumw2();
  hpion_eta_jetaxis_p->Sumw2();
  hpion_phi_jetaxis_p->Sumw2();

  // -ve pion
  hpion_pt_m->Sumw2();
  hpion_eta_m->Sumw2();
  hpion_phi_m->Sumw2();
  hpion_pt_jetaxis_m->Sumw2();
  hpion_eta_jetaxis_m->Sumw2();
  hpion_phi_jetaxis_m->Sumw2();

  //kaon
  hkaon_pt->Sumw2();
  hkaon_eta->Sumw2();
  hkaon_phi->Sumw2();
  hkaon_pt_jetaxis->Sumw2();
  hkaon_eta_jetaxis->Sumw2();
  hkaon_phi_jetaxis->Sumw2();

  // +ve kaon
  hkaon_pt_p->Sumw2();
  hkaon_eta_p->Sumw2();
  hkaon_phi_p->Sumw2();
  hkaon_pt_jetaxis_p->Sumw2();
  hkaon_eta_jetaxis_p->Sumw2();
  hkaon_phi_jetaxis_p->Sumw2();

  // -ve kaon
  hkaon_pt_m->Sumw2();
  hkaon_eta_m->Sumw2();
  hkaon_phi_m->Sumw2();
  hkaon_pt_jetaxis_m->Sumw2();
  hkaon_eta_jetaxis_m->Sumw2();
  hkaon_phi_jetaxis_m->Sumw2();

  //proton
  hproton_pt->Sumw2();
  hproton_eta->Sumw2();
  hproton_phi->Sumw2();
  hproton_pt_jetaxis->Sumw2();
  hproton_eta_jetaxis->Sumw2();
  hproton_phi_jetaxis->Sumw2();

  // +ve proton
  hproton_pt_p->Sumw2();
  hproton_eta_p->Sumw2();
  hproton_phi_p->Sumw2();
  hproton_pt_jetaxis_p->Sumw2();
  hproton_eta_jetaxis_p->Sumw2();
  hproton_phi_jetaxis_p->Sumw2();

  // -ve proton
  hproton_pt_m->Sumw2();
  hproton_eta_m->Sumw2();
  hproton_phi_m->Sumw2();
  hproton_pt_jetaxis_m->Sumw2();
  hproton_eta_jetaxis_m->Sumw2();
  hproton_phi_jetaxis_m->Sumw2();

  //lambda                                                                                                                                      
  hlambda_pt->Sumw2();
  hlambda_eta->Sumw2();
  hlambda_phi->Sumw2();
  hlambda_pt_jetaxis->Sumw2();
  hlambda_eta_jetaxis->Sumw2();
  hlambda_phi_jetaxis->Sumw2();
  
  // +ve lambda
  hlambda_pt_p->Sumw2();
  hlambda_eta_p->Sumw2();
  hlambda_phi_p->Sumw2();
  hlambda_pt_jetaxis_p->Sumw2();
  hlambda_eta_jetaxis_p->Sumw2();
  hlambda_phi_jetaxis_p->Sumw2();

  // -ve lambda
  hlambda_pt_m->Sumw2();
  hlambda_eta_m->Sumw2();
  hlambda_phi_m->Sumw2();
  hlambda_pt_jetaxis_m->Sumw2();
  hlambda_eta_jetaxis_m->Sumw2();
  hlambda_phi_jetaxis_m->Sumw2();

  // correlation 
  //signal histo
  hnchtrk_jt03->Sumw2();
  hnchtrk_jt0p33->Sumw2();
  hnchtrk_jt0p53->Sumw2();
  hsignal_newchtrk_jt03->Sumw2();
  hsignal_newchtrk_jt0p33->Sumw2();
  hsignal_newchtrk_jt0p53->Sumw2();

  // +ve and -ve charge tracks
  hnchtrk_jt03_pm->Sumw2();
  hnchtrk_jt0p33_pm->Sumw2();
  hnchtrk_jt0p53_pm->Sumw2();

  hsignal_newchtrk_jt03_pp->Sumw2();
  hsignal_newchtrk_jt03_mm->Sumw2();
  hsignal_newchtrk_jt03_pm->Sumw2();
  hsignal_newchtrk_jt03_mp->Sumw2();
  
  hsignal_newchtrk_jt0p33_pp->Sumw2();
  hsignal_newchtrk_jt0p33_mm->Sumw2();
  hsignal_newchtrk_jt0p33_pm->Sumw2();
  hsignal_newchtrk_jt0p33_mp->Sumw2();
  
  hsignal_newchtrk_jt0p53_pp->Sumw2();
  hsignal_newchtrk_jt0p53_mm->Sumw2();
  hsignal_newchtrk_jt0p53_pm->Sumw2();
  hsignal_newchtrk_jt0p53_mp->Sumw2();
      
  //pion
  hnpion_jt03->Sumw2();
  hnpion_jt0p33->Sumw2();
  hnpion_jt0p53->Sumw2();
  hsignal_newpion_jt03->Sumw2();
  hsignal_newpion_jt0p33->Sumw2();
  hsignal_newpion_jt0p53->Sumw2();

  // +ve and -ve pion
  hnpion_jt03_pm->Sumw2();
  hnpion_jt0p33_pm->Sumw2();
  hnpion_jt0p53_pm->Sumw2();

  hsignal_newpion_jt03_pp->Sumw2();
  hsignal_newpion_jt03_mm->Sumw2();
  hsignal_newpion_jt03_pm->Sumw2();
  hsignal_newpion_jt03_mp->Sumw2();
  
  hsignal_newpion_jt0p33_pp->Sumw2();
  hsignal_newpion_jt0p33_mm->Sumw2();
  hsignal_newpion_jt0p33_pm->Sumw2();
  hsignal_newpion_jt0p33_mp->Sumw2();
  
  hsignal_newpion_jt0p53_pp->Sumw2();
  hsignal_newpion_jt0p53_mm->Sumw2();
  hsignal_newpion_jt0p53_pm->Sumw2();
  hsignal_newpion_jt0p53_mp->Sumw2();

  //kaon                                                                                                                                           
  hnkaon_jt03->Sumw2();
  hnkaon_jt0p33->Sumw2();
  hnkaon_jt0p53->Sumw2();
  hsignal_newkaon_jt03->Sumw2();
  hsignal_newkaon_jt0p33->Sumw2();
  hsignal_newkaon_jt0p53->Sumw2();

  // +ve and -ve kaon
  hnkaon_jt03_pm->Sumw2();
  hnkaon_jt0p33_pm->Sumw2();
  hnkaon_jt0p53_pm->Sumw2();

  hsignal_newkaon_jt03_pp->Sumw2();
  hsignal_newkaon_jt03_mm->Sumw2();
  hsignal_newkaon_jt03_pm->Sumw2();
  hsignal_newkaon_jt03_mp->Sumw2();
  
  hsignal_newkaon_jt0p33_pp->Sumw2();
  hsignal_newkaon_jt0p33_mm->Sumw2();
  hsignal_newkaon_jt0p33_pm->Sumw2();
  hsignal_newkaon_jt0p33_mp->Sumw2();
  
  hsignal_newkaon_jt0p53_pp->Sumw2();
  hsignal_newkaon_jt0p53_mm->Sumw2();
  hsignal_newkaon_jt0p53_pm->Sumw2();
  hsignal_newkaon_jt0p53_mp->Sumw2();

  //proton                                                                                                                                       
  hnproton_jt03->Sumw2();
  hnproton_jt0p33->Sumw2();
  hnproton_jt0p53->Sumw2();
  hsignal_newproton_jt03->Sumw2();
  hsignal_newproton_jt0p33->Sumw2();
  hsignal_newproton_jt0p53->Sumw2();

  // +ve and -ve proton
  hnproton_jt03_pm->Sumw2();
  hnproton_jt0p33_pm->Sumw2();
  hnproton_jt0p53_pm->Sumw2();

  hsignal_newproton_jt03_pp->Sumw2();
  hsignal_newproton_jt03_mm->Sumw2();
  hsignal_newproton_jt03_pm->Sumw2();
  hsignal_newproton_jt03_mp->Sumw2();
  
  hsignal_newproton_jt0p33_pp->Sumw2();
  hsignal_newproton_jt0p33_mm->Sumw2();
  hsignal_newproton_jt0p33_pm->Sumw2();
  hsignal_newproton_jt0p33_mp->Sumw2();
  
  hsignal_newproton_jt0p53_pp->Sumw2();
  hsignal_newproton_jt0p53_mm->Sumw2();
  hsignal_newproton_jt0p53_pm->Sumw2();
  hsignal_newproton_jt0p53_mp->Sumw2();

  //lambda                                                                                                                                              
  hnlambda_jt03->Sumw2();
  hnlambda_jt0p33->Sumw2();
  hnlambda_jt0p53->Sumw2();
  hsignal_newlambda_jt03->Sumw2();
  hsignal_newlambda_jt0p33->Sumw2();
  hsignal_newlambda_jt0p53->Sumw2();

  // +ve and -ve lambda
  hnlambda_jt03_pm->Sumw2();
  hnlambda_jt0p33_pm->Sumw2();
  hnlambda_jt0p53_pm->Sumw2();

  hsignal_newlambda_jt03_pp->Sumw2();
  hsignal_newlambda_jt03_mm->Sumw2();
  hsignal_newlambda_jt03_pm->Sumw2();
  hsignal_newlambda_jt03_mp->Sumw2();
  
  hsignal_newlambda_jt0p33_pp->Sumw2();
  hsignal_newlambda_jt0p33_mm->Sumw2();
  hsignal_newlambda_jt0p33_pm->Sumw2();
  hsignal_newlambda_jt0p33_mp->Sumw2();
  
  hsignal_newlambda_jt0p53_pp->Sumw2();
  hsignal_newlambda_jt0p53_mm->Sumw2();
  hsignal_newlambda_jt0p53_pm->Sumw2();
  hsignal_newlambda_jt0p53_mp->Sumw2();

  for(int inchbin = 0; inchbin < nch_bin; inchbin++)
    {
      // all charge tracks
      hnchtrk_jt03_[inchbin]->Sumw2();
      hnchtrk_jt0p33_[inchbin]->Sumw2();
      hnchtrk_jt0p53_[inchbin]->Sumw2();
      hsignal_newchtrk_jt03_[inchbin]->Sumw2();
      hsignal_newchtrk_jt0p33_[inchbin]->Sumw2();
      hsignal_newchtrk_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve charge tracks
      hnchtrk_jt03_pm_[inchbin]->Sumw2();
      hnchtrk_jt0p33_pm_[inchbin]->Sumw2();
      hnchtrk_jt0p53_pm_[inchbin]->Sumw2();

      hsignal_newchtrk_jt03_pp_[inchbin]->Sumw2();
      hsignal_newchtrk_jt03_mm_[inchbin]->Sumw2();
      hsignal_newchtrk_jt03_pm_[inchbin]->Sumw2();
      hsignal_newchtrk_jt03_mp_[inchbin]->Sumw2();

      hsignal_newchtrk_jt0p33_pp_[inchbin]->Sumw2();
      hsignal_newchtrk_jt0p33_mm_[inchbin]->Sumw2();
      hsignal_newchtrk_jt0p33_pm_[inchbin]->Sumw2();
      hsignal_newchtrk_jt0p33_mp_[inchbin]->Sumw2();
      
      hsignal_newchtrk_jt0p53_pp_[inchbin]->Sumw2();
      hsignal_newchtrk_jt0p53_mm_[inchbin]->Sumw2();
      hsignal_newchtrk_jt0p53_pm_[inchbin]->Sumw2();
      hsignal_newchtrk_jt0p53_mp_[inchbin]->Sumw2();

      //pion
      hnpion_jt03_[inchbin]->Sumw2();
      hnpion_jt0p33_[inchbin]->Sumw2();
      hnpion_jt0p53_[inchbin]->Sumw2();
      hsignal_newpion_jt03_[inchbin]->Sumw2();
      hsignal_newpion_jt0p33_[inchbin]->Sumw2();
      hsignal_newpion_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve pion
      hnpion_jt03_pm_[inchbin]->Sumw2();
      hnpion_jt0p33_pm_[inchbin]->Sumw2();
      hnpion_jt0p53_pm_[inchbin]->Sumw2();

      hsignal_newpion_jt03_pp_[inchbin]->Sumw2();
      hsignal_newpion_jt03_mm_[inchbin]->Sumw2();
      hsignal_newpion_jt03_pm_[inchbin]->Sumw2();
      hsignal_newpion_jt03_mp_[inchbin]->Sumw2();

      hsignal_newpion_jt0p33_pp_[inchbin]->Sumw2();
      hsignal_newpion_jt0p33_mm_[inchbin]->Sumw2();
      hsignal_newpion_jt0p33_pm_[inchbin]->Sumw2();
      hsignal_newpion_jt0p33_mp_[inchbin]->Sumw2();
      
      hsignal_newpion_jt0p53_pp_[inchbin]->Sumw2();
      hsignal_newpion_jt0p53_mm_[inchbin]->Sumw2();
      hsignal_newpion_jt0p53_pm_[inchbin]->Sumw2();
      hsignal_newpion_jt0p53_mp_[inchbin]->Sumw2();
            

      //kaon
      hnkaon_jt03_[inchbin]->Sumw2();
      hnkaon_jt0p33_[inchbin]->Sumw2();
      hnkaon_jt0p53_[inchbin]->Sumw2();
      hsignal_newkaon_jt03_[inchbin]->Sumw2();
      hsignal_newkaon_jt0p33_[inchbin]->Sumw2();
      hsignal_newkaon_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve kaon
      hnkaon_jt03_pm_[inchbin]->Sumw2();
      hnkaon_jt0p33_pm_[inchbin]->Sumw2();
      hnkaon_jt0p53_pm_[inchbin]->Sumw2();

      hsignal_newkaon_jt03_pp_[inchbin]->Sumw2();
      hsignal_newkaon_jt03_mm_[inchbin]->Sumw2();
      hsignal_newkaon_jt03_pm_[inchbin]->Sumw2();
      hsignal_newkaon_jt03_mp_[inchbin]->Sumw2();

      hsignal_newkaon_jt0p33_pp_[inchbin]->Sumw2();
      hsignal_newkaon_jt0p33_mm_[inchbin]->Sumw2();
      hsignal_newkaon_jt0p33_pm_[inchbin]->Sumw2();
      hsignal_newkaon_jt0p33_mp_[inchbin]->Sumw2();
      
      hsignal_newkaon_jt0p53_pp_[inchbin]->Sumw2();
      hsignal_newkaon_jt0p53_mm_[inchbin]->Sumw2();
      hsignal_newkaon_jt0p53_pm_[inchbin]->Sumw2();
      hsignal_newkaon_jt0p53_mp_[inchbin]->Sumw2();
            

      //proton
      hnproton_jt03_[inchbin]->Sumw2();
      hnproton_jt0p33_[inchbin]->Sumw2();
      hnproton_jt0p53_[inchbin]->Sumw2();
      hsignal_newproton_jt03_[inchbin]->Sumw2();
      hsignal_newproton_jt0p33_[inchbin]->Sumw2();
      hsignal_newproton_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve proton
      hnproton_jt03_pm_[inchbin]->Sumw2();
      hnproton_jt0p33_pm_[inchbin]->Sumw2();
      hnproton_jt0p53_pm_[inchbin]->Sumw2();

      hsignal_newproton_jt03_pp_[inchbin]->Sumw2();
      hsignal_newproton_jt03_mm_[inchbin]->Sumw2();
      hsignal_newproton_jt03_pm_[inchbin]->Sumw2();
      hsignal_newproton_jt03_mp_[inchbin]->Sumw2();

      hsignal_newproton_jt0p33_pp_[inchbin]->Sumw2();
      hsignal_newproton_jt0p33_mm_[inchbin]->Sumw2();
      hsignal_newproton_jt0p33_pm_[inchbin]->Sumw2();
      hsignal_newproton_jt0p33_mp_[inchbin]->Sumw2();
      
      hsignal_newproton_jt0p53_pp_[inchbin]->Sumw2();
      hsignal_newproton_jt0p53_mm_[inchbin]->Sumw2();
      hsignal_newproton_jt0p53_pm_[inchbin]->Sumw2();
      hsignal_newproton_jt0p53_mp_[inchbin]->Sumw2();
            

      //lambda
      hnlambda_jt03_[inchbin]->Sumw2();
      hnlambda_jt0p33_[inchbin]->Sumw2();
      hnlambda_jt0p53_[inchbin]->Sumw2();
      hsignal_newlambda_jt03_[inchbin]->Sumw2();
      hsignal_newlambda_jt0p33_[inchbin]->Sumw2();
      hsignal_newlambda_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve lambda
      hnlambda_jt03_pm_[inchbin]->Sumw2();
      hnlambda_jt0p33_pm_[inchbin]->Sumw2();
      hnlambda_jt0p53_pm_[inchbin]->Sumw2();

      hsignal_newlambda_jt03_pp_[inchbin]->Sumw2();
      hsignal_newlambda_jt03_mm_[inchbin]->Sumw2();
      hsignal_newlambda_jt03_pm_[inchbin]->Sumw2();
      hsignal_newlambda_jt03_mp_[inchbin]->Sumw2();

      hsignal_newlambda_jt0p33_pp_[inchbin]->Sumw2();
      hsignal_newlambda_jt0p33_mm_[inchbin]->Sumw2();
      hsignal_newlambda_jt0p33_pm_[inchbin]->Sumw2();
      hsignal_newlambda_jt0p33_mp_[inchbin]->Sumw2();
      
      hsignal_newlambda_jt0p53_pp_[inchbin]->Sumw2();
      hsignal_newlambda_jt0p53_mm_[inchbin]->Sumw2();
      hsignal_newlambda_jt0p53_pm_[inchbin]->Sumw2();
      hsignal_newlambda_jt0p53_mp_[inchbin]->Sumw2();
            
    }
  // mixing histo
  hmixing_newchtrk_jt03->Sumw2();
  hmixing_newchtrk_jt0p33->Sumw2();
  hmixing_newchtrk_jt0p53->Sumw2();
  
  // +ve and -ve charge tracks
  hmixing_newchtrk_jt03_pp->Sumw2();
  hmixing_newchtrk_jt03_mm->Sumw2();
  hmixing_newchtrk_jt03_pm->Sumw2();
  hmixing_newchtrk_jt03_mp->Sumw2();

  hmixing_newchtrk_jt0p33_pp->Sumw2();
  hmixing_newchtrk_jt0p33_mm->Sumw2();
  hmixing_newchtrk_jt0p33_pm->Sumw2();
  hmixing_newchtrk_jt0p33_mp->Sumw2();

  hmixing_newchtrk_jt0p53_pp->Sumw2();
  hmixing_newchtrk_jt0p53_mm->Sumw2();
  hmixing_newchtrk_jt0p53_pm->Sumw2();
  hmixing_newchtrk_jt0p53_mp->Sumw2();

  //pion
  hmixing_newpion_jt03->Sumw2();
  hmixing_newpion_jt0p33->Sumw2();
  hmixing_newpion_jt0p53->Sumw2();

  // +ve and -ve pion
  hmixing_newpion_jt03_pp->Sumw2();
  hmixing_newpion_jt03_mm->Sumw2();
  hmixing_newpion_jt03_pm->Sumw2();
  hmixing_newpion_jt03_mp->Sumw2();

  hmixing_newpion_jt0p33_pp->Sumw2();
  hmixing_newpion_jt0p33_mm->Sumw2();
  hmixing_newpion_jt0p33_pm->Sumw2();
  hmixing_newpion_jt0p33_mp->Sumw2();

  hmixing_newpion_jt0p53_pp->Sumw2();
  hmixing_newpion_jt0p53_mm->Sumw2();
  hmixing_newpion_jt0p53_pm->Sumw2();
  hmixing_newpion_jt0p53_mp->Sumw2();

  //kaon                                                                                                                                           
  hmixing_newkaon_jt03->Sumw2();
  hmixing_newkaon_jt0p33->Sumw2();
  hmixing_newkaon_jt0p53->Sumw2();

  // +ve and -ve kaon
  hmixing_newkaon_jt03_pp->Sumw2();
  hmixing_newkaon_jt03_mm->Sumw2();
  hmixing_newkaon_jt03_pm->Sumw2();
  hmixing_newkaon_jt03_mp->Sumw2();

  hmixing_newkaon_jt0p33_pp->Sumw2();
  hmixing_newkaon_jt0p33_mm->Sumw2();
  hmixing_newkaon_jt0p33_pm->Sumw2();
  hmixing_newkaon_jt0p33_mp->Sumw2();

  hmixing_newkaon_jt0p53_pp->Sumw2();
  hmixing_newkaon_jt0p53_mm->Sumw2();
  hmixing_newkaon_jt0p53_pm->Sumw2();
  hmixing_newkaon_jt0p53_mp->Sumw2();

  //proton                                                                                                                                       
  hmixing_newproton_jt03->Sumw2();
  hmixing_newproton_jt0p33->Sumw2();
  hmixing_newproton_jt0p53->Sumw2();

  // +ve and -ve proton
  hmixing_newproton_jt03_pp->Sumw2();
  hmixing_newproton_jt03_mm->Sumw2();
  hmixing_newproton_jt03_pm->Sumw2();
  hmixing_newproton_jt03_mp->Sumw2();

  hmixing_newproton_jt0p33_pp->Sumw2();
  hmixing_newproton_jt0p33_mm->Sumw2();
  hmixing_newproton_jt0p33_pm->Sumw2();
  hmixing_newproton_jt0p33_mp->Sumw2();

  hmixing_newproton_jt0p53_pp->Sumw2();
  hmixing_newproton_jt0p53_mm->Sumw2();
  hmixing_newproton_jt0p53_pm->Sumw2();
  hmixing_newproton_jt0p53_mp->Sumw2();

  //lambda                                                                                                                                              
  hmixing_newlambda_jt03->Sumw2();
  hmixing_newlambda_jt0p33->Sumw2();
  hmixing_newlambda_jt0p53->Sumw2();

  // +ve and -ve lambda
  hmixing_newlambda_jt03_pp->Sumw2();
  hmixing_newlambda_jt03_mm->Sumw2();
  hmixing_newlambda_jt03_pm->Sumw2();
  hmixing_newlambda_jt03_mp->Sumw2();

  hmixing_newlambda_jt0p33_pp->Sumw2();
  hmixing_newlambda_jt0p33_mm->Sumw2();
  hmixing_newlambda_jt0p33_pm->Sumw2();
  hmixing_newlambda_jt0p33_mp->Sumw2();

  hmixing_newlambda_jt0p53_pp->Sumw2();
  hmixing_newlambda_jt0p53_mm->Sumw2();
  hmixing_newlambda_jt0p53_pm->Sumw2();
  hmixing_newlambda_jt0p53_mp->Sumw2();

  for(int inchbin = 0; inchbin < nch_bin; inchbin++)
    {
      hmixing_newchtrk_jt03_[inchbin]->Sumw2();
      hmixing_newchtrk_jt0p33_[inchbin]->Sumw2();
      hmixing_newchtrk_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve charge tracks
      hmixing_newchtrk_jt03_pp_[inchbin]->Sumw2();
      hmixing_newchtrk_jt03_mm_[inchbin]->Sumw2();
      hmixing_newchtrk_jt03_pm_[inchbin]->Sumw2();
      hmixing_newchtrk_jt03_mp_[inchbin]->Sumw2();

      hmixing_newchtrk_jt0p33_pp_[inchbin]->Sumw2();
      hmixing_newchtrk_jt0p33_mm_[inchbin]->Sumw2();
      hmixing_newchtrk_jt0p33_pm_[inchbin]->Sumw2();
      hmixing_newchtrk_jt0p33_mp_[inchbin]->Sumw2();
      
      hmixing_newchtrk_jt0p53_pp_[inchbin]->Sumw2();
      hmixing_newchtrk_jt0p53_mm_[inchbin]->Sumw2();
      hmixing_newchtrk_jt0p53_pm_[inchbin]->Sumw2();
      hmixing_newchtrk_jt0p53_mp_[inchbin]->Sumw2();

      //pion
      hmixing_newpion_jt03_[inchbin]->Sumw2();
      hmixing_newpion_jt0p33_[inchbin]->Sumw2();
      hmixing_newpion_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve pion
      hmixing_newpion_jt03_pp_[inchbin]->Sumw2();
      hmixing_newpion_jt03_mm_[inchbin]->Sumw2();
      hmixing_newpion_jt03_pm_[inchbin]->Sumw2();
      hmixing_newpion_jt03_mp_[inchbin]->Sumw2();

      hmixing_newpion_jt0p33_pp_[inchbin]->Sumw2();
      hmixing_newpion_jt0p33_mm_[inchbin]->Sumw2();
      hmixing_newpion_jt0p33_pm_[inchbin]->Sumw2();
      hmixing_newpion_jt0p33_mp_[inchbin]->Sumw2();
      
      hmixing_newpion_jt0p53_pp_[inchbin]->Sumw2();
      hmixing_newpion_jt0p53_mm_[inchbin]->Sumw2();
      hmixing_newpion_jt0p53_pm_[inchbin]->Sumw2();
      hmixing_newpion_jt0p53_mp_[inchbin]->Sumw2();

      //kaon
      hmixing_newkaon_jt03_[inchbin]->Sumw2();
      hmixing_newkaon_jt0p33_[inchbin]->Sumw2();
      hmixing_newkaon_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve kaon
      hmixing_newkaon_jt03_pp_[inchbin]->Sumw2();
      hmixing_newkaon_jt03_mm_[inchbin]->Sumw2();
      hmixing_newkaon_jt03_pm_[inchbin]->Sumw2();
      hmixing_newkaon_jt03_mp_[inchbin]->Sumw2();

      hmixing_newkaon_jt0p33_pp_[inchbin]->Sumw2();
      hmixing_newkaon_jt0p33_mm_[inchbin]->Sumw2();
      hmixing_newkaon_jt0p33_pm_[inchbin]->Sumw2();
      hmixing_newkaon_jt0p33_mp_[inchbin]->Sumw2();
      
      hmixing_newkaon_jt0p53_pp_[inchbin]->Sumw2();
      hmixing_newkaon_jt0p53_mm_[inchbin]->Sumw2();
      hmixing_newkaon_jt0p53_pm_[inchbin]->Sumw2();
      hmixing_newkaon_jt0p53_mp_[inchbin]->Sumw2();

      //proton
      hmixing_newproton_jt03_[inchbin]->Sumw2();
      hmixing_newproton_jt0p33_[inchbin]->Sumw2();
      hmixing_newproton_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve proton
      hmixing_newproton_jt03_pp_[inchbin]->Sumw2();
      hmixing_newproton_jt03_mm_[inchbin]->Sumw2();
      hmixing_newproton_jt03_pm_[inchbin]->Sumw2();
      hmixing_newproton_jt03_mp_[inchbin]->Sumw2();

      hmixing_newproton_jt0p33_pp_[inchbin]->Sumw2();
      hmixing_newproton_jt0p33_mm_[inchbin]->Sumw2();
      hmixing_newproton_jt0p33_pm_[inchbin]->Sumw2();
      hmixing_newproton_jt0p33_mp_[inchbin]->Sumw2();
      
      hmixing_newproton_jt0p53_pp_[inchbin]->Sumw2();
      hmixing_newproton_jt0p53_mm_[inchbin]->Sumw2();
      hmixing_newproton_jt0p53_pm_[inchbin]->Sumw2();
      hmixing_newproton_jt0p53_mp_[inchbin]->Sumw2();


      //lambda
      hmixing_newlambda_jt03_[inchbin]->Sumw2();
      hmixing_newlambda_jt0p33_[inchbin]->Sumw2();
      hmixing_newlambda_jt0p53_[inchbin]->Sumw2();

      // +ve and -ve lambda
      hmixing_newlambda_jt03_pp_[inchbin]->Sumw2();
      hmixing_newlambda_jt03_mm_[inchbin]->Sumw2();
      hmixing_newlambda_jt03_pm_[inchbin]->Sumw2();
      hmixing_newlambda_jt03_mp_[inchbin]->Sumw2();

      hmixing_newlambda_jt0p33_pp_[inchbin]->Sumw2();
      hmixing_newlambda_jt0p33_mm_[inchbin]->Sumw2();
      hmixing_newlambda_jt0p33_pm_[inchbin]->Sumw2();
      hmixing_newlambda_jt0p33_mp_[inchbin]->Sumw2();
      
      hmixing_newlambda_jt0p53_pp_[inchbin]->Sumw2();
      hmixing_newlambda_jt0p53_mm_[inchbin]->Sumw2();
      hmixing_newlambda_jt0p53_pm_[inchbin]->Sumw2();
      hmixing_newlambda_jt0p53_mp_[inchbin]->Sumw2();

    }
}

void write_event_hist()
{
  hntrkTotal->Write();
  hpthat->Write();
  hpthatw->Write();
  hsubprocessid->Write();
  hnjets->Write();
  hnjets_afterCut->Write();
}

void write_jet_hist()
{
  hjet_pt->Write();
  hjet_eta->Write();
  hjet_phi->Write();
  hJet_ntrk->Write();
  hJet_nchtrk->Write();
  hJet_nchtrk_pT->Write();
  for(int inchbin = 0; inchbin < nch_bin; inchbin++)
    {
      hJet_nchtrk_[inchbin]->Write();
    }
  
}

void write_track_hist()
{
  //all tracks
  halltrk_pt->Write();
  halltrk_eta->Write();
  halltrk_phi->Write();
  halltrk_pt_jetaxis->Write();
  halltrk_eta_jetaxis->Write();
  halltrk_phi_jetaxis->Write();
  // charge tracks
  hchtrk_pt->Write();
  hchtrk_eta->Write();
  hchtrk_phi->Write();
  hchtrk_pt_jetaxis->Write();
  hchtrk_eta_jetaxis->Write();
  hchtrk_phi_jetaxis->Write();

  // +ve charge tracks
  hchtrk_pt_p->Write();
  hchtrk_eta_p->Write();
  hchtrk_phi_p->Write();
  hchtrk_pt_jetaxis_p->Write();
  hchtrk_eta_jetaxis_p->Write();
  hchtrk_phi_jetaxis_p->Write();

  // -ve charge tracks                                                                                                     
  hchtrk_pt_m->Write();
  hchtrk_eta_m->Write();
  hchtrk_phi_m->Write();
  hchtrk_pt_jetaxis_m->Write();
  hchtrk_eta_jetaxis_m->Write();
  hchtrk_phi_jetaxis_m->Write();

  //pion
  hpion_pt->Write();
  hpion_eta->Write();
  hpion_phi->Write();
  hpion_pt_jetaxis->Write();
  hpion_eta_jetaxis->Write();
  hpion_phi_jetaxis->Write();

  // +ve pion
  hpion_pt_p->Write();
  hpion_eta_p->Write();
  hpion_phi_p->Write();
  hpion_pt_jetaxis_p->Write();
  hpion_eta_jetaxis_p->Write();
  hpion_phi_jetaxis_p->Write();

  // -ve pion
  hpion_pt_m->Write();
  hpion_eta_m->Write();
  hpion_phi_m->Write();
  hpion_pt_jetaxis_m->Write();
  hpion_eta_jetaxis_m->Write();
  hpion_phi_jetaxis_m->Write();

  //kaon                                                                                                                                              
  hkaon_pt->Write();
  hkaon_eta->Write();
  hkaon_phi->Write();
  hkaon_pt_jetaxis->Write();
  hkaon_eta_jetaxis->Write();
  hkaon_phi_jetaxis->Write();

  // +ve kaon
  hkaon_pt_p->Write();
  hkaon_eta_p->Write();
  hkaon_phi_p->Write();
  hkaon_pt_jetaxis_p->Write();
  hkaon_eta_jetaxis_p->Write();
  hkaon_phi_jetaxis_p->Write();

  // -ve kaon
  hkaon_pt_m->Write();
  hkaon_eta_m->Write();
  hkaon_phi_m->Write();
  hkaon_pt_jetaxis_m->Write();
  hkaon_eta_jetaxis_m->Write();
  hkaon_phi_jetaxis_m->Write();

  //proton                                                                                                                                           
  hproton_pt->Write();
  hproton_eta->Write();
  hproton_phi->Write();
  hproton_pt_jetaxis->Write();
  hproton_eta_jetaxis->Write();
  hproton_phi_jetaxis->Write();

  // +ve proton
  hproton_pt_p->Write();
  hproton_eta_p->Write();
  hproton_phi_p->Write();
  hproton_pt_jetaxis_p->Write();
  hproton_eta_jetaxis_p->Write();
  hproton_phi_jetaxis_p->Write();

  // -ve proton
  hproton_pt_m->Write();
  hproton_eta_m->Write();
  hproton_phi_m->Write();
  hproton_pt_jetaxis_m->Write();
  hproton_eta_jetaxis_m->Write();
  hproton_phi_jetaxis_m->Write();


  //lambda                                                                                                                                           
  hlambda_pt->Write();
  hlambda_eta->Write();
  hlambda_phi->Write();
  hlambda_pt_jetaxis->Write();
  hlambda_eta_jetaxis->Write();
  hlambda_phi_jetaxis->Write();

  // +ve lambda
  hlambda_pt_p->Write();
  hlambda_eta_p->Write();
  hlambda_phi_p->Write();
  hlambda_pt_jetaxis_p->Write();
  hlambda_eta_jetaxis_p->Write();
  hlambda_phi_jetaxis_p->Write();

  // -ve lambda
  hlambda_pt_m->Write();
  hlambda_eta_m->Write();
  hlambda_phi_m->Write();
  hlambda_pt_jetaxis_m->Write();
  hlambda_eta_jetaxis_m->Write();
  hlambda_phi_jetaxis_m->Write();
}

void write_corr_hist()
{
  // signal histo
  hnchtrk_jt03->Write();
  hnchtrk_jt0p33->Write();
  hnchtrk_jt0p53->Write();
  hsignal_newchtrk_jt03->Write();
  hsignal_newchtrk_jt0p33->Write();
  hsignal_newchtrk_jt0p53->Write();

  // +ve and -ve charge tracks
  hnchtrk_jt03_pm->Write();
  hnchtrk_jt0p33_pm->Write();
  hnchtrk_jt0p53_pm->Write();

  hsignal_newchtrk_jt03_pp->Write();
  hsignal_newchtrk_jt03_mm->Write();
  hsignal_newchtrk_jt03_pm->Write();
  hsignal_newchtrk_jt03_mp->Write();

  hsignal_newchtrk_jt0p33_pp->Write();
  hsignal_newchtrk_jt0p33_mm->Write();
  hsignal_newchtrk_jt0p33_pm->Write();
  hsignal_newchtrk_jt0p33_mp->Write();

  hsignal_newchtrk_jt0p53_pp->Write();
  hsignal_newchtrk_jt0p53_mm->Write();
  hsignal_newchtrk_jt0p53_pm->Write();
  hsignal_newchtrk_jt0p53_mp->Write();

  //pion
  hnpion_jt03->Write();
  hnpion_jt0p33->Write();
  hnpion_jt0p53->Write();
  hsignal_newpion_jt03->Write();
  hsignal_newpion_jt0p33->Write();
  hsignal_newpion_jt0p53->Write();

  // +ve and -ve pion
  hnpion_jt03_pm->Write();
  hnpion_jt0p33_pm->Write();
  hnpion_jt0p53_pm->Write();

  hsignal_newpion_jt03_pp->Write();
  hsignal_newpion_jt03_mm->Write();
  hsignal_newpion_jt03_pm->Write();
  hsignal_newpion_jt03_mp->Write();

  hsignal_newpion_jt0p33_pp->Write();
  hsignal_newpion_jt0p33_mm->Write();
  hsignal_newpion_jt0p33_pm->Write();
  hsignal_newpion_jt0p33_mp->Write();

  hsignal_newpion_jt0p53_pp->Write();
  hsignal_newpion_jt0p53_mm->Write();
  hsignal_newpion_jt0p53_pm->Write();
  hsignal_newpion_jt0p53_mp->Write();

  //kaon                                                                                                                                           
  hnkaon_jt03->Write();
  hnkaon_jt0p33->Write();
  hnkaon_jt0p53->Write();
  hsignal_newkaon_jt03->Write();
  hsignal_newkaon_jt0p33->Write();
  hsignal_newkaon_jt0p53->Write();

  // +ve and -ve kaon
  hnkaon_jt03_pm->Write();
  hnkaon_jt0p33_pm->Write();
  hnkaon_jt0p53_pm->Write();

  hsignal_newkaon_jt03_pp->Write();
  hsignal_newkaon_jt03_mm->Write();
  hsignal_newkaon_jt03_pm->Write();
  hsignal_newkaon_jt03_mp->Write();

  hsignal_newkaon_jt0p33_pp->Write();
  hsignal_newkaon_jt0p33_mm->Write();
  hsignal_newkaon_jt0p33_pm->Write();
  hsignal_newkaon_jt0p33_mp->Write();

  hsignal_newkaon_jt0p53_pp->Write();
  hsignal_newkaon_jt0p53_mm->Write();
  hsignal_newkaon_jt0p53_pm->Write();
  hsignal_newkaon_jt0p53_mp->Write();

  //proton                                                                                                                                       
  hnproton_jt03->Write();
  hnproton_jt0p33->Write();
  hnproton_jt0p53->Write();
  hsignal_newproton_jt03->Write();
  hsignal_newproton_jt0p33->Write();
  hsignal_newproton_jt0p53->Write();

  // +ve and -ve proton
  hnproton_jt03_pm->Write();
  hnproton_jt0p33_pm->Write();
  hnproton_jt0p53_pm->Write();

  hsignal_newproton_jt03_pp->Write();
  hsignal_newproton_jt03_mm->Write();
  hsignal_newproton_jt03_pm->Write();
  hsignal_newproton_jt03_mp->Write();

  hsignal_newproton_jt0p33_pp->Write();
  hsignal_newproton_jt0p33_mm->Write();
  hsignal_newproton_jt0p33_pm->Write();
  hsignal_newproton_jt0p33_mp->Write();

  hsignal_newproton_jt0p53_pp->Write();
  hsignal_newproton_jt0p53_mm->Write();
  hsignal_newproton_jt0p53_pm->Write();
  hsignal_newproton_jt0p53_mp->Write();


  //lambda                                                                                                                                              
  hnlambda_jt03->Write();
  hnlambda_jt0p33->Write();
  hnlambda_jt0p53->Write();
  hsignal_newlambda_jt03->Write();
  hsignal_newlambda_jt0p33->Write();
  hsignal_newlambda_jt0p53->Write();
  
  // +ve and -ve lambda
  hnlambda_jt03_pm->Write();
  hnlambda_jt0p33_pm->Write();
  hnlambda_jt0p53_pm->Write();

  hsignal_newlambda_jt03_pp->Write();
  hsignal_newlambda_jt03_mm->Write();
  hsignal_newlambda_jt03_pm->Write();
  hsignal_newlambda_jt03_mp->Write();

  hsignal_newlambda_jt0p33_pp->Write();
  hsignal_newlambda_jt0p33_mm->Write();
  hsignal_newlambda_jt0p33_pm->Write();
  hsignal_newlambda_jt0p33_mp->Write();

  hsignal_newlambda_jt0p53_pp->Write();
  hsignal_newlambda_jt0p53_mm->Write();
  hsignal_newlambda_jt0p53_pm->Write();
  hsignal_newlambda_jt0p53_mp->Write();

  for(int inchbin = 0; inchbin < nch_bin; inchbin++)
    {
      // all charge tracks
      hnchtrk_jt03_[inchbin]->Write();
      hnchtrk_jt0p33_[inchbin]->Write();
      hnchtrk_jt0p53_[inchbin]->Write();
      hsignal_newchtrk_jt03_[inchbin]->Write();
      hsignal_newchtrk_jt0p33_[inchbin]->Write();
      hsignal_newchtrk_jt0p53_[inchbin]->Write();

      // +ve and -ve charge tracks
      hnchtrk_jt03_pm_[inchbin]->Write();
      hnchtrk_jt0p33_pm_[inchbin]->Write();
      hnchtrk_jt0p53_pm_[inchbin]->Write();

      hsignal_newchtrk_jt03_pp_[inchbin]->Write();
      hsignal_newchtrk_jt03_mm_[inchbin]->Write();
      hsignal_newchtrk_jt03_pm_[inchbin]->Write();
      hsignal_newchtrk_jt03_mp_[inchbin]->Write();

      hsignal_newchtrk_jt0p33_pp_[inchbin]->Write();
      hsignal_newchtrk_jt0p33_mm_[inchbin]->Write();
      hsignal_newchtrk_jt0p33_pm_[inchbin]->Write();
      hsignal_newchtrk_jt0p33_mp_[inchbin]->Write();

      hsignal_newchtrk_jt0p53_pp_[inchbin]->Write();
      hsignal_newchtrk_jt0p53_mm_[inchbin]->Write();
      hsignal_newchtrk_jt0p53_pm_[inchbin]->Write();
      hsignal_newchtrk_jt0p53_mp_[inchbin]->Write();

      //pion
      hnpion_jt03_[inchbin]->Write();
      hnpion_jt0p33_[inchbin]->Write();
      hnpion_jt0p53_[inchbin]->Write();
      hsignal_newpion_jt03_[inchbin]->Write();
      hsignal_newpion_jt0p33_[inchbin]->Write();
      hsignal_newpion_jt0p53_[inchbin]->Write();

      // +ve and -ve pion
      hnpion_jt03_pm_[inchbin]->Write();
      hnpion_jt0p33_pm_[inchbin]->Write();
      hnpion_jt0p53_pm_[inchbin]->Write();

      hsignal_newpion_jt03_pp_[inchbin]->Write();
      hsignal_newpion_jt03_mm_[inchbin]->Write();
      hsignal_newpion_jt03_pm_[inchbin]->Write();
      hsignal_newpion_jt03_mp_[inchbin]->Write();

      hsignal_newpion_jt0p33_pp_[inchbin]->Write();
      hsignal_newpion_jt0p33_mm_[inchbin]->Write();
      hsignal_newpion_jt0p33_pm_[inchbin]->Write();
      hsignal_newpion_jt0p33_mp_[inchbin]->Write();

      hsignal_newpion_jt0p53_pp_[inchbin]->Write();
      hsignal_newpion_jt0p53_mm_[inchbin]->Write();
      hsignal_newpion_jt0p53_pm_[inchbin]->Write();
      hsignal_newpion_jt0p53_mp_[inchbin]->Write();

      //kaon
      hnkaon_jt03_[inchbin]->Write();
      hnkaon_jt0p33_[inchbin]->Write();
      hnkaon_jt0p53_[inchbin]->Write();
      hsignal_newkaon_jt03_[inchbin]->Write();
      hsignal_newkaon_jt0p33_[inchbin]->Write();
      hsignal_newkaon_jt0p53_[inchbin]->Write();

      // +ve and -ve kaon
      hnkaon_jt03_pm_[inchbin]->Write();
      hnkaon_jt0p33_pm_[inchbin]->Write();
      hnkaon_jt0p53_pm_[inchbin]->Write();

      hsignal_newkaon_jt03_pp_[inchbin]->Write();
      hsignal_newkaon_jt03_mm_[inchbin]->Write();
      hsignal_newkaon_jt03_pm_[inchbin]->Write();
      hsignal_newkaon_jt03_mp_[inchbin]->Write();

      hsignal_newkaon_jt0p33_pp_[inchbin]->Write();
      hsignal_newkaon_jt0p33_mm_[inchbin]->Write();
      hsignal_newkaon_jt0p33_pm_[inchbin]->Write();
      hsignal_newkaon_jt0p33_mp_[inchbin]->Write();

      hsignal_newkaon_jt0p53_pp_[inchbin]->Write();
      hsignal_newkaon_jt0p53_mm_[inchbin]->Write();
      hsignal_newkaon_jt0p53_pm_[inchbin]->Write();
      hsignal_newkaon_jt0p53_mp_[inchbin]->Write();

      //proton
      hnproton_jt03_[inchbin]->Write();
      hnproton_jt0p33_[inchbin]->Write();
      hnproton_jt0p53_[inchbin]->Write();
      hsignal_newproton_jt03_[inchbin]->Write();
      hsignal_newproton_jt0p33_[inchbin]->Write();
      hsignal_newproton_jt0p53_[inchbin]->Write();

      // +ve and -ve proton
      hnproton_jt03_pm_[inchbin]->Write();
      hnproton_jt0p33_pm_[inchbin]->Write();
      hnproton_jt0p53_pm_[inchbin]->Write();

      hsignal_newproton_jt03_pp_[inchbin]->Write();
      hsignal_newproton_jt03_mm_[inchbin]->Write();
      hsignal_newproton_jt03_pm_[inchbin]->Write();
      hsignal_newproton_jt03_mp_[inchbin]->Write();

      hsignal_newproton_jt0p33_pp_[inchbin]->Write();
      hsignal_newproton_jt0p33_mm_[inchbin]->Write();
      hsignal_newproton_jt0p33_pm_[inchbin]->Write();
      hsignal_newproton_jt0p33_mp_[inchbin]->Write();

      hsignal_newproton_jt0p53_pp_[inchbin]->Write();
      hsignal_newproton_jt0p53_mm_[inchbin]->Write();
      hsignal_newproton_jt0p53_pm_[inchbin]->Write();
      hsignal_newproton_jt0p53_mp_[inchbin]->Write();

      //lambda
      hnlambda_jt03_[inchbin]->Write();
      hnlambda_jt0p33_[inchbin]->Write();
      hnlambda_jt0p53_[inchbin]->Write();
      hsignal_newlambda_jt03_[inchbin]->Write();
      hsignal_newlambda_jt0p33_[inchbin]->Write();
      hsignal_newlambda_jt0p53_[inchbin]->Write();

      // +ve and -ve lambda
      hnlambda_jt03_pm_[inchbin]->Write();
      hnlambda_jt0p33_pm_[inchbin]->Write();
      hnlambda_jt0p53_pm_[inchbin]->Write();

      hsignal_newlambda_jt03_pp_[inchbin]->Write();
      hsignal_newlambda_jt03_mm_[inchbin]->Write();
      hsignal_newlambda_jt03_pm_[inchbin]->Write();
      hsignal_newlambda_jt03_mp_[inchbin]->Write();

      hsignal_newlambda_jt0p33_pp_[inchbin]->Write();
      hsignal_newlambda_jt0p33_mm_[inchbin]->Write();
      hsignal_newlambda_jt0p33_pm_[inchbin]->Write();
      hsignal_newlambda_jt0p33_mp_[inchbin]->Write();

      hsignal_newlambda_jt0p53_pp_[inchbin]->Write();
      hsignal_newlambda_jt0p53_mm_[inchbin]->Write();
      hsignal_newlambda_jt0p53_pm_[inchbin]->Write();
      hsignal_newlambda_jt0p53_mp_[inchbin]->Write();
    }
  
  // mixing histo
  hmixing_newchtrk_jt03->Write();
  hmixing_newchtrk_jt0p33->Write();
  hmixing_newchtrk_jt0p53->Write();

  // +ve and -ve charge tracks
  hmixing_newchtrk_jt03_pp->Write();
  hmixing_newchtrk_jt03_mm->Write();
  hmixing_newchtrk_jt03_pm->Write();
  hmixing_newchtrk_jt03_mp->Write();
  
  hmixing_newchtrk_jt0p33_pp->Write();
  hmixing_newchtrk_jt0p33_mm->Write();
  hmixing_newchtrk_jt0p33_pm->Write();
  hmixing_newchtrk_jt0p33_mp->Write();
  
  hmixing_newchtrk_jt0p53_pp->Write();
  hmixing_newchtrk_jt0p53_mm->Write();
  hmixing_newchtrk_jt0p53_pm->Write();
  hmixing_newchtrk_jt0p53_mp->Write();
  
  //pion
  hmixing_newpion_jt03->Write();
  hmixing_newpion_jt0p33->Write();
  hmixing_newpion_jt0p53->Write();

  // +ve and -ve pion
  hmixing_newpion_jt03_pp->Write();
  hmixing_newpion_jt03_mm->Write();
  hmixing_newpion_jt03_pm->Write();
  hmixing_newpion_jt03_mp->Write();
  
  hmixing_newpion_jt0p33_pp->Write();
  hmixing_newpion_jt0p33_mm->Write();
  hmixing_newpion_jt0p33_pm->Write();
  hmixing_newpion_jt0p33_mp->Write();
  
  hmixing_newpion_jt0p53_pp->Write();
  hmixing_newpion_jt0p53_mm->Write();
  hmixing_newpion_jt0p53_pm->Write();
  hmixing_newpion_jt0p53_mp->Write();
  
  //kaon                                                                                                                                           
  hmixing_newkaon_jt03->Write();
  hmixing_newkaon_jt0p33->Write();
  hmixing_newkaon_jt0p53->Write();

  // +ve and -ve kaon
  hmixing_newkaon_jt03_pp->Write();
  hmixing_newkaon_jt03_mm->Write();
  hmixing_newkaon_jt03_pm->Write();
  hmixing_newkaon_jt03_mp->Write();
  
  hmixing_newkaon_jt0p33_pp->Write();
  hmixing_newkaon_jt0p33_mm->Write();
  hmixing_newkaon_jt0p33_pm->Write();
  hmixing_newkaon_jt0p33_mp->Write();
  
  hmixing_newkaon_jt0p53_pp->Write();
  hmixing_newkaon_jt0p53_mm->Write();
  hmixing_newkaon_jt0p53_pm->Write();
  hmixing_newkaon_jt0p53_mp->Write();

  //proton                                                                                                                                       
  hmixing_newproton_jt03->Write();
  hmixing_newproton_jt0p33->Write();
  hmixing_newproton_jt0p53->Write();

  // +ve and -ve proton
  hmixing_newproton_jt03_pp->Write();
  hmixing_newproton_jt03_mm->Write();
  hmixing_newproton_jt03_pm->Write();
  hmixing_newproton_jt03_mp->Write();
  
  hmixing_newproton_jt0p33_pp->Write();
  hmixing_newproton_jt0p33_mm->Write();
  hmixing_newproton_jt0p33_pm->Write();
  hmixing_newproton_jt0p33_mp->Write();
  
  hmixing_newproton_jt0p53_pp->Write();
  hmixing_newproton_jt0p53_mm->Write();
  hmixing_newproton_jt0p53_pm->Write();
  hmixing_newproton_jt0p53_mp->Write();

  //lambda                                                                                                                                              
  hmixing_newlambda_jt03->Write();
  hmixing_newlambda_jt0p33->Write();
  hmixing_newlambda_jt0p53->Write();

  // +ve and -ve proton
  hmixing_newproton_jt03_pp->Write();
  hmixing_newproton_jt03_mm->Write();
  hmixing_newproton_jt03_pm->Write();
  hmixing_newproton_jt03_mp->Write();
  
  hmixing_newproton_jt0p33_pp->Write();
  hmixing_newproton_jt0p33_mm->Write();
  hmixing_newproton_jt0p33_pm->Write();
  hmixing_newproton_jt0p33_mp->Write();
  
  hmixing_newproton_jt0p53_pp->Write();
  hmixing_newproton_jt0p53_mm->Write();
  hmixing_newproton_jt0p53_pm->Write();
  hmixing_newproton_jt0p53_mp->Write();

  for(int inchbin = 0; inchbin < nch_bin; inchbin++)
    {
      hmixing_newchtrk_jt03_[inchbin]->Write();
      hmixing_newchtrk_jt0p33_[inchbin]->Write();
      hmixing_newchtrk_jt0p53_[inchbin]->Write();

      // +ve and -ve charge tracks
      hmixing_newchtrk_jt03_pp_[inchbin]->Write();
      hmixing_newchtrk_jt03_mm_[inchbin]->Write();
      hmixing_newchtrk_jt03_pm_[inchbin]->Write();
      hmixing_newchtrk_jt03_mp_[inchbin]->Write();

      hmixing_newchtrk_jt0p33_pp_[inchbin]->Write();
      hmixing_newchtrk_jt0p33_mm_[inchbin]->Write();
      hmixing_newchtrk_jt0p33_pm_[inchbin]->Write();
      hmixing_newchtrk_jt0p33_mp_[inchbin]->Write();

      hmixing_newchtrk_jt0p53_pp_[inchbin]->Write();
      hmixing_newchtrk_jt0p53_mm_[inchbin]->Write();
      hmixing_newchtrk_jt0p53_pm_[inchbin]->Write();
      hmixing_newchtrk_jt0p53_mp_[inchbin]->Write();

      //pion
      hmixing_newpion_jt03_[inchbin]->Write();
      hmixing_newpion_jt0p33_[inchbin]->Write();
      hmixing_newpion_jt0p53_[inchbin]->Write();

      // +ve and -ve pion
      hmixing_newpion_jt03_pp_[inchbin]->Write();
      hmixing_newpion_jt03_mm_[inchbin]->Write();
      hmixing_newpion_jt03_pm_[inchbin]->Write();
      hmixing_newpion_jt03_mp_[inchbin]->Write();

      hmixing_newpion_jt0p33_pp_[inchbin]->Write();
      hmixing_newpion_jt0p33_mm_[inchbin]->Write();
      hmixing_newpion_jt0p33_pm_[inchbin]->Write();
      hmixing_newpion_jt0p33_mp_[inchbin]->Write();

      hmixing_newpion_jt0p53_pp_[inchbin]->Write();
      hmixing_newpion_jt0p53_mm_[inchbin]->Write();
      hmixing_newpion_jt0p53_pm_[inchbin]->Write();
      hmixing_newpion_jt0p53_mp_[inchbin]->Write();

      //kaon
      hmixing_newkaon_jt03_[inchbin]->Write();
      hmixing_newkaon_jt0p33_[inchbin]->Write();
      hmixing_newkaon_jt0p53_[inchbin]->Write();

      // +ve and -ve kaon
      hmixing_newkaon_jt03_pp_[inchbin]->Write();
      hmixing_newkaon_jt03_mm_[inchbin]->Write();
      hmixing_newkaon_jt03_pm_[inchbin]->Write();
      hmixing_newkaon_jt03_mp_[inchbin]->Write();

      hmixing_newkaon_jt0p33_pp_[inchbin]->Write();
      hmixing_newkaon_jt0p33_mm_[inchbin]->Write();
      hmixing_newkaon_jt0p33_pm_[inchbin]->Write();
      hmixing_newkaon_jt0p33_mp_[inchbin]->Write();

      hmixing_newkaon_jt0p53_pp_[inchbin]->Write();
      hmixing_newkaon_jt0p53_mm_[inchbin]->Write();
      hmixing_newkaon_jt0p53_pm_[inchbin]->Write();
      hmixing_newkaon_jt0p53_mp_[inchbin]->Write();

      //proton
      hmixing_newproton_jt03_[inchbin]->Write();
      hmixing_newproton_jt0p33_[inchbin]->Write();
      hmixing_newproton_jt0p53_[inchbin]->Write();

      // +ve and -ve proton
      hmixing_newproton_jt03_pp_[inchbin]->Write();
      hmixing_newproton_jt03_mm_[inchbin]->Write();
      hmixing_newproton_jt03_pm_[inchbin]->Write();
      hmixing_newproton_jt03_mp_[inchbin]->Write();

      hmixing_newproton_jt0p33_pp_[inchbin]->Write();
      hmixing_newproton_jt0p33_mm_[inchbin]->Write();
      hmixing_newproton_jt0p33_pm_[inchbin]->Write();
      hmixing_newproton_jt0p33_mp_[inchbin]->Write();

      hmixing_newproton_jt0p53_pp_[inchbin]->Write();
      hmixing_newproton_jt0p53_mm_[inchbin]->Write();
      hmixing_newproton_jt0p53_pm_[inchbin]->Write();
      hmixing_newproton_jt0p53_mp_[inchbin]->Write();

      //lambda
      hmixing_newlambda_jt03_[inchbin]->Write();
      hmixing_newlambda_jt0p33_[inchbin]->Write();
      hmixing_newlambda_jt0p53_[inchbin]->Write();

      // +ve and -ve lambda
      hmixing_newlambda_jt03_pp_[inchbin]->Write();
      hmixing_newlambda_jt03_mm_[inchbin]->Write();
      hmixing_newlambda_jt03_pm_[inchbin]->Write();
      hmixing_newlambda_jt03_mp_[inchbin]->Write();

      hmixing_newlambda_jt0p33_pp_[inchbin]->Write();
      hmixing_newlambda_jt0p33_mm_[inchbin]->Write();
      hmixing_newlambda_jt0p33_pm_[inchbin]->Write();
      hmixing_newlambda_jt0p33_mp_[inchbin]->Write();

      hmixing_newlambda_jt0p53_pp_[inchbin]->Write();
      hmixing_newlambda_jt0p53_mm_[inchbin]->Write();
      hmixing_newlambda_jt0p53_pm_[inchbin]->Write();
      hmixing_newlambda_jt0p53_mp_[inchbin]->Write();
    }
}
