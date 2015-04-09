#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H

#include <vector>
#include <string>
#include <windows.h>


class StringTools
{
    public:
        StringTools();
        virtual ~StringTools();
        static int vecToStr ( std::vector <std::string> vecstrInVector, std::string &strOutString, std::string strConnector);
        static LPCSTR strToLpcstr(std::string strTmp);
        static int printVecstr(std::vector <std::string> &vecstrTmp);
    protected:
    private:
};

#endif // STRINGTOOLS_H
