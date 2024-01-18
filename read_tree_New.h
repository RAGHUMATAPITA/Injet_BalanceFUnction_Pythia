#include "call_libraries.h"  // call libraries from ROOT and C++

// event quantities
int ntrkTotal;
float pthat;
float pthatweight;
int Subprocesscode;
int njets;

// Jets quantities
const int NJet = 99;
int JetMult[NJet];
int JetnCh[NJet];
float jetpt[NJet];
float jeteta[NJet];
float jetrap[NJet];
float jetphi[NJet];

// Track quantities
const int ntrkmax = 999;
int trkid[ntrkmax];
int trkcharge[ntrkmax];
float trkpt[ntrkmax];
float trketa[ntrkmax];
float trkrap[ntrkmax];
float trkphi[ntrkmax];

void read_tree(TTree *tree)
{
  tree->SetBranchStatus("*", 0); // disable all branches - this is important while reading big files
  
  // enable branches of interest -> see definition of each variables above

  // event quantities
  tree->SetBranchStatus("ntrkTotal", 1);
  tree->SetBranchAddress("ntrkTotal", &ntrkTotal);
  tree->SetBranchStatus("pthat", 1);
  tree->SetBranchAddress("pthat", &pthat);
  tree->SetBranchStatus("pthatweight", 1);
  tree->SetBranchAddress("pthatweight", &pthatweight);
  tree->SetBranchStatus("Subprocesscode", 1);
  tree->SetBranchAddress("Subprocesscode", &Subprocesscode);
  tree->SetBranchStatus("njets", 1);
  tree->SetBranchAddress("njets", &njets);

  // jet quantities
  tree->SetBranchStatus("JetMult", 1);
  tree->SetBranchAddress("JetMult", &JetMult);
  tree->SetBranchStatus("JetnCh", 1);
  tree->SetBranchAddress("JetnCh", &JetnCh);
  tree->SetBranchStatus("jetpt", 1);
  tree->SetBranchAddress("jetpt", &jetpt);
  tree->SetBranchStatus("jeteta", 1);
  tree->SetBranchAddress("jeteta", &jeteta);
  tree->SetBranchStatus("jetrap", 1);
  tree->SetBranchAddress("jetrap", &jetrap);
  tree->SetBranchStatus("jetphi", 1);
  tree->SetBranchAddress("jetphi", &jetphi);
  
  // track quantities
  tree->SetBranchStatus("trkid", 1);
  tree->SetBranchAddress("trkid", &trkid);

  tree->SetBranchStatus("trkcharge", 1); 
  tree->SetBranchAddress("trkcharge", &trkcharge);

  tree->SetBranchStatus("trkpt", 1); 
  tree->SetBranchAddress("trkpt", &trkpt);

  tree->SetBranchStatus("trketa", 1); 
  tree->SetBranchAddress("trketa", &trketa);

  tree->SetBranchStatus("trkrap", 1); 
  tree->SetBranchAddress("trkrap", &trkrap);

  tree->SetBranchStatus("trkphi", 1); 
  tree->SetBranchAddress("trkphi", &trkphi);

}
