//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <math.h>
#include <iostream.h>

struct btr
{
  int nm;
  struct btr* l;
  struct btr* r;
};
struct btr* rt;
int k,m,h,w,mh,mw,a[260];

void crt(int x,struct btr* c)
{
  c->nm=a[x];
  if (x<m)
  {
    c->r=new(struct btr);
    c->l=new(struct btr);
    if (a[x]==a[x*2])
    {
      crt(x*2,c->l);
      crt(x*2+1,c->r);
    }
    else
    {
      crt(x*2+1,c->l);
      crt(x*2,c->r);
    }
  }
  else
  {
    c->l=NULL;
    c->r=NULL;
  }
}
void fdh(struct btr* c)
{
  if (c->nm==k)
  {
    mh=h;
    mw=w;
    return;
  }
  else
  {
    w++;
    h++;
    if (c->r)
      fdh(c->r);
    h--;
    if (c->l)
      fdh(c->l);
    w--;
  }
}

int main(int argc, char* argv[])
{
  int cs,n,i,N,I;
  cs=0;
  cin>>n;
  while (n)
  {
    if (cs)   cout<<endl;
    else      cs=1;

    m=pow(2,n);
    for (i=m-1;i>=1;i--)
      cin>>a[i];
    for (i=m;i<m*2;i++)
      a[i]=m*2-i;

    rt=new(struct btr);
    rt->r=NULL;
    rt->l=NULL;

    crt(1,rt);

    cin>>N;
    for (I=0;I<N;I++)
    {
      cin>>k;
      cout<<"Player "<<k<<" can be ranked as high as ";
      h=1; w=0;
      fdh(rt);
      w=n-mw;
      w=pow(2,w);
      w=m-w+1;

      cout<<mh<<" or as low as "<<w;
      cout<<"."<<endl;
    }
    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
