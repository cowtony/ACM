/*
ID:cowtony1
PROG:calfflac
LANG:C++
����һ�����£����������ĵ�һ�Σ��жϻ��ĵ�ʱ�򲻹ܷ���ĸ�Ķ������������Ҫ�������

�ȶ������ݣ�Ȼ��ö�ٻ����е㣬�����ĳ���
������󳤶�ʱ����ߺ��ұߣ�������
��Ŀ���ѣ����ȽϿ�����

�ؼ��ʣ��ַ��������� 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string s;

int solve(int left,int right,int& a,int& b)
{
    int length=right-left-1;

    while(left>=0 && right<s.length())
    {
        while(!isalpha(s[left]) && left>=0)left--;
        while(!isalpha(s[right]) && right<s.length())right++;
        if(tolower(s[left])==tolower(s[right]))
        {
            length+=2;
            a=left;
            b=right;
            left--;
            right++;
        }
        else break;
    }
    return length;
} 

int main()
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);

    while(cin.eof()==false)
        s+=cin.get();
    
    int max_length=0;
    int max_left,max_right;
    
    for(int i=0;i<s.length();i++)
    {
        int len,left,right;
        if(isalpha(s[i]))
        {
            len=solve(i,i,left,right);//���� 
            if(max_length<len)
            {
                max_length=len;
                max_left=left;
                max_right=right;
            }
            len=solve(i,i+1,left,right);//ż��
            if(max_length<len)
            {
                max_length=len;
                max_left=left;
                max_right=right;
            }
        }
    }
    
    cout<<max_length<<endl; 
    for(int i=max_left;i<=max_right;i++)
        cout<<s[i];
    cout<<endl;
}
