#ifndef MOVIEFOLDER_H
#define MOVIEFOLDER_H




class MovieFolder
{
    public:
        MovieFolder( std::string strMovieFolderPath);
        virtual ~MovieFolder();
        int SearchMovieFile();
        int SearchMovieCover();
        int SearchNfoFile();

        std::string getMovieFilename();
        std::string getMovieCovername();
        std::string getNfoFilename();
        std::string getMovieFolderPath();
        void print(void);

    protected:
        std::string strMovieCovername;
        std::string strMovieFolderPath;
        std::string strMovieFilename;
        std::string strNfoFilename;
    private:



};

#endif // MOVIEFOLDER_H
