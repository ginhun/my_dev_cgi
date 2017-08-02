#include <new>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

#if HAVE_UNAME
#include <sys/utsname.h>
#endif 

#if HAVE_SYS_TIME_H
#include <sys/time.h>
#endif 

#include "CAjaxCgi.h"
#include "CTrans.h"


using namespace std;

/*
 * 全局变量
 */
CCftLogger* gPtrSysLog = NULL;
CCftLogger* gPtrAppLog = NULL;
string g_strTid = "";


CAjaxCgi::CAjaxCgi(void)
{
	gettimeofday(&startTimeVal, NULL); //启动时间

    Init(); // 初始化

	try
	{
        FetchHttpEnv();
		
        FetchQueryString();

        CreateHandler();

		gPtrAppLog->debug("tid=[%s] (%s,%s:%d)", g_strTid.c_str(), __func__, __FILE__, __LINE__);

		CommitTrans();
	} 
	catch (int iCode)
	{
        CCGITools::ProcInterface(m_mIODat);
	} 
	catch (CTrsExp &exp)
	{
        CCGITools::ProcInterface(m_mIODat);
		m_mIODat["retcode"] = exp.retcode;
		m_mIODat["retmsg"] = exp.retmsg;
	} 
	catch (...)
	{
        CCGITools::ProcInterface(m_mIODat);
		m_mIODat["retcode"] = "9999";
		m_mIODat["retmsg"] = "系统繁忙,请稍候重试";
	}
}

void CAjaxCgi::Init()
{
	// 初始化系统日志指针
	InitLog();
	
    m_pTrans = NULL;
    
    m_sEncoding = string("UTF-8");

    SetXmlDump();
    SetJsonUnDump();
    SetStringUnDump();
}

void CAjaxCgi::InitLog(void)
{
    string str_log_path = "/data/wwwlogs/cgi/";
    string str_log_prefix = "tmp";
    string str_log_path_prefix = str_log_path + str_log_prefix;

    gPtrSysLog = new CCftLogger(str_log_path_prefix.c_str(),
            1024 * 1024, 
            200,
            CCftLogger::LOG_LEVEL(5),
            CCftLogger::SHIFT_MODE(2));
    gPtrSysLog->setSuffix("_sys");

    gPtrAppLog = new CCftLogger(str_log_path_prefix.c_str(),
            1024 * 1024, 
            200,
            CCftLogger::LOG_LEVEL(5),
            CCftLogger::SHIFT_MODE(2));
    gPtrAppLog->setSuffix("_app");

    gPtrSysLog->debug( "--------------------------------------------");
    gPtrSysLog->debug("Enter %s(%s:%d)", __func__, __FILE__, __LINE__);

	gPtrAppLog->debug( "--------------------------------------------");
	gPtrAppLog->debug("Enter %s(%s:%d)", __func__, __FILE__, __LINE__);
}

void CAjaxCgi::FreeLog(void)
{
    if( NULL != gPtrSysLog )
    {   
        delete gPtrSysLog;
        gPtrSysLog = NULL;
    }
    
    if( NULL != gPtrAppLog )
    {   
        delete gPtrAppLog;
        gPtrAppLog = NULL;
    }
}

CAjaxCgi::~CAjaxCgi(void)
{
    // 输出返回信息
    PrintRetMsg();

	if (m_pTrans)
	{
		delete m_pTrans;
		m_pTrans = NULL;
	}

	gettimeofday(&endTimeVal, NULL); //退出时间
	long long CallTimeBegin = 0, CallTimeEnd = 0, calltime = 0;
	CallTimeBegin = startTimeVal.tv_sec * 1000000 + startTimeVal.tv_usec;
	CallTimeEnd = endTimeVal.tv_sec * 1000000 + endTimeVal.tv_usec;
	calltime = CallTimeEnd - CallTimeBegin; //调用花费时间

	gPtrSysLog->debug("Leave ~CAjaxCgi(%s:%d) tid=[%s] cost[%08lld]", __FILE__,
			__LINE__, g_strTid.c_str(), calltime);
	gPtrAppLog->debug("Leave ~CAjaxCgi(%s:%d) tid=[%s] cost[%08lld]", __FILE__,
			__LINE__, g_strTid.c_str(), calltime);

    FreeLog();
}

