/*
输入K个质数，输出仅由这些质数相乘的第N大的数

我们在数组humble中计算出前n个丑数。为了实现起来更简单，我们把1也作为一个丑数，即humble[0]=1; 
当我们已知前k个丑数时，想得到第k+1个，我们可以这样做：
对于每个质数p寻找最小的丑数h使得h*p比上一个丑数大 
取我们找到的h*p中最小的一个：它就是下一个丑数为了使搜索更快，我们可以为每个质数维护一个指针point[p]表示每个质数已经乘到了哪个丑数，每次都从那里开始，而不是再从头再来。

关键词：数论，有思想 
*/
#include<iostream>
using namespace std;

int main()
{
    int K,N;
    cin>>K>>N;
    
    int prime[100];
    for(int i=0;i<K;i++)
        cin>>prime[i];
        
    
    int humble[100001]={1};
    int point[100]={0};
    
    for(int i=1;i<=N;i++)
    {
        int least=2100000000;
        for(int p=0;p<K;p++)
            least=min(least,prime[p]*humble[point[p]]);
        humble[i]=least;
        
        for(int p=0;p<K;p++)
            if(humble[i]==prime[p]*humble[point[p]])point[p]++;
    }
    
    cout<<humble[N]<<endl;
}
