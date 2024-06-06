/*
File title: CountingSort.cpp
Author: Ramisha Chowdhury
Breif Description: Project 3. This will implement CountingSort class 

This file will be graded
*/

#include "CountingSort.hpp"

void countingSort (const std::string & header, std::vector<int> data){

    // Hash map to store counts of each value from data
    std::unordered_map<int, int> count;

    //auto start = std::chrono::high_resolution_clock::now();


    //Insert into hash map
    for(int x : data){
        if(count.find(x) == count.end()){//If x is not in the map, insert it with count 1
            count[x] = 1;
        }

        else{ //x is already in map so increment the count
            count[x]++; 
        }
    }

    std::vector<std::pair<int, int>> countvec;//Vector to store key-value pair

    // Transfer key-value pairs from hash map to vector
    for (const auto &pair : count) {
        countvec.push_back(pair);
    }

    std::sort(countvec.begin(), countvec.end()); //Sort the vector

    // Initialize variables to store 6 values
    int total_count = 0;
    int P25 = 0;
    int P50 = 0;
    int P75 = 0;
    int min = countvec.front().first;
    int max = countvec.back().first;
    int unique = countvec.size();
    
    // Iterate through the sorted vector to calculate percentiles
    for (const auto &pair : countvec) {
        total_count += pair.second;

        if (P25 == 0 && total_count >= data.size() / 4) {
            P25 = pair.first;
        }
        if (P50 == 0 && total_count >= data.size() / 2) {
            P50 = pair.first;
        }
        if (P75 == 0 && total_count >= (3 * data.size()) / 4) {
            P75 = pair.first;
            break; 
        }
    }

    //auto end = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double, std::micro> elapsed_microseconds = end - start;
        //std::cout << "Time CountingSort: " << elapsed_microseconds.count() << " microseconds" << std::endl;

    std::cout << header << std::endl << "Min: " << min << std::endl << "P25: " << P25 << std::endl
    << "P50: " << P50 << std::endl << "P75: " << P75 << std::endl << "Max: " << max << std::endl
    << "Unique: " << unique << std::endl;


}