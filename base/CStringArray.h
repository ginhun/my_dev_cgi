#if !defined(AFX_STRINGARRAY_H__F0A27122_CFD0_45E6_BF34_0D029ECE8FF9__INCLUDED_)
#define AFX_STRINGARRAY_H__F0A27122_CFD0_45E6_BF34_0D029ECE8FF9__INCLUDED_

//#include "CBaseType.h" 
#include <map>
#include <vector>
#include <string>

using namespace std;

//class bsapi::CStringArray : public vector<string>
class CStringArray : public vector<string>
{
public:
	void SetCommaText(const char* value, const char* sep);
	void SetCommaText(string value, string sep);

	CStringArray();

	virtual ~CStringArray();
};

#endif // !defined(AFX_STRINGARRAY_H__F0A27122_CFD0_45E6_BF34_0D029ECE8FF9__INCLUDED_)
