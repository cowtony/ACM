/*
给一个带空格的英文字符串，求sum[第几个字符*第几个字母]，空格值为零

就那样算么

关键词：简单题
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int sum; 
    char c[255];
    
    //freopen("aaa.txt","r",stdin);
    
    while(cin.getline(c,256))   //读入一个带空格的字符串
    {
        if(c[0]=='#')break;
            
        sum=0;
        for(int i=0;i<strlen(c);i++) 
            if(c[i]!=' ')sum+=(i+1)*(c[i]-'A'+1);
                
        cout<<sum<<endl;
    }
    
    return 0;
}

