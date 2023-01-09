#ifndef TEST_COUNT_REGION_H
#define TEST_COUNT_REGION_H

#include <iostream>
#include <functional>
#include <vector>

using uint32_t = unsigned int;
using int32_t = int;
using pair_t = std::pair<int, int>;

typedef std::vector<std::vector<char>> char_vector;

void DFS(char_vector& matrix, const int row, const int col);

void DFS2(char_vector& matrix, const int row, const int col);

uint32_t count_region(char_vector& matrix, const int row_size, const int col_size);

template<int row_size, int col_size>
uint32_t count_region(char(&matrix)[row_size][col_size]);

#endif //TEST_COUNT_REGION_H