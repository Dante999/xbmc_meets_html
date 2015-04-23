#ifndef MOVIEFOLDER_H
#define MOVIEFOLDER_H




class MovieFolder
{
    public:
        MovieFolder( std::string strMovieFolderPath);
        virtual ~MovieFolder();
        int SearchMovieFile();
        std::string getMovieFilename();

    protected:
    private:

        std::string strMovieFolderPath;
        std::string strMovieFilename;
};

#endif // MOVIEFOLDER_H
