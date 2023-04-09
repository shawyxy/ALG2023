#include "forTest.h"
#include "SelectSort.h"
#include "BubbleSort.h"
#include "InsertSort.h"
#include "BSNearLeft.h"
int main()
{
    for(int i = 0; i < 20; i++)
    {
        vector<int> v;
        randomMachine(v);
        SelectSort(v);
        //BubbleSort(v);
        //InsertSort(v);
        for(auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
        //BSNearLeft(v, 2);
    }
    return 0;
}
