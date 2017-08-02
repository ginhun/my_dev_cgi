#include "CAjaxCgi.h"
#include "CTestCgi.h"

int CAjaxCgi::CreateHandler()
{
	TRACE_FUNC();

    //SetXmlUnDump();
    //SetStringDump();

	TRACE_LINE(m_mIODat["tid"].c_str());
	if( m_mIODat["tid"].empty() )
	{
		m_mIODat["tid"] = g_strTid = "test_cgi";
	}

	m_mIODat["is_interface"] = "true"; //是否接口类cgi，如果是接口类cgi时在输出时会清空输入参数和cookie

	if( m_mIODat["tid"] == string("test_cgi") )
	{
		m_pTrans = new CTestCgi;
	}
	else
	{
		throw(CTrsExp("98", string("错误码98：请通知webmaster.[") + m_mIODat["tid"] + string("]")));
		return 98;
	}

	if( m_pTrans == NULL )
	{
		throw(CTrsExp("97", string("错误码97：请通知webmaster.[") + m_mIODat["tid"] + string("]")));
		return 97;
	}
	else
	{
		return 0;
	}
}
