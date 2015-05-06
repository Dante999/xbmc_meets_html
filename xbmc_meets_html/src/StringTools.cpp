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

 #include <windows.h>

 #include "..\include\StringTools.h"

 using namespace std;

StringTools::StringTools()
{
    //ctor
}

StringTools::~StringTools()
{
    //dtor
}

/** \brief  Setzt die Vektorfelder zu einem String zusammen und kennzeichne diese mit
 *          einem Trennzeichen
 *          Beispiel:
 *          vecstrInVector[0] = "Dies"
 *          vecstrInVector[1] = "ist"
 *          vecstrInVector[2] = "ein"
 *          vecstrInVector[3] = "Test"
 *          strConnector = ";"
 *
 *          -> &strOutString = "Dies;ist;ein;Test"
 *
 *
 * \param   vecstrInVector  Vektor der umgewandelt werden soll
 *          &strOutString   String in dem die Vektorfelder gespeichert werden sollen
 *          strConnector    Trennzeichen zwischen den Vektorfeldern
 *
 * \return  0   kein Fehler vorhanden
 *
 *
 */
int StringTools::vecToStr ( vector <string> vecstrInVector, string &strOutString, string strConnector)
{
    unsigned int uiVecSize = 0;

    strOutString   = "";

    for(uiVecSize=0; uiVecSize<vecstrInVector.size(); uiVecSize++)
    {
        if(uiVecSize == 0)  strOutString += vecstrInVector[uiVecSize];
        else                strOutString  =  strOutString + strConnector + vecstrInVector[uiVecSize];
    }

    return 0;
}

/** \brief  Wandelt einen String in einen Vektor um. Dabei wird ein Trennzeichen vorgegeben um die
 *          Stringteile auf die Vektorfelder aufzuteilen
 *          Beispiel:
 *          strInString = "Dies;ist;ein;Test"
 *          strConnector = ";"
 *
 *          -> vecstrInVector[0] = "Dies"
 *          -> vecstrInVector[1] = "ist"
 *          -> vecstrInVector[2] = "ein"
 *          -> vecstrInVector[3] = "Test"
 *
 * \param   strInString         String der in einen Vektor umgewandelt werden soll
 *          vecstrOutVector     Vektor in dem der aufgeteilte String geschrieben werden soll
 *          strConnector        Trennzeichen im String
 *
 * \return  0   kein Fehler vorhanden
 *
 *
 */
int StringTools::strToVec (string strInString, vector <string> &vecstrOutVector, string strConnector)
{
    size_t  sztLeftPos  = 0;
    size_t  sztRightPos = 0;
    string  strBuffer    = "";

    vecstrOutVector.clear();

    while( sztRightPos != string::npos)
    {
        sztRightPos = strInString.find(strConnector, sztLeftPos);
        strBuffer = strInString.substr(sztLeftPos, sztRightPos-sztLeftPos);
        sztLeftPos = sztRightPos;

        vecstrOutVector.push_back(strBuffer);

        sztLeftPos++;
    }


    return 0;
}

/** \brief  Wandelt einen String in das Format LPCSTR um
 *
 * \param   strTmp  String der umgewandelt werden soll
 *
 * \return  String als LPCSTR
 *
 */
LPCSTR StringTools::strToLpcstr(string strTmp)
{
    return strTmp.c_str();
}

/** \brief  Gibt den Inhalt des Vektors auf der Konsole aus
 *
 * \param   &vecstrTmp  Vektor, der ausgegeben werden soll
 *
 * \return  0   kein Fehler
 *
 */
int StringTools::printVecstr(vector <string> vecstrTmp)
{
    unsigned int i;

    cout << endl << "-------------------------------------------------" << endl;
    cout << "Inhalt des Vectors" << endl << endl;

    for( i=0; i<vecstrTmp.size(); i++)
    {
        cout << "Element " << i << " :  >" << vecstrTmp.at(i) << "<" << endl;
    }

    cout << "-------------------------------------------------" << endl << endl;

    return 0;
}

/** \brief  Vergleicht den Inhalt aller Vektorfelder untereinander und gibt einen
 *          String zurück mit dem Bereich, der bei allen Vektorfelder identisch ist
 *          Beispiel:
 *          vecstrTmp[0] = "Dies ist ein Test"
 *          vecstrTmp[1] = "Dies ist ein Unterschied"
 *          vecstrTmp[2] = "Dies ist kein Test"
 *
 *          -> return = "Dies ist "
 *
 * \param   Vektor, dessen Vektorfelder verglichen werden sollen
 *
 * \return  Substring, der bei allen Vektorfeldern von Beginn an identisch ist
 *
 */
string StringTools::compareVecAttr(vector <string> &vecstrTmp)
{
    string strBuffer;

    unsigned int i;

    if(vecstrTmp.size() == 0)
    {
        return "";
    }

    else if (vecstrTmp.size() == 1)
    {
        return vecstrTmp[0];
    }

    else
    {
        strBuffer = vecstrTmp[1];

        for( i=0; i<vecstrTmp.size(); i++)
        {
            if( strBuffer.size() > vecstrTmp[i].size() )
            {
                strBuffer.erase(vecstrTmp[i].size());
            }

            unsigned int j;

            for (j=0; j < strBuffer.size(); j++)
            {
                if (strBuffer.compare(0, j, vecstrTmp[i].substr(0, j) ) != 0)
                {
                    strBuffer.erase(j-1);
                }
            }
        }
    }

    return strBuffer;
}

/** \brief  Entfernt die Dateiendung aus einem Dateinamen
 *          Beispiel: "Poster.jpg" -> "Poster"
 *
 * \param   Dateiname
 *
 * \return  0   kein Fehler
 *          1   keine Dateiendung vorhanden
 *
 */
int StringTools::removeFileExtension(string &strFileName)
{
    size_t sztPos = 0;

    sztPos = strFileName.find_last_of(".");                 // Finde letzten Punkt im Dateinamen

    if(sztPos != string::npos)                              /** Dateiendung gefunden **/
    {
        strFileName.erase(sztPos);                          // Lösche Dateiendung
    }

    else                                                    /** keine Dateiendung vorhanden **/
    {
        return 1;
    }

    return 0;
}




