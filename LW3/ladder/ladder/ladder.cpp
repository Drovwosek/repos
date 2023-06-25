#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int N;

int t, n;

struct Runner
{
    int n;
    int t;
    int steps;
};

struct Result
{
    int n;
    int t;
};

fstream input("INPUT.TXT");
fstream output("OUTPUT.TXT");

vector<Runner> runners;

vector<Result> result;

void GetRunners()
{
    for (int i = 0; i < N; i++)
    {
        int t, steps;
        input >> t;
        input >> steps;
        runners.push_back({ i, t, steps });
    }
    
};

void SortRunners()
{
    sort(runners.begin(), runners.end(), [](auto p1, auto p2) {return p1.steps < p2.steps; });
    
}

void SortResult()
{
    sort(result.begin(), result.end(), [](auto r1, auto r2) {return r1.n < r2.n; });
    
}

int main()
{
    
    input >> N;

    GetRunners();
    SortRunners();

    for (int i = 0; i < N; i++)
    {
        const auto& currentP = runners[i];
        int resultTime = runners[i].n * runners[i].t;

        if (i > 0 && resultTime < result[i - 1].t)
        {
            resultTime = result[i - 1].t;
        }
        result.push_back({ runners[i].n, resultTime });
    }

    SortResult();

    for (auto r : result)
    {
        output << r.t << endl;
    }

    return 0;
}
