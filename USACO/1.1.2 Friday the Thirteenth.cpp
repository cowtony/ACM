/*
ID: cowtony1
PROG: friday
LANG: C++
1900.1.1是星期一，输入n，输出1900年开始的n年内每个月13号的分布（星期六，星期日。。。星期五）

模拟，注意判断闰年的方法，细心一些

关键词：模拟 
*/
#include<iostream>
#include<fstream>
using namespace std;

bool leap(int year)
{
    return (year%100!=0)&&(year%4==0)||(year%400==0);
}

int main()
{
    ofstream cout("friday.out");
    ifstream cin("friday.in");
    
    int n;
    cin>>n;
    
    int day=6;//1990.1.13 is Saturday
    int weekday[7]={0,0,0,0,0,0,1};//weekday[0]means Sunday
    
    for(int year=1900;year<1900+n;year++)
    {
        for(int month=1;month<=12;month++)
        {
            int t;
            switch(month)
            {
                case 4:case 6:case 9:case 11:
                    t=30;break;
                case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                    t=31;break;
                case 2:
                    if(leap(year)==true)t=29;
                    else t=28;
            }
            day=(day+t)%7;
            weekday[day]++;
        }
    }
    weekday[day]--;//1900+n+1年1月13日，不应该被算入 
    
    cout<<weekday[6];
    for(int i=0;i<6;i++)
        cout<<' '<<weekday[i];
    cout<<endl;
        
    //while(1);
}
