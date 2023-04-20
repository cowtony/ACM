/*
ID:cowtony1
PROG:nocows
LANG:C++

��n<200���ڵ㣬k<100��Ķ�������ÿ���ڵ�ֻ��0��2���ӽڵ㡣��n���ڵ㣬k��Ķ������ж����֣�

��̬�滮��dp[k][n]��ʾk�㼰���£�n���ڵ�Ŀ�������
״̬ת�Ʒ��̣�dp[i][j]+=dp[i-1][k]*dp[i-1][j-k-1]
ע����Ҫ��9901ȡģ���ڵ���ֻ����Ϊ����

�ؼ��ʣ���̬�滮 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    
    int n,k,dp[100][200]={0};
	cin>>n>>k;
	
	for(int i=1;i<=k;i++)dp[i][1]=1;
	
	for(int i=1;i<=k;i++)
		for(int j=3;j<=n;j+=2)
			for(int k=1;k<=j-2;k+=2)
			{
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-k-1];
				dp[i][j]%=9901; 
            }
				
	cout<<(dp[k][n]-dp[k-1][n]+9901)%9901<<endl;
}
