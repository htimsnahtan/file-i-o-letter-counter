/*********************************************************************
** Program name: libraryFunctions.hpp
** Author: Nathan Smith
** Date: 7-8-18
** Description:
*  Implimentation file for library functions
*  
*   Includes funtion to prompt user for a string and validate input
*********************************************************************/

#include "libraryFunctions.hpp"
#include <string>
#include <iostream>


//function parameters include input prompt and optional error prompt
std::string getValidString(std::string inputText, std::string inputErrorText)
{
    
    std::string userInput;

    for (;;)
    {
        std::cout << inputText << std::endl;
        if (std::cin >> userInput)
        {
            break;
        }
        else
        {
            std::cout << inputErrorText << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
    }
    return userInput;
}