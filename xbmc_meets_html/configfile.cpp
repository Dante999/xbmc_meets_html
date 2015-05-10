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
    this->ifstrmConfigFile.open("config.ini");                                  // Datei öffnen

    if( this->ifstrmConfigFile == 0)                                            /** Datei konnte nicht geöffnet werden **/
    {
        cout << endl << "Keine config.ini vorhanden!" << endl;
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
    this->ifstrmConfigFile.close();                                             // Schließe Datei

    if( this->ifstrmConfigFile.is_open() == true)                               /** Datei immer noch geöffnet **/
    {
        cout << endl;
        cout << "config.ini konnte nicht geschlossen werden!" << endl;
        cout << endl;
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

    strValue = "";

    if ( openFile() != 0) return 1;                                             // config.ini öffnen

    while(getline(this->ifstrmConfigFile, strBuffer, '\n'))                     // Lies komplette Zeile ein
    {
      if(strBuffer.find('#') == string::npos)                                   /** Zeile nur beachten, wenn kein '#' in ihr steht **/
      {
         if(strBuffer.find(strParameter) != string::npos)                       /** Parameter wurde gefunden **/
         {
            sztEndPos = strBuffer.find_last_of('"');                            // Positon des letzten '"' finden
            strBuffer.erase(sztEndPos);                                         // alles ab letzte '"' löschen

            sztStartPos = strBuffer.find_first_of('"');                         // Position des ersten '"' finden
            strBuffer.erase(0, (sztStartPos+1));                                // lösche alles bis zum ersten '"' (falls diese erwünscht sind, bis eine Position davor)

            strValue = strBuffer;

         }      // Suchwort gefunden
      }         // kein # gefunden
    }           // alle Zeilen einlesen

    if (closeFile() != 0) return 2;                                             // config.ini schließen

    if(strValue == "")                                                          /** Falls Parameter nicht in der config.ini enthalten **/
    {
        cout << endl <<endl << "$ Eintrag \"" << strParameter << "\" nicht in der config.ini vorhanden!" << endl << endl ;
        this->iMissingEntry++;
        return 3;
    }

    return 0;
}


/** \brief  Überprüfen der config.ini
 *
 * \param   none
 *
 * \return  0   kein Fehler vorhanden
 *          1   Es sind fehlende Einträge in der config.ini vorhanden
 *
 */
int ConfigFile::testConfig(void)
{


    vector <string> strParameter;

    strParameter.push_back("path_movies");
    strParameter.push_back("path_destination");
    strParameter.push_back("cover_row");
    strParameter.push_back("cover_column");
    strParameter.push_back("name_cover");
    strParameter.push_back("codecs");

    string strBuffer = "";
    unsigned int i;

    for( i=0; i<strParameter.size(); i++)
    {
        if (getValue(strParameter[i], strBuffer) == 0)
        {
            cout << strParameter[i] << " -> " << strBuffer << endl;
        }

    }

    cout << endl << "Überprüfung abgeschlossen!" << endl;
    cout << "Fehlende Einträge: " << iMissingEntry << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;

    if(iMissingEntry != 0) return 1;

    return 0;
}


















