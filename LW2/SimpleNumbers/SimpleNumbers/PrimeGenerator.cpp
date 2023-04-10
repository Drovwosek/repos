#include <set>
#include <vector>

using namespace std;

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
    std::set<int> primeNums;

    if (upperBound < 2)
    {
        return primeNums;
    }

    primeNums.insert(2);

    std::vector<int> sieve(upperBound + 1, true);

    for (int i = 4; i < upperBound; i += 2)
    {
        sieve[i] = false;
    }

    int sqrtUpperBound = sqrt(upperBound);

    for (int i = 3; i <= upperBound; i += 2)
    {
        if (sieve[i])
        {
            primeNums.insert(i);

            if (i <= sqrtUpperBound)
            {
                for (int j = 3 * i; j <= upperBound; j += 2 * i)
                {
                    sieve[j] = false;
                }
            }
        }
    }

    return primeNums;
}
/*
set<int> GeneratePrimeNumbersSet(int upperBound)
{
    set<int> primes;

    if (upperBound < 2)
    {
        return primes;
    }

    vector<int> sieve;
    sieve.assign(upperBound + 1, true);

    for (int i = 4; i < upperBound; i += 2) // каждый четный: чемодан, вокзал, ...
    {
        sieve[i] = false;
    }

    primes.insert(2);

    for (int i = 3; i < upperBound + 1; i += 2) // каждый непростой из нечетных: чемодан, вокзал, ...
    {
        if (!sieve[i])
        {
            continue;
        }

        primes.insert(primes.end(), i);

        for (int j = i * 3; j < upperBound + 1; j = i * 2)
        {
            sieve[j] = false;
        }
    }

    return primes;
}
*/