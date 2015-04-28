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
 */
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

#include <windows.h>
#include <sys/stat.h>

#include "..\include\FileOperations.h"
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


/** \brief  Listet alle Ordner im Verzeichnis auf
 *
 * \param   strFolderPath               Verzeichnispfad
 *          &vecstrContainedFodlers     Liste der enthaltenen Ordner
 *
 * \return   0   kein Fehler vorhanden
 *          -1   Verzeichnis ungültig
 *
 */
int FileOperations::listFolders( string strFolderPath, vector <string> &vecstrContainedFolders)
{
    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    strFolderPath = strFolderPath + "\\*.*";                                    // Passe Verzeichnis an

    LPCSTR lpcstr_path = StringTools::strToLpcstr(strFolderPath);               // Konvertiere String -> LPCSTR

    HANDLE hSearch = FindFirstFile(lpcstr_path,&FData);

    if (hSearch == INVALID_HANDLE_VALUE)                                        /** Ungültiger Pfad angegeben **/
    {
        cout << endl;
        cout << "$ get_folder_list(): Pfad zum Ordner nicht vorhanden!" << endl;
        cout << "$ Pfad:     " << strFolderPath << endl;
        cout << endl;
        return -1;
    }

    /** Ordnernamen bestimmen **/
    do                                                                          /** Durchlaufe bis alle Dateien/Ordner geprüft wurden **/
    {
        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                 /** Ordner gefunden **/
        {
                vecstrContainedFolders.push_back(FData.cFileName);              // Hänge Ordnername an die Liste an
        }

        MoreFiles = FindNextFile(hSearch,&FData);                               // Gehe zur nächsten Datei/Ordner
    } while (MoreFiles);

    FindClose(hSearch);

    unsigned int i;

    for( i=0; i<vecstrContainedFolders.size(); i++)                             /** Entferne alle unnötigen gefundenen Ordner **/
    {
        if( (vecstrContainedFolders.at(i) == ".") || (vecstrContainedFolders.at(i) == "..") )
        {
            vecstrContainedFolders.erase(vecstrContainedFolders.begin()+i);
            i--;
        }
    }

    return 0;
}


/** \brief  Sucht eine Datei im Verzeichnis
 *
 * \param   strPath             Pfad zum Verzeichnis
 *          strSearchParam      Suchbegriff
 *          bWholeWord          true    Suchbegriff entspricht dem kompletten Dateinamen
 *                              false   Suchbegriff ist nur ein Teil des Dateinamen
 *          vecstrFoundFiles    Liste der Gefundenen Dateien die den Suchparametern entsprechen
 *
 * \return   0   kein Fehler vorhanden
 *          -1   Verzeichnis ungültig
 *
 */
int FileOperations::findFile( const string strPath, const string strSearchParam, bool bWholeWord, vector <string> &vecstrFoundFiles)
{
    string strFolderPath;
    string strFilename;

    vecstrFoundFiles.clear();

    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    strFolderPath = strPath + "\\*.*";                                          // Passe Verzeichnis an

    LPCSTR lpcstr_path = StringTools::strToLpcstr(strFolderPath);               // Konvertieren String -> LPCSTR
    HANDLE hSearch = FindFirstFile(lpcstr_path,&FData);

    if (hSearch == INVALID_HANDLE_VALUE)                                        /** Ungültiger Pfad angegeben **/
    {
        cout << endl;
        cout << "$ find_file(): ungueltiger Pfad angegeben!" << endl;
        cout << "$ Pfad: " << strPath << endl;
        cout << endl;

        return -1;
    }

    do
    {

        if (FData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)                 /** Datei gefunden **/
        {
            strFilename = FData.cFileName;                                      // Schreibe Ordnernamen in String

            if( bWholeWord == true && strFilename.compare(strSearchParam) == 0)
            {
                vecstrFoundFiles.push_back(strFilename);
            }
            else if ( bWholeWord == false && strFilename.find(strSearchParam) != string::npos)
            {
                vecstrFoundFiles.push_back(strFilename);
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                               // Suche nächste Datei

    } while (MoreFiles);

    FindClose(hSearch);

    return 0;
}


/** \brief  Sucht einen Ordner im Verzeichnis
 *
 * \param   strPath             Pfad zum Verzeichnis
 *          strSearchParam      Suchbegriff
 *          bWholeWord          true    Suchbegriff entspricht dem kompletten Ordnernamen
 *                              false   Suchbegriff ist nur ein Teil des Ordnernamen
 *          vecstrFoundFiles    Liste der Gefundenen Dateien die den Suchparametern entsprechen
 *
 * \return   0   kein Fehler vorhanden
 *          -1   Verzeichnis ungültig
 *
 */
int FileOperations::findFolder( const string strPath, const string strSearchParam, bool bWholeWord, vector <string> &vecstrFoundFolders)
{
    string strFolderPath;
    string strBuffer;

    vecstrFoundFolders.clear();

    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    strFolderPath = strPath + "\\*.*";

    LPCSTR lpcstr_path = StringTools::strToLpcstr(strFolderPath);                           // Konvertiere String -> LPCSTR
    HANDLE hSearch = FindFirstFile(lpcstr_path,&FData);                                     // Suchpfad angeben

    if (hSearch == INVALID_HANDLE_VALUE)                                                    /** Ungültiger Pfad angegeben **/
    {
        cout << endl;
        cout << "$ find_file(): ungueltiger Pfad angegeben!" << endl;
        cout << "$ Pfad: " << strPath << endl;
        cout << endl;

        return -1;
    }

    do
    {

        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                             /** Ordner gefunden **/
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


/** \brief  Überprüft, ob eine Datei existiert
 *
 * \param   filename    Name der Datei die überprüft werden soll
 *
 * \return  true        Datei existiert
 *          false       Datei existiert nicht
 *
 */
bool FileOperations::fileExists(const string &filename)
{
    struct stat buf;

    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }

    return false;
}


