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

int FileOperations::listFolders( string strFolderPath, vector <string> &vecstrContainedFolders)
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


int FileOperations::findFile( const string strPath, const string strSearchParam, bool bWholeWord, vector <string> &vecstrFoundFiles)
{
    string strFolderPath;
    string strFilename;

    vecstrFoundFiles.clear();

    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    strFolderPath = strPath + "\\*.*";

    LPCSTR lpcstr_path = StringTools::strToLpcstr(strFolderPath);                                        // Convertieren str -> LPCSTR
    HANDLE hSearch = FindFirstFile(lpcstr_path,&FData);                                     // Suchpfad angeben

    if (hSearch == INVALID_HANDLE_VALUE)                                                    // Bei ungültigem Pfad, Funktion beenden
    {
        cout << endl;
        cout << "$ find_file(): ungueltiger Pfad angegeben!" << endl;
        cout << "$ Pfad: " << strPath << endl;
        cout << endl;

        return -1;                                                                          // Falls ungueltige Angabe, Funktion beenden
    }

    do
    {

        if (FData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)                             // Datei gefunden
        {
            strFilename = FData.cFileName;                                                    // Schreibe Ordnernamen in String

            if( bWholeWord == true && strFilename.compare(strSearchParam) == 0)
            {
                vecstrFoundFiles.push_back(strFilename);
            }
            else if ( bWholeWord == false && strFilename.find(strSearchParam) != string::npos)
            {
                vecstrFoundFiles.push_back(strFilename);
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                                           // Suche nächste Datei

    } while (MoreFiles);

    FindClose(hSearch);

    return 0;
}


int FileOperations::findFolder( const string strPath, const string strSearchParam, bool bWholeWord, vector <string> &vecstrFoundFolders)
{
    string strFolderPath;
    string strBuffer;

    vecstrFoundFolders.clear();

    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    strFolderPath = strPath + "\\*.*";

    LPCSTR lpcstr_path = StringTools::strToLpcstr(strFolderPath);                                        // Convertieren str -> LPCSTR
    HANDLE hSearch = FindFirstFile(lpcstr_path,&FData);                                     // Suchpfad angeben

    if (hSearch == INVALID_HANDLE_VALUE)                                                    // Bei ungültigem Pfad, Funktion beenden
    {
        cout << endl;
        cout << "$ find_file(): ungueltiger Pfad angegeben!" << endl;
        cout << "$ Pfad: " << strPath << endl;
        cout << endl;

        return -1;                                                                          // Falls ungueltige Angabe, Funktion beenden
    }

    do
    {

        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                             // Datei gefunden
        {
            strBuffer = FData.cFileName;                                                    // Schreibe Ordnernamen in String

            if( bWholeWord == true && strBuffer.compare(strSearchParam) == 0)
            {
                vecstrFoundFolders.push_back(strBuffer);
            }
            else if ( bWholeWord == false && strBuffer.find(strSearchParam) != string::npos)
            {
                vecstrFoundFolders.push_back(strBuffer);
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                                           // Suche nächste Datei

    } while (MoreFiles);

    FindClose(hSearch);

    return 0;
}




