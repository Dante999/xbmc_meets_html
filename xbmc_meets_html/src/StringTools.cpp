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
 */#include "..\include\StringTools.h"

 #include <string>
 #include <vector>
 #include <iostream>

 #include <windows.h>

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
        cout << "Element " << i << " :  " << vecstrTmp.at(i) << endl;
    }

    cout << "-------------------------------------------------" << endl << endl;

    return 0;
}


