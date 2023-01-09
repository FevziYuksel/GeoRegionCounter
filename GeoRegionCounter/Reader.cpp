
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Reader.h"

void reader::ReadWholeFile()
{
    std::ifstream file;
    file.open("map.txt");
    file.seekg(0, std::ios_base::end); // Seek to end of file.
    const unsigned int file_length = file.tellg();
    file.seekg(0);
    std::vector<char> file_data(file_length);
    file.read(&file_data[0], file_length);

    for (char c : file_data)
        std::cout << c;
}


void reader::ReadWholeFile2()
{
    std::ifstream file;
    file.open("map.txt");
    file.seekg(0, std::ios_base::end); // Seek to end of file.
    const unsigned int file_length = file.tellg();
    file.seekg(0);
    std::vector<char> file_data(file_length);
    file.read(&file_data[0], file_length);

    using iter = std::vector<char>::iterator;

    for (iter it = file_data.begin(); it != file_data.end(); ++it)
    {
        if (*it == '\n')
        {
            file_data.erase(it);
        }
    }
    for (char c : file_data)
        std::cout << c;
}


