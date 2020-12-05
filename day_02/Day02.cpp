/************************  ADVENT OF CODE 2020 **********************************       *
**                                                                              *      /.\
**                         adventofcode.com                                     *     /..'\
**                                                                              *     /'.'\
**                         mlogic1 (https://github.com/mlogic1)                 *    /.''.'\
**                                                                              *    /.'.'.\
**                                                                              *   /'.''.'.\
**                         Day 2 - Password Philosophy                          *   ^^^[_]^^^
**                                                                              *
**                                                                              *
**                                                                              *
********************************************************************************/

#include "../common/Common.h"
#include <iostream>
#include <string>

const std::string inputFileName = "Day02.txt";

void Task(const std::vector<std::string>& passwords)
{
    int task1ValidPasswordCount = 0;
    int task2ValidPasswordCount = 0;
    for (const std::string& passwordLine : passwords)
    {
        std::vector<std::string> split = Common::SplitString(passwordLine, ':');
        if (split.size() != 2)
        {
            throw "Error: password not properly split";
        }

        std::string passwordPolicy = split.at(0);
        std::string password = split.at(1);

        std::vector<std::string> data = Common::SplitString(passwordPolicy, ' ');
        std::vector<std::string> dataNumbers = Common::SplitString(passwordPolicy, '-');

        const int policyNumberA = std::stoi(dataNumbers.at(0));
        const int policyNumberB = std::stoi(dataNumbers.at(1));
        const char targetCharacter = data.at(1)[0];

        int targetCharacterCount = 0;
        for (const char& letter : password)
        {
            if (letter == targetCharacter)
            {
                ++targetCharacterCount;
            }
        }

        if (targetCharacterCount >= policyNumberA && targetCharacterCount <= policyNumberB)
        {
            ++task1ValidPasswordCount;
        }

        if (!(password.at(policyNumberA) == targetCharacter) != !(password.at(policyNumberB) == targetCharacter))   // XOR
        {
            ++task2ValidPasswordCount;
        }
    }
    std::cout << "Task1 valid password count: " << task1ValidPasswordCount << std::endl;
    std::cout << "Task2 valid password count: " << task2ValidPasswordCount << std::endl;
}

int main()
{
    std::vector<std::string> passwordsList;
    try
    {
        Common::LoadStringList(inputFileName, passwordsList);
    }
    catch (const char* error)
    {
        std::cout << error << std::endl;
        return -1;
    }

    Task(passwordsList);
    return 0;
}