/*
 * OpenCommon.h
 *
 *  Created on: 2017-07-07
 *      Author: jim
 */

#ifndef _OPENCOMMON_H_
#define _OPENCOMMON_H_

#include "CTrans.h"

extern CCftLogger* gPtrOpenAppLog;

#define APP_DEBUG(format,...) gPtrOpenAppLog->debug("(%s:%u:%s) "format,__FILE__,__LINE__,__func__,##__VA_ARGS__)
#define APP_ERROR(format,...) gPtrOpenAppLog->error("(%s:%u:%s) "format,__FILE__,__LINE__,__func__,##__VA_ARGS__)


class OpenCommon : public CTrans
{
	public:
		OpenCommon();
		virtual ~OpenCommon();
        int Run(CStr2Map & iodat, CStr2Map &urlParams);
        virtual int Commit(CStr2Map & iodat, CStr2Map &urlParams);

	protected:
        CStr2Map m_tmpParams; // 临时变量
        CStr2Map m_outParams; // 输出变量

	private:
        void SetRetMap(CStr2Map & iodat);
};

#endif
