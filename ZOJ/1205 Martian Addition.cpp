/*
输入两行20进制数,求和

用到了vector,细节比较麻烦
需要细心和耐心
题很简单

关键词:高精度计算,进制转换 
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int convert(char c)
{
    if(c>='0' && c<='9')return c-'0';
    else return c-'a'+10;
}
char reconvert(int n)
{
    if(n>=0 && n<=9)return n+'0';
    else return n-10+'a';
}

int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        if(a.length()>b.length())swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        vector<int> result;
        bool flag=0;
        for(int i=0;i<b.length();i++)
        {
            int sum;
            if(i<a.length())sum=convert(a[i])+convert(b[i])+flag;
            else sum=convert(b[i])+flag;
            
            if(sum>=20){sum-=20;flag=1;}
            else flag=0;
            
            result.push_back(sum);
        }
        if(flag==1)result.push_back(1);
        
        for(int i=result.size()-1;i>=0;i--)
            cout<<reconvert(result[i]);
        cout<<endl;
    }
} 
