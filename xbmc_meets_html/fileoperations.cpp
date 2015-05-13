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

FileOperations::FileOperations()
{
    //ctor
}

FileOperations::~FileOperations()
{
    //dtor
}

/** \brief  Wandle von wstring in string um
 *
 * \param   &text   wstring der umgewandelt werden soll
 *
 * \return   Text als string
 *
 */
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
 * \param   folderPath           Verzeichnispfad
 *          containedFodlers     Liste der enthaltenen Ordner
 *
 * \return   0   kein Fehler vorhanden
 *          -1   Verzeichnis ungültig
 *
 */
int FileOperations::listFolders( std::string folderPath, std::vector <std::string> &containedFolders)
{
    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;
    unsigned int i;
    std::string folderName;
    LPCWSTR lpcwstrPath = StringTools::strToLpcwstr(folderPath + "\\*.*");                          // string -> lpcwstr
    containedFolders.clear();

    HANDLE hSearch = FindFirstFile(lpcwstrPath,&FData);                                             // Öffne handler

    if (hSearch == INVALID_HANDLE_VALUE)                                                            /** Ungültiger Pfad angegeben **/
    {
        #if QT_MESSAGEBOX                                                                           // Gib eine Messagebox aus
        QMessageBox msgBox;
        msgBox.setWindowTitle("listFolders()");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Ungültiger Ordnerpfad angegeben!");
        msgBox.setInformativeText("Pfad: " + QString::fromStdString(folderPath));
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        #endif

        return -1;
    }

    do
    {
        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                                     /** Ordner gefunden **/
        {
            folderName = narrow(FData.cFileName);                                                   // Speichere gefundenen Ordnernamen zwischen

            if(folderName != "." && folderName != "..")                                             // Ordnernamen "." und ".." ignorieren
            {
                containedFolders.push_back(narrow(FData.cFileName));                                // Hänge Ordnername an die Liste an
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                                                   // Gehe zur nächsten Datei/Ordner
    } while (MoreFiles);

    FindClose(hSearch);                                                                             // Schließe handler

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
int FileOperations::findFile( const std::string folderPath, const std::string searchParam, bool bWholeWord, std::vector <std::string> &foundFiles)
{
    std::string filenameBuffer;
    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;
    LPCWSTR lpcwstrPath = StringTools::strToLpcwstr(folderPath + "\\*");
    foundFiles.clear();

    HANDLE hSearch = FindFirstFile(lpcwstrPath,&FData);

    if (hSearch == INVALID_HANDLE_VALUE)                                                            /** Ungültiger Pfad angegeben **/
    {
        #if QT_MESSAGEBOX
        QMessageBox msgBox;
        msgBox.setWindowTitle("findFile()");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Ungültiger Ordnerpfad angegeben!");
        msgBox.setInformativeText("Pfad: " + QString::fromStdString(folderPath)+ "\n" +
                                  "Suchparameter: " + QString::fromStdString(searchParam));
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        #endif

        return -1;
    }

    do
    {

        if (FData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)                                     /** Datei gefunden **/
        {
            filenameBuffer = narrow(FData.cFileName);                                               // Schreibe Ordnernamen in String

            if( bWholeWord == true && filenameBuffer.compare(searchParam) == 0)                     /** Es wird nach kompletten Dateinamen gesucht **/
            {
                foundFiles.push_back(filenameBuffer);                                               // Hänge Dateinamen an die Liste an
            }
            else if ( bWholeWord == false && filenameBuffer.find(searchParam) != std::string::npos) /** Es wird nach einem Tei im Dateinamen gesucht **/
            {
                foundFiles.push_back(filenameBuffer);                                               // Hänge Dateinamen an die Liste an
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                                                   // Suche nächste Datei

    } while (MoreFiles);

    FindClose(hSearch);                                                                             // Schließe handler

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
int FileOperations::findFolder( const std::string folderPath, const std::string searchParam, bool bWholeWord, std::vector <std::string> &foundFolders)
{    
    std::string strBuffer;
    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    foundFolders.clear();

    LPCWSTR lpcwstrPath = StringTools::strToLpcwstr(folderPath + "\\*.*");

    HANDLE hSearch = FindFirstFile(lpcwstrPath,&FData);                                             // Suchpfad angeben

    if (hSearch == INVALID_HANDLE_VALUE)                                                            /** Ungültiger Pfad angegeben **/
    {
        #if QT_MESSAGEBOX
        QMessageBox msgBox;
        msgBox.setWindowTitle("findFolder");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Ungültiger Ordnerpfad angegeben!");
        msgBox.setInformativeText("Pfad: " + QString::fromStdString(folderPath) + "\n" +
                                  "Suchparameter: " + QString::fromStdString(searchParam));
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        #endif

        return -1;
    }

    do
    {

        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                                     /** Ordner gefunden **/
        {
            strBuffer = narrow(FData.cFileName);                                                    // Schreibe Ordnernamen in String

            if( bWholeWord == true && strBuffer.compare(searchParam) == 0)
            {
                foundFolders.push_back(strBuffer);
            }
            else if ( bWholeWord == false && strBuffer.find(searchParam) != std::string::npos)
            {
                foundFolders.push_back(strBuffer);
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                                                   // Suche nächste Datei

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
bool FileOperations::fileExists(const std::string &filename)
{
    struct stat buf;

    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }

    return false;
}

/** \brief  Kopiert eine Datei
 *
 * \param   pathExistingFile    Quellpfad zur Datei
 * \param   pathNewFile         Zielpfad  zur Datei (mit evtl. neuem Namen)
 * \param   overwrite           Vorhandene Dateien überschreiben (true = ja; false = nein)
 *
 * \return   0                  bei beenden der Funktion
 *          -1                  Pfad ungültig
 *
 */
int FileOperations::copyFile(const std::string pathExistingFile, const std::string PathNewFile, bool overwrite )
{
    if(fileExists(pathExistingFile) == false)
    {
        return -1;
    }

    LPCWSTR lpcwstrSource =  StringTools::strToLpcwstr(pathExistingFile);
    LPCWSTR lpcwstrDestination = StringTools::strToLpcwstr(PathNewFile);

    if(CopyFile(lpcwstrSource, lpcwstrDestination, !overwrite) == 0)
    {
        #if QT_MESSAGEBOX
        QString ErrorCode = QString("Fehlercode: %1").arg(GetLastError());
        QMessageBox msgBox;
        msgBox.setWindowTitle("copyFile()");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Kopieren fehlgeschlagen!");
        msgBox.setInformativeText("Quellpfad:  " + QString::fromStdString(pathExistingFile)      + "\n" +
                                  "Zielpfad:   " + QString::fromStdString(PathNewFile) + "\n" +
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
 * \param   overwrite       Vorhandene Dateien überschreiben (true = ja; false = nein)
 *
 * \return  0               bei beenden der Funktion
 *          -1              Pfad ungültig
 *
 */
int FileOperations::copyFiles(const std::string sourcePath, const std::string destinationPath, bool overwrite)
{
    std::string newSourcePath;                                                                      // aktueller Pfad zum Quellordner
    std::string newDestinationPath;                                                                 // aktueller Pfad zum Zielordner
    std::string folderName;                                                                         // Name des gefundenen Ordners
    std::string fileName;                                                                           // Name der gefundenen Datei
    std::string strBuffer;                                                                          // Pufferspeicher

    WIN32_FIND_DATA FData;
    BOOL MoreFiles = FALSE;

    LPCWSTR lpcwstrSourcePath =  StringTools::strToLpcwstr(sourcePath + "\\*.*");

    HANDLE hSearch = FindFirstFile(lpcwstrSourcePath,&FData);                                       // Suchpfad angeben

    if (hSearch == INVALID_HANDLE_VALUE) return -1;                                                 // Falls ungueltige Angabe, Funktion beenden

    do
    {
        if (FData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)                                     // Ordner gefunden
        {
            folderName = narrow(FData.cFileName);                                                   // Schreibe Ordnernamen in String

            if( (folderName != ".") && (folderName != "..") )                                       // Ordnernamen "." und ".." aussortieren
            {
                newDestinationPath  = destinationPath   + "\\" + folderName;                        // Zielpfad aktualisieren
                newSourcePath       = sourcePath        + "\\" + folderName;                        // Quellpfad aktualisieren

                LPCWSTR lpcwstrNewDestinationPath = StringTools::strToLpcwstr(newDestinationPath);
                CreateDirectory(lpcwstrNewDestinationPath, NULL);                                   // Erstelle neuen Ordner an Ziel

                copyFiles(newSourcePath, newDestinationPath, overwrite);                            // Rufe Funktion rekursiv auf
            }
        }

        else                                                                                        // Datei gefunden
        {
            fileName = narrow(FData.cFileName);

            if( fileName != "Thumbs.db")                                                            // Thumbs.db aussortieren
            {
                strBuffer = sourcePath + "\\" + fileName;
                LPCWSTR lpcwstrFileSource = StringTools::strToLpcwstr(strBuffer);

                strBuffer = destinationPath + "\\" + fileName;
                LPCWSTR lpcwstrFileDestination = StringTools::strToLpcwstr(strBuffer);

                CopyFile( lpcwstrFileSource, lpcwstrFileDestination, !overwrite);                   // Datei kopieren
            }
        }

        MoreFiles = FindNextFile(hSearch,&FData);                                                   // Suche nächste Datei

    } while (MoreFiles);


    FindClose(hSearch);

    return 0;
}





