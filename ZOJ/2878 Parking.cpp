/*
有个人要在许多家商店买东西，问把车停哪走的路程最少，求最少路程

商店在一条直线上，读入商店的位置
排序以后只要让车停在两头商店之间就行了
走的路程为两头商店的间距乘以二

关键词：简单题 
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
        int shop[20];
        for(int i=0;i<n;i++)
            cin>>shop[i];
            
        sort(shop,shop+n);
        cout<<2*(shop[n-1]-shop[0])<<endl;
    }
}
