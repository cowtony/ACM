/*
读入表明两个人有亲戚关系的数据，然后再判断给的某两个人是否有亲戚关系

基础并查集的题
cin，cout会超时

关键词：并查集 
*/
#include<iostream>
using namespace std;

int main()
{
    int n,m,p,a,b;
    cin>>n>>m>>p;
    
    int vertex[5001];
    for(int i=1;i<=n;i++)
        vertex[i]=i;//初始化并查集 
    
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        if(vertex[a]!=vertex[b])
        {
            int t=vertex[b];
            for(int i=1;i<=n;i++)
                if(vertex[i]==t)vertex[i]=vertex[a];
        }
    }//核心信息建立 
    
    for(int i=0;i<p;i++)
    {
        scanf("%d%d",&a,&b);
        if(vertex[a]==vertex[b])printf("Yes\n");
        else printf("No\n");
    }//查询 
    //while(1);
} 
