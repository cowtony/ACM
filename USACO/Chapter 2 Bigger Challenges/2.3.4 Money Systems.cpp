/*
ID:cowtony1
PROG:money
LANG:C++

��V����ֵ��Ӳ�ң����������ֵΪN�����з�����

�������⣬dp[i]��ʾ�����ֵΪi�Ŀ�����
��ÿһ����ֵp�������е�j��Ҫ��dp[j]+=dp[j-p]��������

�ؼ��ʣ���̬�滮 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    
    int v,n;
    cin>>v>>n;
    
    long long dp[10001]={1};
    for(int i=0;i<v;i++)
    {
        int p;
        cin>>p;
        for(int j=p;j<=n;j++)
            dp[j]+=dp[j-p];
    }
 
    cout<<dp[n]<<endl;
}
