#include <iostream>
#include <string>

#include "include\ConfigFile.h"
#include "include\ConvertASCII.h"
#include "include\NfoFile.h"
#include "include\StringTools.h"
#include "include\FileOperations.h"
#include "include\MovieFolder.h"


using namespace std;

int main()
{
    cout << "##########################################" << endl;
    cout << "#        XBMC meets HTML Tool            #" << endl;
    cout << "#        created by Dante999             #" << endl;
    cout << "##########################################" << endl << endl;


    string strBuffer;
    vector <string> vecstrBuffer;
    vector <string> vecstrBuffer2;


    //MovieFolder *cMovieFolder = new MovieFolder("E:\\Sandbox\\test_movies\\Fight Club (1999) [720 {h264}] [aac {2}]");

    //cMovieFolder->SearchMovieFile();
    string path = "E:\\Sandbox\\test_movies";

    FileOperations::listFolders(path, vecstrBuffer);


    unsigned int i;

    for( i=0; i<vecstrBuffer.size(); i++)
    {
        cout << "Pfad: " << vecstrBuffer[i];

        if(vecstrBuffer[i].find(".") != string::npos) FileOperations::findFile(path + "\\" + vecstrBuffer[i], "a", false, vecstrBuffer2);
        else FileOperations::findFolder(path + "\\" + vecstrBuffer[i], "VIDEO_TS", false, vecstrBuffer2);

        StringTools::printVecstr(vecstrBuffer2);

 /**
        MovieFolder *cMovieFolder = new MovieFolder(path + "\\" + vecstrBuffer[i]);
        cout << i << ": ";
        cMovieFolder->SearchMovieFile();
**/

    }



#if 0
    ConfigFile  *cConfigFile = new ConfigFile();
    NfoFile     *cNfoFile = new NfoFile("TestFiles\\movie.nfo");


    cConfigFile->testConfig();
    cNfoFile->testNfo();

    // TODO : ConvertASCII in gemeinsame Klasse zur verarbeitung von strings und vectoren umbauen


    FileOperations::ListFolders("E:\\Sandbox\\test_movies", vecstrBuffer);
    StringTools::printVecstr(vecstrBuffer);

#endif

    cout << "Ende Main()" << endl;








    return 0;
}
