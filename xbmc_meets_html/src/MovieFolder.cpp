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
}

MovieFolder::~MovieFolder()
{
    //dtor
}

int MovieFolder::SearchMovieFile()
{

   ConfigFile *oConfigFile = new ConfigFile();

        string strBuffer;
        vector <string> vecstrBuffer;
        vector <string> vecstrCodecs;
        unsigned int i = 0;


// TODO FUNKTION ÜBERPRÜFEN!!!!


       oConfigFile->getValue("codecs", strBuffer);
       StringTools::strToVec(strBuffer, vecstrCodecs, " ");

       while( i < vecstrCodecs.size() )
       {

        if( vecstrCodecs[i].find(".") == string::npos)
        {
            FileOperations::findFolder(this->strMovieFolderPath, vecstrCodecs[i], false, vecstrBuffer);

            if(vecstrBuffer.size() > 0) StringTools::printVecstr(vecstrBuffer);
        }

        else
        {
            if( FileOperations::findFile(this->strMovieFolderPath, vecstrCodecs[i], false, vecstrBuffer) == 0)
            {
                cout << "Videodatei(en): " << endl;
                StringTools::printVecstr(vecstrBuffer);
                return 0;
            }

        }



        i++;
       }


        cout << endl;
        cout << "$ find_movie_file(): Keine Videodatei gefunden!" << endl;
        cout << "$ gesuchte Codecs: " << strBuffer << endl;
        cout << "$ Ordnerpfad:      " << this->strMovieFolderPath << endl;
        cout << endl;


    return 1;


/**
        int status_return = 1;


        read_config("codecs", str_buffer);
        str_to_vec(str_buffer, vec_str_buffer, " ");

        unsigned int i = 0;

        while ( status_return == 1 && i<vec_str_buffer.size() )
        {
            if ( find_file(folder_path, vec_str_buffer[i], false, str_buffer, false) == 0 )
            {
                found_filename = str_buffer;
                status_return = 0;
                //cout << "Videodatei: " << str_buffer << endl;
            }

            i++;
        }

        if(status_return == 1)
        {
            cout << endl;
            cout << "$ find_movie_file(): Keine Videodatei gefunden!" << endl;
            cout << "$ gesuchte Codecs: " << str_buffer << endl;
            cout << "$ Ordnerpfad:      " << folder_path << endl;
            cout << endl;
        }


    return status_return;


**/

}
