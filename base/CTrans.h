#ifndef _CTRANS_H_HEADER_INCLUDED_
#define _CTRANS_H_HEADER_INCLUDED_ 1

#include <stdlib.h>
#include "CftLogger.h"
#include <curl/curl.h>
#include "CStringMap.h"
#include "CStringArray.h"
#include "CTools.h"
#include <sstream>

typedef map<string, string> CStr2Map;

class CTrans
{
	public:
		const static string LOG_CONFIG_FILE_PATH;
		CTrans();
		/*
		 * 2011-11-22 leungma ÐÞ¸ÄÎªÐéº¯Êý
		 */
		virtual ~CTrans();


		int TransFramwork(CStr2Map &iodat, CStr2Map &urlParams);



		virtual int Run(CStr2Map & iodat, CStr2Map &urlParams) = 0;

    protected:
		virtual int LoadConfigure();

		virtual void LoadBusiConfig();

};

#endif   /* _CTRANS_H_HEADER_INCLUDED_ */
