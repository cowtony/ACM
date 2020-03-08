//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>


int tra(char ch)
{
  if (ch=='C')   return 0;
  if (ch=='D')   return 2;
  if (ch=='E')   return 4;
  if (ch=='F')   return 5;
  if (ch=='G')   return 7;
  if (ch=='A')   return 9;
  if (ch=='B')   return 11;
  return 0;
}
char trb(int c)
{
  if (c==0 || c==1)   return 'C';
  if (c==2 || c==3)   return 'D';
  if (c==4)           return 'E';
  if (c==5 || c==6)   return 'F';
  if (c==7 || c==8)   return 'G';
  if (c==9 || c==10)  return 'A';
  if (c==11)          return 'B';
  return 'C';
}
int main(int argc, char* argv[])
{
  int w[7]={0,2,4,5,7,9,11};
  char ch,ch2;
  int i,j,s,t,p[14],r[14];
  scanf("%c%c",&ch,&ch2);
  while (ch!='E' || ch2!='N')
  {
    for (i=0;i<13;i++)
      p[i]=0;
    i=tra(ch);
    if (ch2=='#')
      i++;
    p[i]=1;
    if (ch2!='\n')
    {

    scanf("%c",&ch);
    while (ch!='\n')
    {
      if (ch>='A' && ch<='G')
      {
        i=tra(ch);
      }
      else
      if (ch==' ')
        p[i]=1;
      else
      if (ch=='#')
        i++;
      scanf("%c",&ch);
    }
    p[i]=1;
    }

    s=0;
    for (i=0;i<12;i++)
    {
      t=1;
      for (j=0;j<7;j++)
        if (p[(i+w[j])%12])
          p[(i+w[j])%12]=-1;
      for (j=0;j<12;j++)
        if (p[j]>0)
          t=0;
        else
        if (p[j]<0)
          p[j]=1;
      if (t)
        r[s++]=i;
    }

    int v[12]={0,1,0,1,0,0,1,0,1,0,1,0};

    if (s>0)
    {
      printf("%c",trb(r[0]));
      if (v[r[0]])
        printf("#");
    }
    for (i=1;i<s;i++)
    {
      printf(" ");
      printf("%c",trb(r[i]));
      if (v[r[i]])
        printf("#");
    }
    printf("\n");

    scanf("%c%c",&ch,&ch2);
  }
  scanf("%c",&ch);
  return 0;
}
//---------------------------------------------------------------------------
