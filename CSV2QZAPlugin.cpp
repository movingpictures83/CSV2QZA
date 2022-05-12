#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "CSV2QZAPlugin.h"

void CSV2QZAPlugin::input(std::string file) {
 inputfile = file;
}

void CSV2QZAPlugin::run() {
   
}

void CSV2QZAPlugin::output(std::string file) { 
   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";
   command += "qiime tools import --type \'SampleData[PairedEndSequencesWithQuality]\' --input-path "+inputfile+" --output-path "+file+" --input-format PairedEndFastqManifestPhred33; ";

//qiime tools import \
  --type 'SampleData[PairedEndSequencesWithQuality]' \
  --input-path AlphaFinal1.manifest \
  --output-path AlphaFinal1-paired-end-demux.qza \
  --input-format PairedEndFastqManifestPhred33V2
 //std::cout << command << std::endl;
   command += "conda deactivate; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;


 system(command.c_str());
}

PluginProxy<CSV2QZAPlugin> CSV2QZAPluginProxy = PluginProxy<CSV2QZAPlugin>("CSV2QZA", PluginManager::getInstance());
