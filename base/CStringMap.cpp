#include "CStringMap.h"
#include "CStringArray.h"
std::string
CStringMap::charToHex(char c)
{
  std::string result;
  char first, second;

  first = (c & 0xF0) / 16;
  first += first > 9 ? 'A' - 10 : '0';
  second = c & 0x0F;
  second += second > 9 ? 'A' - 10 : '0';

  result.append(1, first);
  result.append(1, second);
  
  return result;
}
char
CStringMap::hexToChar(char first,char second)
{
  int digit;
  
  digit = (first >= 'A' ? ((first & 0xDF) - 'A') + 10 : (first - '0'));
  digit *= 16;
  digit += (second >= 'A' ? ((second & 0xDF) - 'A') + 10 : (second - '0'));
  return static_cast<char>(digit);
}
std::string
CStringMap::UrlDecode(const std::string& src)
{
  std::string result;
  std::string::const_iterator iter;
  char c;

  for(iter = src.begin(); iter != src.end(); ++iter) {
    switch(*iter) {
    /*
    case '+':
      result.append(1, ' ');
      break;
    */
    case '%':
	// Don't assume well-formed input
	if(std::distance(iter, src.end()) >= 2
	   && std::isxdigit(*(iter + 1)) && std::isxdigit(*(iter + 2))) {
	    c = *++iter;
	    result.append(1, hexToChar(c, *++iter));
	}
	// Just pass the % through untouched
	else {
	    result.append(1, '%');
	}
	break;
    
    default:
      result.append(1, *iter);
      break;
    }
  }
  
  return result;
}
std::string 
CStringMap::UrlEncode(const std::string& src)
{
  std::string result;
  std::string::const_iterator iter;
  
  for(iter = src.begin(); iter != src.end(); ++iter) {
    switch(*iter) {
    	/*
    case ' ':
      result.append(1, '+');
      break;
      */
      // alnum
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
    case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
    case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
    case 'V': case 'W': case 'X': case 'Y': case 'Z':
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
    case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
    case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
    case 'v': case 'w': case 'x': case 'y': case 'z':
    case '0': case '1': case '2': case '3': case '4': case '5': case '6':
    case '7': case '8': case '9':
      // mark
    case '-': case '_': case '.': case '!': case '~': case '*': case '\'': 
    case '(': case ')':
      result.append(1, *iter);
      break;
      // escape
    default:
	if((unsigned char)(*iter) > 127)
	{
		result.append(1, *iter);
	}
	else
	{
      result.append(1, '%');
      result.append(charToHex(*iter));
	}
      break;
    }
  }
  
  return result;
}
//##ModelId=44E298120261
int CStringMap::SnapElement(string sDigram, string sEleSep, string sNvSep)
{
  CStringArray vEle,vNv;
  
  int iRetcd = SUC;
  
  clear();
  
  vEle.SetCommaText(sDigram,sEleSep);
  
  for(unsigned int i = 0; i< vEle.size();i++)
  {
    vNv.SetCommaText(vEle[i],sNvSep);
    if(vNv.size() < 2)
    {
      iRetcd |= INV;
    }
    else
    {
      insert(value_type(vNv[0],UrlDecode(vEle[i].substr(vNv[0].length()+1))));
    }
  }
  
  if(size() == 0)
    iRetcd |= NOE;
    
   return iRetcd;
}

//##ModelId=44E298EB0222
int CStringMap::GenString(string &sDigram, string sEleSep, string sNvSep)
{
  int iRetcd = SUC;
  
  iterator mapPos;
  
  mapPos = begin();
  
  sDigram += mapPos->first + sNvSep + UrlEncode(mapPos->second);
  
  for(++mapPos;mapPos != end();mapPos++)
  {
      sDigram += sEleSep + mapPos->first + sNvSep + UrlEncode(mapPos->second);
  }
  
  return iRetcd;
}

