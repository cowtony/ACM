//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>

int main(int argc, char* argv[])
{

  float mx,my,ax,ay,bx,by,x,y;
  int t;
  char ch;
  scanf("%f%f",&ax,&ay);
  while (1)
  {
    scanf("%f%f",&bx,&by);
    t=1;
    while (1)
    {
      if (scanf("%f%f%c",&x,&y,&ch)<0)
      {
        ch='#';
        break;
      }
      if (ch==' ')
      {
        ax=x;
        ay=y;
        break;
      }
      if (t && (bx-x)*(bx-x)+(by-y)*(by-y)
        >=4*(ax-x)*(ax-x)+4*(ay-y)*(ay-y))
      {
          t=0;
          mx=x;
          my=y;
      }
    }
    if (t)
      printf("The gopher cannot escape.\n");
    else
    {
      printf("The gopher can escape through");
      printf(" the hole at (%.3f,%.3f).\n",mx,my);
    }
    if (ch=='#')
      break;
  }
  return 0;
}
//---------------------------------------------------------------------------
