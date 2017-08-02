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
		// 1.���XML����ͷ 
		// 2.��ȡHTTP�������
		// 3.����������
		// 4.�ύ����
		// 5.�쳣ʱ����retcode&retmsg
		CAjaxCgi(void);

		// �������������
		// ���XMLβ��
		virtual ~ CAjaxCgi(void);

        inline void SetXmlDump() { m_bXmlDump = true; }
        inline void SetXmlUnDump() { m_bXmlDump = false; }

        inline void SetJsonDump() { m_bJsonDump = true; }
        inline void SetJsonUnDump() { m_bJsonDump = false; }

        inline void SetStringDump() { m_bStringDump = true; }
        inline void SetStringUnDump() { m_bStringDump = false; }

	private:
        void Init();
		
        // ��ʼ����־
		void InitLog(void);
        void FreeLog(void);
		
        // ��ȡHTTP����Ĳ���������������-ֵ��Ӧ��ϵд��CStr2Map���͵ı����С�
		virtual int FetchHttpEnv(void);
		virtual int FetchQueryString(void);

        // ���ݱ������ͽ�������������
        virtual int CreateHandler(void);

		// ʹ��createhander���صĴ���������
		// pTrans->Commit(mIodat)
		virtual int CommitTrans(void);

        void GetParam(string tmp, CStr2Map& strMap);
   
        // ���������Ϣ
        void PrintRetMsg();
        void PrintXmlByMap();
        void PrintJsonByMap();
        void PrintString();

        bool m_bXmlDump;
        bool m_bJsonDump;
        bool m_bStringDump;
        string m_sEncoding;

        //�����ͽ���ʱ��
        struct timeval startTimeVal;
        struct timeval endTimeVal;

		// ָ�������Ļ���ָ�롣
		CTrans *m_pTrans;
		
        // ��Ż�������
		CStr2Map m_mEnv;

		// ����������Ӧ��Ҫ������
		CStr2Map m_mIODat;

        // ���URL ���������
        CStr2Map m_mUrlParams;
};

#endif  /* _CAJAXCGI_H_HEADER_INCLUDED_ */
