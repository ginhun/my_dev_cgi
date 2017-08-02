#ifndef _CTRANS_H_HEADER_INCLUDED_
#define _CTRANS_H_HEADER_INCLUDED_ 1

#include <stdlib.h>
#include <curl/curl.h>
#include <sstream>
#include "CftLogger.h"
#include "CStringMap.h"
#include "CStringArray.h"
#include "CTools.h"
#include "CExp.h"
#include "transxmlcfg.h"
#include "xmlHelper.h"

extern CCftLogger* gPtrSysLog;
extern CCftLogger* gPtrAppLog;
extern string g_strTid;

typedef map<string, string> CStr2Map;

#define CONF_ROOT      "../../conf"
#define XML_CONF_FILE         CONF_ROOT"/paycgi.conf"

class CTrans
{
	public:
		const static string LOG_CONFIG_FILE_PATH;
		CTrans();
		/*
		 * 2011-11-22 leungma 修改为虚函数
		 */
		virtual ~CTrans();


		int TransFramwork(CStr2Map &iodat, CStr2Map &urlParams);



		virtual int Run(CStr2Map & iodat, CStr2Map &urlParams) = 0;

    protected:
		virtual int LoadConfigure();

		virtual void LoadBusiConfig();

};

#endif   /* _CTRANS_H_HEADER_INCLUDED_ */
