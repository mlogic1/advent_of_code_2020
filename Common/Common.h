#pragma once

#include <string>
#include <vector>

namespace Common
{
	void LoadIntegerList(const std::string& fileName, std::vector<int>& list);
	void LoadStringList(const std::string& fileName, std::vector<std::string>& list);
	std::vector<std::string> SplitString(const std::string& str, const char& delimiter);
}