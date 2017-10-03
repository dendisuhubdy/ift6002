#include <iostream>
#include <vector>

using namespace std;

int peakfind(vector<int> haystack)
{
    int result = 0;
    for (int i = 0; i < haystack.size(); i++)
    {
        if (haystack[i] > result)
        {
            result = haystack[i];
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
