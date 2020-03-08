/*
n个人围成圈握手，两个人握在一起，要求所有的手不能交叉，求有多少种握手组合

首先由于是两人一组，所以奇数个人的话答案肯定是0
假设有n=10个人，那么1号可以有9种选择（2到10号）
每一种选择都把这个圈分成了两半，每边各有一部分人（可以为0，比如1号和2号握手时），设为x人和y人
hand[x]就表示x人时的组合数
所以当1和2握手时，有hand[0]*hand[8]种组合
当1和3握手时，有hand[1]*hand[7]种组合（注意这个值为零）
以此类推，当1和10握手时有hand[8]*hand[0]种组合
全加起来就是hand[10]
利用地推求出所有答案，再直接输出即可
注意用long long

关键词：递推 
*/
#include<iostream>
using namespace std;

int main()
{
    long long hand[51]={0};
    hand[0]=1;
    hand[1]=0;
    
    for(int i=2;i<=50;i++)
        for(int j=0,k=i-2;j<=i-2;j++,k--)
            hand[i]+=hand[j]*hand[k];
    
    int n;
    while(cin>>n)
        cout<<hand[n]<<endl;
}
