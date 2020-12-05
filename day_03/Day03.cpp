/************************  ADVENT OF CODE 2020 **********************************       *
**                                                                              *      /.\
**                         adventofcode.com                                     *     /..'\
**                                                                              *     /'.'\
**                         mlogic1 (https://github.com/mlogic1)                 *    /.''.'\
**                                                                              *    /.'.'.\
**                                                                              *   /'.''.'.\
**                         Day 3 - Toboggan Trajectory                          *   ^^^[_]^^^
**                                                                              *
**                                                                              *
**                                                                              *
********************************************************************************/

#include "../common/Common.h"
#include <iostream>
#include <string>
#include <thread>

const std::string inputFileName = "Day03.txt";

void CalculateSlope(const std::vector<std::string>& tobogganMap, const int horizontalIncrement, const int verticalIncrement, int* result)
{
    *result = 0;
    const unsigned int COLUMN_COUNT = tobogganMap.at(0).size();
    const unsigned int ROW_COUNT = tobogganMap.size();

    unsigned int currentCol = 0;
    unsigned int currentRow = 0;

    while (true)
    {
        currentCol += horizontalIncrement;
        currentRow += verticalIncrement;

        if (currentRow > ROW_COUNT - 1)
        {
            break;
        }

        const std::string& row = tobogganMap.at(currentRow);

        if (currentCol > COLUMN_COUNT - 1)
        {
            currentCol -= COLUMN_COUNT;
        }

        if (row.at(currentCol) == '#')
        {
            ++*result;
        }
    }
}

int main()
{
    std::vector<std::string> tobogganMap;
    try
    {
        Common::LoadStringList(inputFileName, tobogganMap);
    }
    catch (const char* error)
    {
        std::cout << error << std::endl;
        return -1;
    }
    
    int R1D1 = 0, R3D1 = 0, R5D1 = 0, R7D1 = 0, R1D2 = 0;
    std::thread t1(CalculateSlope, tobogganMap, 1, 1, &R1D1);
    std::thread t2(CalculateSlope, tobogganMap, 3, 1, &R3D1);
    std::thread t3(CalculateSlope, tobogganMap, 5, 1, &R5D1);
    std::thread t4(CalculateSlope, tobogganMap, 7, 1, &R7D1);
    std::thread t5(CalculateSlope, tobogganMap, 1, 2, &R1D2);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << "Task 1 trees: " << R3D1 << std::endl;
    std::cout << "Task 2 product: " << R1D1 * R3D1 * R5D1 * R7D1 * R1D2 << std::endl;

    return 0;
}