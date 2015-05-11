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

#include "fileoperations.h"

 #define PATH_TO_CONFIG "C:\\Users\\Dante999\\Documents\\GitHub\\xbmc_meets_html\\xbmc_meets_html\\config.ini"
 #define PATH_TO_CACHE "C:\\Users\\Dante999\\Documents\\GitHub\\xbmc_meets_html\\xbmc_meets_html\\cache.txt"


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

/** \brief ÷ffnen des Config Files
 *
 * \param   none
 *
 * \return  0   kein Fehler vorhanden
 *          1   keine config.ini vorhanden
 *
 */
int ConfigFile::openFile(void)
{
    this->fstrmConfigFile.open(PATH_TO_CONFIG);                                  // Datei √∂ffnen

    if( this->fstrmConfigFile == 0)                                            /** Datei konnte nicht ge√∂ffnet werden **/
    {
        cout << endl << "Keine config.ini vorhanden!" << endl;
        return 1;
    }

    else return 0;
}


/** \brief Schlieﬂen des Config Files
 *
 * \param   none
 *
 * \return  0   kein Fehler vorhanden
 *          1   config.ini konnte nicht geschlossen werden
 *
 */
int ConfigFile::closeFile(void)
{
    this->fstrmConfigFile.close();                                             // Schlie√üe Datei

    if( this->fstrmConfigFile.is_open() == true)                               /** Datei immer noch ge√∂ffnet **/
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
 *          1   config.ini konnte nicht ge√∂ffnet werden
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

    if ( openFile() != 0) return 1;                                             // config.ini √∂ffnen

    while(getline(this->fstrmConfigFile, strBuffer, '\n'))                     // Lies komplette Zeile ein
    {
      if(strBuffer.find('#') == string::npos)                                   /** Zeile nur beachten, wenn kein '#' in ihr steht **/
      {
         if(strBuffer.find(strParameter) != string::npos)                       /** Parameter wurde gefunden **/
         {
            sztEndPos = strBuffer.find_last_of('"');                            // Positon des letzten '"' finden
            strBuffer.erase(sztEndPos);                                         // alles ab letzte '"' l√∂schen

            sztStartPos = strBuffer.find_first_of('"');                         // Position des ersten '"' finden
            strBuffer.erase(0, (sztStartPos+1));                                // l√∂sche alles bis zum ersten '"' (falls diese erw√ºnscht sind, bis eine Position davor)

            strValue = strBuffer;

         }      // Suchwort gefunden
      }         // kein # gefunden
    }           // alle Zeilen einlesen

    if (closeFile() != 0) return 2;                                             // config.ini schlie√üen

    if(strValue == "")                                                          /** Falls Parameter nicht in der config.ini enthalten **/
    {
        cout << endl <<endl << "$ Eintrag \"" << strParameter << "\" nicht in der config.ini vorhanden!" << endl << endl ;
        this->iMissingEntry++;
        return 3;
    }

    return 0;
}

int ConfigFile::setValue(string strParameter, string strValue)
{
    string strBuffer;
    size_t sztStartPos;
    openFile();

        //fstream original_file (file_path.c_str(), ios::in | ios::binary);
        fstream buffer_file;
        buffer_file.open(PATH_TO_CACHE, ios::out);

        while(getline(this->fstrmConfigFile, strBuffer, '\n'))                     // Lies komplette Zeile ein
        {
          if(strBuffer.find('#') == string::npos)                                   /** Zeile nur beachten, wenn kein '#' in ihr steht **/
          {
             if(strBuffer.find(strParameter) != string::npos)                       /** Parameter wurde gefunden **/
             {
                sztStartPos = strBuffer.find_first_of('"');                         // Position des ersten '"' finden
                strBuffer.erase(sztStartPos+1);                                // lˆsche alles bis zum ersten '"' (falls diese erw¸nscht sind, bis eine Position davor)

                strBuffer = strBuffer + strValue + "\"";
             }      // Suchwort gefunden
          }         // kein # gefunden


            buffer_file << strBuffer << endl;
        }           // alle Zeilen einlesen

        closeFile();
        buffer_file.close();

        FileOperations::copyFile(PATH_TO_CACHE, PATH_TO_CONFIG, true);

        // Dateien kopieren


    return 0;



}

/** \brief  ‹berpr¸fen der config.ini
 *
 * \param   none
 *
 * \return  0   kein Fehler vorhanden
 *          1   Es sind fehlende Eintr‰ge in der config.ini vorhanden
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

    cout << endl << "‹berpr¸fung abgeschlossen!" << endl;
    cout << "Fehlende Eintr‰ge: " << iMissingEntry << endl;
    cout << "------------------------------------------------------------------------" << endl << endl;

    if(iMissingEntry != 0) return 1;

    return 0;
}


















