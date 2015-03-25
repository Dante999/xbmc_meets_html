#include <iostream>
#include <string>

#include "include\ConfigFile.h"
#include "include\ConvertASCII.h"


using namespace std;






int main()
{
    string strBuffer;

    ConfigFile *cConfigFile = new ConfigFile();

    cConfigFile->testConfig();

    return 0;
}
