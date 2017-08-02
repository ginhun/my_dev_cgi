#ifndef CTOOLS_H_HEADER_INCLUDED_BB9BF94B
#define CTOOLS_H_HEADER_INCLUDED_BB9BF94B

//#include "gwtools.h" 
#include "bcd.h" 
//#include "RSAcrypter.h"
//#include "QPayClient.h"
//#include "qpay_encrypt_client.h"

extern CCftLogger* gPtrAppLog;

enum PASSWD_CTRL_ERR_ID
{
	PASSWD_CTRL_ERR_ID_INVALID_LEN = 1, /*���볤����Ч */
	PASSWD_CTRL_ERR_ID_EXCEED_TIME = 2, /* ʱ����������Чʱ�䷶Χ */
	PASSWD_CTRL_ERR_ID_ALLOC_MEM = 3, /* �����ڴ�ʧ�� */
	PASSWD_CTRL_ERR_ID_READ_KEY = 4, /* ��ȡ��Կ�ļ�ʧ�� */
	PASSWD_CTRL_ERR_ID_DECRYPT_RSA = 5, /* ����ʧ�� */
	PASSWD_CTRL_ERR_ID_DERSA_SEED_WRONG = 6,
/* ����rsa��Ľ����seed ���ⲿseed����� */
};

#define VALID_INTERVAL 600

typedef map<string,string> CStr2Map;

class CCGITools
{
    public:
        static void ProcInterface(CStr2Map& iodat)
        {
            if (iodat["is_interface"] == "true")
            {
                string tId = iodat["tid"];
                iodat.clear();
                iodat["tid"] = tId;
            }
        }
};

#endif /* CTRANS_H_HEADER_INCLUDED_BB9BF94B */
