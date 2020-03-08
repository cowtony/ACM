/*
ID:cowtony1
PROG:holstein
LANG:C++
有一头牛需要v种维他命，每种需要的量都给出了
现在有g种药，每种药含有的v种维他命的量也给出了，求最少吃哪几种药可以补够牛的维他命

实际上就是枚举所有可能的药组合，找出能补够维他命并且数量最少那种组合
利用DFS实现 

关键词：深度优先搜索，回溯 
*/
#include<iostream>
#include<fstream>
using namespace std;

int v,g;
int present[25]={0};//当前的维他命 
int require[25];//需要的维他命 
int method[25];//记录当前的组合 
int min_method[25];//最小解的组合 
int vitamin[15][25];//存下所有药的信息 
int min_length=100;//记录最小长度 

bool full()
{
    for(int i=0;i<v;i++)
        if(present[i]<require[i])return false;
    return true;
}//判断当前吃过的药是否满足所需 

void dfs(int front,int length)
{
    if(full()==true)//如果满足了所需 
    {
        if(length<min_length)//并且是一个更小的解 
        {
            min_length=length;
            for(int i=0;i<length;i++)
                min_method[i]=method[i];//记下最小的解 
        }
        return;
    }
    //否则 
    for(int i=front+1;i<g;i++)
    {
        method[length]=i;//再去吃一种药 
        for(int j=0;j<v;j++)
            present[j]+=vitamin[i][j];//把吃的维他命加上 
        dfs(i,length+1);//递归搜索 
        for(int j=0;j<v;j++)
            present[j]-=vitamin[i][j];//再把刚才吃的药吐出来 
    }
}

int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    
    cin>>v;
    for(int i=0;i<v;i++)
        cin>>require[i];
    
    cin>>g;
    for(int i=0;i<g;i++)
        for(int j=0;j<v;j++)
            cin>>vitamin[i][j];
            
    dfs(-1,0);
    
    cout<<min_length;
    for(int i=0;i<min_length;i++)
        cout<<' '<<min_method[i]+1;
    cout<<endl;
}
