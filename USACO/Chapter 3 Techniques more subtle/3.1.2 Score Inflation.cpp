/*
ID:cowtony1
PROG:inflate
LANG:C++

������ʱ��time����Ŀ����������kind������������ÿ������Ҫ��ʱ��elapse���ܵõ��ķ���score
������ʱ���������Եö��ٷ�

��ȫ��������
��̬�滮dp[i]��ʾiʱ���������Եõ��ķ���
״̬ת�Ʒ���dp[i]=max(dp[i],dp[i-elapse]+score) 
 
�ؼ��ʣ���̬�滮���������� 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    
    int time,kind;
    cin>>time>>kind;
    
    int dp[10001]={0};
    for(int i=0;i<kind;i++)
    {
        int score,elapse;
        cin>>score>>elapse;
        
        for(int j=elapse;j<=time;j++)
            dp[j]=max(dp[j],dp[j-elapse]+score);
    }
    cout<<dp[time]<<endl;
}
