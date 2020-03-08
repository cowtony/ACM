/*
读入一串数，输出这串数在计算器显示屏上需要几个条条显示

简单

关键词：简单题 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    char c[50];
    int count=0;
    
    cin>>c;
    
    for(int i=0;i<strlen(c);i++)
    {
        switch(c[i])
        {
            case '0':count+=6;break;
            case '1':count+=2;break;
            case '2':count+=5;break;
            case '3':count+=5;break;
            case '4':count+=4;break;
            case '5':count+=5;break;
            case '6':count+=6;break;
            case '7':count+=3;break;
            case '8':count+=7;break;
            case '9':count+=6;break;
        }
    }
    cout<<count;
    
    //while(1);
    return 0;
}
