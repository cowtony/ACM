/*
题意：

前三段通通废话，就是说一个女王她老公让人给杀了，她要去报仇，然后要运武器。

一共有三种武器，每种有各自的重量，大小和杀伤力，同时， 如果三种武器按一定数量组合以来的话，还会产生一种新的杀伤力。

现在大家应该觉得和背包问题很像。

输入第一行是一共有几辆车，然后的三行是三种武器的重量，大小和杀伤力，再下一行是三种武器按多少的数量组合可以产生多大的杀伤力，再接下来的行数就是每辆车可以拉的最大重量和大小。

要求输出格式是和样例那样，同时每两个输出之间要有一个空行。

思路：

动态规划题，复杂就是因为它的属性实在太多了，还要组合。。。

在网上看到一个人的想法：

设dp[k][i][j]表示前k辆车放i个1武器和j个2武器时最多能放dp[k][i][j]个3武器.
状态转移方程为dp[k][i][j]=max(dp[k][i][j],dp[k-1][i-t1][j-t2]+num(k,t1,t2))
num(k,t1,t2)为第k辆车子放了t1个1武器,t2个2武器后还能放的3武器的数量,
由于只用到了dp[k-1][.][.]，因此可以用滚动数组节省空间.

觉得很好，我再具体说一下程序的结构吧

有n辆车，就循环n次

每一次得到如果有现在辆车的时候能拉多少东西

到最后一次循环时，就得到所有车一共可以拉多少东西的各种最大组合。

然后再计算每一种可能的最大杀伤力，就是最后结果。

代码：
*/
#include <iostream>
using namespace std;

int mx(int x,int y){return x>y?x:y;}
int mn(int x,int y){return x<y?x:y;}
int mnt(int x,int y,int z)
{
 if (x>y)x=y;
 if (x>z)x=z;
 return x;
}
int dp[2][501][501];
int main()
{
 int i,j,j1,j2,k1,k2,n,cases=0;
 int t,sum,m1,m2,m3,m4,p,q,res,pows;
 int w[3],s[3],d[4],c[3];
 int x[101],y[101];
 while (cin>>n)
 {
  if (n==0)
   break;
  cases++;
  for (i=0;i<3;i++)
   cin>>w[i]>>s[i]>>d[i];
  cin>>c[0]>>c[1]>>c[2]>>d[3];
  for (i=0;i<n;i++)
   cin>>x[i]>>y[i];
  memset(dp,-1,sizeof(dp));
  dp[0][0][0]=0;
  p=0;q=1;
  m1=0;m2=0;
  for (i=0;i<n;i++)
  {
   for (j1=0;;j1++)
   {
    if (w[0]*j1>x[i]||s[0]*j1>y[i])
     break;
    for (j2=0;;j2++)
    {
     if (w[0]*j1+w[1]*j2>x[i]||s[0]*j1+s[1]*j2>y[i])
      break;
     t=mn((x[i]-w[0]*j1-w[1]*j2)/w[2],(y[i]-s[0]*j1-s[1]*j2)/s[2]);
     m3=m1;m4=m2;
     for (k1=0;k1<=m1;k1++)
     {
      if (k1+j1>500)
       break;
      for (k2=0;k2<=m2;k2++)
      {
       if (k2+j2>500)
        break;
       m3=mx(k1+j1,m3);
       m4=mx(k2+j2,m4);
       if (dp[p][k1][k2]!=-1)
        dp[q][k1+j1][k2+j2]=mx(dp[q][k1+j1][k2+j2],dp[p][k1][k2]+t);

      }
     }
     m1=m3;m2=m4;
    }
   }
   p=(p+1)%2;
   q=(q+1)%2;
  }
  res=0;
  for (i=0;i<=500;i++)
  {
   for (j=0;j<=500;j++)
   {
    sum=0;
    t=dp[p][i][j];
    if (t==-1)continue;
    pows=mnt(i/c[0],j/c[1],t/c[2]);
    sum=mx(pows*d[3]+(i-pows*c[0])*d[0]+(j-pows*c[1])*d[1]+(t-pows*c[2])*d[2],d[0]*i+d[1]*j+d[2]*t);
    res=mx(res,sum);
   }
  }
  if (cases>1)
   cout<<endl;
  cout<<"Case "<<cases<<": "<<res<<endl;
 }
 return 0;
}