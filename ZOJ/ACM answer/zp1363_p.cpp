#include<iostream.h>
#include<stdio.h>
main()
{
  double last[110],next[110];
  double result;
  int c,n,m,i,j;
  while(cin>>c>>n>>m)
  {
    if((n==0)&&(m==0)) result=1;
    else if((m>c)||(m>n)||((n-m)%2!=0)) result=0;
    else
    {
      for(i=0;i<=c;i++)
      {
        last[i]=0;
        next[i]=0;
      }
      if(n>c*5) n=c*5;
      if((n-m)%2!=0) n++;
      if(m%2==1)
      {
        last[1]=1;
        for(i=3;i<=n;i=i+2)
        {
          if(i<=c)
          {
            for(j=1;j<i;j=j+2)
            {
              {
                next[j]+=last[j]*(double)(j*j*(-2)+2*c*j+c)/(c*c);
                if(j>1) next[j-2]+=last[j]*(double)(j*j-j)/(c*c);
                if(j<(c-1)) next[j+2]+=last[j]*(double)(c-j)*(c-j-1)/(c*c);
              }
            }
            for(j=1;j<=i+2;j=j+2)
            {
              last[j]=next[j];
              next[j]=0;
            }
          }
          else
          {
            for(j=1;j<=c;j=j+2)
            {
              next[j]+=last[j]*(double)(j*j*(-2)+2*c*j+c)/(c*c);
              if(j>1) next[j-2]+=last[j]*(double)(j*j-j)/(c*c);
              if(j<(c-1)) next[j+2]+=last[j]*(double)(c-j)*(c-j-1)/(c*c);
            }
            for(j=1;j<=c+2;j=j+2)
            {
              last[j]=next[j];
              next[j]=0;
            }
          }
        }
      }
      else
      {
        last[0]=(double)1.0/c;
        last[2]=(double)(c-1)/c;
        for(i=4;i<=n;i=i+2)
        {
          if(i<=c)
          {
            for(j=0;j<i;j=j+2)
            {
              next[j]+=last[j]*(double)(j*j*(-2)+2*c*j+c)/(c*c);
              if(j>1) next[j-2]+=last[j]*(double)(j*j-j)/(c*c);
              if(j<(c-1)) next[j+2]+=last[j]*(double)(c-j)*(c-j-1)/(c*c);
            }
            for(j=0;j<=i+2;j=j+2)
            {
              last[j]=next[j];
              next[j]=0;
            }
          }
          else
          {
            for(j=0;j<=c;j=j+2)
            {
              next[j]+=last[j]*(double)(j*j*(-2)+2*c*j+c)/(c*c);
              if(j>1) next[j-2]+=last[j]*(double)(j*j-j)/(c*c);
              if(j<(c-1)) next[j+2]+=last[j]*(double)(c-j)*(c-j-1)/(c*c);
            }
            for(j=0;j<=c+2;j=j+2)
            {
              last[j]=next[j];
              next[j]=0;
            }
          }
        }
      }
      result=last[m];
    }
  printf("%.3f\n",result);
  }
}
