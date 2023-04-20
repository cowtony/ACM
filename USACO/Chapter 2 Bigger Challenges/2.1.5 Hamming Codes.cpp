/*
ID:cowtony1
PROG:hamming
LANG:C++
�ҳ�N��������������֮��ĺ������벻С��D������ÿ����С��2^B
����������������������ֵ�����Ʊ�ʾ���ж��ٸ�1 

0�ǵ�һ������һ���ҵ���ǰ���Ѵ�𰸾��붼��С�ں�������ľͼ�������´𰸣�ֱ����N����

�ؼ��ʣ����� 
*/
#include<iostream>
#include<fstream>
using namespace std;

int hamming(int a,int b)
{
    int count=0;
    int c=a^b;
    while(c)
    {
        if(c%2==1)count++;
        c/=2;
    }
    return count;
}//��a,b�ĺ������� 

int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
        
    int N,B,D;
    cin>>N>>B>>D;
    
    int result[64]={0};
    int n=1;//��𰸵� 
    
    int max=1<<B;
    for(int i=1;i<max;i++)
    {
        for(int j=0;j<n;j++)
            if(hamming(i,result[j])<D)goto end;
        result[n++]=i;
        if(n==N)break;
        end:;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<result[i];
        if((i+1)%10==0)cout<<endl;
        else if(i<n-1)cout<<' ';
    }//��� 
    if(n%10!=0)cout<<endl;
}
