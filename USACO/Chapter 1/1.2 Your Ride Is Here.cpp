/*
ID: cowtony1
PROG: ride
LANG: C++
两个大写字母单词，A代表1，Z代表26，他们的值是每个字母的值乘起来，如果最后对47同余输出GO否则输出STAY

直接做

关键词：简单题 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ofstream cout("ride.out");
    ifstream cin("ride.in");
    
    int a=1,b=1;
    string s1,s2;
    cin>>s1>>s2;
    
    for(int i=0;i<s1.length();i++)
        a*=s1[i]-'A'+1;
    for(int i=0;i<s2.length();i++)
        b*=s2[i]-'A'+1;
        
    if(a%47==b%47)cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
    
    //while(1);
}
