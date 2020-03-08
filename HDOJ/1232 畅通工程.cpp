/*
基础的并查集 
*/
#include<iostream>
using namespace std;

int joint[1000];

int find(int a)
{
    if(joint[a]==a)return a;
    else return joint[a]=find(joint[a]);
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    int N,M;
    while(cin>>N && N!=0)
    {
        cin>>M;
        for(int i=1;i<1000;i++)
            joint[i]=i;
        
        int ans=N-1;
        for(int i=0;i<M;i++)
        {
            int x,y;
            cin>>x>>y;
            int f1=find(x);
            int f2=find(y);
            if(f1!=f2)
            {
                ans--;
                joint[f2]=f1;
            }
        }
        cout<<ans<<endl;
    }
    //while(1);
}
