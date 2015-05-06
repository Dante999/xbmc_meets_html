#ifndef NFOFILE_H
#define NFOFILE_H

#include <string>
#include <fstream>
#include <vector>
#include "MovieFolder.h"

class NfoFile
{
    public:
        NfoFile( std::string strNfoPath);
        virtual ~NfoFile();

        int getValue(std::string strParameter, std::vector <std::string> &vecstrValue);
        int testNfo(void);

    protected:
    private:
        int getClippers(void);
        int openFile(void);
        int closeFile(void);

        std::ifstream ifstrmNfoFile;
        std::string strKeyWord;
        std::string strLeftInnerClipper;
        std::string strRightInnerClipper;
        std::string strLeftOuterClipper;
        std::string strRightOuterClipper;

        std::string strNfoPath;
        std::string strParameter;

};

#endif // NFOFILE_H
