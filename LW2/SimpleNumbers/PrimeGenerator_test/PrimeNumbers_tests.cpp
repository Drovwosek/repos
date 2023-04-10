#include "../../../repos/catch/catch.hpp"
#include "../SimpleNumbers/PrimeGenerator.h"

using namespace std;

TEST_CASE("GeneratePrimeNumbersSet: check timings and count of primes")
{
	auto t1 = chrono::high_resolution_clock::now();
	set<int> primes = GeneratePrimeNumbersSet(100000000);
	auto t2 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
	REQUIRE(duration < 12);
	REQUIRE(primes.size() == 5761455);
}

TEST_CASE("PrimeGenerator: Set of prime numbers less 1")
{
	int upperBound = 1;
	set<int> setExpected = {};	
	REQUIRE(GeneratePrimeNumbersSet(upperBound) == setExpected);
}

TEST_CASE("PrimeGenerator: Set of prime numbers ?????? negative value ")
{
	int upperBound = -5;
	set<int> setExpected = {};
	REQUIRE(GeneratePrimeNumbersSet(upperBound) == setExpected);
}

TEST_CASE("PrimeGenerator: Set of prime numbers less 2 value ")
{
	int upperBound = 2;
	set<int> setExpected = {2};
	REQUIRE(GeneratePrimeNumbersSet(upperBound) == setExpected);
}

TEST_CASE("PrimeGenerator: Set of prime numbers less 7 value ")
{
	int upperBound = 7;
	set<int> setExpected = { 2, 3, 5, 7 };
	REQUIRE(GeneratePrimeNumbersSet(upperBound) == setExpected);
}
