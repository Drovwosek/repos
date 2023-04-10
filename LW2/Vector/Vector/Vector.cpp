#include <iostream>
#include <fstream>
#include <vector>
#include "VectorProcessor.h"

/*
    ++сообщения на пустой массив не выводить
    ++считывание istream_iterator
    ++для печати использовать copy, а не for_each
*/

using namespace std;

const string EMPTY_DATA = "Empty data entered";

void PrintVector(vector<float> const& vec)
{
    copy(vec.begin(), vec.end(), ostream_iterator <float>(cout, " "));
};

int main()
{
    vector<float> vec;

   if (!ParseVector(std::cin, vec))
    {
       cout << EMPTY_DATA << endl;
        return 1;
    }

    ProcessVector(vec);

    PrintVector(vec);

    return 0;
}
