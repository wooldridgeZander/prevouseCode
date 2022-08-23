/*
Zander wooldridge
csc 160-section
04/18/2021
summary: takes the 12 hour day time frame and puts it into 24 hour time
*/

#include <iostream>
#include <cstring>
#include <string>

void print24(std::string str)
{
    //get hours
    int h1 = (int)str[1] - '0';
    int h2 = (int)str[0] - '0';
    int hh = (h2 * 10 + h1 % 10);

    // If time is in "AM"
    if (toupper(str[6]) == 'A')
    {
        if (hh == 12)
        {
            std::cout << "00";
            for (int i = 2; i <= 4; i++)
                std::cout << str[i];
        }
        else
        {
            for (int i = 0; i <= 4; i++)
                std::cout << str[i];
        }
    }

    // If time is in "PM"
    else
    {
        if (hh == 12)
        {
            std::cout << "12";
            for (int i = 2; i <= 4; i++)
                std::cout << str[i];
        }
        else
        {
            hh = hh + 12;
            std::cout << hh;
            for (int i = 2; i <= 4; i++)
                std::cout << str[i];
        }
    }
}


int main()
{
    std::string time;

    std::cout << "Enter the time as (hh:mm xm) ";
    std::getline(std::cin, time);

    print24(time);

    

    return 0;
}