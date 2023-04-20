/*
ID:cowtony1
PROG:prefix
LANG:C++
��һ���ַ������ϣ���һ���ַ�����������ַ���ǰ�������ٸ��ַ����Ա�ʾ�ɼ����ַ�����������

��̬�滮��bool dp[i]��ʾ��i���ַ�����ǰ�����Ա���ʾ����
��ô�ʹ��ڼ����е�һ������Ϊa��Ԫ�أ�����dp[i-a]=true�����Ҹ��ַ�����i-a~i��һ����ͬ
ȫ�����������Ժ��ҳ�����iʹ��dp[i]=true����

�ؼ��ʣ���̬�滮 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string set[201];
string m;

bool check(int i,int j)
{
    for(int k=0;k<set[j].length();k++)
        if(set[j][k]!=m[i-set[j].length()+k])return false;
    return true;
}

int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    
    int n=0;
    string temp;
    while(cin>>temp && temp!=".")set[n++]=temp;
    while(cin>>temp)m+=temp;

    bool dp[200001]={1};
    for(int i=0;i<=m.length();i++)
        for(int j=0;j<n;j++)
        {
            if(i<set[j].length()-1)continue;
            if(check(i,j)==true)dp[i]=dp[i]||dp[i-set[j].length()];
        }
    
    for(int i=m.length();i>=0;i--)
        if(dp[i]==true){cout<<i<<endl;break;}
}
