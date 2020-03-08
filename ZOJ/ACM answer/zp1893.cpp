#include <stdio.h>

int main(int argc, char* argv[])
{
  long long n;
  while (scanf("%Ld",&n)>0)
  {
    while (n>18)
    {
      n--;
      n/=18;
      n++;
    }
    if (n>9)
      printf("Ollie wins.\n");
    else
      printf("Stan wins.\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
