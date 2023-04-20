/*
ID:cowtony1
PROG:stamps
LANG:C++

�ŷ�����������K<=200����Ʊ������N����ֵ����Ʊ���ʿ�������1��������ֵ��

��̬�滮��f[i]��ʾ������ֵΪi������Ҫ��������Ʊ
״̬ת�Ʒ��̾���f[i]=min{f[i-value[j]]}+1
��������ֵΪi-value[j]�ķ���������һ����ֵΪvalue[j]����Ʊ
�������õ��ĵ�һ������K������1

�ؼ��ʣ���̬�滮������ 
*/
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

int f[2000001];

int main()
{
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    
    int K,N;
    cin>>K>>N;
    
    int value[50];
    for(int i=0;i<N;i++)
        cin>>value[i];
        
    sort(value,value+N);
    
    f[0]=0;
    for(int i=1;i<=K*value[N-1];i++)
    {
        int min=99999999;
        for(int j=0;j<N && i-value[j]>=0;j++)
            if(min>f[i-value[j]])min=f[i-value[j]];
        f[i]=min+1;
        
        if(f[i]>K)
        {
            cout<<i-1<<endl;
            return 0;
        }
    }
    cout<<K*value[N-1]<<endl;
}
