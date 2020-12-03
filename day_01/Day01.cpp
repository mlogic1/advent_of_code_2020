/************************  ADVENT OF CODE 2020 **********************************       *
**                                                                              *      /.\
**                         adventofcode.com                                     *     /..'\
**                                                                              *     /'.'\
**                         mlogic1 (https://github.com/mlogic1)                 *    /.''.'\
**                                                                              *    /.'.'.\
**                                                                              *   /'.''.'.\
**                         Day 1 - Report Repair                                *   ^^^[_]^^^
**                                                                              *
**                                                                              *
**                                                                              *
********************************************************************************/

#include "../common/Common.h"
#include <iostream>
#include <string>

const std::string inputFileName = "Day01.txt";
const int TargetSum = 2020;

void Task1(const std::vector<int>& numbersList)
{
    int multiplicationResult = -1;

    for (int i = 0, len = numbersList.size(); i < len; ++i)
    {
        const int firstNumber = numbersList.at(i);
        for (int j = 0; j < len; ++j)
        {
            if (i == j)
                continue;
            const int secondNumber = numbersList.at(j);
            const int sum = firstNumber + secondNumber;

            if (sum == TargetSum)
            {
                multiplicationResult = firstNumber * secondNumber;
                break;
            }
        }
    }

    if (multiplicationResult != -1)
    {
        std::cout << "Task 1 Result: " << multiplicationResult << std::endl;
    }
    else
    {
        std::cout << "Sum not found, no result to display." << std::endl;
    }
}

void Task2(const std::vector<int>& numbersList)
{
    int multiplicationResult = -1;

    for (int i = 0, len = numbersList.size(); i < len; ++i)
    {
        const int firstNumber = numbersList.at(i);
        for (int j = 0; j < len; ++j)
        {
            if (i == j)
                continue;
            const int secondNumber = numbersList.at(j);

            for (int k = 0; k < len; ++k)
            {
                if (k == i || k == j)
                {
                    continue;
                }
                const int thirdNumber = numbersList.at(k);
                const int sum = firstNumber + secondNumber + thirdNumber;

                if (sum == TargetSum)
                {
                    multiplicationResult = firstNumber * secondNumber * thirdNumber;
                    break;
                }
            }
        }
    }

    if (multiplicationResult != -1)
    {
        std::cout << "Task 2 Result: " << multiplicationResult << std::endl;
    }
    else
    {
        std::cout << "Sum not found, no result to display." << std::endl;
    }
}


int main()
{
    std::vector<int> numbersList;
    try
    {
        Common::LoadIntegerList(inputFileName, numbersList);
    }
    catch (const char* error)
    {
        std::cout << error << std::endl;
        return -1;
    }

    Task1(numbersList);
    Task2(numbersList);
}