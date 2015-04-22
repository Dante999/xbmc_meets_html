#ifndef MOVIEFOLDER_H
#define MOVIEFOLDER_H




class MovieFolder
{
    public:
        MovieFolder( std::string strMovieFolderPath);
        virtual ~MovieFolder();
        int SearchMovieFile();

    protected:
    private:

        std::string strMovieFolderPath;
};

#endif // MOVIEFOLDER_H
