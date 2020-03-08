/*
输入球员的speed，weight，strength数据，根据题中要求判断该球员适合哪些位置

题很简单，就是判断
但是输出格式比较麻烦，练练

关键词：简单题，输出格式 
*/
#include<iostream>
using namespace std;

bool fit_a(double speed,double weight,double strength)
{
    if(weight<150)return false;
    else if(strength<200)return false;
    else if(speed>4.5)return false;
    else return true;
}

bool fit_b(double speed,double weight,double strength)
{
    if(weight<300)return false;
    else if(strength<500)return false;
    else if(speed>6)return false;
    else return true;
}

bool fit_c(double speed,double weight,double strength)
{
    if(weight<200)return false;
    else if(strength<300)return false;
    else if(speed>5)return false;
    else return true;
}

int main()
{
    double speed,weight,strength;
    while(cin>>speed>>weight>>strength)
    {
        if(speed==0 && weight==0 && strength==0)break;
        
        int n=0;
        if(fit_a(speed,weight,strength)==true)
        {
            cout<<"Wide Receiver";
            n++;
        }
        if(fit_b(speed,weight,strength)==true)
        {
            if(n>0)cout<<" ";
            cout<<"Lineman";
            n++;
        }
        if(fit_c(speed,weight,strength)==true)
        {
            if(n>0)cout<<" ";
            cout<<"Quarterback";
            n++;
        }
        if(n>0)cout<<endl;
        else cout<<"No positions"<<endl;
    }
}
