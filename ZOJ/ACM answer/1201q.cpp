#include<iostream>
using namespace std;


int main(){
int n;
char PI;

while(cin>>n&&n)
{
   cin>>PI;
   int count;
   int initial;
   int result[50];
   for(int ii=0; ii<50; ii++)
     result[ii] = 10000;
   int iii[50];

   if(PI=='P')
   {
    int p[50];
    for(int i=0; i<50; i++)
     p[i] = 0;
    for(int k=0;k<n;k++)
     cin>>p[k];
    for(int v=0; v<n; v++)
    {
     initial=0;
     count=0;
     while(p[initial]!=(v+1)){
      if(p[initial]>(v+1))
      {
       count++;
      
      }
      initial++;
     }
     result[v] = count;
     if(v==0)
      cout<<result[v];
     else
      cout<<" "<<result[v];
    }
    cout<<endl;
  

   }
   if(PI=='I')
   {
   
    //for(int j=0; j<50; j++)
     //iii[50] = 0;
    for(int k=0;k<n;k++)
     cin>>iii[k];
    for(int t=0; t<n; t++)
    {
     count=0;
     for(int y=0;y<n;y++)
     {
     
      if(result[y]<(t+1))
       count++;
      if(iii[t]==(y-count))
      {
       break;
      }
      
     }
     result[iii[t]+count] = t+1;
    }
    cout<<result[0];
    for(int ty=1; ty<n; ty++)
     cout<<" "<<result[ty];
    cout<<endl;
   }
}
}
