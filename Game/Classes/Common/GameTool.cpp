#include "GameTool.h"
#include "iconv.h"

#define MAX_GBK_TO_UTF8_LENGTH 1024
std::string GBKToUtf8(string strGBK)
{
	static iconv_t iconvH = iconv_open("utf-8", "gb2312");
	if (iconvH == (iconv_t)(-1))
	{
		return strGBK;
	}

	const char* strChar = strGBK.data();
	const char** pin = &strChar;

	size_t strLength = strGBK.length();

	if (strLength >= MAX_GBK_TO_UTF8_LENGTH)
		return strGBK;
	size_t outLength = strLength * 4 + 1;
	char* pOutBuf = new char[outLength];
	if (!pOutBuf)
	{
		return strGBK;
	}
	char* pTemp = pOutBuf;
	memset(pOutBuf, 0, outLength);

	iconv(iconvH, NULL, NULL, NULL, NULL);

	int res = iconv(iconvH, pin, (size_t *)&strLength, &pTemp, (size_t *)&outLength);
	if (-1 == res)
	{
		delete[] pOutBuf;
		return strGBK;
	} 
	std::string outString = pOutBuf;
	delete[] pOutBuf;
	return outString;
}


extern void split(string src, const char* token, vector<string>& vect)
{
	vect.clear();
	if (token == nullptr || strlen(token) == 0)
	{
		return;
	}
	size_t nend = 0;
	size_t nbegin = 0;
	string strTemp = "";
	while (nend != string::npos  && nend != src.size())
	{
		nend = src.find(token, nbegin);
		if (nend == string::npos)
		{
			strTemp = src.substr(nbegin, src.length() - nbegin);
			if ( !strTemp.empty() )
			{
				vect.push_back(strTemp);
			}
		}
		else
		{
			strTemp = src.substr(nbegin, nend - nbegin);
			if ( !strTemp.empty() )
			{
				vect.push_back(strTemp);
			}
		}
		nbegin = nend + strlen(token);
	}
}

