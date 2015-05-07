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

int FileOperations::copyFile(const string strSourceFilepath, const string strDestinationFilepath, bool overwrite )
{
    if(fileExists(strSourceFilepath) == false)
    {
        return -1;
    }

    LPCSTR lpcstrSource = StringTools::strToLpcstr(strSourceFilepath);
    LPCSTR lpcstrDestination = StringTools::strToLpcstr(strDestinationFilepath);

    if( overwrite == true)
    {
        CopyFile(lpcstrSource, lpcstrDestination, false);
    }
    else
    {
        CopyFile(lpcstrSource, lpcstrDestination, true);
    }

    return 0;
}

/** \brief  kopiert rekursiv alle Dateien
 *
 * \param   source          Quellpfad
 * \param   destination     Zielpfad
 * \param   overwrite       Vorhandene Dateien überschreiben (true = ja; false = nein)
 *
 * \return  0               bei beenden der Funktion
 *          -1              Pfad ungültig
 *
 */
int FileOperations::copyFiles(const string source, const string destination, bool overwrite)
{

    string current_source_folder;                                                           // aktueller Pfad zum Quellordner
    string current_destination_folder;                                                      // aktueller Pfad zum Zielordner
    string folder_name;                                                                     // Name des gefundenen Ordners
    string file_name;                                                                       // Name der gefundenen Datei
    string buffer;                                                                          // Pufferspeicher

    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    current_source_folder = source + "\\*.*";
    current_destination_folder = destination;                                               // Pfad um Suche erweitern

    LPCSTR lpcstr_source = StringTools::strToLpcstr(current_source_folder);                 // Convertieren str -> LPCSTR
    HANDLE hSearch = FindFirstFile(lpcstr_source,&FData);                                   // Suchpfad angeben

    if (hSearch == INVALID_HANDLE_VALUE) return -1;                                         // Falls ungueltige Angabe, Funktion beenden

    do
    {

        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                             // Ordner gefunden
        {
            folder_name = FData.cFileName;                                                  // Schreibe Ordnernamen in String

            if( (folder_name != ".") && (folder_name != "..") )                             // Ordnernamen "." und ".." aussortieren
            {
                current_destination_folder  = destination + "\\" + folder_name;             // Zielpfad aktualisieren
                current_source_folder       = source + "\\" + folder_name;                  // Quellpfad aktualisieren

                LPCSTR lpcstr_dest = StringTools::strToLpcstr(current_destination_folder);  // Wandle string in LPCSTR um
                CreateDirectory(lpcstr_dest, NULL);                                         // Erstelle neuen Ordner an Ziel

                copyFiles(current_source_folder, current_destination_folder, true);         // Rufe Funktion rekursiv auf
            }
        }

        else                                                                                // Datei gefunden
        {
            file_name = FData.cFileName;

            if( file_name != "Thumbs.db")                                                   // Thumbs.db aussortieren
            {
                buffer = source + "\\" + file_name;
                LPCSTR lpcstr_file_source = StringTools::strToLpcstr(buffer) ;              // Quelldatei in LPCSTR umwandeln

                buffer = destination + "\\" + file_name;
                LPCSTR lpcstr_file_destination = StringTools::strToLpcstr(buffer);         // Zieldatei in LPCSTR umwandeln

                CopyFile( lpcstr_file_source, lpcstr_file_destination, false);              // Datei kopieren
            }


        }

        MoreFiles = FindNextFile(hSearch,&FData);                                           // Suche nächste Datei

    } while (MoreFiles);


    FindClose(hSearch);

    return 0;
}





