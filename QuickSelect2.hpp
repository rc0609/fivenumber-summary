/*
File title: QuickSelect2.hpp
Author: Ramisha Chowdhury
Breif Description: Project 3. For QuickSelect2  

This file will be graded
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <algorithm>
#include <string>

#ifndef QUICKSELECT2_HPP
#define QUICKSELECT2_HPP

void quickSelect2 (const std::string & header, std::vector<int> data);
void quickSelect2nd(std::vector<int> & a, int left, int right, std::vector<int> k);
void insertionSort2nd(std::vector<int> & a, int left, int right);
int & median3(std::vector<int> & a, int left, int right);

#endif