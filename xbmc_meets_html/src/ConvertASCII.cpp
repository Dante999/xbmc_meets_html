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

 #include "..\include\ConvertASCII.h"

 using namespace std;

ConvertASCII::ConvertASCII()
{
    this->vecstrUmlaut.push_back("Ä");
    this->vecstrASCII.push_back("\x8E \b");

    this->vecstrUmlaut.push_back("ä");
    this->vecstrASCII.push_back("\x84 \b");

    this->vecstrUmlaut.push_back("Ö");
    this->vecstrASCII.push_back("\x99 \b");

    this->vecstrUmlaut.push_back("ö");
    this->vecstrASCII.push_back("\x94 \b");

    this->vecstrUmlaut.push_back("Ü");
    this->vecstrASCII.push_back("\x9A \b");

    this->vecstrUmlaut.push_back("ü");
    this->vecstrASCII.push_back("\x81 \b");

    this->vecstrUmlaut.push_back("ß");
    this->vecstrASCII.push_back("\xE1 \b");
}

ConvertASCII::~ConvertASCII()
{
    //dtor
}

/** \brief  Umwandeln eines Strings im ASCII Format um Sonderzeichen
 *          Darzustellen
 *
 * \param   strText     zu konvertierender Text
 *
 * \return  0   kein Fehler vorhanden
 *          1   config.ini konnte nicht geschlossen werden
 *
 */
string ConvertASCII::str ( string strText)
{
    unsigned int i = 0;

    size_t sztCursorPos = 0;

    while( sztCursorPos != strText.size() )
    {
        for(i=0; i<this->vecstrUmlaut.size(); i++)
        {
            if(strText.find(this->vecstrUmlaut[i]) != string::npos)
            {
                sztCursorPos = strText.find(this->vecstrUmlaut[i]);

                strText.erase( sztCursorPos, 1);
                strText.insert(sztCursorPos, this->vecstrASCII[i]);
            }
        }

        sztCursorPos++;
    }

    return strText;
}
