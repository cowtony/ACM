#include <iostream>
using namespace std;

int main(){
int array[5000][2];
int cases;
cin>>cases;
while(cases--)
{
   int N;
   cin>>N;
   for(int i=0;i<N;i++)
    cin>>array[i][0]>>array[i][1];
   for(int i=0;i<N-1;i++)
   {
    int min=i;
    for(int j=i+1;j<N;j++)
     if(array[min][0]>array[j][0])
      min = j;
    int tmp = array[min][0];
    array[min][0] = array[i][0];
    array[i][0] = tmp;
    tmp = array[min][1];
    array[min][1] = array[i][1];
    array[i][1] = tmp;
   }
   for(int i=0;i<N-1;i++)
    if(array[i][0]==array[i+1][0])
     if(array[i][1]>array[i+1][1])
     {
      int tmp = array[i][1];
      array[i][1] = array[i+1][1];
      array[i+1][1] = tmp;
     }
   int sum = 0;
   int count = -1;
   while(count)
   {
       sum++;
       count=0;
       int s=0;
                     for(int i=1;i<N;i++)
                     {
                            if(array[s][1]<=array[i][1])
                            {
                                   array[s][1]=0;
                                   s=i;
                            }
                            else
                                   count++;
                     }
                     array[s][1]=0;
       int t=0;
                     for(int i=0;i<N;i++)
                            if(array[i][1])
                            {
                                   array[t][0]=array[i][0];
                                   array[t][1]=array[i][1];
                                   t++;
                            }
                     N=count;
   
   }
   cout<<sum<<endl;
}
}

