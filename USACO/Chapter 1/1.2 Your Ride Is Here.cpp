/*
ID: cowtony1
PROG: ride
LANG: C++
������д��ĸ���ʣ�A����1��Z����26�����ǵ�ֵ��ÿ����ĸ��ֵ���������������47ͬ�����GO�������STAY

ֱ����

�ؼ��ʣ����� 
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
