/*
 * =====================================================================================
 *
 *       Filename:  insertionsort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/04/2017 13:30:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>

void insertionsort(int arr[], int n)
{
    int i, key, j;
    for(i = 1; i< n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1] that are 
         * greater than key, to the one position
         * ahead.
         */

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j -1 ;
        }

        arr[j+1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        std::cout << arr[i] << " " ;
    std::cout << std::endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::cout << "Array before sorting " << std::endl;
    printArray(arr, n);
    insertionsort(arr, n);
    std::cout << "Array after sorting " << std::endl;
    printArray(arr, n);
    return 0;
}

