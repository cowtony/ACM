/*
N*N棋盘上摆N个皇后互不攻击的方案数

深度优先搜索
judge()函数判断新摆的棋子是否和前面的矛盾
search()函数是深度优先搜索的，如果深度能到达N，那么方案数加一
column[i]表示第i行皇后的横坐标
main_diagonal[row-i+N]表示第row行第i列的主对角线标记 
vice_diagonal[row+i]表示第row行第i列的副对角线标记 

关键词：递归，DFS，深度优先搜索 
*/
#include<iostream>
using namespace std;

int n,c;
bool column[11];
bool main_diagonal[21];
bool vice_diagonal[21];

void search(int row)
{
    if(row==n){c++;return;}
    for(int i=0;i<n;i++)
        if(column[i]==false && main_diagonal[row-i+n]==false && vice_diagonal[row+i]==false)
        {
            column[i]=main_diagonal[row-i+n]=vice_diagonal[row+i]=true;
            search(row+1);
            column[i]=main_diagonal[row-i+n]=vice_diagonal[row+i]=false;
        }
}

int main()
{
    while(cin>>n && n)
    {
        fill_n(column,sizeof(column),0);
        fill_n(main_diagonal,sizeof(main_diagonal),0);
        fill_n(vice_diagonal,sizeof(vice_diagonal),0);
        c=0;
        
        search(0);
        cout<<c<<endl;
    }
}
