//#include <iostream>
//using namespace std;
#include <stdio.h>
int c[21],r[21],final,n,f[21];
bool flag;
void Search(int sn,int I)
{
    if(flag==true)
    {
        return;
    }
    if(sn==n)
    {
        if(I>=final)
        {
            flag=true;
        }
        return;
    }
    int i;
    for(i=1;i<n;++i)
    {
        if(f[i]==1)
        {
            if(I>=c[i])
            {
                f[i]=0;
                Search(sn+1,(I-c[i]+r[i])<=100?(I-c[i]+r[i]):100);
                f[i]=1;
            }
        }
    }
}
int main()
{
    int i,j,temp;
    while(scanf("%d",&n)!=EOF)
    {
        int t=0,sumc=0,sumr=100;
        for(i=1;i<n;++i)
        {
            scanf("%d%d",c+i,r+i);
            f[i]=1;
            if(c[i]>100)
                t=1;
            sumc+=c[i];
            sumr+=r[i];
        }
        scanf("%d",&final);
        sumc+=final;
        flag=false;
        if(!t && sumc<=sumr)
        {
            for(i=1;i<n;++i)
            {
                for(j=1;j+1<n;++j)
                {
                    if(r[j]<r[j+1])
                    {
                        temp=r[j];
                        r[j]=r[j+1];
                        r[j+1]=temp;
                        temp=c[j];
                        c[j]=c[j+1];
                        c[j+1]=temp;
                    }
                }
            }
            Search(1,100);
        }
        if(flag==false)
          printf("try again\n");
        else
          printf("clear!!!\n");
    }
    return 0;
}
