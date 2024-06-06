/*
File title: QuickSelect1.cpp
Author: Ramisha Chowdhury
Breif Description: Project 3. This will implement QuickSelect1. 

This file will be graded
*/

#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"
#include "InsertionSort.cpp"


//Textbook implementaion
int & medianOfThree(std::vector<int> & a, int left, int right)
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


    

void insertionSort(std::vector<int> & a, int left, int right){
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
void quickSelect(std::vector<int> & a, int left, int right, int k)
{
    if( left + 20 <= right )
    {
    const int & pivot = medianOfThree( a, left, right );
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
        // Recurse; only this part changes
        if( k <= i )
        quickSelect( a, left, i - 1, k );
        else if( k>i+1)
        quickSelect( a, i + 1, right, k );
        }
        else // Do an insertion sort on the subarray
        insertionSort(a, left, right );
}

void quickSelect1(const std::string & header, std::vector<int> data){

    //auto start_time = std::chrono::high_resolution_clock::now(); //Timer starts
    int size = data.size()-1;
    int medianIndex = data.size()/2-1;
    int p25Index = data.size()/4-1;
    int p75Index = data.size()*3/4-1;
    
    quickSelect(data, 0, size, medianIndex);
    int median = data[medianIndex]; //P50

    quickSelect(data, 0, medianIndex, p25Index);
    int p25 = data[p25Index]; //p25

    quickSelect(data, medianIndex, size, p75Index);
    int p75 = data[p75Index]; //p75

    int min = *std::min_element(data.begin(), data.begin() + p25Index);
    int max = *std::max_element(data.begin() + p75Index, data.end());

        //auto end = std::chrono::high_resolution_clock::now();
        //std::chrono::duration<double, std::micro> elapsed_microseconds = end - start;
        //std::cout << "Time quickSelect1: " << elapsed_microseconds.count() << " microseconds" << std::endl;

    std::cout << header << std::endl << "Min: " << min << std::endl << "P25: " << p25 << std::endl
    << "P50: " << median << std::endl << "P75: " << p75 << std::endl << "Max: " << max << std::endl;



}
