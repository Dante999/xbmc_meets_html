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

    vecstrUmlaut.push_back("Ä");
    vecstrASCII.push_back("\x8E \b");

    vecstrUmlaut.push_back("ä");
    vecstrASCII.push_back("\x84 \b");

    vecstrUmlaut.push_back("Ö");
    vecstrASCII.push_back("\x99 \b");

    vecstrUmlaut.push_back("ö");
    vecstrASCII.push_back("\x94 \b");

    vecstrUmlaut.push_back("Ü");
    vecstrASCII.push_back("\x9A \b");

    vecstrUmlaut.push_back("ü");
    vecstrASCII.push_back("\x81 \b");

    vecstrUmlaut.push_back("ß");
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
