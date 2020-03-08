/*
定义字符串a的n次方为n个a相接，a^0=""。给出字符串s，求s=a^n成立的n的最大值

从s的长度的约数着手，一个一个的试是否成立
递归也可也做

关键词：字符串，递归
*/
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s;
    
    while(cin>>s)
    {
        if(s==".")return 0;
        
        string a;
        int len=s.length();
        int i,j;

        for (i=1;i<len;i++)
        {
            if(len%i==0)
                for (j=i;j<2*i;j++)
                    for(int k=j;k<len;k+=i)
                        if (s[k]!=s[k-i])goto end;
     
            end:if(j>=2*i)break;    
        }

        cout<<len/i<<endl;
    }
}
