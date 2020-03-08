//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>

int valueit(int a[],int t[],int r[])
{
  r[0]=a[0];
  t[0]=1;
  int i,j,m,n=1;
  for (i=1;i<5;i++)
  {
    if (a[i]!=r[n-1])
    {
      t[n]=1;
      r[n++]=a[i];
    }
    else
      t[n-1]++;
  }
  for (i=0;i<n-1;i++)
    for (j=i+1;j<n;j++)
      if (t[i]<t[j])
      {
        m=t[i];t[i]=t[j];t[j]=m;
        m=r[i];r[i]=r[j];r[j]=m;
      }
  return n;
}
void sortit(int a[])
{
  for (int i=0;i<4;i++)
    for (int j=i+1;j<5;j++)
      if (a[i]<a[j])
      {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
      }
}

int calit(int a[])
{
  if (a[0]/100==a[4]/100 && a[0]-a[4]==4)
    return 80000000+a[0]%100;

  int p[5],t[5],r[5];

  for (int i=0;i<5;i++)
    p[i]=a[i]%100;

  sortit(p);
  int n=valueit(p,t,r);

  if (n==2)
    if (t[0]==4)
      return 70000000+r[0];
    else
      return 60000000+r[0];

  if (a[0]/100==a[4]/100)
    return 50000000+
           p[0]*160000+p[1]*8000+p[2]*400+p[3]*20+p[4];

  if (p[0]-p[1]==1 && p[1]-p[2]==1
   && p[2]-p[3]==1 && p[3]-p[4]==1)
    return 40000000+p[0];

  if (n==3)
    if (t[0]==3)
      return 30000000+r[0];
    else
      return 20000000+r[0]*400+r[1]*20+r[2];
  if (n==4)
    return 10000000+r[0]*8000+r[1]*400+r[2]*20+r[3];

  return p[0]*160000+p[1]*8000+p[2]*400+p[3]*20+p[4];
}
int transvalue(char ch)
{
  switch (ch)
  {
    case 'T': return 10;
    case 'J': return 11;
    case 'Q': return 12;
    case 'K': return 13;
    case 'A': return 14;
    default : return ch-'0';
  }
}
int transsuit(char ch)
{
  switch (ch)
  {
    case 'C': return 0;
    case 'D': return 1;
    case 'H': return 2;
    case 'S': return 3;
  }
  return 0;
}
int input(int a[],int b[])
{
  char st[3];
  if (scanf("%s",st)==EOF)
    return 0;
  for (int i=0;i<5;i++)
  {
    a[i]=transvalue(st[0]);
    a[i]+=100*transsuit(st[1]);
    scanf("%s",st);
  }
  for (int i=0;i<5;i++)
  {
    b[i]=transvalue(st[0]);
    b[i]+=100*transsuit(st[1]);
    if (i<4) scanf("%s",st);
  }
  return 1;
}
int main(int argc, char* argv[])
{
  int valuebl,valuewh,black[5],white[5];
  while (input(black,white))
  {
    sortit(black);
    sortit(white);

    valuebl=calit(black);
    valuewh=calit(white);

    if (valuebl>valuewh)
      printf("Black wins.\n");
    else
    if (valuebl<valuewh)
      printf("White wins.\n");
    else
      printf("Tie.\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
