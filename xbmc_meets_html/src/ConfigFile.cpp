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
 #include "..\include\ConfigFile.h"
 #include "..\include\ConvertASCII.h"

 #define debug 0

 using namespace std;

ConfigFile::ConfigFile()
{
    this->iMissingEntry = 0;
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
        this->iMissingEntry++;
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

int ConfigFile::testConfig(void)
{
    ConvertASCII *cConvert = new ConvertASCII();

    vector <string> strKeyWord;

    strKeyWord.push_back("path_movies");
    strKeyWord.push_back("path_destination");
    strKeyWord.push_back("cover_row");
    strKeyWord.push_back("cover_column");
    strKeyWord.push_back("name_cover");
    strKeyWord.push_back("codecs");

    string strBuffer = "";
    unsigned int i;

    cout << "------------------------------------------------------------------------" << endl;
    cout << cConvert->str("Überprüfe config Einträge...") << endl << endl;

    for( i=0; i<strKeyWord.size(); i++)
    {
        if (getValue(strKeyWord[i], strBuffer) == 0)
        {
            cout << strKeyWord[i] << " -> " << strBuffer << endl;
        }

    }

    cout << endl <<  cConvert->str("Überprüfung beendet!") << endl;
    cout << cConvert->str("Fehlende Einträge: ") << iMissingEntry << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;

    return 0;
}


















