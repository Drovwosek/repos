#include <iostream>
#include <math.h>
#include <algorithm>
#include <iterator>
#include "VectorProcessor.h"

using namespace std;

bool ParseVector(istream& input, vector<float>& vec)
{
    float num;

    istream_iterator<double> eos;//ссылается на элемент после конечного
    istream_iterator<double> iit(cin);

    while (iit != eos) 
    { //перебираем до равенства
        
        iit++;
    }

    if (vec.size() == 0)
    {
        return false;
    }

    return true;
};
    
void SortVector(vector<float>& vec)
{
    sort(vec.begin(), vec.end());
}

vector<float> ProcessVector(vector<float>& vec)
{
    auto minElement = min_element(vec.begin(), vec.end());
    if (minElement == vec.end())
    {
        return vec;
    }

    float min = *minElement;

    auto MultiplyOnMinElement = [min](float& num) 
    {
        return num = round(num * min * 1000) / 1000; 
    };

    transform(vec.begin(), vec.end(), vec.begin(), MultiplyOnMinElement);

    return vec;
};
