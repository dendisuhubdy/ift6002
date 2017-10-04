#include <iostream>
#include <vector>

using namespace std;

#define MAX 20

bool isinarray(int number, vector<int> numlist)
{
    // traverse all of the numlist 
    for (auto i:numlist) {
        // if we have a match, return true
        if (i == number) { 
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

int main()
{
    vector<int> integers;
    vector<int> nonprimes;

    // fill in values of 0 to 100 
    std::cout << "List of integers here " << std::endl;
    for (int i = 0; i <= MAX; i++) {
        integers.push_back(i + 1);
        std::cout << i + 1 <<  ' ' ; // std::endl;
    }

    std::cout << "Sieving to detect non primes" << std::endl;

    for (auto x:integers) {
        if (x == 1) {
            continue;
        }
        else {
            // now we would want to sieve
            // x*1; x*2; x*3; x*4; x*5; etc....
            // so another for here
            for(auto j:integers) {
                // basically neglect if the multiplicator is one
                // unless you would want to trigger the prime also in nonprimes
                if(j == 1) {
                    continue;
                }
                else {
                    nonprimes.push_back(x*j);
                    // print the values of non primes to be right (debugging)
                    std::cout << x*j << ' ' ;
                }
            }
        }
    }

    // std::cout << "Print values of non-primes to check" << std::endl;
    
    std::cout << "Now basically the ones without the element number in non-primes are primes" << std::endl;
    // traverse all of the values in nonprimes in random access, then print the ones not there
    
    for (auto i:integers) {    
        auto found = std::find(nonprimes.begin(), nonprimes.end(), i);

        if (found != std::end(nonprimes)) {  
        //if (isinarray(i, nonprimes)) {
            std::cout << " Non-Prime : " << i << std::endl;
        }
        else {
            // we have our prime number here
            std::cout << " Prime : " << i << std::endl; 
        }
    }

    return 0;
}
