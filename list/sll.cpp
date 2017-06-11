/*
Single linked list in C++
*/

#include <iostream>
#include <vector>

int maxSubSum2(const std::vector<int> &a)
{
    int maxSum = 0;
    for (int i=0; i < a.size(); ++i) {
        int thisSum = 0;
        for (int j=i; j<a.size(); ++j) {
            thisSum += a[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int main(void)
{
    std::vector<int> a = {1,2,3,4,5,6,7};
    int maxSum = 0;

    std::cout << maxSubSum2(a) << std::endl;
}
