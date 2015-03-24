/*-----------------------------------------------------------------------------
 *                         Fachhochschule Ingolstadt
 *     Fakultät Elektrotechnik und Informatik - Studiengang EIT1a
 *-----------------------------------------------------------------------------
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
 #include "..\include\ConfigFile.h"

 #define debug 1

 using namespace std;

ConfigFile::ConfigFile()
{
    //ctor
}

ConfigFile::~ConfigFile()
{
    //dtor
}

int ConfigFile::openFile(void)
{
    if(checkIfExists() == 0)
    {
        this->ifConfigFile.open("config.ini");
        return 0;
    }
    else return 1;
}

int ConfigFile::closeFile(void)
{
    this->ifConfigFile.close();

    return 0;
}

int ConfigFile::getValue(string strKeyWord, string &strValue)
{
    string strBuffer = "";
    size_t sztStartPos;
    size_t sztEndPos;

    strValue = "";
    if ( openFile() != 0) return 1;

    while(getline(this->ifConfigFile, strBuffer, '\n'))               // Lies komplette Zeile ein
    {
      if(strBuffer.find('#') == string::npos)                    // Zeile nur beachten, wenn kein '#' in ihr steht
      {
         if(strBuffer.find(strKeyWord) != string::npos)            // Ausführen wenn String gefunden wurde
         {
            sztEndPos = strBuffer.find_last_of('"');         // Positon des letzten '"' finden
            strBuffer.erase(sztEndPos);                      // alles ab letzte '"' löschen

            sztStartPos = strBuffer.find_first_of('"');          // Position des ersten '"' finden
            strBuffer.erase(0, (sztStartPos+1));     // lösche alles bis zum ersten '"' (falls diese erwünscht sind, bis eine Position davor)

            if (debug) cout << strKeyWord << "    " << strBuffer << endl;

            strValue = strBuffer;

         }      // Suchwort gefunden
      }         // kein # gefunden
    }           // alle Zeilen einlesen

    closeFile();


    if(strValue == "")
    {
        cout << endl <<endl << "$ Eintrag \"" << strKeyWord << "\" nicht in der config.ini vorhanden!" << endl << endl ;
        return 2;
    }



    return 0;
}

int ConfigFile::checkIfExists(void)
{
    fstream streamConfigFile ("config.ini", ios::in);                // Datei öffnen

    if( streamConfigFile == 0)
    {
        cout << endl << "Keine config.ini vorhanden!" << endl;
        return 1;
    }
    else return 0;
}


















