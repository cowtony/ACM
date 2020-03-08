//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

struct rgb
{
  int r,g,b;
};
struct rgb x,t[16];
int main(int argc, char* argv[])
{
  int i,v,d;
  for (i=0;i<16;i++)
    scanf("%d%d%d",&t[i].r,&t[i].g,&t[i].b);
  while (scanf("%d%d%d",&x.r,&x.g,&x.b) && x.r>=0)
  {
    v=0;i=0;
    d=(t[i].r-x.r)*(t[i].r-x.r)+
      (t[i].g-x.g)*(t[i].g-x.g)+
      (t[i].b-x.b)*(t[i].b-x.b);
    for (i=1;i<16;i++)
      if ((t[i].r-x.r)*(t[i].r-x.r)+
          (t[i].g-x.g)*(t[i].g-x.g)+
          (t[i].b-x.b)*(t[i].b-x.b)<d)
      {
        d=(t[i].r-x.r)*(t[i].r-x.r)+
          (t[i].g-x.g)*(t[i].g-x.g)+
          (t[i].b-x.b)*(t[i].b-x.b);
        v=i;
      }
    printf("(%d,%d,%d) maps to (%d,%d,%d)\n",
           x.r,x.g,x.b,t[v].r,t[v].g,t[v].b);
  }
  return 0;
}
//---------------------------------------------------------------------------
