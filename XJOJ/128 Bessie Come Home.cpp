/*
有a-z,A-Z这52个节点，输入一个图，注意两点间有可能含有多条边，也会有自己到自己的路径
然后输出大写字母节点到Z节点最近的一个以及长度

输入的时候要注意，因为节点较少，所以可以用floyd算法求最短路

关键词：图论，最短路径
*/
#include<iostream>
using namespace std;

const int MAX=1000000000;

int f(char c)
{
    if(c>='a' && c<='z')return c-'a';
    else return c-'A'+26;
}

int main()
{
    int P;
    cin>>P;
    
    int map[52][52];
    for(int i=0;i<52;i++)
        for(int j=0;j<52;j++)
        {
            map[i][j]=MAX;
            if(i==j)map[i][j]=0;
        }
    bool used[52]={false};
    
    for(int i=0;i<P;i++)
    {
        char a,b;
        int distance;
        cin>>a>>b>>distance;
        used[f(a)]=true;
        used[f(b)]=true;
        map[f(a)][f(b)]=min(map[f(a)][f(b)],distance);
        map[f(b)][f(a)]=min(map[f(b)][f(a)],distance);
    }
    
    for(int k=0;k<52;k++)
        for(int i=0;i<52;i++)
            for(int j=0;j<52;j++)
                if(map[i][j]>map[i][k]+map[k][j])
                   map[i][j]=map[i][k]+map[k][j];

    int shortest=MAX;
    char No;
    for(int i=26;i<51;i++)//注意不能把'Z'加进去，不然最短路径肯定是Z 0 
        if(map[i][f('Z')]<shortest)
        {
            shortest=map[i][f('Z')];
            No=i-26+'A';
        }
    cout<<No<<' '<<shortest<<endl;
}
