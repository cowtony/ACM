/*
ID:cowtony1
PROG:milk
LANG:C++

要买N加仑牛奶，有M个农民，每人都有一个单价和一定量的牛奶，问最少花多少钱可以买N加仑牛奶

可以直接按价钱排序，然后贪心
这道题价钱的范围是一千，所以可以用个数组price[i]表示单价为i的奶可以买多少
注意有可能两个农民的价钱一样，所以读入的时候不能写price[p]=a,要写price[p]+=a; 

关键词：贪心，简单题 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    
    int N,M;
    cin>>N>>M;
    int P,A;
    int price[1001]={0};
    for(int i=0;i<M;i++)
    {
        cin>>P>>A;
        price[P]+=A;
    }
    
    int total=0,money=0;
    for(int i=0;i<1001;i++)
        if(total+price[i]<=N)
        {
            total+=price[i];
            money+=i*price[i];
        }
        else
        {
            money+=i*(N-total);
            break;
        }
    cout<<money<<endl;
}
