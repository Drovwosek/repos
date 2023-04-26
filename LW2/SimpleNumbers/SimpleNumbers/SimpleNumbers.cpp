#include <iostream>
#include <set>
#include <vector>
#include <optional>
#include <iterator>
#include "PrimeGenerator.h"

/*
    ++вывксти в функцию вывод чисел (мб через copy сделать?)
    ++static_cast преобразует типы, не надо
    ++в primeGeneratoer большая вложенность - исправить
*/

using namespace std;

int main(int argc, char* argv[])
{
    int upperBound;
    cin >> upperBound;

    set<int> primes = GeneratePrimeNumbersSet(upperBound);

    copy(primes.begin(), primes.end(), ostream_iterator<int>(cout, " "));
        
    return 0;
}
