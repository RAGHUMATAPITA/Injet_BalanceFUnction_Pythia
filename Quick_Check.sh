#!/bin/bash

rm -rf *.C~
rm -rf *.h~
rm -rf *.sh~
rm -rf *.txt~

#1st Arguments : if you want to test run, true. It will take only 4 root files. For full jobs, it will be false
#2nd arguments : Your input txt file, where all the root files are there
#3rd arguments : Which step we are doing or some name

root -l -b -q "Create_subtxtFile.C(true, \"test_TuneCP5.txt\", \"Jets_TuneCP5\")"

echo "Again enter the number of jobs you have given:"
read njobs

#1st Arguments : Divided txt files are stored in the path "Divided_txt_files/Step1/". "Outfile_Step1" is the name of recreate txt files.
###-----Note that, 3rd argument of the macro "Create_subtxtFile.C", which is "Step1" in this case, will be same in the path after "Divided_txt_files/", e.g., Divided_txt_files/Step1/" and also will be same after Outfile_, e.g., "Outfile_Step1"

#2nd arguments : number of txt file created. You will enter the when run the this script. It will take automatically

#4th arguments : Output root file name. Better to give same name as in 3rd argument name of the macro "Create_subtxtFile.C", which is "Step1"

root -l -b -q "Tree_Analyzer_NewNew_Condor.C(\"Divided_txt_files/Jets_TuneCP5/Outfile_Jets_TuneCP5_0.txt\", $njobs, \"/eos/user/r/rpradhan/Research/With_NirbhayBhai/Out_RootFile\", \"Jets_TuneCP5_Local\")" # new mac
#root -l -b -q "Tree_Analyzer_NewNew_Local.C(\"Divided_txt_files/Jets_TuneCP5/Outfile_Jets_TuneCP5\", $njobs, \"/eos/user/r/rpradhan/Research/With_NirbhayBhai/Out_RootFile\", \"Jets_TuneCP5_Local\")" # new mac
#root -l -b -q "Tree_Analyzer_NewNew.C(\"Divided_txt_files/Jets_TuneCP5/Outfile_Jets_TuneCP5\", $njobs, \"/Users/raghumatapita/cernbox/Research/With_NirbhayBhai/Out_RootFile\", \"Jets_TuneCP5_Local\")" # new mac

#root -l -b -q "Tree_Analyzer_NewNew.C(\"Divided_txt_files/Jets_TuneCP5/Outfile_Jets_TuneCP5\", $njobs, \"/Users/PITAMATA/cernbox/Research/With_NirbhayBhai/Out_RootFile\", \"Jets_TuneCP5\")" # old mac
