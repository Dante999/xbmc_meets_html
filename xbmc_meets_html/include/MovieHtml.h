#ifndef MOVIEHTML_H
#define MOVIEHTML_H

#include <string>


class MovieHtml
{
    public:

        MovieHtml( std::string strDestinationPath, std::string strNfoPath );
        virtual ~MovieHtml();
        int copyImages();
        int copyHtmlTemplate();

    protected:
    private:

        std::string strHtmlDestination;
        std::string strNfoFilepath;

};

#endif // MOVIEHTML_H
