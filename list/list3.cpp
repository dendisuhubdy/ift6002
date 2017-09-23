#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
int binarySearch(const vector<Comparable> &a, const Comparable &x)
{
    int low = 0;
    int high = a.size() - 1;

    while (low <= high)
    {
        int mid = (low+high) /2;

        if(a[mid] <x){
            low = mid + 1;
        }
        else if(a[mid]>x) {
            high = mid -1;
        }
        else {
            return mid; //Found
        }
    }
    return -1;
}        

int main(void)
{
    return 0;
}

