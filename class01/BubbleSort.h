// 冒泡排序

void BubbleSort(vector<int>& v)
{
    if(v.empty() || v.size() == 1)
        return;
    int size = v.size() - 1;
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j <= size; j++)
        {
            if(v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }
}
