#include <iostream>

#include "include\ConfigFile.h"


using namespace std;

int main()
{
    string strBuffer;

    ConfigFile *cConfigFile = new ConfigFile();

    cConfigFile->getValue("path_movies", strBuffer);
    cConfigFile->getValue("path_moviess", strBuffer);
    cConfigFile->getValue("cover_row", strBuffer);

    return 0;
}
