#include <iostream>
#include <string>
#include <map>
#include "Decoder.h"

using namespace std;

int main()
{
    string str;

    while (getline(cin, str))
    {
        cout << HTMLDecode(str) << endl;
    }
}
