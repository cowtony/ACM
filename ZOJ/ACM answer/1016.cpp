#include <iostream>
using namespace std;
int main() 
{
int case_num;
cin>>case_num;

int p[20];
for(int j=0; j<20; j++)
   p[j] = 0;

int result[20];
for(int j=0; j<20; j++)
   result[j] = 0;

while(case_num--)
{
   char a[1000];
   for(int k=0;k<1000;k++)
    a[k]=0;
   int size=0;//代表'('')'的字符串长度
   int nz = 0;//输出的第nz个结果
   int n;
   cin>>n;
   for(int j=0; j<n; j++)
   {
    cin>>p[j];
   }
   int tmp[20];
   for(int k=0;k<20;k++)
    tmp[k]=0;

   tmp[0] = p[0];
   for(int k=1; k<n; k++)
    tmp[k] = p[k] - p[k-1];
   for(int s=0; s<n; s++)
   {
    for(int c=0; c<tmp[s]; c++)
    {
     a[size++] = '(';
    }
    a[size++] = ')';
   }
   for(int ty=0; ty<size; ty++)//遍历所有'（'和‘）’字符
   {
    if(a[ty]==')')//找到每一个')'
    {
     int count=0;//输出的结果
     int temp = 1;//计数
    
     for(int tu=ty-1; tu>=0; tu--)
     {
      if(a[tu]=='(')
      {
       temp--;
       if(temp>0)
        count++;
       else
        break;
      

      
      }
      if(a[tu]==')')
       temp++;

     }
     result[nz] = count+1;
     if(nz!=0)
      cout<<" "<<result[nz];
     else
      cout<<result[nz];
    
     nz++;
    }
   
   }
    cout<<endl;
  

}

}
