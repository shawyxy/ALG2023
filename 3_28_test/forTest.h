#include <iostream>

#include <random>
using namespace std;

// for test
void randomMachine(vector<int>& v)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-100, 100);

    v.resize(10);
    for(int i = 0; i < 10; i++)
    {
        v[i] = (dis(gen));
    }
    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}
