#include <stdio.h>
#include <math.h>
int main()
{
    double result[50];
    float d[6],co,a,b,c;
    int i,j=0;
    while(1)
    {
        if(scanf("%f",&d[0])==EOF) break;
        for(i=1;i<6;i++)
        {
            scanf("%f",&d[i]);
        }
        a=(d[1]-d[3])*(d[1]-d[3])+(d[0]-d[2])*(d[0]-d[2]);
        b=(d[1]-d[5])*(d[1]-d[5])+(d[0]-d[4])*(d[0]-d[4]);
        c=(d[3]-d[5])*(d[3]-d[5])+(d[2]-d[4])*(d[2]-d[4]);
        co=(b+c-a)*(b+c-a)/(4.0*b*c);
        result[j++]=3.141592653589793*sqrt(a/(1.0-co));

    }
    for(i=0;i<j;i++)
        printf("%.2f\n",result[i]);
    return 0;
}
            

