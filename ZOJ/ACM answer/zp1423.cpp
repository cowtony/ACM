#include <stdio.h>

int main(int argc, char* argv[])
{
  int N,I,ln,i,t,s,j,p[300];
  char ch,st[300];
  scanf("%d%c",&N,&ch);
  for (I=0;I<N;I++)
  {
    ln=0;
    while (scanf("%c",&ch) && ch!='\n')
      if (ch!=' ')
        st[ln++]=ch;
    for (i=0;i<ln;i++)
      p[i]=0;
    for (i=0;i<ln;i++)
      if (st[i]=='-')
        if (st[i+1]=='(')
          if (st[i+2]!=')')
          {
            j=i+3;
            t=0;
            s=0;
            if (st[i+2]<='Z' && st[i+2]>='A')
              s++;
            if (st[i+2]=='(')
              t++;
            while (!(st[j]==')' && j<ln && t==0))
            {
              if (st[j]<='Z' && st[j]>='A')
                s++;
              if (st[j]=='(')
                t++;
              if (st[j]==')')
                t--;
              j++;
            }
            if (s>1)
            {
              p[i+1]=1;
              p[j]=1;
            }
          }
    for (i=0;i<ln;i++)
      if (st[i]=='(' || st[i]==')')
      {
        if (p[i])
          printf("%c",st[i]);
      }
      else
        printf("%c",st[i]);
    printf("\n");

  }
  return 0;
}
//---------------------------------------------------------------------------
