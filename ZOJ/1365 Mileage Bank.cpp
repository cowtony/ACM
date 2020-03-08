/*
求坐飞机的里程积分。头等舱二倍积分，商务舱1.5倍，经济舱小于500mile当500mile算，大于的按原值算

读入数据是个难点
输出其实不会有小数 

关键词：模拟，简单题 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1,s2;
    int mile;
    char c;
    
    while(true)
    {
        double mileage=0;
        
        while(cin>>s1)
        {
            if(s1=="0")break;
            if(s1=="#")return 0;
        
            cin>>s2>>mile>>c;
            
            switch(c)
            {
                case 'F':mileage+=mile*2;break;
                case 'B':mileage+=mile*1.5;break;
                case 'Y':if(mile<500)mileage+=500;
                         else mileage+=mile;
            }
        }
        cout<<mileage<<endl;
    }
} 
