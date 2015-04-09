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
 */#include "..\\include\NfoFile.h"

 #include "..\\include\ConvertASCII.h"
 #include <iostream>
 #include <vector>
 #include <string>
 #include <cstring>


using namespace std;


NfoFile::NfoFile()
{
    //ctor
}

NfoFile::~NfoFile()
{
    //dtor
}

int NfoFile::openFile(void)
{
    this->ifstrmNfoFile.open(this->strNfoPath.c_str() );

    if( this->ifstrmNfoFile == 0)
    {
        cout << endl;
        cout << "Keine .nfo Datei vorhanden!" << endl;
        cout << "Pfad: " << this->strNfoPath << endl;
        cout << endl;
        return 1;
    }

    else return 0;
}

int NfoFile::closeFile(void)
{
    this->ifstrmNfoFile.close();

    if( this->ifstrmNfoFile.is_open() == true)
    {
        cout << endl;
        cout << ".nfo Datei konnte nicht geschlossen werden!" << endl;
        cout << "Pfad: " << this->strNfoPath << endl;
        cout << endl;
        return 1;
    }

    return 0;

}

int NfoFile::getValue(string strParameter, string strNfoPath, vector <string> &vecstrValue)
{
    vecstrValue.clear();

    string strBuffer = "";
    bool bPosInsideOuterClippers = false;

    size_t sztStartPos = 0;
    size_t sztEndPos   = 0;
    int iFoundResults = 0;


    this->strKeyWord = strParameter;
    this->strNfoPath = strNfoPath;


    if (openFile() != 0) return 1;

    getClippers();


    while(getline(this->ifstrmNfoFile, strBuffer, ('\n')) )
    {

        if(strBuffer.find(this->strLeftOuterClipper) != string::npos)
        {
            bPosInsideOuterClippers = true;
        }
        else if(strBuffer.find(this->strRightOuterClipper) != string::npos)
        {
            bPosInsideOuterClippers = false;
        }

        if(strBuffer.find(strLeftInnerClipper) != string::npos && (bPosInsideOuterClippers == true))
        {
            sztStartPos = strBuffer.find_first_of(strLeftInnerClipper);
            sztEndPos   = strBuffer.find_last_of(strRightInnerClipper);

            strBuffer.erase( (sztEndPos+1) - strRightInnerClipper.length() );
            strBuffer.erase( 0, sztStartPos + strLeftInnerClipper.length() );

            iFoundResults++;

            vecstrValue.push_back(strBuffer);
        }
    }

    if(iFoundResults == 0)
    {
        cout << endl;
        cout << "Entsprechenden Eintrag nicht in der .nfo Datei gefunden!" << endl;
        cout << "Eintrag: " << this->strKeyWord << endl;
        cout << "Pfad: " << this->strNfoPath << endl;
        cout << endl;

        return 1;
    }

    return 0;
}



int NfoFile::getClippers(void)
{

    if (this->strKeyWord == "title")
    {
        this->strLeftInnerClipper   = "<title>";
        this->strRightInnerClipper  = "</title>";
        this->strLeftOuterClipper   = "";
        this->strRightOuterClipper  = "";
    }

    else if (this->strKeyWord == "year")
    {
        this->strLeftInnerClipper   = "<year>";
        this->strRightInnerClipper  = "</year>";
        this->strLeftOuterClipper   = "";
        this->strRightOuterClipper  = "";
    }

    else if (this->strKeyWord == "plot")
    {
        this->strLeftInnerClipper   = "<plot>";
        this->strRightInnerClipper  = "</plot>";
        this->strLeftOuterClipper   = "";
        this->strRightOuterClipper  = "";
    }

    else if (this->strKeyWord == "runtime")
    {
        this->strLeftInnerClipper   = "<runtime>";
        this->strRightInnerClipper  = "</runtime>";
        this->strLeftOuterClipper   = "";
        this->strRightOuterClipper  = "";
    }

    else if (this->strKeyWord == "genre")
    {
        this->strLeftInnerClipper   = "<genre>";
        this->strRightInnerClipper  = "</genre>";
        this->strLeftOuterClipper   = "";
        this->strRightOuterClipper  = "";
    }

    else if (this->strKeyWord == "actor")
    {
        this->strLeftInnerClipper   = "<name>";
        this->strRightInnerClipper  = "</name>";
        this->strLeftOuterClipper   = "<actor>";
        this->strRightOuterClipper  = "</actor>";
    }

    else if(this->strKeyWord == "fsk")
    {
        this->strLeftInnerClipper   = "<mpaa>";
        this->strRightInnerClipper  = "</mpaa>";
        this->strLeftOuterClipper   = "";
        this->strRightOuterClipper  = "";
    }

    else if(this->strKeyWord == "video_codec")
    {
        this->strLeftInnerClipper   = "<codec>";
        this->strRightInnerClipper  = "</codec>";
        this->strLeftOuterClipper   = "<video>";
        this->strRightOuterClipper  = "</video>";
    }

    else if(this->strKeyWord == "video_height")
    {
        this->strLeftInnerClipper   = "<height>";
        this->strRightInnerClipper  = "</height>";
        this->strLeftOuterClipper   = "<video>";
        this->strRightOuterClipper  = "</video>";
    }

    else if(this->strKeyWord == "video_width")
    {
        this->strLeftInnerClipper   = "<width>";
        this->strRightInnerClipper  = "</width>";
        this->strLeftOuterClipper   = "<video>";
        this->strRightOuterClipper  = "</video>";
    }

    else if(this->strKeyWord == "audio_codec")
    {
        this->strLeftInnerClipper   = "<codec>";
        this->strRightInnerClipper  = "</codec>";
        this->strLeftOuterClipper   = "<audio>";
        this->strRightOuterClipper  = "</audio>";
    }

    else if(this->strKeyWord == "audio_channels")
    {
        this->strLeftInnerClipper   = "<channels>";
        this->strRightInnerClipper  = "</channels>";
        this->strLeftOuterClipper   = "<audio>";
        this->strRightOuterClipper  = "</audio>";
    }

    else if(this->strKeyWord == "audio_language")
    {
        this->strLeftInnerClipper   = "<language>";
        this->strRightInnerClipper  = "</language>";
        this->strLeftOuterClipper   = "<audio>";
        this->strRightOuterClipper  = "</audio>";

    }

    else
    {
        cout << endl;
        cout << "$ getClippers(): falsches Eingabeparameter in Funktion!" << endl;
        cout << "$ Parameter: " << this->strKeyWord << endl;
        cout << endl;

        return 1;
    }

    return 0;

}




int NfoFile::testNfo (void)
{
    ConvertASCII *cConvert = new ConvertASCII();
    int iErrors = 0;

    this->strNfoPath = "TestFiles\\movie.nfo";

    cout << "------------------------------------------------------------------------" << endl;
    cout << cConvert->str("Überprüfe Klasse NfoFile...") << endl;

    if( openFile() == 0)
    {
        cout << endl << cConvert->str("Test-Nfo File erfolgreich geöffnet!") << endl;
    }
    else iErrors++;

    if( closeFile() == 0)
    {
        cout << endl << cConvert->str("Test-Nfo File erfolgreich geschlossen!") << endl;
    }
    else iErrors++;

    cout << endl << cConvert->str("Überprüfung abgeschlossen!") << endl;
    cout << "Fehler: " << iErrors << endl;
    cout << "------------------------------------------------------------------------" << endl;
    delete cConvert;

    return 0;
}


