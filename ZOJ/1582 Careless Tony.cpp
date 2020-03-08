/*
输入正确的字符串和打错的字符串，要删到错的地方重打，问要花多长时间

将正确字符串和错误字符串放一起比较
假设从第i个字符首次出现错误
则要删到第i个字符，再打完整才行
所以花的时间为(a.len-i)+(b.len-i) 

关键词：简单题，字符串 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int time;
        cin>>time;
        cin.ignore();
        
        string correct,type;
        getline(cin,correct);
        getline(cin,type);
        
        int i;
        for(i=0;i<correct.length() && i<type.length();i++)
            if(correct[i]!=type[i])break;
        
        cout<<time*(correct.length()-i+type.length()-i)<<endl;
    }
} 
