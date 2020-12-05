#include "Common.h"
#include <fstream>
#include <sstream>

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

    void LoadStringList(const std::string& fileName, std::vector<std::string>& list)
    {
        std::ifstream input(fileName.c_str(), std::ifstream::in);

        std::string line;
        if (input.is_open())
        {
            while (std::getline(input, line))
            {
                list.push_back(line);
            }
            input.close();
        }
        else
        {
            throw "Error opening file";
        }
    }

    std::vector<std::string> SplitString(const std::string& str, const char& delimiter)
    {
        std::vector<std::string> result;
        std::string token;
        std::istringstream stream(str);

        while (std::getline(stream, token, delimiter))
        {
            result.push_back(token);
        }
        return result;
    }
}