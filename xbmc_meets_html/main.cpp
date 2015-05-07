#include <iostream>
#include <string>

#include "include\ConfigFile.h"
#include "include\ConvertASCII.h"
#include "include\NfoFile.h"
#include "include\StringTools.h"
#include "include\FileOperations.h"
#include "include\MovieFolder.h"
#include "include\MovieHtml.h"


using namespace std;

int main()
{
    cout << "##########################################" << endl;
    cout << "#        XBMC meets HTML Tool            #" << endl;
    cout << "#        created by Dante999             #" << endl;
    cout << "##########################################" << endl << endl;


    string strBuffer;
    vector <string> vecstrFoldername;



    string path = "E:\\Sandbox\\test_movies";





#if 1

    FileOperations::listFolders(path, vecstrFoldername);

    unsigned int i;
    for( i=0; i<vecstrFoldername.size(); i++)
    {
        cout << endl << endl << i << ". Pfad: " << vecstrFoldername[i] << endl;

        MovieFolder oMovieFolder(path + "\\" + vecstrFoldername[i]);
        oMovieFolder.print();

        MovieHtml oMovieHtml(oMovieFolder.getMovieFolderPath(), oMovieFolder.getMovieFolderPath() + "\\" + oMovieFolder.getNfoFilename());

    }
#endif


    cout << endl << endl;
    cout << "Ende Main()" << endl;








    return 0;
}
