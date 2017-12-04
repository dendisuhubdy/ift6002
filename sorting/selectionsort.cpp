/*
 * =====================================================================================
 *
 *       Filename:  selectionsort.cpp
 *
 *    Description:  Selection Sort algorithm
 *
 *        Version:  1.0
 *        Created:  12/04/2017 13:14:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  DENDI SUHUBDY (2017), 
 *   Organization:  MILA
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

int selectionsort(vector <int>unsorted)
{
    for (auto i=std::begin(unsorted); i!= std::end(unsorted)-2; i++) {
        int minidx = i;
        for (auto j = i+1; i!=std::end(unsorted); j++) {
            if unsorted[j] < unsorted[minidx] {
                minidx = j;
            }
        }
        if (i != minidx) {
            swap(A[i], A[mindx]) ;
        }
    }
    // return the sorted index
    return unsorted; 
}

int main() 
{
    vector <int> a = {1, 2, 10, 3, 4, 1};
    std::cout << selectionsort(a) << std::endl;
    return 0;
}
