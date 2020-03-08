/*
题意：

有两种巧克力，把它们放到一些盒子里，盒子必须装满，而且不能一个盒子里同时有两种巧克力，巧克力可以有剩余。

输入里第一行是两种巧克力的数量

第二行是有多少个盒子

第三行是每个盒子放多少个巧克力

要求如果能把所以的盒子全部填满，则输出放第一种巧克力的盒子数量，然后在同一行接着输出分别是哪些盒子放的第一种巧克力。

如果不能，则输出Impossible to distribute

思路：

DP题，首先统计把所有的盒子全部放满需要多少个巧克力，如果这个数大于巧克力数，则肯定是不能的

然后循环i从1到n

表示每次从i个盒子开始往后放，再循环j=i到n

表示从i个盒子开始把所有能放第一种巧克力的盒子全部放了

j循环完毕后，判断剩下没放的巧克力数，如果大于第二个巧克力数，说明当前放第一种巧克力的方案不对，接着循环，否则，跳出循环

双重循环完毕后验证如果i循环超过了n，说明每一种放第一种巧克力的方案都不对，说明不能放满盒子。

否则则输出。

代码：
*/
#include <iostream>
using namespace std;

int main()
{
 int m,l,n,sum,total,count;
 int c[2001],f[2001];
 int i,j;
 while (cin>>m>>l)
 {
  if (m==0&&l==0)
   break;
  cin>>n;
  sum=0;
  for (i=0;i<n;i++)
  {
   cin>>c[i];
   sum+=c[i];
  }
  if (sum>m+l)
  {
   cout<<"Impossible to distribute\n";
   continue;
  }
  for (i=0;i<n;i++)
  {
   total=0;
   count=0;
   memset(f,0,sizeof(f));
   for (j=i;j<n;j++)
   {
    if (c[j]+total>m)
     continue;
    total+=c[j];
    f[j]=1;
    count++;
   }
   if (sum-total<=l)
    break;
  }
  if (i==n)
   cout<<"Impossible to distribute\n";
  else
  {
   cout<<count;
   for (i=0;i<n;i++)
    if (f[i]==1)
     cout<<" "<<i+1;
   cout<<endl;
  }
 }
 return 0;
}