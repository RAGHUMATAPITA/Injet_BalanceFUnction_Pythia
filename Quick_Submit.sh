#!/bin/bash

rm -rf *.C~
rm -rf *.h~
rm -rf *.sh~
rm -rf *.txt~

#1st Arguments : Divided txt files are stored in the path "Divided_txt_files/Step1/". "Outfile_Step1" is the name of recreate txt files.
###-----Note that, 3rd argument of the macro "Create_subtxtFile.C", which is "Step1" in this case, will be same in the path after "Divided_txt_files/", e.g., Divided_txt_files/Step1/" and also will be same after Outfile_, e.g., "Outfile_Step1"

#2nd arguments : number of txt file created. You will enter the when run the this script. It will take automatically

#4th arguments : Output root file name. Better to give same name as in 3rd argument name of the macro "Create_subtxtFile.C", which is "Step1"

#root -l -b -q "Tree_Analyzer_NewNew_Condor.C(\"test_TuneCP5\", 1, \"/Users/raghumatapita/cernbox/Research/With_NirbhayBhai/Out_RootFile\", \"Jets_TuneCP5\")" # new mac
root -l -b -q "Tree_Analyzer_NewNew.C(\"test_TuneCP5\", 1, \"/eos/user/r/rpradhan/Research/With_NirbhayBhai/Out_RootFile\", \"Jets_TuneCP5\")" # new mac

#root -l -b -q "Tree_Analyzer_NewNew.C(\"Divided_txt_files/Jets_TuneCP5/Outfile_Jets_TuneCP5\", $njobs, \"/Users/PITAMATA/cernbox/Research/With_NirbhayBhai/Out_RootFile\", \"Jets_TuneCP5\")" # old mac
