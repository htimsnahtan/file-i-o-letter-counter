/*********************************************************************
** Program name: output_letters.cpp
** Author: Nathan Smith
** Date: 7-8-18
** Description:
* Header implimentation file for output_letters function
* 
output_letters function takes an output file stream variable, and a pointer to 
an array of integers that contains frequencies of letters.

The function first asks user for the filename the user would like to output to, 
then outputs the frequencies of letters to the output file in the format specified 
above.
*********************************************************************/

#include "output_letters.hpp"
#include <fstream>
#include <iostream>
#include "libraryFunctions.hpp"

void output_letters(std::ofstream& foutIn, int* arrayIn)
{
    std::string oFileName = getValidString("Please enter the filename you would like to output to:");
    foutIn.open(oFileName.c_str());
    
    for (char ch = 'a'; ch <= 'z'; ch++)//iterates through characters using ascii values
    {
      foutIn << ch << " : " << arrayIn[ch] << std::endl;
    }
    foutIn.close();
}