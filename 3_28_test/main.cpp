#include "forTest.h"
#include "SelectSort.h"
#include "BubbleSort.h"
#include "InsertSort.h"
int main()
{
    for(int i = 0; i < 10; i++)
    {
        vector<int> v;
        randomMachine(v);
        //SelectSort(v);
        //BubbleSort(v);
        InsertSort(v);
        for(auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
