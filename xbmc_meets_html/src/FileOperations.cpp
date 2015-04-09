/*-----------------------------------------------------------------------------
 * Programm :
 * Thema    :
 * Autor    : Escher Matthias
 * Datum    :
 *-----------------------------------------------------------------------------
 * Modulbeschreibung:
 *
 *
 *-----------------------------------------------------------------------------
 */#include "..\include\FileOperations.h"

#include <string>
#include <vector>
#include <iostream>

#include <windows.h>

#include "..\include\StringTools.h"

using namespace std;


FileOperations::FileOperations()
{
    //ctor
}

FileOperations::~FileOperations()
{
    //dtor
}

int FileOperations::ListFolders( string strFolderPath, vector <string> &vecstrContainedFolders)
{
    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    strFolderPath = strFolderPath + "\\*.*";

    LPCSTR lpcstr_path = StringTools::strToLpcstr(strFolderPath);

    HANDLE hSearch = FindFirstFile(lpcstr_path,&FData);

    if (hSearch == INVALID_HANDLE_VALUE)
    {
        cout << endl;
        cout << "$ get_folder_list(): Pfad zum Ordner nicht vorhanden!" << endl;
        cout << "$ Pfad:     " << strFolderPath << endl;
        cout << endl;
        return -1;
    }

    /** Ordnernamen bestimmen **/
    do
    {
        // Ist das ein Ordner ?
        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
        {
                vecstrContainedFolders.push_back(FData.cFileName);
        }

        MoreFiles = FindNextFile(hSearch,&FData);
    } while (MoreFiles);

    FindClose(hSearch);

    unsigned int i;

    for( i=0; i<vecstrContainedFolders.size(); i++)
    {
        if( (vecstrContainedFolders.at(i) == ".") || (vecstrContainedFolders.at(i) == "..") )
        {
            vecstrContainedFolders.erase(vecstrContainedFolders.begin()+i);
            i--;
        }
    }

#if 0
        cout << "-------------------------------------------------" << endl;
        cout << "Pfad Filme: " << strFolderPath << endl << endl;

        for( i=0; i<vecstrContainedFolders.size(); i++)
        {
            cout << "Ordner " << i << " :  " << vecstrContainedFolders.at(i) << endl;
        }

        cout << "-------------------------------------------------" << endl << endl;
#endif

    return 0;
}









