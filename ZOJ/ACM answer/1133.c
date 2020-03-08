#include <stdio.h>
#include <math.h>
int main()
{
    long num;
    long i,j,temp1,temp2,m,n;
    long t,l;
    long ch,sh;
    int c;
    while(1)
    {
        scanf("%ld",&num);
        if(num==0) break;
        for(ch=num+1;;ch++)
        {
            c=1;
            for(i=2;i<=sqrt(ch);i++)
            {
                if(ch%i==0) {c=0;break;}
            }
            if(c==1) continue;
            sh=ch;
            temp1=0;
            t=1;
            for(j=0;sh/t!=0;j++)
            {
                t*=10;
                temp1+=(sh%t)*10/t;
            }
            temp2=0;
            sh=ch;
            m=2;
            for(i=0;m<=sqrt(sh);i++)
            {
                n=sh%m;
                if(n==0) 
                {
                    sh=sh/m;
                    l=1; 
                    for(j=0;m/l!=0;j++)
                     {
                          l*=10;
                          temp2+=(m%l)*10/l;
                    }
                    continue;
                }
                else m++;
            }
            l=1;
            for(j=0;sh/l!=0;j++)
            {
                 l*=10;
                 temp2+=(sh%l)*10/l;
            }
            if(temp2==temp1) {printf("%ld\n",ch);break;}
        }
    }
    return 0;
}
