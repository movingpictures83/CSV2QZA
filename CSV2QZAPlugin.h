#ifndef CSV2QZAPLUGIN_H
#define CSV2QZAPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>
#include <map>

class CSV2QZAPlugin : public Plugin
{
public: 
 std::string toString() {return "CSV2QZA";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;
};

#endif
