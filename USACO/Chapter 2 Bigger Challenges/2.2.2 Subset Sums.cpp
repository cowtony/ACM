/*
ID:cowtony1
PROG:subset
LANG:C++
��1��n����Ȼ���ֳ����飬ʹ��ÿ��ĺ���ȣ��������

��̬�滮
count[i][j]��ʾ��1-i����Ȼ���дճ�j�ķ�����
������Ҫ��ľ���count[n][sum(n)/2]
״̬ת�Ʒ���Ϊcount[i][j]=count[i-1][j]+count[i-1][j-i]
�������ǣ�i�дճ�j�ķ���������i-1�дճ�j�ķ���������ѡȡi��������i-1�дճ�j-i�ķ�������ѡȡi������뷽����

�ؼ��ʣ���̬�滮 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);    
    int n;
    cin>>n;
    
    int sum=(1+n)*n/2;
    int count[40][1000]={0};
    count[1][1]=1;
    
    for(int i=2;i<=n;i++)
        for(int j=1;j<=(1+i)*i/2;j++)
            count[i][j]=count[i-1][j]+count[i-1][max(0,j-i)];

    if(sum%2!=0)cout<<0<<endl;
    else cout<<count[n][sum/2]<<endl;
}
