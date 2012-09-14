#include "Utility.h"
#include "MyLog.h"
std::vector<std::string> SplitString(const std::string& strContent, char cSpliter)
{
	std::vector<std::string> vecParams;

	std::string::size_type iStart = 0, iPos;
	iPos = strContent.find(cSpliter, iStart);
	while(std::string::npos != iPos)
	{
		if(iPos > iStart)
		{
			std::string strParam = strContent.substr(iStart, iPos - iStart);
			vecParams.push_back(strParam);
		}
		iStart = iPos + 1;
		iPos = strContent.find(cSpliter, iStart);
	}

	if(iStart < strContent.size())
	{
		std::string strParam = strContent.substr(iStart, strContent.size() - iStart);
		vecParams.push_back(strParam);
	}

	return vecParams;
}

const char* FindChar(const char* szStart, const char* szEnd, char cFind)
{
	int iLen = szEnd - szStart;
	const char * pFind = NULL;
	for(int i = 0; i < iLen; ++i)
	{
		if(*(szStart+i) == cFind)
		{
			pFind = szStart + i;
			break;
		}
	}
	return pFind;
}

std::string Time2String(time_t tVal)
{
	try
	{
		struct tm* pTm = localtime(&tVal);
		if(pTm)
		{
			char szBuf[128];
			strftime(szBuf, 128, "%Y-%m-%d %H:%M:%S", pTm);
			return szBuf;
		}
	}
	catch (...)
	{
		MyLog::log->error("%s	%d, Time2String(%u)", __FILE__, __LINE__, tVal);
	} 
	return "";
}

time_t String2Time(const std::string& strVal)
{
	time_t tRet = 0;
	try
	{
		struct tm tmMake;
		if(6 == sscanf(strVal.c_str(), "%d-%d-%d %d:%d:%d", &tmMake.tm_year, &tmMake.tm_mon, &tmMake.tm_mday, &tmMake.tm_hour, &tmMake.tm_min, &tmMake.tm_sec))
		{
			tmMake.tm_year -= 1900;
			tmMake.tm_mon -= 1;
			tRet = mktime(&tmMake);
		}
	}
	catch (...)
	{
		MyLog::log->error("%s	%d, String2Time('%s')", __FILE__, __LINE__, strVal.c_str());
	} 
	return tRet;
}