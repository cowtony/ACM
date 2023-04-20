/*
ID:cowtony1
PROG:palsquare
LANG:C++

�������300����ƽ����B���Ʊ�ʾ���ǻ���������

ö�٣�Ȼ���жϣ���������

�ؼ��ʣ����⣬����ת�� 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int B;
char t[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

string base(int n)
{
    string s;
    while(n)
    {
        s+=t[n%B];
        n/=B;
    }
    return s;
}

bool palindromic(string s)
{
    for(int i=0;i<s.length();i++)
        if(s[i]!=s[s.length()-1-i])return false;
    return true;
}

int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    
    cin>>B;
    for(int i=1;i<=300;i++)
    {
        string b=base(i*i);
        if(palindromic(b)==true)
        {
            string a=base(i);
            for(int i=a.length()-1;i>=0;i--)
                cout<<a[i];
            cout<<' '<<b<<endl;
        }
    }
    //while(1);
}
