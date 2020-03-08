/*
读入时间（时，分，秒），输出时针和分针的夹角

先根据时间算出时针和分针的绝对角度，化为秒的单位存储
再相减化为相对角度
最后保持该角度在180度以内，如果大于180度，用360度减它，如果小于零度，加360度
以要求格式输出

关键词：细心，进制转换 
*/
#include<iostream>
#include<cmath> 
using namespace std;

int main()
{
    int hour,minute,second;
    int hour_degree;
    int minute_degree;
    int d,m,s;
    
    //freopen("aaa.txt","r",stdin);
    
    while(scanf("%d:%d:%d",&hour,&minute,&second)!=EOF)
    {
        if(hour>=12)hour-=12;
        hour_degree=hour*30*60*60;
        hour_degree+=minute*30*60;
        hour_degree+=second*30;

        minute_degree=minute*6*3600;
        minute_degree+=second*6*60;
        
        d=abs(hour_degree-minute_degree);
        if(d>180*60*60)d=360*60*60-d;
        
        s=d%60;
        d/=60;
        m=d%60;
        d/=60;
        cout<<d<<" ";
        if(m<10)cout<<"0"<<m<<" ";
        else cout<<m<<" ";
        if(s<10)cout<<"0"<<s<<endl;
        else cout<<s<<endl;
    }
    //while(1);
    return 0;
} 
