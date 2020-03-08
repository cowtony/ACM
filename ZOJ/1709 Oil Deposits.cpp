/*
输入一个矩形，上面的点如果是'@'代表有油，'*'代表没油
求该矩形油田有多少块油区。斜着连接也算相邻

写一个递归check函数，表示从有油的某一点向外扩散，直到把该块连通区域全部置为'*'
然后在主函数里遍历所有点即可，每运行一次check函数就相当于找到一块连续油区

关键词：递归，搜索 
*/
#include<iostream> 
using namespace std;

int m,n;
char grid[100][100];
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};//从左边格子顺时针转一圈的八个坐标 

void check(int x,int y) 
{
    grid[x][y]='*';
    for(int i=0;i<8;i++) 
    { 
        int s=x+dir[i][0];
        int t=y+dir[i][1];
        if(s<0||t<0||s>=m||t>=n)
            continue;
        if(grid[s][t]=='@')
        check(s,t);
    } 
}

int main() 
{ 
    while(cin>>m>>n) 
    {
        if(m==0 && n==0)break;
        
        int count=0;
        for(int i=0;i<m;i++) 
            for(int j=0;j<n;j++) 
                cin>>grid[i][j];
                
        for(int i=0;i<m;i++) 
            for(int j=0;j<n;j++) 
            {
                if(grid[i][j]=='@')
                { 
                    check(i,j);
                    count++;
                } 
            } 
        cout<<count<<endl;
    } 
}
