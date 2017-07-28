#include "CTrans.h"

extern CCftLogger*   gPtrSysLog;            // 日志文件指针
extern CCftLogger*   gPtrAppLog;

const string CTrans::LOG_CONFIG_FILE_PATH = "../../conf/log4cpp.properties";

CTrans::CTrans()
{
}

CTrans::~CTrans()
{
}



int CTrans::LoadConfigure()
{
	//加载自身业务的配置文件
	LoadBusiConfig();

	return 0;
}


void CTrans::LoadBusiConfig()
{
	return;
}

int CTrans::TransFramwork(CStr2Map &iodat, CStr2Map &urlParams)
{
	//TRACE_FUNC();

	LoadConfigure();

	if(Run(iodat, urlParams) == 0)
	{
		if(iodat["retcode"].empty())
		{
			iodat["retcode"] = "00";
		}
		if(iodat["retmsg"].empty())
		{
			//iodat["retmsg"] = "操作成功";
			iodat["retmsg"] = "success";
		}

		return 0;
	}

	return 1;
}

