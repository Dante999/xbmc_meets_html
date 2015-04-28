#ifndef MOVIEFOLDER_H
#define MOVIEFOLDER_H




class MovieFolder
{
    public:
        MovieFolder( std::string strMovieFolderPath);
        virtual ~MovieFolder();
        int SearchMovieFile();
        int SearchMovieCover();

        std::string getMovieFilename();
        std::string getMovieCovername();

    protected:
    private:

        std::string strMovieFolderPath;
        std::string strMovieFilename;
        std::string strMovieCovername;
};

#endif // MOVIEFOLDER_H
