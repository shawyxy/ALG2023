// 在升序序列中找到<=num的最左边的数
int BSNearLeft(vector<int>& v, int num)
{
    if(v.empty() || v.size() == 1)
        return -1;
    int L = 0, R = v.size() - 1;
    int index = -1; // 保存有效mid的下标
    int mid = 0;
    while(L <= R)
    {
        mid = L + ((R - L) >> 1);
        if(v[mid] >= num)
        {
            R = mid - 1;
            index = mid;
        }
        else
        {
            L = mid + 1;
        }
    }
    //cout << "LeftIndex:" << index << ":" << v[index] << endl;
    return index;
}
