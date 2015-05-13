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

#include <QMessageBox>

#include "fileoperations.h"
#include "stringtools.h"

#define QT_MESSAGEBOX 1

using namespace std;


FileOperations::FileOperations()
{
    //ctor
}

FileOperations::~FileOperations()
{
    //dtor
}


inline std::string narrow(std::wstring const& text)
{
    std::locale const loc("");
    wchar_t const* from = text.c_str();
    std::size_t const len = text.size();
    std::vector<char> buffer(len + 1);
    std::use_facet<std::ctype<wchar_t> >(loc).narrow(from, from + len, '_', &buffer[0]);
    return std::string(&buffer[0], &buffer[len]);
}





/** \brief  Listet alle Ordner im Verzeichnis auf
 *
 * \param   strFolderPath               Verzeichnispfad
 *          &vecstrContainedFodlers     Liste der enthaltenen Ordner
 *
 * \return   0   kein Fehler vorhanden
 *          -1   Verzeichnis ungÃ¼ltig
 *
 */
int FileOperations::listFolders( string strFolderPath, vector <string> &vecstrContainedFolders)
{
    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;    

    LPCWSTR lpcwstrPath = StringTools::strToLpcwstr(strFolderPath + "\\*.*");

    HANDLE hSearch = FindFirstFile(lpcwstrPath,&FData);

    if (hSearch == INVALID_HANDLE_VALUE)                                        /** UngÃ¼ltiger Pfad angegeben **/
    {
        #if QT_MESSAGEBOX
        QMessageBox msgBox;
        msgBox.setWindowTitle("listFolders()");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Ungültiger Ordnerpfad angegeben!");
        msgBox.setInformativeText("Pfad: " + QString::fromStdString(strFolderPath));
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        #endif

        return -1;
    }

    /** Ordnernamen bestimmen **/
    do                                                                          /** Durchlaufe bis alle Dateien/Ordner geprÃ¼ft wurden **/
    {
        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                 /** Ordner gefunden **/
        {
                vecstrContainedFolders.push_back(narrow(FData.cFileName));              // HÃ¤nge Ordnername an die Liste an
        }

        MoreFiles = FindNextFile(hSearch,&FData);                               // Gehe zur nÃ¤chsten Datei/Ordner
    } while (MoreFiles);

    FindClose(hSearch);

    unsigned int i;

    for( i=0; i<vecstrContainedFolders.size(); i++)                             /** Entferne alle unnÃ¶tigen gefundenen Ordner **/
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
 *          -1   Verzeichnis ungÃ¼ltig
 *
 */
int FileOperations::findFile( const string strFolderPath, const string strSearchParam, bool bWholeWord, vector <string> &vecstrFoundFiles)
{
    string strFilename;
    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    vecstrFoundFiles.clear();

    LPCWSTR lpcwstrPath = StringTools::strToLpcwstr(strFolderPath + "\\*");

    HANDLE hSearch = FindFirstFile(lpcwstrPath,&FData);

    if (hSearch == INVALID_HANDLE_VALUE)                                        /** Ungültiger Pfad angegeben **/
    {
        #if QT_MESSAGEBOX
        QMessageBox msgBox;
        msgBox.setWindowTitle("findFile()");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Ungültiger Ordnerpfad angegeben!");
        msgBox.setInformativeText("Pfad: " + QString::fromStdString(strFolderPath)+ "\n" +
                                  "Suchparameter: " + QString::fromStdString(strSearchParam));
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        #endif

        return -1;
    }

    do
    {

        if (FData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)                 /** Datei gefunden **/
        {
            strFilename = narrow(FData.cFileName);                                      // Schreibe Ordnernamen in String

            if( bWholeWord == true && strFilename.compare(strSearchParam) == 0)
            {
                vecstrFoundFiles.push_back(strFilename);
            }
            else if ( bWholeWord == false && strFilename.find(strSearchParam) != string::npos)
            {
                vecstrFoundFiles.push_back(strFilename);                
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                               // Suche nÃ¤chste Datei

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
 *          -1   Verzeichnis ungÃ¼ltig
 *
 */
int FileOperations::findFolder( const string strPath, const string strSearchParam, bool bWholeWord, vector <string> &vecstrFoundFolders)
{    
    string strBuffer;
    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    vecstrFoundFolders.clear();

    LPCWSTR lpcwstrPath = StringTools::strToLpcwstr(strPath + "\\*.*");

    HANDLE hSearch = FindFirstFile(lpcwstrPath,&FData);                                     // Suchpfad angeben

    if (hSearch == INVALID_HANDLE_VALUE)                                                    /** UngÃ¼ltiger Pfad angegeben **/
    {
        #if QT_MESSAGEBOX
        QMessageBox msgBox;
        msgBox.setWindowTitle("findFolder");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Ungültiger Ordnerpfad angegeben!");
        msgBox.setInformativeText("Pfad: " + QString::fromStdString(strPath) + "\n" +
                                  "Suchparameter: " + QString::fromStdString(strSearchParam));
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        #endif

        return -1;
    }

    do
    {

        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                             /** Ordner gefunden **/
        {
            strBuffer = narrow(FData.cFileName);                                                    // Schreibe Ordnernamen in String

            if( bWholeWord == true && strBuffer.compare(strSearchParam) == 0)
            {
                vecstrFoundFolders.push_back(strBuffer);
            }
            else if ( bWholeWord == false && strBuffer.find(strSearchParam) != string::npos)
            {
                vecstrFoundFolders.push_back(strBuffer);
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                                           // Suche nÃ¤chste Datei

    } while (MoreFiles);

    FindClose(hSearch);

    return 0;
}


/** \brief  Überprüft, ob eine Datei existiert
 *
 * \param   filename    Name der Datei die Ã¼berprÃ¼ft werden soll
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

    LPCWSTR lpcwstrSource =  StringTools::strToLpcwstr(strSourceFilepath);
    LPCWSTR lpcwstrDestination = StringTools::strToLpcwstr(strDestinationFilepath);

    if(CopyFile(lpcwstrSource, lpcwstrDestination, !overwrite) == 0)
    {
        #if QT_MESSAGEBOX
        QString ErrorCode = QString("Fehlercode: %1").arg(GetLastError());
        QMessageBox msgBox;
        msgBox.setWindowTitle("copyFile()");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Kopieren fehlgeschlagen!");
        msgBox.setInformativeText("Quellpfad:  " + QString::fromStdString(strSourceFilepath)      + "\n" +
                                  "Zielpfad:   " + QString::fromStdString(strDestinationFilepath) + "\n" +
                                  ErrorCode);
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        #endif
    }

    return 0;
}

/** \brief  kopiert rekursiv alle Dateien
 *
 * \param   source          Quellpfad
 * \param   destination     Zielpfad
 * \param   overwrite       Vorhandene Dateien Ã¼berschreiben (true = ja; false = nein)
 *
 * \return  0               bei beenden der Funktion
 *          -1              Pfad ungÃ¼ltig
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

    current_destination_folder = destination;                                               // Pfad um Suche erweitern


    LPCWSTR lpcwstr_source =  StringTools::strToLpcwstr(source + "\\*.*");

    HANDLE hSearch = FindFirstFile(lpcwstr_source,&FData);                                   // Suchpfad angeben

    if (hSearch == INVALID_HANDLE_VALUE) return -1;                                         // Falls ungueltige Angabe, Funktion beenden

    do
    {

        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                             // Ordner gefunden
        {
            folder_name = narrow(FData.cFileName);                                                  // Schreibe Ordnernamen in String

            if( (folder_name != ".") && (folder_name != "..") )                             // Ordnernamen "." und ".." aussortieren
            {
                current_destination_folder  = destination + "\\" + folder_name;             // Zielpfad aktualisieren
                current_source_folder       = source + "\\" + folder_name;                  // Quellpfad aktualisieren

                LPCWSTR lpcwstr_dest =StringTools::strToLpcwstr(current_destination_folder);
                CreateDirectory(lpcwstr_dest, NULL);                                         // Erstelle neuen Ordner an Ziel

                copyFiles(current_source_folder, current_destination_folder, overwrite);         // Rufe Funktion rekursiv auf
            }
        }

        else                                                                                // Datei gefunden
        {
            file_name = narrow(FData.cFileName);

            if( file_name != "Thumbs.db")                                                   // Thumbs.db aussortieren
            {
                buffer = source + "\\" + file_name;
                LPCWSTR lpcwstr_file_source = (LPCWSTR) buffer.c_str() ;              // Quelldatei in LPCSTR umwandeln

                buffer = destination + "\\" + file_name;
                LPCWSTR lpcwstr_file_destination = (LPCWSTR) buffer.c_str();         // Zieldatei in LPCSTR umwandeln

                CopyFile( lpcwstr_file_source, lpcwstr_file_destination, !overwrite);              // Datei kopieren
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                                           // Suche nächste Datei

    } while (MoreFiles);


    FindClose(hSearch);

    return 0;
}





