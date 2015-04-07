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
    vector <string> vecstrBuffer;

    ConfigFile  *cConfigFile = new ConfigFile();
    NfoFile     *cNfoFile = new NfoFile();

    cConfigFile->testConfig();
    cNfoFile->testNfo();

    // TODO : ConvertASCII in gemeinsame Klasse zur verarbeitung von strings und vectoren umbauen


    cNfoFile->getValue("title", "TestFile\\movie.nfo", vecstrBuffer);





    return 0;
}
