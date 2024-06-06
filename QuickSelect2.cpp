/*
File title: QuickSelect2.cpp
Author: Ramisha Chowdhury
Breif Description: Project 3. This will implement QuickSelect2.

This file will be graded
*/

#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"
#include "InsertionSort.cpp"


//Textbook implementaion
int & median3(std::vector<int> & a, int left, int right)
{
    int center = ( left + right ) / 2;
    if( a[ center ] < a[ left ] )
    std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
    std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
    std::swap( a[ center ], a[ right ] );
    // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];

}


    

void insertionSort2nd(std::vector<int> & a, int left, int right){
    for (int i = left; i <= right; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= left && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }

}

//Modified textbook implementation
void quickSelect2nd(std::vector<int> & a, int left, int right, std::vector<int> k)
{
    if( left + 20 <= right )
    {
    const int & pivot = median3( a, left, right );
    // Begin partitioning
    int i = left, j = right - 1;
    for( ; ; )
        {
        while( a[ ++i ] < pivot ) { }
        while( pivot < a[ --j ] ) { }
        if( i < j )
        std::swap( a[ i ], a[ j ] );
        else
        break;
        }
        std::swap( a[ i ], a[ right - 1 ] ); // Restore pivot
        
        //Below are different from quickSelect1

        //Create key containers
        std::vector<int> leftkey;
        std::vector<int> rightkey;

        for(int key : k){
            if(key <= i)
                leftkey.push_back(key);

            else if (key > i + 1)
                rightkey.push_back(key);

        }

        if(!leftkey.empty())
            quickSelect2nd(a, left, i - 1, leftkey);

        if (!rightkey.empty())
            quickSelect2nd(a, i + 1, right, rightkey);
    } 
    
    else {
        insertionSort2nd(a, left, right);
    }



}


void quickSelect2(const std::string & header, std::vector<int> data){

    //auto start = std::chrono::high_resolution_clock::now(); //Timer starts
    int size = data.size()-1;
    int medianIndex = data.size()/2-1;
    int p25Index = data.size()/4-1;
    int p75Index = data.size()*3/4-1;

    std::vector<int> keys = {0, p25Index, medianIndex, p75Index, size};

    quickSelect2nd(data, 0, size, keys);

    int p25 = data[p25Index];
    int median = data[medianIndex];
    int p75 = data[p75Index];

    int min = data[0];
    int max = data[size];

        //auto end = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double, std::micro> elapsed_microseconds = end - start;
        //std::cout << "Time quickSelect2: " << elapsed_microseconds.count() << " microseconds" << std::endl;

    std::cout << header << std::endl << "Min: " << min << std::endl << "P25: " << p25 << std::endl
    << "P50: " << median << std::endl << "P75: " << p75 << std::endl << "Max: " << max << std::endl;



}
