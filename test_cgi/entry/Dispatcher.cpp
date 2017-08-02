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

	m_mIODat["is_interface"] = "true"; //�Ƿ�ӿ���cgi������ǽӿ���cgiʱ�����ʱ��������������cookie

	if( m_mIODat["tid"] == string("test_cgi") )
	{
		m_pTrans = new CTestCgi;
	}
	else
	{
		throw(CTrsExp("98", string("������98����֪ͨwebmaster.[") + m_mIODat["tid"] + string("]")));
		return 98;
	}

	if( m_pTrans == NULL )
	{
		throw(CTrsExp("97", string("������97����֪ͨwebmaster.[") + m_mIODat["tid"] + string("]")));
		return 97;
	}
	else
	{
		return 0;
	}
}
