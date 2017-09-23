#include <iostream>
#include <map>

using namespace std;

int hash1(const string & key, int tableSize)
{
    int hashVal = 0;

    for (char ch: key) {
        hashVal += ch;
    }

    return hashVal % tableSize;
}

int hash2(const string & key, int tableSize)
{
    return (key[0] + 27 * key[1] + 729 * key[2]) % tableSize;
}

int main()
{
    return 0;
}
