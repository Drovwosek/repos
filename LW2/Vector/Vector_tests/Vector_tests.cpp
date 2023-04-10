#include "../../../repos/catch/catch.hpp"
#include "../Vector/VectorProcessor.h"

using namespace std;

TEST_CASE("ProcessVector: Vector with no numbers")
{
	vector<float> vec = {};
	vector<float> vecExpected = {};
	ProcessVector(vec);
	SortVector(vec);
	CHECK_THAT(vec, Catch::Approx(vecExpected).epsilon(1.e-3f)); // vec примерно совпадает c vecExpected с погрешностью 1.e-3f
}

TEST_CASE("ProcessVector: Vector with negative numbers")
{
	vector<float> vec = { 6.0, 2.0, 8.0, -1.0 };
	vector<float> vecExpected = { -8.0, -6.0, -2.0, 1.0 };
	ProcessVector(vec);
	SortVector(vec);
	CHECK_THAT(vec, Catch::Approx(vecExpected).epsilon(1.e-3f)); 
}

TEST_CASE("ProcessVector: Vector with same numbers")
{
	vector<float> vec = {2.0, 2.0, 2.0, 2.0, 2.0};
	vector<float> vecExpected = {4.0, 4.0, 4.0, 4.0, 4.0};
	ProcessVector(vec);
	SortVector(vec);
	CHECK_THAT(vec, Catch::Approx(vecExpected).epsilon(1.e-3f)); 
}

TEST_CASE("ProcessVector: Vector with zeroes")
{
	vector<float> vec = {0, 0, 0, 0};
	vector<float> vecExpected = {0.0, 0.0, 0.0, 0.0};
	ProcessVector(vec);
	SortVector(vec);
	CHECK_THAT(vec, Catch::Approx(vecExpected).epsilon(1.e-3f)); 
}

TEST_CASE("ProcessVector: Diminishing vector")
{
	vector<float> vec = { 6.0, 2.0, 8.0, 1.0 };
	vector<float> vecExpected = { 1.0, 2.0, 6.0, 8.0 };
	ProcessVector(vec);
	SortVector(vec);
	CHECK_THAT(vec, Catch::Approx(vecExpected).epsilon(1.e-3f));
}

TEST_CASE("ProcessVector: Rounding vector elements")
{
	vector<float> vec = { 2.12345, 4.12345, 5.12345, 8.54321 };
	vector<float> vecExpected = { 4.509, 8.756, 10.879, 18.141 };
	ProcessVector(vec);
	SortVector(vec);
	CHECK_THAT(vec, Catch::Approx(vecExpected).epsilon(1.e-3f));
}
