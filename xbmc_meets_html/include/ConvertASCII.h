#ifndef CONVERTASCII_H
#define CONVERTASCII_H


#include <string>
#include <vector>



class ConvertASCII
{
    public:
        ConvertASCII();
        virtual ~ConvertASCII();
        std::string str ( std::string strText);

    protected:
    private:

        std::vector <std::string> vecstrUmlaut;
        std::vector <std::string> vecstrASCII;
};

#endif // CONVERTASCII_H
