/*
给出明文字母和对应的密文字母，再给出一段明文，按照字母替换法输出密文，每行不超过64个字母

笨办法一个一个替换

关键词：字符串，简单题 
*/
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char plaintext[65];
    char substitution[65];
    char text[65];
    
    gets(plaintext);
    gets(substitution);//可录入空格 
    
    cout<<substitution<<endl<<plaintext<<endl;
    
    while(gets(text))
    {
        for(int i=0;i<strlen(text);i++)
            for(int j=0;j<strlen(plaintext);j++)
                if(text[i]==plaintext[j]){text[i]=substitution[j];break;}

        cout<<text<<endl;
    }
}
