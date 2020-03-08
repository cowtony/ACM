/*
n个人要住店，他们必须住同一个旅馆，有w个周末可以选择
已知每个旅馆的价格和每个周末的床数，求最少花费，超过预算输出stay home

简单题，直接模拟

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n,budget,hotel,week;
    cin>>n>>budget>>hotel>>week;
    
    int min_price=1000000;
    for(int i=0;i<hotel;i++)
    {
        int price;
        cin>>price;
        
        int max_bed=0;
        for(int j=0;j<week;j++)
        {
            int bed;
            cin>>bed;
            if(max_bed<bed)max_bed=bed;
        }
        
        if(max_bed>=n)
            if(min_price>price)min_price=price;
    }
    
    if(min_price*n>budget)cout<<"stay home"<<endl;
    else cout<<min_price*n<<endl;
    
    //while(1);
} 
