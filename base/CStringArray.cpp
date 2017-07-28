// StringArray.cpp: implementation of the CStringArray class.
//
//////////////////////////////////////////////////////////////////////

#include "CStringArray.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStringArray::CStringArray()
{

}

CStringArray::~CStringArray()
{

}
void CStringArray::SetCommaText(string value, string sep)
{
	SetCommaText(value.c_str(),sep.c_str());
}
void CStringArray::SetCommaText(const char* value, const char *sep)
{
	erase(begin(), end());
	
	char* p;
	const char* s = value;
	do
	{
		p = strpbrk((char *)s, sep);
		if (p)
		{
			if (p == s)
			{
				p++;
				s++;
			}
			else
			{
				string tmp(s, p - s);
				push_back(tmp);
				
				p++;
				s = p;
			}
		}
		else
		{
			if (strlen(s))
			{
				string tmp(s);
				push_back(tmp);
			}
		}
	} while (p);
}
