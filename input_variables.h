#include "call_libraries.h"
// event cuts

// jet cuts
float jet_radius = 0.8;
double jet_pt_min = 550.;
double jet_eta_min = -1.6;
double jet_eta_max = 1.6;

// track cut
double newtrk_eta_min = -5.;
double newtrk_eta_max = 5.;
double newtrk_jt03_min = 0.;
double newtrk_jt03_max = 3.;
double newtrk_jt0p33_min = 0.3;
double newtrk_jt0p33_max = 3.;
double newtrk_jt0p53_min = 0.5;
double newtrk_jt0p53_max = 3.;

//number of events to mix
int bkgFactor = 5;