int CAjaxCgi::FetchHttpEnv(void)
{
	TRACE_FUNC();

    extern char **environ;    
    char **pp_env;
    for( pp_env = environ; *pp_env; pp_env++ )
    {   
        GetParam(*pp_env, m_mEnv);
    }

    //int i = 1;
    //for(CStr2Map::iterator it = m_mEnv.begin(); it != m_mEnv.end(); ++it,++i )
    //{ 
    //    gPtrAppLog->debug("(%s:%d) i=[%d],key=[%s],value=[%s]", __FILE__,__LINE__, i, it->first.c_str(), it->second.c_str());
    //}
	
    return ROK;
}

int CAjaxCgi::FetchQueryString(void)
{
	TRACE_FUNC();

    CStringMap qryStrMap;
    qryStrMap.SnapElement(m_mEnv["QUERY_STRING"]);
    m_mIODat = qryStrMap;

    m_mIODat["ENV_Accept"] = m_mEnv["HTTP_ACCEPT"];
    m_mIODat["ENV_Lang"] = m_mEnv["HTTP_ACCEPT_LANGUAGE"];

	return 0;
}

int CAjaxCgi::CommitTrans(void)
{
	if (NULL != m_pTrans)
	{
		return m_pTrans->TransFramwork(m_mIODat, m_mUrlParams);
	}
	else
	{
		throw(CTrsExp("100", "1111111"));
		return -1;
	}
}

void CAjaxCgi::GetParam(string tmp, CStr2Map& strMap)
{
    size_t pos = tmp.find('=');
    if( string::npos != pos )
    {   
        strMap[tmp.substr(0,pos)] = tmp.substr(pos+1,tmp.length()-pos-1);
    }   
}

void CAjaxCgi::PrintRetMsg()
{
    if( m_bXmlDump )
    {
        PrintXmlByMap();
    }

    if( m_bJsonDump )
    {
        PrintJsonByMap();
    }
    
    if( m_bStringDump )
    {
        PrintString();
    }
}

void CAjaxCgi::PrintXmlByMap()
{
    string sContentType = "Content-Type: application/xml;charset=" + m_sEncoding + "\r\n";
    cout << sContentType << endl;

    std::stringstream sstr;
    sstr << "<?xml version=\"1.0\" encoding=\"" << m_sEncoding << "\" ?>" << "<root>";

    for( CStr2Map::iterator it = m_mIODat.begin(); it != m_mIODat.end(); ++it )
    {
        if( it->first.substr(0, 7) == "COOKIE_" || it->first.substr(0, 4) == "ENV_" )
        {
            continue;
        }
        if( "UTF-8" == m_sEncoding )
        {
            sstr << "<" << it->first << ">" << it->second << "</"
                << it->first << ">";
        }
    }
    sstr << "</root>";

    gPtrAppLog->debug("[%s:%d] out_str=[%s] ", __FILE__, __LINE__, sstr.str().c_str());
    cout << sstr.str() << endl;
}

void CAjaxCgi::PrintJsonByMap()
{
}
    
void CAjaxCgi::PrintString()
{
    string sContentType = "Content-Type: text;charset=" + m_sEncoding + "\r\n";
    cout << sContentType << endl;
    
    std::stringstream sstr;
    sstr << m_mIODat["STRINGDATA"];
    
    gPtrAppLog->debug("[%s %d] out_str=[%s] ", __FILE__, __LINE__, sstr.str().c_str());
    cout << sstr.str() << endl;
}



