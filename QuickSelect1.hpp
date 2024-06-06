
/*
File title: QuickSelect1.hpp
Author: Ramisha Chowdhury
Breif Description: Project 3. For QuickSelect1. 

This file will be graded
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <iterator>
#include <algorithm>

#ifndef QUICKSELECT1_HPP
#define QUICKSELECT1_HPP

void quickSelect1(const std::string & header, std::vector<int> data);
int & medianOfThree(std::vector<int> & a, int left, int right);
void quickSelect(std::vector<int> & a, int left, int right, int k);
void insertionSort(std::vector<int> & a, int left, int right);

#endif
