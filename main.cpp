/*
File title: main.cpp
Author: Ramisha Chowdhury
Breif Description: Project 3.  

This file will be graded
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

using namespace std;

int main(){
    // Open the input file
    std::ifstream inputFile("test_input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    // Vector to store the instructions
    std::vector<int> data;

    //Read header
    std::string header;
    getline(inputFile, header);

    //Read the data and push back to vector
    int num;
    while (inputFile >> num){
        data.push_back(num);
    }


    // Close the input file
    inputFile.close();

    //Test cases
    stdSort(header, data);
    quickSelect1(header, data);
    quickSelect2(header, data);
    countingSort(header, data);

    return 0;



}