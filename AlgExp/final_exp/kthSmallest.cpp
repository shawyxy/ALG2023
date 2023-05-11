// #include <iostream>
// #include <vector>
// using namespace std;

// int partition(vector<int> &nums, int left, int right)
// {
//     int pivot = nums[right];
//     int i = left;
//     for (int j = left; j < right; j++)
//     {
//         if (nums[j] <= pivot)
//         {
//             swap(nums[i], nums[j]);
//             i++;
//         }
//     }
//     swap(nums[i], nums[right]);
//     return i;
// }

// int quickSelect(vector<int> &nums, int left, int right, int k)
// {
//     if (left == right)
//         return nums[left];
//     int pIndex = partition(nums, left, right);
//     if (k == pIndex)
//         return nums[k];
//     else if (k < pIndex)
//         return quickSelect(nums, left, pIndex - 1, k);
//     else
//         return quickSelect(nums, pIndex + 1, right, k);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for (int i = 0; i < n; i++)
//         cin >> nums[i];
//     int k;
//     cin >> k;
//     cout << quickSelect(nums, 0, n - 1, k - 1) << endl;
//     return 0;
// }
// 优化版本
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int medianOfMedians(vector<int> &nums, int left, int right)
{
    if (right - left + 1 <= 5)
    {
        sort(nums.begin() + left, nums.begin() + right + 1);
        return (left + right) / 2;
    }
    for (int i = left; i <= right; i += 5)
    {
        int subRight = min(i + 4, right);
        sort(nums.begin() + i, nums.begin() + subRight + 1);
        swap(nums[left + (i - left) / 5], nums[(i + subRight) / 2]);
    }
    return medianOfMedians(nums, left, left + (right - left) / 5);
}

int partition(vector<int> &nums, int left, int right)
{
    int pivotIndex = medianOfMedians(nums, left, right);
    swap(nums[pivotIndex], nums[right]);
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; j++)
    {
        if (nums[j] <= pivot)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

void insertionSort(vector<int> &nums, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = nums[i];
        int j = i - 1;
        while (j >= left && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

int quickSelect(vector<int> &nums, int left, int right, int k)
{
    while (left < right)
    {
        if (right - left + 1 <= 10)
        {
            insertionSort(nums, left, right);
            return nums[k];
        }
        int pIndex = partition(nums, left, right);
        if (k == pIndex)
            return nums[k];
        else if (k < pIndex)
            right = pIndex - 1;
        else
            left = pIndex + 1;
    }
    return nums[left];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    cout << quickSelect(nums, 0, n - 1, k - 1) << endl;
    return 0;
}