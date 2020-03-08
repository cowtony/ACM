/*
一共有N张牌，两个人轮流取牌，每次可以取1-M张，假设两人都足够聪明，问先取的人能否取胜 

倒推去想，当N小于等于M时，先取的人肯定能赢
若N=M+1，则先取的人不管取多少另一个人都能取胜，所以lose
若M+1<N<=2M+1，只要先取的人取到剩余M+1张，则他必能赢
同理，在数轴上只有N=k(M+1)时先取的人会输，否则都有必胜的策略

关键词：巧算法 
*/
#include<iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        
        if(n%(m+1)==0)cout<<"lose"<<endl;
        else cout<<"win"<<endl;
    }
}
