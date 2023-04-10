#include <iostream>
#include <set>
#include <vector>
#include <optional>
#include "PrimeGenerator.h"

using namespace std;

int main(int argc, char* argv[])
{
    int upperBound;
    cin >> upperBound;

    set<int> primes = GeneratePrimeNumbersSet(static_cast<size_t>(upperBound));

    for (auto primeNumber : primes)
    {
        for(int i = 0; i < 20; i++)
            cout << primeNumber << " ";
        cout << endl;
    }
    
    return 0;
}
