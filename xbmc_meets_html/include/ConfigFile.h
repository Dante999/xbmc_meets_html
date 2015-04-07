#ifndef CONFIGFILE_H
#define CONFIGFILE_H


#include <fstream>

class ConfigFile
{

    public:
        ConfigFile();
        virtual ~ConfigFile();
        int getValue(std::string strParameter, std::string &strValue);
        bool checkIfExists(void);
        int testConfig(void);

    protected:
    private:
        std::ifstream ifstrmConfigFile;
        int openFile(void);
        int closeFile(void);
        int iMissingEntry;


};

#endif // CONFIGFILE_H
