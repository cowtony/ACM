//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include<iostream>
#include<math.h>
//#include<fstream>
using namespace std;
//ifstream fin("pairs.in");
//ofstream fout("output.txt");
int num,tot,len,alen;
int numarr[2000];
int numa[20],numc[20];
int stk[20];
int numlen(int num)
{
   int ct;
   ct=0;
   if(num==0) return 1;
   while(num>0)
   {
      num=num/10;
      ct++;
   }
   return ct;
}
void putanswer(void)
{
   int a,b,i;
   a=0;b=0;
   if(numa[1]==0) return;
   for(i=1;i<=alen;i++)
   {
      a=a*10+numa[i];
   }
   for(i=1;i<=alen-1;i++)
   {
      b=b*10+numa[stk[i]];
   }
   if(num-a==b)
   {
      tot++;
      numarr[tot]=a;
   }
}
void dfs(int dep,int cur)
{
   int tmp;
   if(dep==alen)
   {
      putanswer();
      return;
   }
   if(numa[stk[dep]]==-1)
   {
      if(numc[cur]%2==0)
      {
         numa[stk[dep]]=numc[cur]/2;
         dfs(dep+1,cur+1);
         if((numc[cur]+10)/2<=9)
         {
            numa[stk[dep]]=(numc[cur]+10)/2;
            dfs(dep+1,cur+1);
         }
      }else
      {
         tmp=numc[cur]-1;
         if(tmp<0) tmp+=10;
         numa[stk[dep]]=tmp/2;
         dfs(dep+1,cur+1);
         if((tmp+10)/2<=9)
         {
            numa[stk[dep]]=(tmp+10)/2;
            dfs(dep+1,cur+1);
         }
      }
      numa[stk[dep]]=-1;
   }else
   {
      if(numc[cur]-numa[stk[dep]]>=0)
      {
         numa[dep+1]=numc[cur]-numa[stk[dep]];
      }else
      {
         numa[dep+1]=numc[cur]-numa[stk[dep]]+10;
      }
      dfs(dep+1,cur+1);
      tmp=numc[cur]-1;
      if(tmp<0) tmp+=10;
      if(tmp-numa[stk[dep]]>=0)
      {
         numa[dep+1]=tmp-numa[stk[dep]];
      }else
      {
         numa[dep+1]=tmp-numa[stk[dep]]+10;
      }
      dfs(dep+1,cur+1);
      numa[dep+1]=-1;
   }
}
void case_solve(void)
{
   int i,cur,j;
   len=numlen(num);
   cur=num;tot=0;
   for(i=len;i>=1;i--)
   {
      numc[i]=cur%10;
      cur=cur/10;
   }
   if(len>=2&&numc[1]==1&&numc[2]==0)
   {
      numa[1]=9;alen=len-1;
      for(i=1;i<=alen;i++)
      {
         for(j=2;j<=alen;j++)
         {
            numa[j]=-1;
         }
         cur=0;
         for(j=1;j<=alen;j++)
         {
            if(j!=i)
            {
               cur++;
               stk[cur]=j;
            }
         }
         dfs(1,3);
      }
   }
   alen=len;
   numa[1]=numc[1];
   for(i=1;i<=alen;i++)
   {
      for(j=2;j<=alen;j++)
      {
         numa[j]=-1;
      }
      cur=0;
      for(j=1;j<=alen;j++)
      {
         if(j!=i)
         {
            cur++;
            stk[cur]=j;
         }
      }
      dfs(1,2);
   }
   numa[1]=numc[1]-1;
   for(i=1;i<=alen;i++)
   {
      for(j=2;j<=alen;j++)
      {
         numa[j]=-1;
      }
      cur=0;
      for(j=1;j<=alen;j++)
      {
         if(j!=i)
         {
            cur++;
            stk[cur]=j;
         }
      }
      dfs(1,2);
   }
}
void answer(void)
{
   int i,len1,len2,j,tmp;
   for(i=1;i<=tot-1;i++)
   {
      for(j=i+1;j<=tot;j++)
      {
         if(numarr[i]>numarr[j])
         {
            tmp=numarr[i];numarr[i]=numarr[j];numarr[j]=tmp;
         }
      }
   }
   i=1;
   while(i<tot)
   {
      if(numarr[i]==numarr[i+1])
      {
         for(j=i;j<=tot-1;j++)
         {
            numarr[j]=numarr[j+1];
         }
         tot--;
      }else i++;
   }
   cout<<tot<<endl;
   for(i=1;i<=tot;i++)
   {
      cout<<numarr[i]<<" + ";
      len1=numlen(numarr[i]);
      len2=numlen(num-numarr[i]);
      for(j=len1-len2-1;j>=1;j--)
      {
         cout<<"0";
      }
      cout<<num-numarr[i];
      cout<<" = "<<num<<endl;
   }
}
int main(int argc, char* argv[])
{
   int N;
   cin>>N;
   for (int I=0;I<N;I++)
   {
      if (I) cout<<endl;
      cin>>num;
      case_solve();
      answer();
   }
   return 0;
}
//---------------------------------------------------------------------------
