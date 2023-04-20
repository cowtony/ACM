/*
ID: cowtony1
PROG: gift1
LANG: C++
��һ���ˣ�ÿ���˸�ָ������һЩ����Ǯ������x��Ǯ����Щ��ƽ����ЩǮ������ֻ����������ÿ�������ӯ������Ǯ

ģ���⣬��map����������������������˳��
ע���������200��������ˣ������ֻ������198�飬��Ϊÿ������200/3=66��

�ؼ��ʣ�STL��ģ�� 
*/
#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

int main()
{
    ofstream cout("gift1.out");
    ifstream cin("gift1.in");
    
    int n;
    cin>>n;
    map<string,int> person;
    string name[10];
    
    for(int i=0;i<n;i++)
    {
        cin>>name[i];
        person[name[i]]=0;
    }
    
    string send;
    while(cin>>send)
    {
        int money,number;
        cin>>money>>number;
        for(int i=0;i<number;i++)
        {
            string recieve;
            cin>>recieve;
            person[send]-=money/number;
            person[recieve]+=money/number;
        }
    }
    
    for(int i=0;i<n;i++)
        cout<<name[i]<<' '<<person[name[i]]<<endl;
}
