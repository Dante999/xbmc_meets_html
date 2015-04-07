#include <iostream>
#include <string>

#include "include\ConfigFile.h"
#include "include\ConvertASCII.h"
#include "include\NfoFile.h"


using namespace std;






int main()
{
    cout << "##########################################" << endl;
    cout << "#        XBMC meets HTML Tool            #" << endl;
    cout << "#        created by Dante999             #" << endl;
    cout << "##########################################" << endl << endl;


    string strBuffer;

    ConfigFile  *cConfigFile = new ConfigFile();
    NfoFile     *cNfoFile = new NfoFile();

    cConfigFile->testConfig();
    cNfoFile->testNfo();





    return 0;
}
