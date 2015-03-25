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
    //ctor
}

ConvertASCII::~ConvertASCII()
{
    //dtor
}

string ConvertASCII::str ( string strText)
{
    vector <string> vecstrUmlaut;
    vector <string> vecstrASCII;

    vecstrUmlaut.push_back("�");
    vecstrASCII.push_back("\x8E \b");

    vecstrUmlaut.push_back("�");
    vecstrASCII.push_back("\x84 \b");

    vecstrUmlaut.push_back("�");
    vecstrASCII.push_back("\x99 \b");

    vecstrUmlaut.push_back("�");
    vecstrASCII.push_back("\x94 \b");

    vecstrUmlaut.push_back("�");
    vecstrASCII.push_back("\x9A \b");

    vecstrUmlaut.push_back("�");
    vecstrASCII.push_back("\x81 \b");

    vecstrUmlaut.push_back("�");
    vecstrASCII.push_back("\xE1 \b");

    unsigned int i;

    size_t sztCursorPos;


    while( sztCursorPos != strText.size() )
    {
        for(i=0; i<vecstrUmlaut.size(); i++)
        {
            if(strText.find(vecstrUmlaut[i]) != string::npos)
            {
                sztCursorPos = strText.find(vecstrUmlaut[i]);

                strText.erase( sztCursorPos, 1);
                strText.insert(sztCursorPos, vecstrASCII[i]);
            }
        }

        sztCursorPos++;

    }

    return strText;}
