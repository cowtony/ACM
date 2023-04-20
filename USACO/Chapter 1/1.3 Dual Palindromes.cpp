/*
ID:cowtony1
PROG:dualpal
LANG:C++

�ҵ���S���N������������2��10�����������������ǻ��ĵ�

ö�٣��ж�

�ؼ��ʣ�����ת�������� 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Converse(int B,int n)
{
    string s;
    while(n)
    {
        s+=n%B+'0';
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
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    
    int N,S;
    cin>>N>>S;
    for(int i=S+1,c=0;c<N;i++)
    {
        int count=0;
        for(int base=2;base<=10;base++)
            if(palindromic(Converse(base,i))==true)count++;
        if(count>=2)
        {
            cout<<i<<endl;
            c++;
        }
    }
    //while(1);
}
