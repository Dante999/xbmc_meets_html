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


LPCSTR StringTools::strToLpcstr(string strTmp)
{
    return strTmp.c_str();
}


int StringTools::printVecstr(vector <string> &vecstrTmp)
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
