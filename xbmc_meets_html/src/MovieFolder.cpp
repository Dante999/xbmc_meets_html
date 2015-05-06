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
    SearchNfoFile();
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

string MovieFolder::getNfoFilename()
{
    return this->strNfoFilename;
}

string MovieFolder::getMovieFolderPath()
{
    return this->strMovieFolderPath;
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
            StringTools::removeFileExtension(vecstrBuffer[j]);                                              // Dateiendung entfernen (z.B. '.avi'
            vecstrFoundMovieFiles.push_back(vecstrBuffer[j]);                                               // Dateinamen in Vektor speichern
        }
    }

    if(vecstrFoundMovieFiles.size() == 0)                                                                   /** Keine Videodateien gefunden **/
    {
        return 1;
    }


    size_t sztPos;

    oConfigFile.getValue("multiple_files", strConfigValue);                                                 // lies Namensgebung bei mehren Videodateien aus der config.ini
    StringTools::strToVec(strConfigValue, vecstrBuffer, ";");                                               // Wandle string in Vektor um


    for(i=0; i<vecstrBuffer.size(); i++)
    {
        this->strMovieFilename = StringTools::compareVecAttr(vecstrFoundMovieFiles);                        // Entferne Nummerierung der Videodateien (z.B. CD1, CD2, CD3)

        sztPos = this->strMovieFilename.find(vecstrBuffer[i]);                                              // Entferne erweiterung (z.B. '_CD' bei 'Hangover_CD'

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

    oConfigFile.getValue("name_cover", strModeCovername);                                                   // Lies Namenskonvention aus der Configfile

    if( strModeCovername == "0" || this->strMovieFilename == "VIDEO_TS")                                    /** Filmcover wird pauschal "folder.jpg" genannt **/
    {
        this->strMovieCovername = "folder.jpg";
    }

    else if ( strModeCovername == "1")                                                                      /** Filmcover wird nach "[Filmdatei]-poster.jpg" benannt **/
    {
        this->strMovieCovername = this->strMovieFilename + "-poster.jpg";
    }


    if( FileOperations::fileExists(this->strMovieFolderPath + "\\" + this->strMovieCovername) )             /** Filmcover im Ordner vorhanden **/
    {
      return 0;
    }

    else                                                                                                    /** Filmcover nicht vorhanden **/
    {
        this->strMovieCovername = "";
        return 1;
    }

}

int MovieFolder::SearchNfoFile()
{
    string strModeNfo;
    ConfigFile oConfigfile;

    oConfigfile.getValue("name_nfo", strModeNfo);

    if( strModeNfo == "0" || this->strMovieFilename == "VIDEO_TS")                                    /** Filmcover wird pauschal "folder.jpg" genannt **/
    {
        this->strNfoFilename = "movie.nfo";
    }

    else if ( strModeNfo == "1")                                                                      /** Filmcover wird nach "[Filmdatei]-poster.jpg" benannt **/
    {
        this->strNfoFilename = this->strMovieFilename + ".nfo";
    }


    if( FileOperations::fileExists(this->strMovieFolderPath + "\\" + this->strNfoFilename) )             /** Filmcover im Ordner vorhanden **/
    {
      return 0;
    }

    else                                                                                                    /** Filmcover nicht vorhanden **/
    {
        this->strNfoFilename = "";
        return 1;
    }

}

void MovieFolder::print()
{
    cout << "Pfad:        " << getMovieFolderPath() << endl;
    cout << "MovieFile:   " << getMovieFilename() << endl;
    cout << "CoverName:   " << getMovieCovername() << endl;
    cout << "NfoFilename: " << getNfoFilename() << endl;
}


