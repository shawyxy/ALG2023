// #include <iostream>
// #include <vector>
// using namespace std;

// void permute(vector<int>& nums, int start, vector<vector<int>>& result) 
// {
//     if (start == nums.size()) 
//     {
//         result.push_back(nums);
//         return;
//     }
//     for (int i = start; i < nums.size(); i++) 
//     {
//         swap(nums[start], nums[i]);
//         permute(nums, start + 1, result);
//         swap(nums[start], nums[i]);
//     }
// }

// vector<vector<int>> permute(vector<int>& nums) 
// {
//     vector<vector<int>> result;
//     permute(nums, 0, result);
//     return result;
// }
// int main() 
// {
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> result = permute(nums);
//     for (auto& perm : result) 
//     {
//         for (int num : perm) 
//         {
//             cout << num << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
// 递归方程:
// T(N) = N * T(N-1) + O(N)
// T(N) 表示生成 N 个元素的全排列所需的时间
// O(N) 表示将元素放到每个排列的开头所需的时间
// 这个递归方程的解为 T(N) = O(N!)
// 即此算法的时间复杂度为 O(N!)

// -----------------------------------------------------------------

// #include <iostream>
// #include <vector>
// using namespace std;

// void permute(vector<int> &nums, int n, vector<vector<int>> &result) 
// {
//     if (n == 0) 
//     {
//         result.push_back(nums);
//         return;
//     }
//     for (int i = 0; i <= nums.size() - n; i++) 
//     {
//         swap(nums[i], nums[nums.size() - n]);
//         permute(nums, n - 1, result);
//         swap(nums[i], nums[nums.size() - n]);
//     }
// }

// vector<vector<int>> permute(vector<int> &nums) 
// {
//     vector<vector<int>> result;
//     permute(nums, nums.size(), result);
//     return result;
// }

// int main() 
// {
//     vector<int> nums = {1, 2, 3};
//     vector<vector<int>> result = permute(nums);
//     for (auto &v : result) 
//     {
//         for (int x : v) 
//         {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// }
// 在每一层递归中，需要枚举 N 个位置来放置当前元素
// 然后递归生成剩余 N-1 个元素的全排列
// 递归方程：
// T(N) = N * T(N-1) + O(N)
// O(N) 表示交换元素和递归调用所需的常数时间
// 解为T(N) = O(N!)
// 即此算法的时间复杂度为 O(N!)

// -----------------------------------------------------------------

// 在上述算法设计的基础上，编写程序，输入 5 个同学的姓名，输出 5 个同学
// 姓名的全排列。

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
// template<class T>
// void permute(vector<T>& names, int n, vector<vector<T>>& result) 
// {
//     if (n == 0) 
//     {
//         result.push_back(names);
//         return;
//     }
//     for (int i = 0; i <= names.size() - n; i++) 
//     {
//         swap(names[i], names[names.size() - n]);
//         permute(names, n - 1, result);
//         swap(names[i], names[names.size() - n]);
//     }
// }
// template<class T>
// vector<vector<T>> permute(vector<T>& names) 
// {
//     vector<vector<T>> result;
//     permute(names, names.size(), result);
//     return result;
// }

// int main() 
// {
//     vector<string> names(5);
//     int count = 0;
//     for (int i = 0; i < 5; i++) 
//     {
//         cout << "请输入第 " << i + 1 << " 个同学的姓名：";
//         cin >> names[i];
//     }
//     vector<vector<string>> result = permute(names);
//     cout << "这些同学姓名的全排列如下：" << endl;
//     for (auto &v : result) 
//     {
//         for (string name : v) 
//         {
//             cout << name << " ";
//         }
//         count++;
//         cout << endl;
//     }
//     cout << "共" << count << "种排列方式" << endl;
// }
// -----------------------------------------------------------------

// 把 m 颗糖果放在 n 个同样的盘子里，可以用盘子空着不放，请计算共有多少
// 种不同的分法？
// 输入样例：7 3
// 输出样例：8

// #include <iostream>
// using namespace std;

// int countWays(int m, int n) 
// {
//     if (m == 0 || n == 1) 
//         return 1;
//     if (n > m) 
//         return countWays(m, m);
//     return countWays(m, n - 1) + countWays(m - n, n);
// }

// int main() 
// {
//     int m = 0, n = 0;
//     while(cin >> m >> n)
//     {
//         cout << countWays(m, n) << endl;
//     }
//     return 0;
// }
// -----------------------------------------------------------------

// 算术表达式的前置形式提供了一种新颖的计算表达方法，例如：传统算术表
// 达式 6+8，用前置运算符的表达形式为+68，对优先级和括号运算有更好的表达
// 能力。例如表达式(3+4)*5 可表达为：*+345。
// 请设计算法，计算运算符前置表达式的值，运算符包括+、 -、 *、 /。
// 输入样例：
// * + 2 3 4
// 输出样例：
// 20.000000

#include <iostream>
#include <string>
#include <stack>
using namespace std;

double evalPrefix(string& exp) 
{
    stack<double> s;
    for (int i = exp.size() - 1; i >= 0; i--) 
    {
        if (isdigit(exp[i])) 
        {
            s.push(exp[i] - '0');
        } 
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') 
        {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            switch (exp[i]) 
            {
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
            }
        }
    }
    return s.top();
}

int main() 
{
    string str;
    while(getline(cin, str))
    {
        printf("%.6f\n", evalPrefix(str));
    }
    return 0;
}