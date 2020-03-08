/*
最大非降子序列 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int N,M;
    while(cin>>N>>M)
    {
        cin.ignore();
        int sum=0;
        for(int i=0;i<N;i++)
        {
            string book[50];
            int niu[50];
            int maxn=0;
            for(int j=0;j<M;j++)
            {
                getline(cin,book[j]);
                niu[j]=1;
                
                for(int k=0;k<j;k++)
                    if(book[k]<=book[j])
                        niu[j]=max(niu[j],niu[k]+1);
                
                maxn=max(maxn,niu[j]);
                
                //cout<<book[j]<<' '<<maxn<<endl;
            }
            sum+=M-maxn;
        }
        cout<<sum<<endl;
    }
    //while(1);
}
