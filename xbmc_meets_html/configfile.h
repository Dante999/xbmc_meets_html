#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <fstream>

#define PATH_TO_CONFIG "config.ini"
#define PATH_TO_CACHE "cache.txt"


#define CFG_PATH_MOVIES "path_movies"
#define CFG_PATH_INDEX "path_index"
#define CFG_DO_MOVIE_HTML "do_movieHTML"
#define CFG_DO_INDEX_HTML "do_indexHTML"
#define CFG_COVER_LINE "cover_line"
#define CFG_COVER_COLUMN "cover_column"
#define CFG_NAME_COVER "name_cover"
#define CFG_NAME_NFO "name_nfo"
#define CFG_MULTIPLE_FILES "multiple_files"
#define CFG_CODECS "codecs"




class ConfigFile
{
    public:
        ConfigFile();
        virtual ~ConfigFile();
        int getValue(std::string strParameter, std::string &strValue);
        int setValue(std::string strParameter, std::string strValue);
        bool checkIfExists(void);

    protected:
    private:
        std::fstream fstrmConfigFile;
        int openFile(void);
        int closeFile(void);        
};

#endif // CONFIGFILE_H
