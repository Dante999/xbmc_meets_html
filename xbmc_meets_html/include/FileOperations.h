#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <string>
#include <vector>

class FileOperations
{
    public:
        FileOperations();
        virtual ~FileOperations();

        static int ListFolders( std::string strFolderPath, std::vector <std::string> &vecstrContainedFolders);
    protected:
    private:
};

#endif // FILEOPERATIONS_H
