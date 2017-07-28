#include "OpenCommon.h"

CCftLogger* gPtrOpenSysLog = NULL;
CCftLogger* gPtrOpenAppLog = NULL;

OpenCommon::OpenCommon()
{
    string str_log_path = "/data/wwwlogs/cgi/";
    string str_log_prefix = "tmp";
    string str_log_path_prefix = str_log_path + str_log_prefix;

    gPtrOpenSysLog = new CCftLogger(str_log_path_prefix.c_str(),
            1024 * 1024, 
            200,
            CCftLogger::LOG_LEVEL(5),
            CCftLogger::SHIFT_MODE(2));
    gPtrOpenSysLog->setSuffix("_sys");

    gPtrOpenAppLog = new CCftLogger(str_log_path_prefix.c_str(),
            1024 * 1024, 
            200,
            CCftLogger::LOG_LEVEL(5),
            CCftLogger::SHIFT_MODE(2));
    gPtrOpenAppLog->setSuffix("_app");
}

OpenCommon::~OpenCommon()
{
    if ( NULL != gPtrOpenSysLog )
    {   
        delete gPtrOpenSysLog;
        gPtrOpenSysLog = NULL;
    }

    if ( NULL != gPtrOpenAppLog )
    {
        delete gPtrOpenAppLog;
        gPtrOpenAppLog = NULL;
    }

}

int OpenCommon::Run(CStr2Map & iodat, CStr2Map &urlParams)
{
    // 以上都校验正常，开始业务。
    Commit(iodat, urlParams);

    SetRetMap(iodat);

    return 0;
}

int OpenCommon::Commit(CStr2Map & iodat, CStr2Map &urlParams)
{
    return 0;
}

void OpenCommon::SetRetMap(CStr2Map & iodat)
{
    iodat.clear();
    iodat = m_outParams;
}


