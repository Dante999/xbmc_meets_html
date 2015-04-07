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
_� "\x8E \b"
_� "\x84 \b"
_� "\x99 \b"
_� "\x94 \b"
_� "\x9A \b"
_� "\x81 \b"
_� "\xE1 \b"
**/


ConvertASCII::ConvertASCII()
{
    this->vecstrUmlaut.push_back("�");
    this->vecstrASCII.push_back("\x8E \b");

    this->vecstrUmlaut.push_back("�");
    this->vecstrASCII.push_back("\x84 \b");

    this->vecstrUmlaut.push_back("�");
    this->vecstrASCII.push_back("\x99 \b");

    this->vecstrUmlaut.push_back("�");
    this->vecstrASCII.push_back("\x94 \b");

    this->vecstrUmlaut.push_back("�");
    this->vecstrASCII.push_back("\x9A \b");

    this->vecstrUmlaut.push_back("�");
    this->vecstrASCII.push_back("\x81 \b");

    this->vecstrUmlaut.push_back("�");
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
