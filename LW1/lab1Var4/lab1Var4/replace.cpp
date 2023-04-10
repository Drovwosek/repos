#include <iostream>
#include <fstream>
#include <optional>
#include <string>

/*
	
*/

using namespace std;

const string ARGS_ERROR = "Invalid arguments count",
			 ARGS_USAGE = "Usage: replace.exe <input file name> <output file name> <search string> <replace string>",
			 EMPTY_PATTERN_ERROR = "Your search string can't be empty",
			 INPUT_FILE_ERROR = "Input file is failed to open",
			 OUTPUT_FILE_ERROR = "Output file is failed to open",
			 FILE_USAGE = "Usage: <name of your existing file>.txt";

const int ARGC_COUNT = 5,
		  EMPTY_LINE = 0;

struct Args 
{
	string inputFileName;
	string outputFileName;
	string searchString;
	string replaceString;
};

//optional может вернуть Nullable тип; <T, bool>, когда значение функции может быть недоступно
optional<Args> ParseArgs(int argc, char* argv[]) //стандарт языка 20 
//
{
	if (argc != ARGC_COUNT) 
	{
		cout << ARGS_ERROR << endl;
		cout << ARGS_USAGE << endl;
		return nullopt;
	}

	Args args; 
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	args.searchString = argv[3];
	args.replaceString = argv[4];

	return args;
}

string ReplaceInString(string selectedString, string pattern, string replace) 
{
	string src = selectedString;
	string replacedSrc = "";
	size_t entry = 0; 
	
	while(src.find(pattern) != string::npos) 
	{ 
		entry = src.find(pattern);
		replacedSrc += src.substr(0, entry) + replace;
		src = src.erase(0, entry + pattern.size());
		
	}
	replacedSrc += src;

	return replacedSrc;
}

void ReplaceInStream(istream& input, ostream& output, const string& pattern, const string& replace)
{
	string src;

	while (getline(input, src))
	{	
		output << ReplaceInString(src, pattern, replace) ;
		if (!input.eof())
		{
			output << endl;
		}
	} 

}

int main(int argc, char* argv[]) //глобальные переменные. argc - счетчик числа аргументов; argv -  массив указателей на первые символы строк
/*
	Строение строки в си: 0х1, 0х2, ..., \0;
	строка заканчивается нулём(\0 - нулевой символ)
*/

{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 2;
	}

	ifstream input;
	input.open(args->inputFileName);
	
	if (!input.is_open())
	{
		cout << INPUT_FILE_ERROR << endl;
		cout << FILE_USAGE << endl;
		return 1;
	}

	ofstream output;
	output.open(args->outputFileName);

	if (!output.is_open())
	{
		cout << OUTPUT_FILE_ERROR << endl;
		cout << FILE_USAGE << endl;
		return 4;
	}

	string searchStr = args->searchString; 
	string replaceStr = args->replaceString;

	if (searchStr.length() == EMPTY_LINE) 
	{
		cout << EMPTY_PATTERN_ERROR << endl;
		return 3;
	}

	ReplaceInStream(input, output, searchStr, replaceStr); 

	input.close();

	output.flush();
	output.close();
	return 0;
}
