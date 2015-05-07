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

 #include "..\include\MovieHtml.h"
 #include "..\include\FileOperations.h"
 #include "..\include\NfoFile.h"
 #include "..\include\StringTools.h"

 #include <string>
 #include <iostream>

 #define PATH_HTML_IMAGES   "data\\html_files"
 #define PATH_HTML_TEMPLATE "data\\movie_template.html"


using namespace std;

MovieHtml::MovieHtml( string strDestinationPath, string strNfoPath )
{
    this->strHtmlDestination = strDestinationPath;
    this->strNfoFilepath = strNfoPath;

    copyImages();
    copyHtmlTemplate();
}

MovieHtml::~MovieHtml()
{
    //dtor
}

int MovieHtml::copyImages()
{
    FileOperations::copyFiles(PATH_HTML_IMAGES, this->strHtmlDestination, true);

    return 0;
}

int MovieHtml::copyHtmlTemplate()
{
    string strHtmlFilename;
    string strBuffer;
    vector <string> vecstrHtmlFilename;
    NfoFile oNfoFile(this->strNfoFilepath);

    oNfoFile.getValue("title", vecstrHtmlFilename);
    StringTools::vecToStr(vecstrHtmlFilename, strHtmlFilename, "");

    oNfoFile.getValue("year", vecstrHtmlFilename);
    StringTools::vecToStr(vecstrHtmlFilename, strBuffer, "");

    /** Umlaute werden aus der Nfo falsch ausgelesen -> müssen umgewandelt werden **/
    strHtmlFilename += " (" + strBuffer + ").html";

    cout << "Kopieren: " << FileOperations::copyFile(PATH_HTML_TEMPLATE, this->strHtmlDestination + "\\" + strHtmlFilename, true) << endl;

    return 0;

}
