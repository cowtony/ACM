/*
ID: cowtony1
PROG: gift1
LANG: C++
有一堆人，每个人给指定的另一些人送钱，他有x块钱，那些人平分这些钱，但是只拿整数，求每个人最后盈利多少钱

模拟题，用map，再做个索引表索引人名顺序
注意比如我有200块给三个人，最后我只给出了198块，因为每个人拿200/3=66块

关键词：STL，模拟 
*/
#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

int main()
{
    ofstream cout("gift1.out");
    ifstream cin("gift1.in");
    
    int n;
    cin>>n;
    map<string,int> person;
    string name[10];
    
    for(int i=0;i<n;i++)
    {
        cin>>name[i];
        person[name[i]]=0;
    }
    
    string send;
    while(cin>>send)
    {
        int money,number;
        cin>>money>>number;
        for(int i=0;i<number;i++)
        {
            string recieve;
            cin>>recieve;
            person[send]-=money/number;
            person[recieve]+=money/number;
        }
    }
    
    for(int i=0;i<n;i++)
        cout<<name[i]<<' '<<person[name[i]]<<endl;
}
