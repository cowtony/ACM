#include<iostream>
using namespace std;

int main(){
int n;
cin>>n;
int max=-1024;
int a[100][100];
int sum[100] = {0};

for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
    cin>>a[i][j];


   for(int top=0; top<n; top++)
   {
     for(int j=0; j<n; j++)
      sum[j] = a[top][j];
     for(int bottom=top+1; bottom<n; bottom++)
     {
      for(int j=0; j<n; j++)
       sum[j] += a[bottom][j];
      int sum2 = 0;
      for(int j=0; j<n; j++)
      {
       if(sum2>0)
        sum2 += sum[j];
       else
        sum2 = sum[j];
       if(sum2>max)
        max = sum2;
      }
     
     }
    
   }


cout<<max<<endl;

}
