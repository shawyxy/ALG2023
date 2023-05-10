// #include <iostream>
// #include <vector>
// using namespace std;

// int max_value = 0;         // 最大价值
// vector<int> best_solution; // 最优解
// int n, W; // 物品个数 背包容量

// void backtrack(int i, int current_weight, int current_value, vector<int> &solution, const vector<int> &weights, const vector<int> &values, int W)
// {
//     if (i == weights.size())
//     { // 到达叶子节点
//         if (current_value > max_value)
//         { // 更新最大价值和最优解
//             max_value = current_value;
//             best_solution = solution;
//         }
//         return;
//     }
//     // 不选第i个物品
//     solution[i] = 0;
//     backtrack(i + 1, current_weight, current_value, solution, weights, values, W);
//     // 选第i个物品
//     if (current_weight + weights[i] <= W)
//     { // 满足重量限制
//         solution[i] = 1;
//         backtrack(i + 1, current_weight + weights[i], current_value + values[i], solution, weights, values, W);
//     }
// }

// int main()
// {
//     vector<int> weights;  // 物品重量
//     vector<int> values;   // 物品价值
//     cin >> n >> W;
//     for (int i = 0; i < n; i++)
//     {
//         int w, v;
//         cin >> w >> v;
//         weights.push_back(w);
//         values.push_back(v);
//     }
//     vector<int> solution(weights.size(), 0); // 当前解
//     backtrack(0, 0, 0, solution, weights, values, W);
//     cout << "最大价值: " << max_value << endl;
//     cout << "最优解: ";
//     for (int i = 0; i < best_solution.size(); i++)
//     {
//         cout << best_solution[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int n, W;
vector<int> w;
vector<int> x;
int bestW = 0;
vector<int> bestX;

void backtrack(int i, int cw)
{
    if (i == n)
    {
        if (cw > bestW)
        {
            bestW = cw;
            bestX = x;
        }
        return;
    }
    if (cw + w[i] <= W)
    {
        x[i] = 1;
        backtrack(i + 1, cw + w[i]);
    }
    
    x[i] = 0;
    backtrack(i + 1, cw);
}
int main()
{
    cin >> n >> W;
    w.resize(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    x.resize(n);
    backtrack(0, 0);
    cout << "最大价值: " << bestW << endl;
    cout << "最优解: ";
    for (int i = 0; i < n; i++)
        cout << bestX[i] << " ";
    cout << endl;

    return 0;
}