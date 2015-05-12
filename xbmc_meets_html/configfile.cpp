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
 #include <fstream>
 #include <iostream>
 #include <vector>

 #include "configfile.h"
 #include "windows.h"
 #include <sys/stat.h>
 #include <QMessageBox>

 #include "fileoperations.h"
#include "stringtools.h"

 #define QT_MESSAGEBOX 1

 using namespace std;

ConfigFile::ConfigFile()
{    
    //ctor
}

ConfigFile::~ConfigFile()
{
    //dtor
}

/** \brief Öffnen des Config Files
 *
 * \param   none
 *
 * \return  0   kein Fehler vorhanden
 *          1   keine config.ini vorhanden
 *
 */
int ConfigFile::openFile(void)
{
    this->fstrmConfigFile.open(PATH_TO_CONFIG);                                  // Datei öffnen    

    if( this->fstrmConfigFile == 0)                                            /** Datei konnte nicht geöffnet werden **/
    {
        #if QT_MESSAGEBOX
        QMessageBox msgBox;
        msgBox.setWindowTitle("config.ini");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("config.ini konnte nicht geöffnet werden!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        #endif

        return 1;
    }

    else return 0;
}


/** \brief Schließen des Config Files
 *
 * \param   none
 *
 * \return  0   kein Fehler vorhanden
 *          1   config.ini konnte nicht geschlossen werden
 *
 */
int ConfigFile::closeFile(void)
{    
    this->fstrmConfigFile.close();                                             // Schließe Datei

    if( this->fstrmConfigFile.is_open() == true)                               /** Datei immer noch geöffnet **/
    {
        #if QT_MESSAGEBOX
        QMessageBox msgBox;
        msgBox.setWindowTitle("config.ini");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("config.ini konnte nicht geschlossen werden!");
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        #endif

        return 1;
    }

    return 0;
}


/** \brief  Auslesen eines Wertes in der config.ini
 *
 * \param   strParameter    Parameter in der config.ini
 *          &strValue       Wert der in der config.ini steht
 *
 * \return  0   kein Fehler vorhanden
 *          1   config.ini konnte nicht geöffnet werden
 *          2   config.ini konnte nicht geschlossen werden
 *          3   Eintrag nicht in der config.ini gefunden
 *
 */
int ConfigFile::getValue(string strParameter, string &strValue)
{
    string strBuffer = "";
    size_t sztStartPos = 0;
    size_t sztEndPos = 0;
    strValue = "kein Eintrag";

    if ( openFile() != 0) return 1;                                             // config.ini öffnen

    while(getline(this->fstrmConfigFile, strBuffer, '\n'))                      // Lies komplette Zeile ein
    {
      if(strBuffer.find('#') == string::npos)                                   /** Zeile nur beachten, wenn kein '#' in ihr steht **/
      {
         if(strBuffer.find(strParameter) != string::npos)                       /** Parameter wurde gefunden **/
         {
             sztStartPos = strBuffer.find_first_of('"');                        // Position des ersten '"' finden
             sztEndPos = strBuffer.find_last_of('"');                           // Positon des letzten '"' finden

             strValue = strBuffer.substr(sztStartPos+1, sztEndPos-(sztStartPos+1));
         }      // Suchwort gefunden
      }         // kein # gefunden
    }           // alle Zeilen einlesen

    if (closeFile() != 0) return 2;                                             // config.ini schließen    

    if(strValue == "kein Eintrag")                                              /** Falls Parameter nicht in der config.ini enthalten **/
    {
        #if QT_MESSAGEBOX
        QMessageBox msgBox;
        msgBox.setWindowTitle("config.ini");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Wert in der config.ini nicht gefunden!");
        msgBox.setInformativeText("Wert: " + QString::fromStdString(strParameter));
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        #endif
        return 3;
    }

    return 0;
}

int ConfigFile::setValue(string strParameter, string strValue)
{
    fstream fstrmCacheFile;                                                     // Pointer auf cache.txt
    string strBuffer;                                                           // Buffer Variable
    size_t sztStartPos;                                                         // Position im String


    if(openFile() != 0) return 1;                                               // Öffne config.ini
    fstrmCacheFile.open(PATH_TO_CACHE, ios::out);                               // Öffne cache.txt

    while(getline(this->fstrmConfigFile, strBuffer, '\n'))                      // Lies komplette Zeile ein
    {
      if(strBuffer.find('#') == string::npos)                                   /** Zeile nur beachten, wenn kein '#' in ihr steht **/
      {
         if(strBuffer.find(strParameter) != string::npos)                       /** Parameter wurde gefunden **/
         {
            sztStartPos = strBuffer.find_first_of('"');                         // Position des ersten '"' finden
            strBuffer.erase(sztStartPos);                                       // Lösche alles ab dem ersten '"'

            strBuffer = strBuffer + "\"" + strValue + "\"";                     // Überschreibe mit neuem Wert
         }
      }
        fstrmCacheFile << strBuffer << endl;                                    // Schreibe geänderte Zeile in cache.txt
    }

    if(closeFile() != 0) return 2;                                              // Schließe config.ini
    fstrmCacheFile.close();                                                     // Schließe cache.txt

    FileOperations::copyFile(PATH_TO_CACHE, PATH_TO_CONFIG, true);              // Überschreibe config.ini mit cache.txt

    getValue(strParameter, strBuffer);                                          // Überprüfe neuen Wert

    if(strBuffer != strValue)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("config.ini");
        msgBox.setText("Wert konnte nicht in der config.ini gespeichert werden");
        msgBox.setInformativeText("Parameter: " + QString::fromStdString(strParameter) + "\n" +
                                  "alter Wert: " + QString::fromStdString(strBuffer) + "\n" +
                                  "fehlgeschlagener Wert: " + QString::fromStdString(strValue) + "\n");
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
    }

    return 0;
}









