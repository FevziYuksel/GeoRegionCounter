// GeoRegionCounter.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

#include "Reader.h"
#include "Matrix.h"

#define LOG(x) std::cout << x 



void getPos(size_t x, size_t y, size_t arr[], size_t n)
{
	std::cout << arr[x * n + y] << std::endl;
}
size_t* makeArr(size_t size)
{
	return (size_t*)malloc(sizeof(size_t) * size);
}




