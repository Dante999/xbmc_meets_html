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
 #include "..\include\ConvertASCII.h"
 #include <string>
 #include <vector>
 #include <iostream>

 using namespace std;

/**
_Ä "\x8E \b"
_ä "\x84 \b"
_Ö "\x99 \b"
_ö "\x94 \b"
_Ü "\x9A \b"
_ü "\x81 \b"
_ß "\xE1 \b"
**/


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
