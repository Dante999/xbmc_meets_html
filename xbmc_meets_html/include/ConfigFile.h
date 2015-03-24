#ifndef CONFIGFILE_H
#define CONFIGFILE_H

using namespace std;
#include <fstream>

class ConfigFile
{

    public:
        ConfigFile();
        virtual ~ConfigFile();
        int getValue(string strKeyWord, string &strValue);
        int checkIfExists(void);

    protected:
    private:
        ifstream ifConfigFile;
        int openFile(void);
        int closeFile(void);


};

#endif // CONFIGFILE_H
