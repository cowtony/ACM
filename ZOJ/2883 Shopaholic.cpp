/*
输入许多东西的价格，现在买超过三件可以免最便宜一件的钱，求最多可以省多少钱

把所有价钱从大到小排，三件三件的买
这样省的是第3,6,9...件，最划算

关键词：简单题，贪心 
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int money[20000];
        for(int i=0;i<n;i++)
            cin>>money[i];
        
        sort(money,money+n,greater<int>());
        int discount=0;
        for(int i=2;i<n;i+=3)
            discount+=money[i];
            
        cout<<discount<<endl;
    }
}
