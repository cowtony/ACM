#include <iostream>
using namespace std;

int main() 
{ 
       int weight[1000],speed[1000],index[1000]; 
       int k=0;
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF) 
       { 
     weight[k] = a;
     speed[k] = b;
     index[k]=k; 
              k++; 
       } 
       for(int i=0;i<k;i++) 
              for(int j=i+1;j<k;j++) 
                     if(weight[i]>weight[j]) //∞¥’’weight≈≈–Ú
                     { 
                            int tmp=weight[i]; 
                            weight[i]=weight[j]; 
                            weight[j]=tmp; 
                            tmp=index[i]; 
                            index[i]=index[j]; 
                            index[j]=tmp; 
                            tmp=speed[i]; 
                            speed[i]=speed[j]; 
                            speed[j]=tmp; 
                     } 
       int way[1000];
    way[0]=-1;
    int len[1000];
       len[0]=1; 
       for(int i=1;i<k;i++) 
       { 
              len[i]=1; 
              way[i]=-1; 
     int tmp;
              for(int j=0;j<i;j++) 
                     if((speed[j]>speed[i])&&(weight[j]<weight[i])) 
                            if((tmp=len[j]+1)>len[i]) 
                            { 
                                   len[i]=tmp; 
                                   way[i]=j; 
                            } 
       } 
       int max=-1; 
    int p;
       for(int i=0;i<k;i++) 
              if(len[i]>max) 
              { 
                     max=len[i]; 
                     p=i; 
              } 
       cout<<max<<endl;
    int count=0;
    int w[1000];
    
       while(p>=0)
       { 
              w[count++]=p; 
              p=way[p]; 
       } 
       for(int i=count-1;i>=0;i--) 
     cout<<index[w[i]]+1<<endl;
      
}
