/*
输入第i个齿轮的type和他套在哪个轴上，再输入哪些对儿齿轮咬合，求这个系统是否可以正常工作

首先读入数据，teeth[i]表示第i个齿轮的型号，rod[i]表示第i个齿轮在哪根轴上
注意这里齿轮的型号表示速度差，比如8号和4号固结，两个轴的速度并不是二倍关系，而是相差4 
disjoint是并查集
然后利用咬合关系不断的更新数据，判断是否jammed

关键词：并查集 
*/
#include<iostream>
#include<cstring>
using namespace std;

int disjoint[100000],v[100000]; 
bool zf[100000];//转的方向

int find(int x)
{
    if(disjoint[x]==x)return x;
    else
    {
        int t=disjoint[x];
        disjoint[x]=find(disjoint[x]);
        v[x]+=v[t];
        zf[x]^=zf[t];
        return disjoint[x];
    }
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int ng,nr,ni;
        cin>>ng>>nr>>ni;

        int teeth[100000],rod[100000];
        for(int i=0;i<ng;i++)
            cin>>teeth[i]>>rod[i];

        memset(v,0,sizeof(v));
        memset(zf,0,sizeof(zf));
        for(int i=0;i<nr;i++)disjoint[i]=i;//i<100000

        bool flag=true;
        for(int i=0;i<ni;i++)
        {
            int aj,bj;
            cin>>aj>>bj;
            if(flag==false)continue;//不直接退出是为了把数据读完，不会导致以后数据读取错误 
            int x,y;
            x=find(rod[aj]);
            y=find(rod[bj]);
            if(x==y)
            {
                if((v[rod[aj]]-v[rod[bj]]!=teeth[aj]-teeth[bj])||(zf[rod[aj]]==zf[rod[bj]]))flag=false;
            }
            else
            {
                v[y]=v[rod[aj]]-v[rod[bj]]-(teeth[aj]-teeth[bj]);
                if(zf[rod[bj]]==zf[rod[aj]])zf[y]=1-zf[rod[aj]];
                disjoint[y]=disjoint[x];
            }
        }
        if(flag==true)cout<<"ok"<<endl;
        else cout<<"jammed"<<endl;
    }
    //while(1);
}
