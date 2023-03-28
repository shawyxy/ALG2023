// 选择排序
// Pos <- FindMin
//  0  <- [1, N-1]
//   1  <- [2, N-1]
//    2  <- [3, N-1]
//      ...
//          N-1 <- [N, N]

void SelectSort(vector<int>& v)
{
    if(v.empty() || v.size() == 1) return;

    int size = v.size() - 1;
    for(int i = 0; i < size; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j <= size; j++) // 在 [i+1, N-1]上找最小值的Index
        {
            if(v[minIndex] > v[j])
            {
                minIndex = j;
            }
        }
        swap(v[minIndex], v[i]); // 将最小值放在i位置
    }
}