/*
ID:cowtony1
PROG:checker
LANG:C++
N<=13皇后问题，输出前三组解，以及总解数

同XJOJ一样的深度优先搜索，但是要做一些优化：位运算
用位运算模拟在棋盘上放子，然后输出前三组解即可

关键词：位运算，深度优先搜索 
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int COUNT=0,N,step[13];
int MAX;

void DFS(int st1,int st2,int st3,int depth)
{
     int st,ii;
     if(depth==N && COUNT++<3)
     {
         cout<<step[0];
         for(int i=1;i<depth;i++)
             cout<<' '<<step[i];
         cout<<endl;
         return;
     }
     st=(st1|st2|st3)&MAX;
     while(st!=MAX)
     {
         ii=(~st)&(st+1)&MAX;
         if(COUNT<3)step[depth]=log2(ii)+1;
         DFS(((st1|ii)<<1),(st2|ii),((st3|ii)>>1),depth+1);
         st=st|ii&MAX;
     }
}

int main()
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    cin>>N;
    MAX=(1<<N)-1;
    DFS(0,0,0,0);
    cout<<COUNT<<endl;
}
