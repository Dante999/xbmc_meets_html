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
        static int printVecstr(std::vector <std::string> vecstrTmp);
        static int strToVec (std::string strInString, std::vector <std::string> &vecstrOutVector, std::string strConnector);
        static std::string compareVecAttr(std::vector <std::string> &vecstrTmp);
        static int removeFileExtension(std::string &strFileName);
        static LPCWSTR strToLpcwstr(std::string strTmp);
    protected:
    private:
};

#endif // STRINGTOOLS_H
