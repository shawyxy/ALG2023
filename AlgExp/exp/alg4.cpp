#include <iostream>
#include <math.h>
using namespace std;

int amount = 0,Board[100][100];
string input = "next";
int k = 0, dr = 0, dc = 0;
void Cover(int tr,int tc,int dr,int dc,int size) 
{
    int s,t;
    if(size<2) return;
    amount++;
    t=amount;
    s=size/2;
    if(dr<tr+s&&dc<tc+s)// 残缺在左上角
    {
        // 覆盖中间位置
        Board[tr+s-1][tc+s]=t;
        Board[tr+s][tc+s-1]=t;
        Board[tr+s][tc+s]=t;
        Cover(tr,tc,dr,dc,s);// 覆盖左上
        Cover(tr,tc+s,tr+s-1,tc+s,s);// 覆盖右上
        Cover(tr+s,tc,tr+s,tc+s-1,s);// 覆盖左下
        Cover(tr+s,tc+s,tr+s,tc+s,s);// 覆盖右下
    }
    else if(dr<tr+s&&dc>=tc+s)// 残缺在右上角
    {
        Board[tr+s-1][tc+s-1]=t;
        Board[tr+s][tc+s-1]=t;
        Board[tr+s][tc+s]=t;
        Cover(tr,tc,tr+s-1,tc+s-1,s);
        Cover(tr,tc+s,dr,dc,s);
        Cover(tr+s,tc,tr+s,tc+s-1,s);
        Cover(tr+s,tc+s,tr+s,tc+s,s);
    }
    else if(dr>=tr+s&&dc<tc+s)// 残缺在左下角
    {
        Board[tr+s-1][tc+s-1]=t;
        Board[tr+s-1][tc+s]=t;
        Board[tr+s][tc+s]=t;
        Cover(tr,tc,tr+s-1,tc+s-1,s);
        Cover(tr,tc+s,tr+s-1,tc+s,s);
        Cover(tr+s,tc,dr,dc,s);
        Cover(tr+s,tc+s,tr+s,tc+s,s);
    }
    else// 残缺在右下角
    {
        Board[tr+s-1][tc+s-1]=t;
        Board[tr+s-1][tc+s]=t;
        Board[tr+s][tc+s-1]=t;
        Cover(tr,tc,tr+s-1,tc+s-1,s);
        Cover(tr,tc+s,tr+s-1,tc+s,s);
        Cover(tr+s,tc,tr+s,tc+s-1,s);
        Cover(tr+s,tc+s,dr,dc,s);  
    }
}
void resetBoard(int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            Board[i][j] = 0;

    amount = 0;
}
void BoardTest()
{
    cout << "请输入残缺棋盘的规模:2^k,k=";
    cin >> k;
    cout << "输入棋盘残缺的位置(x,y):";
    cin >> dr >> dc;
    int size = pow(2, k);
    Cover(0, 0, dr - 1, dc - 1, size);
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            printf("%5d", Board[i][j]);
        }
        cout << endl;
    }
    resetBoard(size);
}
int main()
{
    while(1)
    {
        if(input == "quit") break;
        if(input == "next") BoardTest();
        cout << "输入\"quit\"退出, 输入\"next\"继续:";
        cin >> input;
        cout << "--------------------------" << endl;
    }
    
    return 0;
}
