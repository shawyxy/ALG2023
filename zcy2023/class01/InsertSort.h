// [0, i] [i+1, N-1]
// [0, 0] [1, N-1]
// [0, 1] [2, N-1]
// [0, 2] [3, N-1]
// ...
// [0, N-1] [N, N]
void InsertSort(vector<int>& v)
{
    if(v.empty() || v.size() == 1)
        return;
    int size = v.size();
    // i从1开始,因为[0, 0]本身有序
    for(int i = 1; i < v.size(); i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
            else
                break;
        }
    }
}
