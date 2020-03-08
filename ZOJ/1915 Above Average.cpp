/*
输入一些学生的成绩，输出有百分之多少的学生高于平均分

直接做

关键词：简单题 
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int n;
        cin>>n;
        
        int grade[1000];
        double average=0;
        for(int i=0;i<n;i++)
        {
            cin>>grade[i];
            average+=grade[i];
        }
        average/=double(n);
        
        int count=0;
        for(int i=0;i<n;i++)
            if(grade[i]>average)count++;
        
        cout.precision(3);
        cout<<fixed<<count/double(n)*100<<"%"<<endl;
    }
} 
