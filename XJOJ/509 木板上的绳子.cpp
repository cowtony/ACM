/*
木板上整数点有穿孔，上面每个m号和2m号相连一条绳，下面n和3n+1相连
求N与N+1之间有多少跳绳

在图上画一下，分奇偶考虑，一加就可以了

关键词：模拟，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        
        int even=N-N/2;
        int odd=(N+1)/2-(N+2)/6;
        cout<<even+odd<<endl;
    }
    
    
    //while(1);
}
