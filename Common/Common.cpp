#include "Common.h"
#include <fstream>

namespace Common
{
	void LoadIntegerList(const std::string& fileName, std::vector<int>& list)
	{
        std::ifstream input(fileName.c_str(), std::ifstream::in);

        std::string line;
        if (input.is_open())
        {
            while (std::getline(input, line))
            {
                list.push_back(std::stoi(line));
            }
            input.close();
        }
        else
        {
            throw "Error opening file";
        }
	}
}