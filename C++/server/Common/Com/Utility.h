#pragma once
#include <string>
#include <vector>
#include "time.h"

std::vector<std::string> SplitString(const std::string& strContent, char cSpliter);

const char* FindChar(const char* szStart, const char* szEnd, char cFind);

std::string Time2String(time_t tVal);
time_t String2Time(const std::string& strVal);
