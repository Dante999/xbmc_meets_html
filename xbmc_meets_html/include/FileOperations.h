#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <string>
#include <vector>

class FileOperations
{
    public:
        FileOperations();
        virtual ~FileOperations();

        static int listFolders( std::string strFolderPath, std::vector <std::string> &vecstrContainedFolders);
        static int findFile( const std::string strPath, const std::string strSearchParam, bool bWholeWord, std::vector <std::string> &vecstrFoundFiles);
        static int findFolder( const std::string strPath, const std::string strSearchParam, bool bWholeWord, std::vector <std::string> &vecstrFoundFolders);
        static bool fileExists(const std::string &filename);
    protected:
    private:
};

#endif // FILEOPERATIONS_H
