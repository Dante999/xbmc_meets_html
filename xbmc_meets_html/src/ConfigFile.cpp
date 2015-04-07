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




/** TODO

    - configfile wird bei CheckIfExists und OpenFile doppelt zugewiesen


**/




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
    this->ifstrmConfigFile.open("config.ini");

    if( this->ifstrmConfigFile == 0)
    {
        cout << endl << "Keine config.ini vorhanden!" << endl;
        return 1;
    }

    else return 0;
}


int ConfigFile::closeFile(void)
{
    this->ifstrmConfigFile.close();

    return 0;
}

int ConfigFile::getValue(string strParameter, string &strValue)
{
    string strBuffer = "";
    size_t sztStartPos;
    size_t sztEndPos;

    strValue = "";
    if ( openFile() != 0) return 1;

    while(getline(this->ifstrmConfigFile, strBuffer, '\n'))               // Lies komplette Zeile ein
    {
      if(strBuffer.find('#') == string::npos)                    // Zeile nur beachten, wenn kein '#' in ihr steht
      {
         if(strBuffer.find(strParameter) != string::npos)            // Ausführen wenn String gefunden wurde
         {
            sztEndPos = strBuffer.find_last_of('"');         // Positon des letzten '"' finden
            strBuffer.erase(sztEndPos);                      // alles ab letzte '"' löschen

            sztStartPos = strBuffer.find_first_of('"');          // Position des ersten '"' finden
            strBuffer.erase(0, (sztStartPos+1));     // lösche alles bis zum ersten '"' (falls diese erwünscht sind, bis eine Position davor)

            if (debug) cout << strParameter << "    " << strBuffer << endl;

            strValue = strBuffer;

         }      // Suchwort gefunden
      }         // kein # gefunden
    }           // alle Zeilen einlesen

    closeFile();


    if(strValue == "")
    {
        cout << endl <<endl << "$ Eintrag \"" << strParameter << "\" nicht in der config.ini vorhanden!" << endl << endl ;
        this->iMissingEntry++;
        return 2;
    }



    return 0;
}



int ConfigFile::testConfig(void)
{
    ConvertASCII *cConvert = new ConvertASCII();

    vector <string> strParameter;

    strParameter.push_back("path_movies");
    strParameter.push_back("path_destination");
    strParameter.push_back("cover_row");
    strParameter.push_back("cover_column");
    strParameter.push_back("name_cover");
    strParameter.push_back("codecs");

    string strBuffer = "";
    unsigned int i;

    cout << "------------------------------------------------------------------------" << endl;
    cout << cConvert->str("Überprüfe config Einträge...") << endl << endl;

    for( i=0; i<strParameter.size(); i++)
    {
        if (getValue(strParameter[i], strBuffer) == 0)
        {
            cout << strParameter[i] << " -> " << strBuffer << endl;
        }

    }

    cout << endl <<  cConvert->str("Überprüfung abgeschlossen!") << endl;
    cout << cConvert->str("Fehlende Einträge: ") << iMissingEntry << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;

    delete cConvert;

    return 0;
}


















