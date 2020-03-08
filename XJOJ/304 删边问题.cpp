/*
读入一个连通无向图，输出最多删掉多少条边使这个图仍然连通

N个节点的连通图最少有N-1条边
所以直接输出M-(N-1)就行了 

关键词：图论，巧算法，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int N,M;
    while(cin>>N>>M)
    {
        int a,b;
        for(int i=0;i<M;i++)
            cin>>a>>b;
            
        cout<<M-N+1<<endl;
    }
}
