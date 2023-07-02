#include <iostream>
#include <vector>
using namespace std;

void fillBoard(vector<vector<int>> &board, int k, int x, int y, int &tile)
{
    int x1 = x, y1 = y;
    if (k == 0) return;
    int cx = x + (1 << (k - 1)) - 1; // 中心位置横坐标
    int cy = y + (1 << (k - 1));     // 中心位置纵坐标
    if (board[x1][y1] == 0 && x1 <= cx && y1 <= cy) // 左边子棋盘的残缺位置在中心位置的左上方
    {
        board[cx][cy] = board[cx + 1][cy] = board[cx][cy - 1] = ++tile; // 放置一个向右下方延伸的 L 形板
    }
    else if (board[x1][y1] == 0 && x1 <= cx && y1 > cy) // 左边子棋盘的残缺位置在中心位置的右上方
    {
        board[cx][cy] = board[cx + 1][cy] = board[cx + 1][cy - 1] = ++tile; // 放置一个向左下方延伸的 L 形板
    }
    else if (board[x1][y1] == 0 && x1 > cx && y1 <= cy) // 左边子棋盘的残缺位置在中心位置的左下方
    {
        board[cx][cy] = board[cx][cy - 1] = board[cx + 1][cy - 1] = ++tile; // 放置一个向右上方延伸的 L 形板
    }
    else // 左边子棋盘的残缺位置在中心位置的右下方
    {
        board[cx][cy] = board[cx + 1][cy] = board[cx][cy - 1] = ++tile; // 放置一个向左上方延伸的 L 形板
    }
    fillBoard(board, k - 1, x, y, tile); // 对左上角的小子棋盘递归调用
    fillBoard(board, k - 1, x, y + (1 << (k - 1)), tile); // 对右上角的小子棋盘递归调用
    fillBoard(board, k - 1, x + (1 << (k - 1)), y, tile); // 对左下角的小子棋盘递归调用
    fillBoard(board, k - 1, x + (1 << (k - 1)), y + (1 << (k - 1)), tile); // 对右下角的小子棋盘递归调用
}

void fillBoard2(vector<vector<int>> &board, int k, int x, int y, int &tile)
{
    int x2 = x, y2 = y;

    if (k == 0) return;
    int cx = x + (1 << (k - 1));     // 中心位置横坐标
    int cy = y + (1 << (k - 1)) - 1; // 中心位置纵坐标
    if (board[x2][y2] == 0 && x2 <= cx && y2 <= cy) // 右边子棋盘的残缺位置在中心位置的左上方
    {
        board[cx][cy] = board[cx - 1][cy] = board[cx][cy + 1] = ++tile; // 放置一个向右下方延伸的 L 形板
    }
    else if (board[x2][y2] == 0 && x2 <= cx && y2 > cy) // 右边子棋盘的残缺位置在中心位置的右上方
    {
        board[cx][cy] = board[cx - 1][cy] = board[cx - 1][cy + 1] = ++tile; // 放置一个向左下方延伸的 L 形板
    }
    else if (board[x2][y2] == 0 && x2 > cx && y2 <= cy) // 右边子棋盘的残缺位置在中心位置的左下方
    {
        board[cx][cy] = board[cx][cy + 1] = board[cx - 1][cy + 1] = ++tile; // 放置一个向右上方延伸的 L 形板
    }
    else // 右边子棋盘的残缺位置在中心位置的右下方
    {
        board[cx][cy] = board[cx - 1][cy] = board[cx][cy + 1] = ++tile; // 放置一个向左上方延伸的 L 形板
    }
    fillBoard2(board, k - 1, x, y, tile); // 对左上角的小子棋盘递归调用
    fillBoard2(board, k - 1, x, y + (1 << (k - 1)), tile); // 对右上角的小子棋盘递归调用
    fillBoard2(board, k - 1, x + (1 << (k - 1)), y, tile); // 对左下角的小子棋盘递归调用
    fillBoard2(board, k - 1, x + (1 << (k - 1)), y + (1 << (k - 1)), tile); // 对右下角的小子棋盘递归调用
}

int main()
{
    int k;
    cin >> k;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n = (1 << k);
    vector<vector<int>> board(n, vector<int>(n * 2));
    board[x1 - 1][y1 - 1] = board[x2 - 1][y2 + n - 1] = 0; // 标记残缺位置为0，注意坐标从0开始，所以要减一
    int tile = 0; // 记录放置的L形板的编号
    fillBoard(board, k, 0, 0, tile); // 填充左边子棋盘
    fillBoard2(board, k, 0, n, tile); // 填充右边子棋盘
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}