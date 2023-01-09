#include <iostream>
#include <fstream>
#include "count_region.h"

#define LOG(x) std::clog << x //<< std::endl
#define ROW 32

template<typename Container>
Container& test_containers();
void print_vector(const std::vector<std::vector<char>>& base);
void print_vector(const std::vector<char>& sub);

int main() {

    std::ifstream file("C:\\Users\\201434\\CLionProjects\\test\\map.txt");
    //write append/add for matrix class
    std::vector<std::vector<char>> base;
    std::vector<char> sub;
    char c;

    if (file.is_open()) {
        while (!file.eof()) {
            file >> c;
            sub.push_back(c);
            if (sub.size() == ROW) {
                base.push_back(sub);
                sub.clear();
            }
        }
        file.close();
    }
    else {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    LOG(count_region(base, 18, 32));


    return 0;
}

template<typename Container>
Container& test_containers() {

    std::vector<std::vector<char>> matrix{
            {'.','#','#','#'},
            {'#','#','.','#'},
            {'.','#','#','#'},
            {'.','#','#','.'} };

    //std::cout << count_region(matrix, 4, 4) << std::endl;

    char matrix_arr[4][4] = {
            {'.','#','#','#'},
            {'#','#','.','#'},
            {'.','#','#','#'},
            {'.','#','#','.'} };

    return matrix;
}

void print_vector(const std::vector<std::vector<char>>& base) {
    for (const std::vector<char>& sub : base) {
        for (const char& c : sub) {
            std::cout << c;//<< ' ';
        }
        std::cout << std::endl;
    }
}

void print_vector(const std::vector<char>& sub) {
    for (const char& c : sub) {
        std::cout << c;
    }
}

