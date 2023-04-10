#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <algorithm>
#include <limits>

using namespace std;

const string OWERFLOW_ERROR = "Overflow error\n";
const string USAGE_VALUE_OWERFLOW = "<value> is too big\n";
const string INVALID_CHAR_CONVERTATION = "Invalid num to char convertation\n";
const string USAGE_NUM_CONVERTATION = "num must be from 0 to ";
const string INVALID_AGRS_COUNT = "Invalid arguments count\n";
const string INVALID_CH_TO_NUM_CONVERTATION = "Invalid char to num convertation\n";
const string USAGE_CH_TO_NUM_CONVERTATION = "char must be from 0 to 9 and from A to ";
const string USAGE_AGRS_COUNT = "Usage radix.exe <source notation> <destiantion notation> <value>\n";
const string INVALID_ARGUMENT = "Invalid argument\n";
const string USAGE_SOURCE_NOTATION = "<source notation> must be from 2 to 36\n";
const string USAGE_DESTINATION_NOTATION = "<destiantion notation> must be from 2 to 36\n";
const string USAGE_VALUE = "<value> must contain only digits that are in the <source notation> range\n";

const int MIN_RADIX = 2;
const int MAX_RADIX = 36;
const char MAX_RADIX_MAX_DIGIT = 'Z';
const int MAX_RADIX_MAX_DIGIT_NUM = 35;

struct Args
{
	int sourceNotation;
	int destinationNotation;
	string value;
};

optional<Args> ParseArgs(int argc, char* argv[]);
string ConvertFromSourceNotationToDestinationNotation(int sourceNotation, int destinationNotation, const string& value, bool& wasError);

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return 1;
	}

	bool wasError = false;

	string resultVal = ConvertFromSourceNotationToDestinationNotation(args->sourceNotation, args->destinationNotation, args->value, wasError);

	if (wasError)
	{
		return 1;
	}

	cout << resultVal;

	return 0;
}

bool IsSrcNotationChar(int srcNotation, char ch)  // только символы 0-9 и А-Z
{ //toUpperCase
	return (ch >= '0' && ch < ('0' + srcNotation)) ||
		(ch >= 'A' && ch < ('A' + srcNotation - 10));
}

bool IsValueInSrcNototation(int srcNot, const string& value)
{
	if (value.empty())
	{
		return false;
	}

	int start = 0;
	if (value[0] == '-')
	{
		if (value.length() == 1)
		{
			return false;
		}

		start = 1;
	}

	for (int i = start; i < value.length(); i++)
	{
		if (!IsSrcNotationChar(srcNot, value[i]))
		{
			return false;
		}
	}

	return true;
}

bool IsValidValueInput(const string& value, int srcNotation)
{
	if (srcNotation < MIN_RADIX || srcNotation > MAX_RADIX || value.empty())
	{
		return false;
	}

	return IsValueInSrcNototation(srcNotation, value);
}

bool IsAddingWouldCauseOverflow(int result, int adding)
{
	if (adding > 0 && result > numeric_limits<int>::max() - adding)
	{
		return true;
	}

	if (adding < 0 && result < numeric_limits<int>::min() - adding)
	{
		return true;
	}

	return false;
}

int CharToNum(char ch, bool& wasError)
{
	if (ch >= '0' && ch <= '9')
	{
		return (int)(ch - '0');
	}
	else if (ch >= 'A' && ch <= MAX_RADIX_MAX_DIGIT)
	{
		return (int)(ch + 10 - 'A');
	}
	else
	{
		cout << INVALID_CH_TO_NUM_CONVERTATION; //"Invalid char to num convertation\n"
		cout << USAGE_CH_TO_NUM_CONVERTATION << MAX_RADIX_MAX_DIGIT << "\n"; //"char must be from 0 to 9 and from A to "
		wasError = true;
		return 1;
	}
}

int StringToInt(const string& str, int radix, bool& wasError)
{
	int resultInt = 0;
	int exp = 0;

	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] == '-')
		{
			resultInt *= -1;
		}
		else
		{
			int num = CharToNum(str[i], wasError) * (int)pow(radix, exp++);

			if (IsAddingWouldCauseOverflow(resultInt, num))
			{
				cout << OWERFLOW_ERROR;//"Overflow error\n"
				cout << USAGE_VALUE_OWERFLOW; // "<value> is too big\n"
				wasError = true;
				return 1;
			}

			resultInt += num;
		}
	}

	return resultInt;
}

char NumToChar(int num, bool& wasError)
{
	if (num >= 0 && num <= 9)
	{
		return (char)(num + '0');
	}

	if (num <= MAX_RADIX_MAX_DIGIT_NUM)
	{
		return (char)(num - 10 + 'A');
	}

	cout << INVALID_CHAR_CONVERTATION; //"Invalid num to char convertation\n"
	cout << USAGE_NUM_CONVERTATION << MAX_RADIX_MAX_DIGIT_NUM << "\n"; //"num must be from 0 to "
	wasError = true;
	return '\0';
}

string IntToString(int inputNum, int radix, bool& wasError)
{
	string resultStr = "";
	bool isNegative = inputNum < 0;
	inputNum = abs(inputNum);

	if (inputNum == 0)
	{
		return "0";
	}

	while (inputNum > 0)
	{
		resultStr += NumToChar(inputNum % radix, wasError);
		inputNum /= radix;
	}

	if (isNegative)
	{
		resultStr += '-';
	}

	reverse(resultStr.begin(), resultStr.end());

	return resultStr + "\n";
}

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << INVALID_AGRS_COUNT; //"Invalid arguments count\n"
		std::cout << USAGE_AGRS_COUNT; //"Usage radix.exe <source notation> <destiantion notation> <value>\n"
		return nullopt;
	}

	Args args;
	bool wasError = false;

	args.sourceNotation = StringToInt(argv[1], 10, wasError);
	if (args.sourceNotation < MIN_RADIX || args.sourceNotation > MAX_RADIX || wasError)
	{
		cout << INVALID_ARGUMENT; //"Invalid argument\n" 
		cout << USAGE_SOURCE_NOTATION; //"<source notation> must be from 2 to 36\n"
		return nullopt;
	}

	args.destinationNotation = StringToInt(argv[2], 10, wasError);
	if (args.destinationNotation < MIN_RADIX || args.destinationNotation > MAX_RADIX || wasError)
	{
		cout << INVALID_ARGUMENT;
		cout << USAGE_DESTINATION_NOTATION;
		return nullopt;
	}

	args.value = argv[3];
	if (!IsValidValueInput(args.value, args.sourceNotation))
	{
		cout << INVALID_ARGUMENT;
		cout << USAGE_VALUE;
		return nullopt;
	}

	return args;
}

string ConvertFromSourceNotationToDestinationNotation(int sourceNotation, int destinationNotation, const string& value, bool& wasError)
{
	int num = StringToInt(value, sourceNotation, wasError);
	string result = IntToString(num, destinationNotation, wasError);

	return result;
}
