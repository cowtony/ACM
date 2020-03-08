/*
给一串灯泡的状态，每过一秒，每个灯的状态就变为他与下一个灯的异或，求m秒后所有灯的状态

找规律
时刻1时
  		灯泡1:s[1] xor s[2]
  		灯泡2:s[2] xor s[3]
  		灯泡3:s[3] xor s[4]
  		灯泡4:s[4] xor s[1]
时刻2时
  		灯泡1:(s[1] xor s[2]) xor (s[2] xor s[3])=s[1] xor s[3]
  		灯泡2:(s[2] xor s[3]) xor (s[3] xor s[4])=s[2] xor s[4]
  		灯泡3:(s[3] xor s[4]) xor (s[4] xor s[1])=s[3] xor s[1]
  		灯泡4:(s[4] xor s[1]) xor (s[1] xor s[2])=s[4] xor s[2]
规律是：2^k秒后，状态是当前每个灯泡与2^k后个灯的异或
找到了规律就好办了，把时间m分解为许多形如2^k的和（二进制）
然后再计算

关键词：巧算法 
*/
#include<iostream>
#define MAX 1000000
using namespace std;

int result[MAX],a[MAX];

int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
        cin>>a[i];

    memcpy(result,a,sizeof(int)*n);
    while(m>0)
    {
       int t=1;
       while(t*2<=m)t*=2;
       
       for(int i=0;i<n;i++)
           result[i]=a[i]^a[(i+t)%n];
           
       memcpy(a,result,sizeof(int)*n);
       m-=t;       
    }
    
    for(int i=0;i<n;i++)
        cout<<result[i]<<endl;
        
    return 0;
}
