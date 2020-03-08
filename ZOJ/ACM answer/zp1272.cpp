#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
//   FILE *in=fopen("input.txt","r");
//   FILE *out=fopen("output.txt","w");

  char st[40];
  int ln,i,j,s,p,dl,cl,
      a[40],c[40],d[40],b[40];
  while (scanf("%s",st) && st[0]!='*')
  {
    ln=strlen(st);
    if (st[0]>='0' && st[0]<='9')
    {
      for (i=0;i<ln;i++)
        a[i]=st[ln-i-1]-'0';
      s=0;
      p=ln;
      while (ln>1)
      {

        a[0]--;
        for (i=0;i<ln;i++)
          if (a[i]<0)
          {
            a[i]=9;
            a[i+1]--;
          }
          else
            break;
        if (a[ln-1]==0)
          ln--;

        for (i=ln-1;i>0;i--)
        {
          a[i-1]+=(a[i]%26)*10;
          a[i]/=26;
          if (a[i]==0 && i==ln-1)
            ln--;
        }
        b[s++]=a[0]%26;
        a[0]/=26;
      }
      if (a[0])
        b[s++]=a[0]-1;

      for (i=s-1;i>=0;i--)
        printf("%c",b[i]+'a');
      for (i=0;i<22-s;i++)
        printf(" ");
      for (i=0;i<p;i++)
        if ((i-p%3)%3==0 && i)
          printf(",%c",st[i]);
        else
          printf("%c",st[i]);
      printf("\n");
    }
    else
    {
      for (i=0;i<32;i++)
      {
        c[i]=0;
        d[i]=0;
      }

      dl=1;
      d[0]=1;
      cl=1;
      c[0]=st[ln-1]-'a'+1;
       for (i=0;i<cl;i++)
          if (c[i]>9)
          {
            c[i+1]+=c[i]/10;
            c[i]%=10;
            if (i==cl-1) cl++;
          }

      for (j=ln-2;j>=0;j--)
      {
        for (i=0;i<dl;i++)
          d[i]*=26;
        for (i=0;i<dl;i++)
          if (d[i]>9)
          {
            d[i+1]+=d[i]/10;
            d[i]%=10;
            if (i==dl-1) dl++;
          }
        for (i=0;i<dl;i++)
          c[i]+=(st[j]-'a'+1)*d[i];
        if (dl>cl)
          cl=dl;
        for (i=0;i<cl;i++)
          if (c[i]>9)
          {
            c[i+1]+=c[i]/10;
            c[i]%=10;
            if (i==cl-1) cl++;
          }
      }
      printf("%s",st);
      for (i=0;i<22-ln;i++)
        printf(" ");

      for (i=cl-1;i>=0;i--)
        if ((cl-1-i-cl%3)%3==0 && cl-1-i)
          printf(",%d",c[i]);
        else
          printf("%d",c[i]);
      printf("\n");
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
