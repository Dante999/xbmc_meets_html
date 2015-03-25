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

NfoFile::NfoFile()
{
    //ctor
}

NfoFile::~NfoFile()
{
    //dtor
}


int NfoFile::getClippers(void)
{
#if 0
    if (this->strKeyWord == "title")
    {
        this->strLeftInnerClipper  = "<title>";
        this->strRightInnerClipper    = "</title>";
        this->strLeftOuterClipper  = "";
        this->strRightOuterClipper    = "";
    }

    else if (this->strKeyWord == "year")
    {
        this->strLeftInnerClipper  = "<year>";
        this->strRightInnerClipper    = "</year>";
        this->strLeftOuterClipper  = "";
        this->strRightOuterClipper    = "";
    }

    else if (this->strKeyWord == "plot")
    {
        this->strLeftInnerClipper  = "<plot>";
        this->strRightInnerClipper    = "</plot>";
        this->strLeftOuterClipper  = "";
        this->strRightOuterClipper    = "";
    }

    else if (this->strKeyWord == "runtime")
    {
        this->strLeftInnerClipper  = "<runtime>";
        this->strRightInnerClipper    = "</runtime>";
        this->strLeftOuterClipper  = "";
        this->strRightOuterClipper    = "";
    }

    else if (this->strKeyWord == "genre")
    {
        this->strLeftInnerClipper  = "<genre>";
        this->strRightInnerClipper    = "</genre>";
        this->strLeftOuterClipper  = "";
        this->strRightOuterClipper    = "";
    }

    else if (this->strKeyWord == "actor")
    {
        this->strLeftInnerClipper  = "<name>";
        this->strRightInnerClipper    = "</name>";
        this->strLeftOuterClipper  = "<actor>";
        this->strRightOuterClipper    = "</actor>";
    }

    else if(this->strKeyWord == "fsk")
    {
        this->strLeftInnerClipper  = "<mpaa>";
        this->strRightInnerClipper    = "</mpaa>";
        this->strLeftOuterClipper  = "";
        this->strRightOuterClipper    = "";
    }

    else if(this->strKeyWord == "video_codec")
    {
        this->strLeftInnerClipper  = "<codec>";
        this->strRightInnerClipper    = "</codec>";
        this->strLeftOuterClipper  = "<video>";
        this->strRightOuterClipper    = "</video>";
    }

    else if(this->strKeyWord == "video_height")
    {
        this->strLeftInnerClipper  = "<height>";
        this->strRightInnerClipper    = "</height>";
        this->strLeftOuterClipper  = "<video>";
        this->strRightOuterClipper    = "</video>";
    }

    else if(this->strKeyWord == "video_width")
    {
        this->strLeftInnerClipper  = "<width>";
        this->strRightInnerClipper    = "</width>";
        this->strLeftOuterClipper  = "<video>";
        this->strRightOuterClipper    = "</video>";
    }

    else if(this->strKeyWord == "audio_codec")
    {
        this->strLeftInnerClipper  = "<codec>";
        this->strRightInnerClipper    = "</codec>";
        this->strLeftOuterClipper  = "<audio>";
        this->strRightOuterClipper    = "</audio>";
    }

    else if(this->strKeyWord == "audio_channels")
    {
        this->strLeftInnerClipper  = "<channels>";
        this->strRightInnerClipper    = "</channels>";
        this->strLeftOuterClipper  = "<audio>";
        this->strRightOuterClipper    = "</audio>";
    }

    else if(this->strKeyWord == "audio_language")
    {
        this->strLeftInnerClipper  = "<language>";
        this->strRightInnerClipper    = "</language>";
        this->strLeftOuterClipper  = "<audio>";
        this->strRightOuterClipper    = "</audio>";

    }

    else
    {
        cout << endl;
        cout << "$ create_tags(): falsches Eingabeparameter in Funktion!" << endl;
        cout << "$ Parameter: " << this->strKeyWord << endl;
        cout << endl;

        return 1;
    }
#endif
    return 0;

}
