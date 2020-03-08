/*
输入n<=100行大写字母，每行不大于100个字符，将重复的如BBBB缩写为4B再输出

就那样做，细心点

关键词：简单题 
*/
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char code[101];
    int n,len;
    
    cin>>n;
    while(n--)
    {
        cin>>code;
        len=1;
        for(int i=0;i<strlen(code);i++)
        {
            if(code[i]==code[i+1]){len++;continue;}
            else 
            {
                if(len==1)cout<<code[i];
                    else cout<<len<<code[i];
                len=1;
            }
        }
        cout<<endl;
    }
    
    return 0;
} 
