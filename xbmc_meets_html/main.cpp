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





#if 1

    FileOperations::listFolders(path, vecstrBuffer);

    unsigned int i;
    for( i=0; i<vecstrBuffer.size(); i++)
    {
        cout << endl << endl << i << ". Pfad: " << vecstrBuffer[i] << endl;

        MovieFolder *cMovieFolder = new MovieFolder(path + "\\" + vecstrBuffer[i]);
        cMovieFolder->SearchMovieFile();

        cout << "MovieFiles: " << cMovieFolder->getMovieFilename() << endl;

        cMovieFolder->~MovieFolder();
    }
#endif


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
