#include "count_region.h"


void DFS(char_vector& matrix, const int row, const int col) 
{

    matrix[row][col] = '#';

    if (matrix[row + 1][col] == '.') DFS(matrix, row + 1, col);
    if (matrix[row - 1][col] == '.') DFS(matrix, row - 1, col);
    if (matrix[row][col + 1] == '.') DFS(matrix, row, col + 1);
    if (matrix[row][col - 1] == '.') DFS(matrix, row, col - 1);
}

void DFS2(char_vector& matrix, const int row, const int col) 
{

    matrix[row][col] = '#';

    //    bool (*is_safe)(int,int) = [](const int row, const int col){
    //        return (row >= 0 && row < matrix.size()) && (col >= 0 && col < matrix[0].size()); };

    std::function<bool(int, int)> is_safe = [&](const int row, const int col) 
    {
        return (row >= 0 && row < matrix.size()) && (col >= 0 && col < matrix[0].size()); }; //make it as its own function

    pair_t dir[] = 
    {
            std::make_pair(1,0),
            std::make_pair(-1,0),
            std::make_pair(0,1),
            std::make_pair(0,-1)
    };

    for (pair_t pair : dir) 
    {
        int n_row = row + pair.first, n_col = col + pair.second;
        if (is_safe(n_row, n_col) && matrix[n_row][n_col] == '.') {
            DFS2(matrix, n_row, n_col);
        }
    }
}

uint32_t count_region(char_vector& matrix, const int row_size, const int col_size)
{

    static uint32_t count = 0;
    for (int row = 0; row < row_size; row++) 
    {
        for (int col = 0; col < col_size; col++) 
        {

            if (matrix[row][col] == '.') {  // is_safe is redundant

                DFS2(matrix, row, col);
                count++;
            }
        }
    }
    return count;
}

template<int row_size, int col_size>
uint32_t count_region(char(&matrix)[row_size][col_size]) 
{
    //    std::function<bool(int, int)> is_safe = [&](int row, int col){
//        return (row >= 0 && row < row_size) && (col >= 0 && col < col_size); };
    //return uint32_t(1);
    return static_cast<uint32_t>(1);
}