#include "../../../repos/catch/catch.hpp"
#include "../HTMLDecode/Decoder.h"

using namespace std;

TEST_CASE("Decoder: Empty string")
{
	string str = "";
	string expectedStr = "";
	HTMLDecode(str);

	REQUIRE(HTMLDecode(str) == expectedStr);
 
}

TEST_CASE("Decoder: Check all map Entity")
{
	string str = " &quot; &apos; &lt; &gt; &amp; ";
	string expectedStr = " \" \' < > & ";
	HTMLDecode(str);

	REQUIRE(HTMLDecode(str) == expectedStr);

}

TEST_CASE("Decoder: Substring code")
{
	string str = " &quo&quot; ";
	string expectedStr = " &quo\" ";
	HTMLDecode(str);

	REQUIRE(HTMLDecode(str) == expectedStr);

}
/*HTMLDecode в многострочный*/
TEST_CASE("Decoder: Line break decode ")
{
	string str = " &quot; \n &lt; ";
	string expectedStr = " \" \n < ";
	HTMLDecode(str);

	REQUIRE(HTMLDecode(str) == expectedStr);
	
}
