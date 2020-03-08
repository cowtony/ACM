/*
题目大意：

找出颜色最相近的RGB值，有一个公式，就是当给出两个RGB值，其差距为题中给的那个公式。

题目会给你16组RGB值，然后剩下的行数每行是一个RGB值，每次输出预先给出的16组RGB值和这个RGB值最相近的一组。当遇到-1，-1，-1时中止。

思路：

对每次输入做一次循环，遍历16组RGB值，求出每个差距，然后和当前最小差距比较，如果小于差距，则成为当前最小差距。
*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
 int color[16][3];
 int rgb[3];
 int r,g,b;
 int i,d,t;
 for (i=0;i<16;i++)
 {
  cin>>color[i][0];
  cin>>color[i][1];
  cin>>color[i][2];
 }
 while (cin>>r>>g>>b)
 {
  if (r==-1&&g==-1&&b==-1)
   break;
  t=422;
  for (i=0;i<16;i++)
  {
   d=sqrt((r-color[i][0])*(r-color[i][0])+(g-color[i][1])*(g-color[i][1])+(b-color[i][2])*(b-color[i][2]));
   if (d<t)
   {
    t=d;
    rgb[0]=color[i][0];
    rgb[1]=color[i][1];
    rgb[2]=color[i][2];
   }
  }
  cout<<"("<<r<<","<<g<<","<<b<<") maps to ("<<rgb[0]<<","<<rgb[1]<<","<<rgb[2]<<")\n";
 }
 return 0;
}