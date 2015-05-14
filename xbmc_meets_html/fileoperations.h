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
        static int findFile( std::string strFolderPath, std::string strSearchParam, bool bWholeWord, std::vector <std::string> &vecstrFoundFiles);
        static int findFolder( std::string strPath, std::string strSearchParam, bool bWholeWord, std::vector <std::string> &vecstrFoundFolders);
        static bool fileExists(const std::string &filename);
        static int copyFiles(const std::string source, const std::string destination, bool overwrite);
        static int copyFile(const std::string strSourceFilepath, const std::string strDestinationFilepath, bool overwrite );
    protected:
    private:
};

#endif // FILEOPERATIONS_H
