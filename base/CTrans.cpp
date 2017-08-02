#include "CTrans.h"


const string CTrans::LOG_CONFIG_FILE_PATH = "../../conf/log4cpp.properties";

CTrans::CTrans()
{
}

CTrans::~CTrans()
{
}



int CTrans::LoadConfigure()
{
    if( LoadCfg(XML_CONF_FILE) != 0 )
    {
        string errmsg = "read conf file[" + string(XML_CONF_FILE) + "] fail!";
        gPtrAppLog->debug("(%s:%d:%s) %s", __FILE__, __LINE__, __func__, errmsg.c_str());
        throw( CTrsExp(9999, "读取配置文件失败!"));
    }

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

