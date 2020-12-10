/************************  ADVENT OF CODE 2020 **********************************       *
**                                                                              *      /.\
**                         adventofcode.com                                     *     /..'\
**                                                                              *     /'.'\
**                         mlogic1 (https://github.com/mlogic1)                 *    /.''.'\
**                                                                              *    /.'.'.\
**                                                                              *   /'.''.'.\
**                         Day 4 - Passport Processing                          *   ^^^[_]^^^
**                                                                              *
**                                                                              *
**                                                                              *
********************************************************************************/

#include "../common/Common.h"
#include <iostream>
#include <string>
#include <thread>

const std::string inputFileName = "Day04.txt";
const std::vector<std::string> REQUIRED_FIELDS = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };

const int BYR_MIN = 1920;
const int BYR_MAX = 2002;
const int IYR_MIN = 2010;
const int IYR_MAX = 2020;
const int EYR_MIN = 2020;
const int EYR_MAX = 2030;
const int HGT_MIN_CM = 150;
const int HGT_MAX_CM = 193;
const int HGT_MIN_IN = 59;
const int HGT_MAX_IN = 76;
const std::vector<char> HCL_VALID = { '0','1','2','3','4','5','6','7','8','9','a', 'b','c','d','e','f' };
const std::vector<std::string> ECL_VALID = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
const int PID_CHAR_COUNT = 9;

bool ValidatePassport(const std::string& passportData)
{
    bool passportValid = true;
    for (const std::string& field : REQUIRED_FIELDS)
    {
        if (passportData.find(field) == std::string::npos)
        {
            passportValid = false;
            break;
        }
    }
    return passportValid;
}

bool ValidatePassportData(const std::string& passportData)
{
    std::vector<std::string> entries = Common::SplitString(passportData, ' ');
    bool dataValid = true;

    for (const std::string& entry : entries)
    {
        if (entry == "")
            continue;

        const std::string entryID = entry.substr(0, 3);
        const std::string entryValue = Common::SplitString(entry, ':').at(1);
        if (entryID == "byr")
        {
            int byr = std::stoi(entryValue);
            if (byr < BYR_MIN || byr > BYR_MAX)
            {
                dataValid = false;
            }
        }
        else if (entryID == "iyr")
        {
            int iyr = std::stoi(entryValue);
            if (iyr < IYR_MIN || iyr > IYR_MAX)
            {
                dataValid = false;
            }
        }
        else if (entryID == "eyr")
        {
            int eyr = std::stoi(entryValue);
            if (eyr < EYR_MIN || eyr > EYR_MAX)
            {
                dataValid = false;
            }
        }
        else if (entryID == "hgt")
        {
            bool centimeters = entryValue.find("cm");
            int value = std::stoi(entryValue.substr(0, entryValue.size() - 2));
            if (centimeters)
            {
                if (value < HGT_MIN_CM || value > HGT_MAX_CM)
                {
                    dataValid = false;
                }
            }
            else
            {
                if (value < HGT_MIN_IN || value > HGT_MAX_IN)
                {
                    dataValid = false;
                }
            }
        }
        else if (entryID == "hcl")
        {
            if (entryValue.size() != 7)
            {
                dataValid = false;
            }
            else
            {
                const std::string colorCode = entryValue.substr(1, 6);
                for (const char& c : colorCode)
                {
                    if (std::find(HCL_VALID.begin(), HCL_VALID.end(), c) == HCL_VALID.end())
                    {
                        dataValid = false;
                        break;
                    }
                }
            }
        }
        else if (entryID == "ecl")
        {
            if (std::find(ECL_VALID.begin(), ECL_VALID.end(), entryValue) == ECL_VALID.end())
            {
                dataValid = false;
            }
        }
        else if (entryID == "pid")
        {
            if (entryValue.size() != PID_CHAR_COUNT)
            {
                dataValid = false;
            }
            else
            {
                for (const unsigned char& c : entryValue)
                {
                    if (!std::isdigit(c))
                        dataValid = false;
                }
            }
        }
    }
    return dataValid;
}

void Task(const std::vector<std::string>& passportList)
{
    std::vector<std::string> passports;
    
    std::string temp = "";
    for (int i = 0 ; i < passportList.size() ; ++i)
    {
        const std::string line = passportList.at(i);
        temp += line + " ";

        if (i == passportList.size() - 1)
        {
            passports.push_back(temp);
            break;
        }
        
        if (line == "")
        {
            passports.push_back(temp);
            temp = "";
            continue;
        }
    }

    unsigned int validPassportCount = 0;
    unsigned int validPassportAndDataCount = 0;
    for (const std::string& passportData : passports)
    {
        if (ValidatePassport(passportData))
        {
            ++validPassportCount;

            if (ValidatePassportData(passportData))
            {
                ++validPassportAndDataCount;
            }
        }
    }
    std::cout << "Task 1 valid passport count: " << validPassportCount << std::endl;
    // TASK 2 does not properly validate passports
    // std::cout << "Task 2 valid passport count: " << validPassportAndDataCount << std::endl;
}

int main()
{
    std::vector<std::string> passportList;
    try
    {
        Common::LoadStringList(inputFileName, passportList);
    }
    catch (const char* error)
    {
        std::cout << error << std::endl;
        return -1;
    }

    Task(passportList);
    return 0;
}