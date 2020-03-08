#include <iostream>
using namespace std;

int main(){
int case_num;
cin>>case_num;
while(case_num--)
{
   int days;
   int k[20][20];
   cin>>days;
   int D[16];
   int density[22][22];
   int new_density[22][22];
   char result[20][20];
   for(int i=0;i<16;i++)
    cin>>D[i];
   for(int i=1;i<=20;i++)
    for(int j=1; j<=20; j++)
     cin>>density[i][j];
   for(int i=0;i<22;i++)
   {
    density[i][0]=0;
    density[i][21]=0;
   }
   for(int i=0;i<22;i++)
   {
    density[0][i]=0;
    density[21][i]=0;
   }
  
   while(days--){
    for(int i=1;i<=20;i++)
     for(int j=1; j<=20; j++)
     {
      k[i-1][j-1] = density[i][j]+density[i][j-1]+density[i][j+1]+density[i-1][j]+density[i+1][j];
      new_density[i][j] = density[i][j]+D[k[i-1][j-1]];//changed by D[k]
      if(new_density[i][j]>=3)//density cannot exceed 3 nor drop below 0
       new_density[i][j]=3;
      else if(new_density[i][j]<=0)
       new_density[i][j]=0;
     
     }
    for(int i=1;i<=20;i++)
     for(int j=1; j<=20; j++)
     {
      density[i][j]=new_density[i][j];
     
     }

   }
   for(int i=1;i<=20;i++)
    for(int j=1; j<=20; j++)
    {
     if(density[i][j]==0)
      result[i-1][j-1]='.';
     else if(density[i][j]==1)
      result[i-1][j-1]='!'; 
     else if(density[i][j]==2)
      result[i-1][j-1]='X';
     else if(density[i][j]==3)
      result[i-1][j-1]='#';
    }
   for(int i=0;i<20;i++)
    for(int j=0; j<20; j++)
    {
     if(j<19)
      cout<<result[i][j];
     else
      cout<<result[i][j]<<endl; 
    
    }
   if(case_num>0)  
    cout<<endl;  
}
}
