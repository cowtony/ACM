/*
ID:cowtony1
PROG:namenum
LANG:C++

����һ���ֵ䣬�ٶ���һ�����ִ���ʾ���ֻ��ϵİ���������ֵ����ܰ������ĵ��ʣ�û�������NONE

�����Ƚ�����ĸ��Ӧ���ֵ�ƥ��
Ȼ��ÿ��һ�����ʾͰ���ת�������ִ������Ƿ�Ͷ����һ��

�ؼ��ʣ�ֱ���������� 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    
    char trans[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
    
    string num;
    cin>>num;
    
    ifstream infile("dict.txt");
    string word;
    bool flag=false;
    while(infile>>word)
    {
        string temp=word;
        for(int i=0;i<temp.length();i++)
            temp[i]=trans[temp[i]-'A'];
        if(num==temp){cout<<word<<endl;flag=true;}
    }
    if(flag==false)cout<<"NONE"<<endl;
}
