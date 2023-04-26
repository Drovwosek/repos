#include <set>
#include <vector>

using namespace std;

const set<int> EMPTY_SET{};

void ExcludeEvenNumbers(vector<int> sieve, int upperBound)
{
    for (int i = 4; i < upperBound; i += 2) // в функцию "закрыть все чЄтные числа" ? наху€? а главное: зачем?
    {
        sieve[i] = false;
    }
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
    if (upperBound < 2)
    {
        return EMPTY_SET;
    }

    set<int> primeNums{ 2 };
    
    vector<int> sieve(upperBound + 1, true);

    ExcludeEvenNumbers(sieve, upperBound);

    int sqrtUpperBound = sqrt(upperBound);
    
    for (int i = 3; i <= upperBound; i += 2)
    {
        if (!sieve[i])
        {
            continue;
        }
        primeNums.insert(i);

        if (i <= sqrtUpperBound)
        {
            for (int j = 3 * i; j <= upperBound; j += 2 * i)
            {
                    sieve[j] = false;
            }
        }
    }

    return primeNums;
}
