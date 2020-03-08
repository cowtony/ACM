/*
输入列数column，把原文竖着写成column列
再按行s型可得到密文。现在已知密文和column，求原文

因为是s型加密的
所以读入密文后把偶数行的子串反转
然后一个一个字符的加到与列对应的string上
最后输出就可以了

关键词：字符串 
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int column;
    char c[200];
    while(cin>>column)
    {
        if(column==0)break;
        
        cin>>c;
        string s[20];
        for(int start=column;start<strlen(c);start+=2*column)
            reverse(c+start,c+start+column);
            
        for(int i=0;i<strlen(c);i++)
            s[i%column]+=c[i];
        
        for(int i=0;i<column;i++)
            cout<<s[i];
        cout<<endl;
    }
} 
