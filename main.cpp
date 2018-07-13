/*********************************************************************
** Program name: main.cpp
** Author: Nathan Smith
** Date: 7-8-18
** Description:
* Given a user inputted file, reads file, counts letter frequencies, and writes
* result to a new file.
* Note: file should consist only of: ‘a’ - ‘z’, ‘A’ – ‘Z’, space character, 
* newline characters
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "count_letters.hpp"
#include "output_letters.hpp"
#include "libraryFunctions.hpp"

int main()
{
    const int NUMBER_OF_ASCII_CHARS = 128;
    std::ifstream fin;
    int letterFrequencies[NUMBER_OF_ASCII_CHARS+1];//extra 1 is to tell if success

    //get file name then try to open it
    std::string fileName = getValidString("Please enter the filename you would like to read:");
    
    fin.open(fileName.c_str(), std::ifstream::in);
    
    if (fin.fail())
    {
        std::cout << "File not found." << std::endl;
        return 1;
    }
    
    int counter = 0;
    while (!fin.eof())
    {   
        counter++;
        count_letters(fin, letterFrequencies);
        
        if (letterFrequencies[NUMBER_OF_ASCII_CHARS])// checks last index to see if characters appended
        {
            std::ofstream fout;
            output_letters(fout, letterFrequencies);
        }

    }
    
    // close file
    fin.close();
    return 0;
}