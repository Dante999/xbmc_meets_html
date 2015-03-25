#ifndef NFOFILE_H
#define NFOFILE_H

using namespace std;

class NfoFile
{
    public:
        NfoFile();
        virtual ~NfoFile();

        int getClippers(void);
#if 0
        string strKeyWord;
        string strLeftInnerClipper;
        string strRightInnerClipper;
        string strLeftOuterClipper;
        string strRightOuterClipper;

#endif
    protected:
    private:

};

#endif // NFOFILE_H
