/*********************************************************************
** Program name: count_letters.cpp
** Author: Nathan Smith
** Date: 7-8-18
** Description:
* Header implimentation file for count_letters function
* 
Program takes an input file stream variable, and a pointer to an array of integers.

The function first reads the paragraph string from the input file stream, 
then counts the letter frequencies of that paragraph, and store the frequencies 
in the array. Disregards upper/lower case letters.
*********************************************************************/

#include "count_letters.hpp"
#include <iostream>
#include <fstream>

void count_letters(std::ifstream& finIn, int* arrayIn)
{
    const int NumberOfAsciiChars = 128;
    // initalize all counts to 0
    for (int i = 0; i <= NumberOfAsciiChars; i++)
    {
        arrayIn[i] = 0;
    }
    
    char oneChar = finIn.get();
    while(oneChar != EOF && oneChar != '\n')
    {
        arrayIn[tolower(oneChar)]++;
        arrayIn[NumberOfAsciiChars] = 1; //reserve last index to tell if data collected
        oneChar = finIn.get();
    }
}