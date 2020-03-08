#include <stdio.h>
#include <string.h>
int main()
{
    char a[101][7];
    char b[10000][7];
    char d[101][7];
    char p[7];
    int c[7];
    int i,j,k,dw,sw,l,t,m,n;
    for(i=0;;i++)
    {
        gets(a[i]);
        if(strcmp(a[i],"XXXXXX")==0) {dw=i;break;}
    }
    for(j=0;;j++)
    {
        gets(b[j]);
        if(strcmp(b[j],"XXXXXX")==0) {sw=j;break;}
    }
    for(i=0;i<sw;i++)
    {
        l=0;
        for(j=0;j<dw;j++)
        {
            t=0;
            if(strlen(b[i])==strlen(a[j]))
            {
                for(k=0;k<strlen(b[i]);k++)
                {
                    c[k]=0;
                }
                for(m=0;m<strlen(b[i]);m++)
                {
                    for(n=0;n<strlen(a[j]);n++)
                    {
                        if(a[j][n]==b[i][m]&&c[n]==0) {c[n]=1;t++;break;}
                    }
                    if(t==0) break;
                }
                if(t==strlen(b[i])) {strcpy(d[l],a[j]);l++;}
            }
        }
        if(l==0) printf("NOT A VALID WORD\n");
        else
        {
            for(j=0;j<l-1;j++)
            {
                for(k=j+1;k<l;k++)
                {
                    if(strcmp(d[j],d[k])>0) {strcpy(p,d[j]);strcpy(d[j],d[k]);strcpy(d[k],p);}
                }
            }
            for(j=0;j<l;j++)
            {
                puts(d[j]);
            }
        }
        printf("******\n");
    }
    return 0;
}
