// #include <iostream>
// #include <algorithm>
// #include <cstdlib>
// using namespace std;

// int partition(int arr[], int p, int r) 
// {
//     int x = arr[r];
//     int i = p - 1;
//     for (int j = p; j <= r - 1; j++) 
//     {
//         if (arr[j] <= x) 
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[r]);
//     return i + 1;
// }

// int randomizedPartition(int arr[], int p, int r) 
// {
//     int i = rand() % (r - p + 1) + p;
//     swap(arr[r], arr[i]);
//     return partition(arr, p, r);
// }

// void randomizedQuickSort(int arr[], int p, int r) 
// {
//     if (p < r) 
//     {
//         int q = randomizedPartition(arr, p, r);
//         randomizedQuickSort(arr, p, q - 1);
//         randomizedQuickSort(arr, q + 1, r);
//     }
// }
// void Print(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//         printf("%3d", arr[i]);
//     cout << endl;
// }
// #define SIZE 15
// #define TIMES 5
// int main() 
// {
//     srand(time(nullptr));
//     for (int i = 0; i < TIMES; i++) 
//     {
//         int arr[SIZE];
//         for (int j = 0; j < SIZE; j++) 
//         {
//             arr[j] = rand() % 201 - 100;
//         }
//         Print(arr, SIZE);
//         randomizedQuickSort(arr, 0, SIZE - 1);
//         Print(arr, SIZE);
//     }
//     return 0;
// } 

#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r) 
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[q + j + 1];
    }
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) 
    {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
    }
}

void mergeSort(int arr[], int p, int r) 
{
    if (p < r) 
    {
        int q = (p + r) >> 1;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
void Print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);
    cout << endl;
}
#define SIZE 15
#define TIMES 5
int main() 
{
    srand(time(nullptr));
    for (int i = 0; i < TIMES; i++) 
    {
        int arr[SIZE];
        for (int j = 0; j < SIZE; j++) 
        {
            arr[j] = rand() % 201 - 100;
        }
        Print(arr, SIZE);
        mergeSort(arr, 0, SIZE - 1);
        Print(arr, SIZE);
    }
    return 0;
} 