/*
File title: StdSort.cpp
Author: Ramisha Chowdhury
Breif Description: Project 3. This will implement StdSort  

This file will be graded
*/

#include "StdSort.hpp"

void stdSort (const std::string & header, std::vector<int> data){

    //auto start = std::chrono::high_resolution_clock::now();

    if(!data.empty()){
            //Sort the vector
            std::sort(data.begin(), data.end()); 
            
            //Calculate the min
            int min = data.front();
            //Calculate the max
            int max = data.back();


            //Calculate percentiles
            int medianIndex = data.size()/2-1;
            int p25Index = data.size()/4-1;
            int p75Index = data.size()*3/4-1;

            int p25 = data[p25Index];
            int p50 = data[medianIndex];
            int p75 = data[p75Index];

        //auto end = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double, std::micro> elapsed_microseconds = end - start;
        //std::cout << "Time StdSort: " << elapsed_microseconds.count() << " microseconds" << std::endl;

            std::cout << header << std::endl << "Min: " << min << std::endl << "P25: " << p25 << std::endl
            << "P50: " << p50 << std::endl << "P75: " << p75 << std::endl << "Max: " << max << std::endl; 



        }


    }

