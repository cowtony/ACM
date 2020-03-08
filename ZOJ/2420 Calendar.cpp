/*
以2000-1-1为第零天，输入第x天，求那天的日期

2000-1-1为星期六
先存下2000到9999年所有的信息，边算边存
注意判断闰年 
然后直接输出

关键词：好想但很复杂 
*/
#include<iostream>
using namespace std;

struct date
{
    short int year,month,day;
    short int week;

    date(int y=0,int m=0,int d=0,int w=0)
    {
        year=y;
        month=m;
        day=d;
        week=w;
    }
    
    bool leap_year()
    {
        return ((year%4==0 && year%100!=0) || year%400==0);
    }
    
    void plus_1(void)
    {
        day++;
        switch(month)
        {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                if(day>31){day-=31;month++;}
                break;
            case 4:case 6:case 9:case 11:
                if(day>30){day-=30;month++;}
                break;
            case 2:
                if(leap_year()==true)
                {
                    if(day>29){day-=29;month++;}
                }
                else 
                    if(day>28){day-=28;month++;}
        }
        if(month>12){month-=12;year++;}
        week=(week+1)%7;
    }
    void print(void)
    {
        cout<<year<<"-";
        if(month<10)cout<<"0"<<month<<"-";
        else cout<<month<<"-";
        if(day<10)cout<<"0"<<day<<" ";
        else cout<<day<<" ";
        
        switch(week)
        {
            case 0:cout<<"Sunday"<<endl;break;
            case 1:cout<<"Monday"<<endl;break;
            case 2:cout<<"Tuesday"<<endl;break;
            case 3:cout<<"Wednesday"<<endl;break;
            case 4:cout<<"Thursday"<<endl;break;
            case 5:cout<<"Friday"<<endl;break;
            case 6:cout<<"Saturday"<<endl;break;
        }
    }
};

date d[8000*366];

int main()
{
    date temp(2000,1,1,6);
    for(int i=0;i<8000*366;i++)
    {
        d[i]=temp;
        temp.plus_1();
    }
    
    int n;
    while(cin>>n)
    {
        if(n==-1)break;
        d[n].print();
    }
}
