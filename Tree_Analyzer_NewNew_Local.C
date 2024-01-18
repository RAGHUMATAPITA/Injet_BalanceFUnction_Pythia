#include "read_tree_New.h"
#include "function_defination.h" // call_libraries.h, input_variables.h and histogram_definition.h are called within function_defination.h
#include "coordinateTools.h" // for coordinate transformation w.r.t jet axis

void Tree_Analyzer_NewNew_Local(TString input_file, int itxtoutFile, TString out_directory, TString name_of_roorFile)
{
  clock_t sec_start, sec_end;
  sec_start = clock();

  TDatime* date = new TDatime();

  print_start(); // start timing print

  // calling function to define array histograms
  array_hist_def();

  for(int itxt = 0; itxt < itxtoutFile; itxt++)
    {
      std::cout<<"###################-----Job will run for the "<<itxt<<" th txt file-----#################"<<std::endl;  
      fstream openInputFile;
      openInputFile.open(Form("%s_%d.txt",input_file.Data(), itxt), ios::in);
      if(!openInputFile.is_open())
        {
          cout << "List of input files not founded!" << endl;
          return;
        }
      
      std::vector<TString> file_name_vector;
      string file_chain;
      
      while(getline(openInputFile, file_chain))
	{
	  file_name_vector.push_back(file_chain);
	}
      
      openInputFile.close();
      
      TChain *tree = new TChain("tr");
      
      for (std::vector<TString>::iterator listIterator = file_name_vector.begin(); listIterator != file_name_vector.end(); listIterator++)
	{
	  TFile *testfile = TFile::Open(*listIterator);
	  
	  if(!testfile || testfile->IsZombie() || testfile->TestBit(TFile::kRecovered))
	    {
	      cout << "File: " << *listIterator << " failed to open" << endl;
	      continue;
	    }
	  
	  cout << "Adding file:--- " << *listIterator << "--- to the chains" << endl;
	  
	  tree->Add(*listIterator);
	}
      
      read_tree(tree);
      
      int nevents = tree->GetEntries(); // number of events
      
      cout<<endl;
      cout << "Total number of events in those files: "<< nevents << endl;
      cout<<endl;
      
      //~~~~~~~~~~~~Define vectors use for Signal and Mixed event correlation
      // 1D event vector
      std::vector<float> pthatw_vec_1D;
      std::vector<int> processID_vec_1D;
      
      // 2D jet vector
      std::vector<std::vector<TVector3>> jet_vec_2D;
      
      // 3D trk vector
      std::vector<std::vector<std::vector<TVector3>>> jet_oldtrk_vec_3D;
      std::vector<std::vector<std::vector<TVector3>>> jet_newtrk_vec_3D;
      std::vector<std::vector<std::vector<TVector3>>> jet_newchtrk_vec_3D;
      std::vector<std::vector<std::vector<TVector3>>> jet_oldchtrk_vec_3D;
      std::vector<std::vector<std::vector<int>>> jet_trk_charge_3D;
      std::vector<std::vector<std::vector<int>>> jet_trk_id_3D;
      
      //for(int iev = 0; iev < nevents; iev++)
	for(int iev = 0; iev < 100; iev++)
	{
	  tree->GetEntry(iev);
	  
	  //~~~~~~~~~~~~Define 1D jet vectors use to fill 2D jet vector
	  std::vector<TVector3> jet_vec_1D;
	  
	  //~~~~~~~~~~~~Define 2D trk vectors use to fill 3D trk vector
	  std::vector<std::vector<TVector3>> oldtrk_vec_2D;
	  std::vector<std::vector<TVector3>> newtrk_vec_2D;
	  std::vector<std::vector<TVector3>> oldchtrk_vec_2D;
	  std::vector<std::vector<TVector3>> newchtrk_vec_2D;
	  std::vector<std::vector<int>> trk_charge_2D;
	  std::vector<std::vector<int>> trk_id_2D;
	  
	  
	  int nTotTrk_Jet = 0;
	  
	  for (int ijet = 0; ijet < (int)njets; ijet++) // jet loop start
	    {
	      float jet_pt = (float)jetpt[ijet];
	      float jet_eta = (float)jeteta[ijet];
	      float jet_rap = (float)jetrap[ijet];
	      float jet_phi = (float)jetphi[ijet];
	      
	      //push back to 1D jet vector
	      TVector3 saved_jet;
	      saved_jet.SetPtEtaPhi(jet_pt, jet_eta, jet_phi);
	      jet_vec_1D.push_back(saved_jet);
	      
	      //std::cout<<"Jet properties: "<<jet_pt<<" "<<jet_eta<<" "<<jet_rap<<" "<<jet_phi<<std::endl;
	      //std::cout<<"Jet ncharge and Jet mult form tree: "<<JetnCh[ijet]<<"  "<<JetMult[ijet]<<std::endl;
	      
	      //~~~~~~~~~~~~Define 1D trk vectors use to fill 2D trk vector
	      std::vector<TVector3> oldtrk_vec_1D;
	      std::vector<TVector3> newtrk_vec_1D;
	      std::vector<TVector3> oldchtrk_vec_1D;
	      std::vector<TVector3> newchtrk_vec_1D;
	      std::vector<int> trk_charge_vec_1D;
	      std::vector<int> trk_id_vec_1D;
	      
	      int nchtrk_jet = 0, ntrk_jet = 0;
	      
	      for (int itrk = 0; itrk < (int)JetMult[ijet]; itrk++) // jet track loop start
		{
		  float trk_pt = (float)trkpt[nTotTrk_Jet];
		  float trk_eta = (float)trketa[nTotTrk_Jet];
		  float trk_rap = (float)trkrap[nTotTrk_Jet];
		  float trk_phi = (float)trkphi[nTotTrk_Jet];
		  int trk_id = (int)trkid[nTotTrk_Jet];
		  int trk_charge = (int)trkcharge[nTotTrk_Jet];
		  
		  nTotTrk_Jet++;
		  
		  // to check whether the partcile is inside the the jet or not
		  /*
		    float DEta_jet_trk = (jet_eta - trk_eta);
		    float DPhi_jet_trk = TVector2::Phi_mpi_pi(jet_phi - trk_phi);
		    float DR_jet_trk = TMath::Sqrt(pow(DEta_jet_trk,2) + pow(DPhi_jet_trk,2));
		    
		    if(DR_jet_trk > jet_radius)
		    {
		    //std::cout<<"track is not inside jet cone: "<<trk_pt<<" "<<trk_eta<<" "<<trk_phi<<" "<<trk_charge<<std::endl;
		    continue;
		    }
		  */
		  
		  ntrk_jet++;
		  
		  if(fabs((int)trk_charge) > 0)
		    {
		      nchtrk_jet++;
		    }
		  
		  float new_trk_pt = ptWRTJet(jet_pt, jet_eta, jet_phi, trk_pt, trk_eta, trk_phi);
		  float new_trk_eta = etaWRTJet(jet_pt, jet_eta, jet_phi, trk_pt, trk_eta, trk_phi);
		  float new_trk_phi = phiWRTJet(jet_pt, jet_eta, jet_phi, trk_pt, trk_eta, trk_phi);
		  
		  //std::cout<<trk_pt<<" "<<trk_eta<<" "<<trk_phi<<"    "<<new_trk_pt<<" "<<new_trk_eta<<" "<<new_trk_phi<<std::endl;
		  
		  //push back to 1D trk vector
		  trk_charge_vec_1D.push_back(trk_charge);
		  trk_id_vec_1D.push_back(trk_id);
		  
		  TVector3 saved_oldtrk, saved_newtrk, saved_oldchtrk, saved_newchtrk;
		  saved_oldtrk.SetPtEtaPhi(trk_pt, trk_eta, trk_phi);
		  oldtrk_vec_1D.push_back(saved_oldtrk);
		  saved_newtrk.SetPtEtaPhi(new_trk_pt, new_trk_eta, new_trk_phi);
		  newtrk_vec_1D.push_back(saved_newtrk);
		  
		  if(fabs((int)trk_charge) > 0)
		    {
		      saved_oldchtrk.SetPtEtaPhi(trk_pt, trk_eta, trk_phi);
		      oldchtrk_vec_1D.push_back(saved_oldchtrk);
		      saved_newchtrk.SetPtEtaPhi(new_trk_pt, new_trk_eta, new_trk_phi);
		      newchtrk_vec_1D.push_back(saved_newchtrk);
		    }
		} // jet track loop end
	      
	      //push back to 2D trk vector
	      oldtrk_vec_2D.push_back(oldtrk_vec_1D);
	      newtrk_vec_2D.push_back(newtrk_vec_1D);
	      oldchtrk_vec_2D.push_back(oldchtrk_vec_1D);
	      newchtrk_vec_2D.push_back(newchtrk_vec_1D);
	      trk_charge_2D.push_back(trk_charge_vec_1D);
	      trk_id_2D.push_back(trk_id_vec_1D);
	      
	      //clear 1D trk vector
	      oldtrk_vec_1D.clear();
	      newtrk_vec_1D.clear();
	      oldchtrk_vec_1D.clear();
	      newchtrk_vec_1D.clear();
	      trk_charge_vec_1D.clear();
	      trk_id_vec_1D.clear();
	      
	    } // jet loop end
	  
	  //push back to 2D jet vector
	  jet_vec_2D.push_back(jet_vec_1D);
	  
	  //clear 1D jet vector
	  jet_vec_1D.clear();
	  
	  //push back to 3D trk vector
	  jet_oldtrk_vec_3D.push_back(oldtrk_vec_2D);
	  jet_newtrk_vec_3D.push_back(newtrk_vec_2D);
	  jet_oldchtrk_vec_3D.push_back(oldchtrk_vec_2D);
	  jet_newchtrk_vec_3D.push_back(newchtrk_vec_2D);
	  jet_trk_charge_3D.push_back(trk_charge_2D);
	  jet_trk_id_3D.push_back(trk_id_2D);
	  
	  //clear 2D trk vector
	  oldtrk_vec_2D.clear();
	  newtrk_vec_2D.clear();
	  oldchtrk_vec_2D.clear();
	  newchtrk_vec_2D.clear();
	  trk_charge_2D.clear();
	  trk_id_2D.clear();
	  
	  //pthatweight = 1.; // for test
	  
	  // push back event quatities (pthatweight, Subprocesscode, etc) before closing event loop
	  pthatw_vec_1D.push_back(pthatweight);
	  processID_vec_1D.push_back(Subprocesscode);
	  
	  //fill event histograms
	  hntrkTotal->Fill(ntrkTotal, pthatweight);
	  hpthat->Fill(pthat, pthatweight);
	  hpthatw->Fill(pthatweight);
	  hsubprocessid->Fill(Subprocesscode, pthatweight);
	  hnjets->Fill(njets, pthatweight);
	} // event loop end
      
      //calling function for signal correlation
      signal_corr(pthatw_vec_1D, processID_vec_1D, jet_vec_2D, jet_oldtrk_vec_3D, jet_newtrk_vec_3D, jet_oldchtrk_vec_3D, jet_newchtrk_vec_3D, jet_trk_charge_3D, jet_trk_id_3D);
      
      //calling function for mixing correlation  
      mixing_corr(pthatw_vec_1D, processID_vec_1D, jet_vec_2D, jet_oldtrk_vec_3D, jet_newtrk_vec_3D, jet_oldchtrk_vec_3D, jet_newchtrk_vec_3D, jet_trk_charge_3D, jet_trk_id_3D);
      
      
      // clear event vector
      pthatw_vec_1D.clear();
      processID_vec_1D.clear();
      
      //clear jet vector
      jet_vec_2D.clear();
      
      //clear trk vector
      jet_oldtrk_vec_3D.clear();
      jet_newtrk_vec_3D.clear();
      jet_oldchtrk_vec_3D.clear();
      jet_newchtrk_vec_3D.clear();
      jet_trk_charge_3D.clear();
      jet_trk_id_3D.clear();
      
      // delete the tree to clean memory                                                                                    
      delete tree;
    } // txt file loop end

  // output file name
  std::string outfilename = Form("%s/%s_Outfile_%d", out_directory.Data(), name_of_roorFile.Data(), itxtoutFile);
  std::replace(outfilename.begin(), outfilename.end(), '.', 'p'); // replace . to p
  std::replace(outfilename.begin(), outfilename.end(), '-', 'N'); // replace - to N for negative
  
  TFile* fout = new TFile(Form("%s.root", outfilename.c_str()), "recreate");
  
  fout->mkdir("Event_Hist");
  fout->cd("Event_Hist");
  write_event_hist();
  
  fout->mkdir("Jet_Hist");
  fout->cd("Jet_Hist");
  write_jet_hist();
  
  fout->mkdir("Track_Hist");
  fout->cd("Track_Hist");
  write_track_hist();
  
  fout->mkdir("Corr_Hist");
  fout->cd("Corr_Hist");
  write_corr_hist();

  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~Finished, DONE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
  std::cout<<std::endl;
  
  sec_end = clock(); // stop time counting                                                                                       
  cout << "========================================" << endl;
  cout << "Total running time: " << (double)(sec_end - sec_start) / CLOCKS_PER_SEC << " [s]" << endl;
  cout << "========================================" << endl;
  
  print_stop(); // Print time, date and hour when it stops
}

int main(int argc, char **argv)
{
  using namespace std;

  TString inputfile;
  int itxtout;
  TString outfile;
  TString outfile_name;
  if(argc == 5)
    {
      std::cout<<std::endl;
      std::cout<<"You have given "<< argc <<" arguments including the program name;  Your program will run"<<std::endl;
      std::cout<<std::endl;
      inputfile = argv[1];
      itxtout = atoi(argv[2]);
      outfile = argv[3];
      outfile_name  = argv[4];

      Tree_Analyzer_NewNew_Local(inputfile, itxtout, outfile, outfile_name);
    }
  return 0;
}
