//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<values.h>
//#include<fstream.h>
//ifstream fin("in364.txt");
//ofstream fout("output.txt");
struct NodeType
{
   int l,p;
};
struct ArcType
{
   int c,f;
};
struct ArcType g[300][300];
bool mp[300][300];
struct NodeType lt[300];
int mpl[300][300];
int a[300],b[300];
bool used[300];
int m,n,s,t,nn,num,an,bn,k;
void insert(int a,int b)
{
   int cnow;
   g[a][b].c=1;
   mpl[a][0]++;
   cnow=mpl[a][0];
   mpl[a][cnow]=b;
   mpl[b][0]++;
   cnow=mpl[b][0];
   mpl[b][cnow]=a;   
}
void read_graph(void)
{
   int i,j,curn,a,b;
   memset(g,0,sizeof(g));
   memset(lt,0,sizeof(lt));
   memset(mpl,0,sizeof(mpl));
   cin>>bn;an=n;
   cin>>k;
   nn=an+bn+2;
   s=1;t=nn;
   for(i=1;i<=k;i++)
   {
      cin>>curn>>a>>b;
      insert(a+1,b+an+1);
   }
   for(i=1;i<=an;i++)
   {
      insert(1,i+1);
   }
   for(i=1;i<=bn;i++)
   {
      insert(an+i+1,nn);
   }
}
int check(void)
{
   int i;
   i=s;
   while(i<=nn&&(!((lt[i].l!=0)&&(lt[i].p==0))))
     i++;
   if(i>nn) return 0;
   else return i;
}
bool ford(int& a)
{
   int i,j,m,x,cur,k;
   bool result;
   result=true;
   memset(lt,0,sizeof(lt));
   lt[s].l=s;
   do
   {
      i=check();
      if(i==0)
      {
         return result;
      }
      cur=mpl[i][0];
      for(k=1;k<=cur;k++)
      {
         j=mpl[i][k];
         if(lt[j].l==0&&((g[i][j].c!=0)||(g[j][i].c!=0)))
         {
            if(g[i][j].f<g[i][j].c) lt[j].l=i;
            if(g[j][i].f>0) lt[j].l=-i;
         }
      }
      lt[i].p=1;
   }while(lt[t].l==0);
   m=t;a=MAXINT;
   do
   {
      j=m;m=abs(lt[j].l);
      if(lt[j].l<0) x=g[j][m].f-0;
      if(lt[j].l>0) x=g[m][j].c-g[m][j].f;
      if(a>x) a=x;
   }while(m!=s);
   return false;
}
void fulkerson(int a)
{
   int j,m;
   m=t;
   do
   {
      j=m;m=abs(lt[j].l);
      if(lt[j].l<0) g[j][m].f=g[j][m].f-a;
      if(lt[j].l>0) g[m][j].f=g[m][j].f+a;
   }while(m!=s);
}
void stream(void)
{
   int del,tot,i;
   bool success;
   do
   {
      success=ford(del);
      if(!success) fulkerson(del);
   }while(!success);
   tot=0;
   for(i=2;i<=an+1;i++)
   {
      if(g[1][i].f>0) tot++;
   }
   num=tot;
}
void case_solve(void)
{
   read_graph();
   stream();
}
int main(int argc, char* argv[])
{
   do
   {
      cin>>n;
      if(n==0) break;
      case_solve();
      cout<<num<<endl;
   }while(true);
   //cin.close();
   //cout.close();
   return 0;
}
//---------------------------------------------------------------------------

