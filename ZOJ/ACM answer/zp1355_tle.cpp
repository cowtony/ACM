//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;
ifstream fin("problemg.in");
ofstream fout("output.txt");
struct DicType
{
   char c;
   string d;
};
char instr1[300],instr2[300];
struct DicType dic[200];
struct DicType rdic[200];
int n,len1,len2,rn;
bool flag;
int finddic(char c)
{
   int i;
   for(i=1;i<=n;i++)
   {
      if(c==dic[i].c) return i;
   }
   return 0;
}
bool checks(string curstr)
{
   int i,len1,len2;
   char tmp[300];
   len1=curstr.length();
   for(i=1;i<=n;i++)
   {
      len2=dic[i].d.length();
      if(len1<len2)
      {
         dic[i].d.copy(tmp,len1,0);
         tmp[len1]='\0';
         if(tmp==curstr) return false;
      }else
      {
         curstr.copy(tmp,len2,0);
         tmp[len2]='\0';
         if(tmp==dic[i].d) return false;
      }
   }
   return true;
}
bool checkcur(string curstr,int cur)
{
   int pre;
   string tmp;
   pre=cur;tmp="";
   while(cur<len2&&cur-pre+1<=curstr.length())
   {
      tmp=tmp+instr2[cur];
      cur++;
   }
   if(tmp==curstr) return true;
   else return false;
}
bool checkafter(string curstr,int cur)
{
   int pre;
   string tmp;
   if(cur>=len2) return true;
   pre=cur;tmp="";
   while(cur<len2&&cur-pre+1<=curstr.length())
   {
      tmp=tmp+instr2[cur];
      cur++;
   }
   if(tmp==curstr) return false;
   else return true;
}
void dfs(int dep,int cur)
{
   int i,curp;
   string curstr;
   if(dep==len1&&cur==len2)
   {
      if(rn!=0)
      {
         flag=true;
         return;
      }
      for(i=1;i<=n;i++)
      {
         rdic[i].c=dic[i].c;
         rdic[i].d=dic[i].d;
      }
      rn=n;
      return;
   }
   if(cur>=len2) return;
   curp=finddic(instr1[dep]);
   if(curp==0)
   {
      curstr=instr2[cur];
      for(i=1;i<=n;i++)
      {
         if(!checkafter(dic[i].d,cur)) return;
      }
      do
      {
         if(checks(curstr))
         {
            n++;
            dic[n].c=instr1[dep];
            dic[n].d=curstr;
            dfs(dep+1,cur+1);
            if(flag) return;
            n--;
         }
         cur++;
         if(cur==len2) return;
         curstr=curstr+instr2[cur];
      }while(cur+len1-dep-2<len2);

   }else
   {
      if(checkcur(dic[curp].d,cur))
      {
         dfs(dep+1,cur+dic[curp].d.length());
         if(flag) return;
      }else return;
   }
}
void case_solve(void)
{
   int i;
   len1=strlen(instr1);
   len2=strlen(instr2);
   flag=false;
   n=0;rn=0;
   dfs(0,0);
}
void answer(void)
{
   int i,j;
   char tc;
   string tmp;
   if(flag)
   {
      fout<<"MULTIPLE TABLES"<<endl;
      return;
   }
   for(i=1;i<=rn-1;i++)
   {
      for(j=i+1;j<=rn;j++)
      {
         if(rdic[i].c>rdic[j].c)
         {
            tc=rdic[i].c;rdic[i].c=rdic[j].c;rdic[j].c=tc;
            tmp=rdic[i].d;rdic[i].d=rdic[j].d;rdic[j].d=tmp;
         }
      }
   }
   for(i=1;i<=rn;i++)
   {
      fout<<rdic[i].c<<" = "<<rdic[i].d<<endl;
   }
}
int main(int argc, char* argv[])
{
   int t,i;
   fin>>t;
   fin.getline(instr1,300);
   for(i=1;i<=t;i++)
   {
      fin.getline(instr1,300);
      fin.getline(instr2,300);
      fout<<"DATASET #"<<i<<endl;
      case_solve();
      answer();
   }
   fin.close();
   fout.close();
   return 0;
}
//---------------------------------------------------------------------------
 