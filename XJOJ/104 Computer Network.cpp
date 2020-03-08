/*
机房最开始只有一台电脑，每新增一台电脑就用网线和以前某一台相连，并且得知网线长度。现在求出对于每台电脑，离他网线距离最远的电脑长度

按题目的意思正好建立了一棵树，每一个节点存有他到父亲的网线长度，他父亲的编号，儿子们的编号
另外定义first为该节点子树上离他最远的距离
定义second为该节点子树上离他第二远的距离
定义third为该节点父亲方向上离他最远的距离
由于我们读入数据是从父到子，所以只要从后向前遍历一遍即可依次求出first和second
求third的方法： 
1、如果first[i]+d[i]=first[p[i]](其中p[i]表示i的父亲节点编号，d[i]表示由此节点到父亲节点的距离）
就表明从父亲节点的子树中到父亲节点的最长距离在以i为根的子树中，显然这个值不能用于求third,这也是要一个second的原因，
如果是这种情况，third [i]=max(second[p[i]]+d[i],third[p[i]]+d[i])。
2、如果first[i]+d[i]!=first[p[i]],这说明从父亲节点的子树中到父亲节点的最长距离的点不再以i为根的子树中，
这样third[i]=max(first[p[i]]+d[i],third[p[i]]+d[i])。
最后要求的最长距离就是f[i]=max(first[i],third[i])

关键词：有思想，动态规划，树，好题 
*/
#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;

struct Tree
{
    int length;
    int father;
    vector<int> son;
    int first;
    int second;
    int third;
    Tree():length(0),father(0),first(0),second(0),third(0){}
};

int main()
{
    //freopen("aaa.txt","r",stdin);
    int N;
    scanf("%d",&N);
    
    Tree computer[10000];
    for(int i=1;i<N;i++)
    {
        scanf("%d %d",&computer[i].father,&computer[i].length);
        computer[i].father--;
        computer[computer[i].father].son.push_back(i);
    }
    
    for(int i=N-1;i>=0;i--)
    {
        priority_queue<int> pq;
        for(vector<int>::iterator it=computer[i].son.begin();it!=computer[i].son.end();it++)
            pq.push(computer[*it].first+computer[*it].length);
        computer[i].first=pq.empty()?0:pq.top();
        if(pq.empty()==false)pq.pop();
        computer[i].second=pq.empty()?0:pq.top();
    }
    
    for(int i=1;i<N;i++)
    {
        if(computer[i].first+computer[i].length==computer[computer[i].father].first)
            computer[i].third=max(computer[computer[i].father].second+computer[i].length,computer[computer[i].father].third+computer[i].length);
        else computer[i].third=max(computer[computer[i].father].first+computer[i].length,computer[computer[i].father].third+computer[i].length);
    }
    
    for(int i=0;i<N;i++)
        printf("%d\n",max(computer[i].first,computer[i].third));
        
    //while(1);
}
