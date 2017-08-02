#ifndef _CAJAXCGI_H_HEADER_INCLUDED_
#define _CAJAXCGI_H_HEADER_INCLUDED_  1

///////////////////////////////////////////
//AjaxCGI CTrans Implementaion header
///////////////////////////////////////////
#include "CTrans.h"

#define ROK   1
#define RFAIL 0

class CTrans;

class CAjaxCgi
{
	public:
		// 1.输出XML报文头 
		// 2.获取HTTP请求参数
		// 3.建立处理器
		// 4.提交处理
		// 5.异常时设置retcode&retmsg
		CAjaxCgi(void);

		// 输出处理结果内容
		// 输出XML尾部
		virtual ~ CAjaxCgi(void);

        inline void SetXmlDump() { m_bXmlDump = true; }
        inline void SetXmlUnDump() { m_bXmlDump = false; }

        inline void SetJsonDump() { m_bJsonDump = true; }
        inline void SetJsonUnDump() { m_bJsonDump = false; }

        inline void SetStringDump() { m_bStringDump = true; }
        inline void SetStringUnDump() { m_bStringDump = false; }

	private:
        void Init();
		
        // 初始化日志
		void InitLog(void);
        void FreeLog(void);
		
        // 获取HTTP请求的参数，并按照名字-值对应关系写入CStr2Map类型的变量中。
		virtual int FetchHttpEnv(void);
		virtual int FetchQueryString(void);

        // 根据报文类型建立处理器对象
        virtual int CreateHandler(void);

		// 使用createhander返回的处理器对象
		// pTrans->Commit(mIodat)
		virtual int CommitTrans(void);

        void GetParam(string tmp, CStr2Map& strMap);
   
        // 输出返回信息
        void PrintRetMsg();
        void PrintXmlByMap();
        void PrintJsonByMap();
        void PrintString();

        bool m_bXmlDump;
        bool m_bJsonDump;
        bool m_bStringDump;
        string m_sEncoding;

        //启动和结束时间
        struct timeval startTimeVal;
        struct timeval endTimeVal;

		// 指向处理器的基类指针。
		CTrans *m_pTrans;
		
        // 存放环境变量
		CStr2Map m_mEnv;

		// 存放请求和响应的要素内容
		CStr2Map m_mIODat;

        // 存放URL 请求参数串
        CStr2Map m_mUrlParams;
};

#endif  /* _CAJAXCGI_H_HEADER_INCLUDED_ */
