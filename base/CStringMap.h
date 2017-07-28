#ifndef CSTRINGMAP_H_HEADER_INCLUDED_BB1D285C
#define CSTRINGMAP_H_HEADER_INCLUDED_BB1D285C


//#include "CBaseType.h" 
#include <map>
#include <string>

using namespace std;

enum ENUM_RETCODE_CStringMap
{
  SUC = 0,
  NOE = 1, //none element
  INV = 2, //invalid name  value pair
};

//##ModelId=44E2967A03A9
//class bsapi::CStringMap : public std::map<string,string>
class CStringMap : public std::map<string,string>
{
public:
  std::string UrlEncode(const std::string& src);
  std::string UrlDecode(const std::string& src);
  std::string charToHex(char c);
  char hexToChar(char first,char second);
  CStringMap(){};
  virtual ~CStringMap(){};
    //##ModelId=44E298120261
    int SnapElement(
        // ԭʼ����
        string sDigram, 
        // �ֶηָ���
        string sEleSep = "&", 
        // ����ֵ�ָ���
        string sNvSep = "=");

    // ��MAP��ԭ���ģ�����ָ���ָ���
    //##ModelId=44E298EB0222
    int GenString(
        // ԭʼ����
        string &sDigram, 
        // �ֶηָ���
        string sEleSep = "&", 
        // ����ֵ�ָ���
        string sNvSep = "=");

};



#endif /* CSTRINGMAP_H_HEADER_INCLUDED_BB1D285C */
