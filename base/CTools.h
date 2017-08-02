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
	PASSWD_CTRL_ERR_ID_INVALID_LEN = 1, /*密码长度无效 */
	PASSWD_CTRL_ERR_ID_EXCEED_TIME = 2, /* 时间间隔超过有效时间范围 */
	PASSWD_CTRL_ERR_ID_ALLOC_MEM = 3, /* 分配内存失败 */
	PASSWD_CTRL_ERR_ID_READ_KEY = 4, /* 读取密钥文件失败 */
	PASSWD_CTRL_ERR_ID_DECRYPT_RSA = 5, /* 解密失败 */
	PASSWD_CTRL_ERR_ID_DERSA_SEED_WRONG = 6,
/* 解密rsa后的结果中seed 与外部seed不相符 */
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
