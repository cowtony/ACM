/*
给两个字符串，他们经过不同的错位得到共同字母的最大值max，按分数格式输出max*2/(len1+len2)这个值

依次计算不同错位得到的值，找出最大的后按格式输出即可
注意要约分 

关键词：字符串 
*/
#include<iostream>
#include<cstring>
using namespace std;

int gcd(int a,int b)
{   
    if (b != 0) 
    return gcd(b, a % b); 
    else return a;   
}//最小公倍数 

int main()
{   
    string word_a;
    string word_b;
    int numerator,denominator;
    
    while(cin>>word_a>>word_b)
    {   
        if(word_a=="-1")return 0;
        
        int len1=word_a.length();
        int len2=word_b.length();
        int max = 0;
        int sum = 0;

        for(int i=0;i<len1;i++)
            for(int j=0;j<len2;j++)  
                if(word_a[i]==word_b[j]) 
                { 
                    sum=1;
                    for(int g=1;g+j<len2&&g+i<len1;g++)
                        if(word_a[i+g]==word_b[j+g])sum++;        
                    if(sum>max)max=sum;    
                }

        if(max>0)
        { 
            numerator=max*2;
            denominator=len1+len2;
            int div=gcd(numerator,denominator);
            numerator/=div;
            denominator/=div;
            
            if(denominator!=1)cout<<"appx("<<word_a<<","<<word_b<<") = "<<numerator<<"/"<<denominator<<endl;
                else cout<<"appx("<<word_a<<","<<word_b<<") = "<<numerator<<endl;
        }
        else cout<<"appx("<<word_a<<","<<word_b<<") = 0"<<endl;
    }
}
