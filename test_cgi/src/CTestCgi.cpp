#include "CTestCgi.h"

//#include <fcgi_stdio.h>

#include "transxmlcfg.h"
#include "xmlHelper.h"

CTestCgi::CTestCgi()
{
}

CTestCgi::~CTestCgi()
{
}

void XmlDemo()
{
    APP_DEBUG("Begin...");
    APP_DEBUG("aaaaa");
    
    string xmlstr = "<root><aa>123456</aa></root>";
    TiXmlDocument doc;
    doc.Parse(xmlstr.c_str());
    if( doc.Error() )
    {
        APP_ERROR("ErrMsg = [%s]", "parse xml error");
        throw(CTrsExp(11, "parse xml error"));
    }

    XmlNodeWrapper xmlWrap(doc.RootElement());
    string str = xmlWrap.getValue("/root/aa","");
    APP_DEBUG("aa=[%s]", str.c_str());
    
    string request_type = g_mTransactions["user_server"].m_mVars["user_reg_service"];
    APP_DEBUG("request_type=[%s]", request_type.c_str());
    
    APP_DEBUG("End");
}

void CTestCgi::CheckSession(CStr2Map& iodat)
{
    APP_DEBUG("Begin...");
    APP_DEBUG("End");
}

void CTestCgi::CheckParams(CStr2Map& iodat, CStr2Map& urlParams)
{
    APP_DEBUG("Begin...");

    APP_DEBUG("iodat params:");
    for(CStr2Map::iterator it = iodat.begin(); it != iodat.end(); ++it )
    {
        APP_DEBUG("key=[%s],value=[%s]", it->first.c_str(), it->second.c_str());
    }

    APP_DEBUG("End");
}

void CTestCgi::SetRetMsg(CStr2Map& iodat)
{
    APP_DEBUG("Begin...");

    m_outParams["aaa"]  = "111";
    m_outParams["bbb"]  = "222";
    m_outParams["ccc"]  = "输出";

    APP_DEBUG("End");
}

int CTestCgi::Commit(CStr2Map& iodat, CStr2Map& urlParams)
{
    APP_DEBUG("Begin...");

	//for test git
    APP_DEBUG("test git.");
    APP_DEBUG("test git 2.");

    XmlDemo();

    //登录态校验
    CheckSession(iodat);

    //入参校验
    CheckParams(iodat, urlParams);

    //设置返回参数
    SetRetMsg(iodat);

    APP_DEBUG("End");
    return 0;
}
