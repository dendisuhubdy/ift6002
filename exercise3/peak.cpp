#include <iostream>
#include <vector>

using namespace std;

int peakfind(vector<int> haystack)
{
    int result = 0;
    for (auto x:haystack)
    {
        if (x > result)
        {
            result = x;
        }
    }
    return result;
}

int main()
{
    vector<int> haystack {1,2,5,1,3,7, 11, 2, 4, 5, 6 };
    int trial =  peakfind(haystack);
    std::cout << trial << std::endl;
}
