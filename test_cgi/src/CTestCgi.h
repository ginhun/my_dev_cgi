#ifndef _CTestCgi_H_
#define _CTestCgi_H_

#include "CTrans.h"
#include "OpenCommon.h"

class CTestCgi: public OpenCommon
{
    public:
        const static string tid;        

        CTestCgi();
        virtual ~CTestCgi();
        virtual int Commit(CStr2Map& iodat, CStr2Map& urlParams);
    private:
        
        void CheckSession(CStr2Map& iodat);
        void CheckParams(CStr2Map& iodat, CStr2Map& urlParams);
        void SetRetMsg(CStr2Map& iodat);

};

#endif
