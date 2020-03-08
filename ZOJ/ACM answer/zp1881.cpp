#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int n,s,i,ram[1000]={0},res[10]={0};

  char st[4];


  while (gets(st)>0)
  {
    memset(ram,0,sizeof(ram));
    memset(res,0,sizeof(res));
    n=0;
    ram[n++]=(st[0]-'0')*100+(st[1]-'0')*10+st[2]-'0';
    while (gets(st) && st[0]!='\0')
      ram[n++]=(st[0]-'0')*100+(st[1]-'0')*10+st[2]-'0';

  i=0;
  s=0;
  while (1)
  {
    s++;
    switch (ram[i]/100)
    {
      case 0:
        if (res[ram[i]%10])
          i=res[ram[i]%100/10]-1;
        break;
      case 1:
        break;
      case 2:
        res[ram[i]%100/10]=ram[i]%10;
        res[ram[i]%100/10]%=1000;
        break;
      case 3:
        res[ram[i]%100/10]+=ram[i]%10;
        res[ram[i]%100/10]%=1000;
        break;
      case 4:
        res[ram[i]%100/10]*=ram[i]%10;
        res[ram[i]%100/10]%=1000;
        break;
      case 5:
        res[ram[i]%100/10]=res[ram[i]%10];
        res[ram[i]%100/10]%=1000;
        break;
      case 6:
        res[ram[i]%100/10]+=res[ram[i]%10];
        res[ram[i]%100/10]%=1000;
        break;
      case 7:
        res[ram[i]%100/10]*=res[ram[i]%10];
        res[ram[i]%100/10]%=1000;
        break;
      case 8:
        res[ram[i]%100/10]=ram[res[ram[i]%10]];
        res[ram[i]%100/10]%=1000;
        break;
      case 9:
        ram[res[ram[i]%10]]=res[ram[i]%100/10];
        ram[res[ram[i]%10]]%=1000;
        break;
    }
    if (ram[i]==100)
      break;
    i++;
  }
  printf("%d\n",s);
  }
  return 0;

}

