/*
ID:cowtony1
PROG:humble
LANG:C++

����K�����������������Щ������˵ĵ�N�����

����������humble�м����ǰn��������Ϊ��ʵ���������򵥣����ǰ�1Ҳ��Ϊһ����������humble[0]=1; 
��������֪ǰk������ʱ����õ���k+1�������ǿ�����������
����ÿ������pѰ����С�ĳ���hʹ��h*p����һ�������� 
ȡ�����ҵ���h*p����С��һ������������һ������Ϊ��ʹ�������죬���ǿ���Ϊÿ������ά��һ��ָ��point[p]��ʾÿ�������Ѿ��˵����ĸ�������ÿ�ζ������￪ʼ���������ٴ�ͷ������

�ؼ��ʣ����ۣ���˼�� 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    
    int K,N;
    cin>>K>>N;
    
    int prime[100];
    for(int i=0;i<K;i++)
        cin>>prime[i];
        
    
    int humble[100001]={1};
    int point[100]={0};
    
    for(int i=1;i<=N;i++)
    {
        int least=2100000000;
        for(int p=0;p<K;p++)
            least=min(least,prime[p]*humble[point[p]]);
        humble[i]=least;
        
        for(int p=0;p<K;p++)
            if(humble[i]==prime[p]*humble[point[p]])point[p]++;
    }
    
    cout<<humble[N]<<endl;
}
