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

#include "..\include\MovieFolder.h"
#include "..\include\ConfigFile.h"
#include "..\include\StringTools.h"
#include "..\include\FileOperations.h"


using namespace std;

MovieFolder::MovieFolder( string strMovieFolderPath)
{
    this->strMovieFolderPath = strMovieFolderPath;

    SearchMovieFile();
    SearchMovieCover();
}

MovieFolder::~MovieFolder()
{
    //dtor
}

string MovieFolder::getMovieFilename()
{
    return this->strMovieFilename;
}

string MovieFolder::getMovieCovername()
{
    return this->strMovieCovername;
}

int MovieFolder::SearchMovieFile()
{
   ConfigFile oConfigFile;

    string strConfigValue;
    vector <string> vecstrBuffer;
    vector <string> vecstrCodecs;
    vector <string> vecstrFoundMovieFiles;
    unsigned int i = 0;
    unsigned int j;

    oConfigFile.getValue("codecs", strConfigValue);                                                             // Zwischenspeichern aller Codecs in einen String
    StringTools::strToVec(strConfigValue, vecstrCodecs, " ");                                                    // Umwandeln der Codecs in einen Vektor


    while( i < vecstrCodecs.size() )                                                                        /** Durchsuche Filmordner nach allen Codecs **/
    {
        if( vecstrCodecs[i].find(".") != string::npos)                                                      /** gesuchtes Codec ist eine Dateiendung **/
        {
            FileOperations::findFile(this->strMovieFolderPath, vecstrCodecs[i], false, vecstrBuffer);
        }

        else                                                                                                /** gesuchtes Codec ist ein Ordner (z.B. DVD-> VIDEO_TS **/
        {
            FileOperations::findFolder(this->strMovieFolderPath, vecstrCodecs[i], false, vecstrBuffer);
        }

        i++;

        for(j=0; j<vecstrBuffer.size(); j++)                                                                /** Speichere gefundenes Codec in einen Vektor **/
        {
            vecstrFoundMovieFiles.push_back(vecstrBuffer[j]);
        }
    }

    if(vecstrFoundMovieFiles.size() == 0)                                                                   // kein Codec im Filmordner gefunden
    {
        return 1;
    }

    size_t sztPos;

    oConfigFile.getValue("multiple_files", strConfigValue);
    StringTools::strToVec(strConfigValue, vecstrBuffer, ";");

    for(i=0; i<vecstrBuffer.size(); i++)
    {
        this->strMovieFilename = StringTools::compareVecAttr(vecstrFoundMovieFiles);

        sztPos = this->strMovieFilename.find(vecstrBuffer[i]);

        if(sztPos != string::npos)
        {
            this->strMovieFilename.erase(sztPos);
            return 0;
        }
    }


    return 0;
}


int MovieFolder::SearchMovieCover()
{
    string strModeCovername;

    ConfigFile oConfigFile;

    oConfigFile.getValue("name_cover", strModeCovername);

    if( strModeCovername == "0")
    {
        this->strMovieCovername = "folder.jpg";
    }

    else if ( strModeCovername == "1")
    {
        this->strMovieCovername = this->strMovieFilename + ".jpg";
    }


    if( FileOperations::fileExists(this->strMovieFolderPath + "\\" + this->strMovieCovername) )
    {
      return 0;
    }

    else
    {
        this->strMovieCovername = "";
        return 1;
    }

}





