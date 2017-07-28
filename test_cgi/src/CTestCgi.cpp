#include "CTestCgi.h"

//#include <fcgi_stdio.h>

CTestCgi::CTestCgi()
{
}

CTestCgi::~CTestCgi()
{
}

void CTestCgi::CheckSession(CStr2Map& iodat)
{
    APP_DEBUG("Begin...");
    APP_DEBUG("End");
}

void CTestCgi::CheckParams(CStr2Map& iodat, CStr2Map& urlParams)
{
    APP_DEBUG("Begin...");

    int i = 1;
    for(CStr2Map::iterator it = iodat.begin(); it != iodat.end(); it++ )
    {
        APP_DEBUG("i=[%d],key=[%s],value=[%s]", i++, it->first.c_str(), it->second.c_str());
    }

    APP_DEBUG("End");
}

void CTestCgi::SetRetMsg(CStr2Map& iodat)
{
    APP_DEBUG("Begin...");

    m_outParams["aaa"]  = "111";
    m_outParams["bbb"]  = "222";
    //m_outParams["ccc"]  = "输出";
    //m_outParams["retcode"]  = "0";
    //m_outParams["retmsg"]   = "success";

    APP_DEBUG("End");
}

int CTestCgi::Commit(CStr2Map& iodat, CStr2Map& urlParams)
{
    APP_DEBUG("Begin...");

    //登录态校验
    CheckSession(iodat);

    //入参校验
    CheckParams(iodat, urlParams);

    //设置返回参数
    SetRetMsg(iodat);

    //int count = 0;
    //printf("Content-type: text/html\r\n"
    //        "\r\n"
    //        "<title>CGI Hello!</title>"

    //        "<h1>CGI Hello!</h1>"
    //        "Request number %d running on host <i>%s</i>\n",
    //        ++count, getenv("SERVER_NAME"));

    //printf("Content-type: text/html\r\n\r\n");
    //printf("hello world!\n");

    APP_DEBUG("End");
    return 0;
}
