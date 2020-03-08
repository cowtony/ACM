/*
输入一个数字字符串，把连续相同的压缩为kX的格式输出

用到了string类里的erase函数，注意用法
就那样做，找一节输出一节删一节

关键词：字符串，简单题 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    
    while(cases--)
    {
        string s;
        cin>>s;
        
        while(s.length()>0)
        {
            int i;
            for(i=0;s[i+1]==s[i];i++);
            cout<<i+1<<s[i];
            s.erase(0,i+1);//好好琢磨怎么用，删掉的是s[0]到s[i] 
        }
        cout<<endl;
    }
    
    //while(1);
} 
