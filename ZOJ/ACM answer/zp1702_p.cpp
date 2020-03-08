//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <iostream.h>
#include <string.h>
#include <fstream.h>

ifstream fin("d:\in1702.txt");
//ofstream fout("output.txt");
#define fout cout
const int mm=80;
const int mx=25;
const int ms=100;

char oper[mm],item[mx][mm][mm],s[ms];
int colmax[mm],len[mx][mm],m,i,j,k,li,sl,c;
bool b1,b2,b3,b4;

void print(int x,int y)
{
   int i,j,k;
   if (x==1) fout<<"@-";
   else if (x==2) fout<<"|-";
   else fout<<"| ";
   for (i=0;i<m;i++)
   {
     if (i>0)
     {
       if (x==1) fout<<"---";
       else if (x==2) fout<<"-+-";
       else fout<<" | ";
     }
     if (x<3)
     {
       for (j=0;j<colmax[i];j++) fout<<'-';
     }
     else
     {
       if (oper[i]=='<')
       {
         fout<<item[y][i];
         k=colmax[i]-len[y][i];
         for (j=0;j<k;j++) fout<<' ';
       }
       else if (oper[i]=='=')
       {
         k=(colmax[i]-len[y][i])/2;
         for (j=0;j<k;j++) fout<<' ';
         fout<<item[y][i];
         k=colmax[i]-len[y][i]-k;
         for (j=0;j<k;j++) fout<<' ';
       }
       else if (oper[i]=='>')
       {
         k=colmax[i]-len[y][i];
         for (j=0;j<k;j++) fout<<' ';
         fout<<item[y][i];
       }
     }
   }
   if (x==1) fout<<"-@\n";
   else if (x==2) fout<<"-|\n";
   else fout<<" |\n";
}

int main(int argc, char* argv[])
{
   b1=true;
   do
   {
      if (b1)
      {
         fin.getline(s,ms);
         b1=false;
      }
      li=0;
      strcpy(oper,s);
      m=strlen(oper);
      memset(colmax,0,sizeof(int)*mm);
      do
      {
        fin.getline(s,ms);
        b2=(s[0]!='<' && s[0]!='=' && s[0]!='>' && s[0]!='*');
        if (b2)
        {
            //readit
            j=0;
            sl=strlen(s);
            c=0;
            for (i=0;i<sl;i++)
              if (s[i]=='&')
              {
                for (k=j;k<i;k++) item[li][c][k-j]=s[k];
                item[li][c][k-j]=0;
                len[li][c]=strlen(item[li][c]);
                if (len[li][c]>colmax[c]) colmax[c]=len[li][c];
                j=i+1;
                c++;
              }
            for (k=j;k<i;k++) item[li][c][k-j]=s[k];
            item[li][c][k-j]=0;
            len[li][c]=strlen(item[li][c]);
            if (len[li][c]>colmax[c]) colmax[c]=len[li][c];
            c++;
            li++;
        }
        else
        {
            //print
            print(1,0);
            print(3,0);
            print(2,0);
            for (i=1;i<li;i++) print(3,i);
            print(1,0);
        }
      } while (b2);
   } while (strcmp(s,"*"));
   return 0;
}
//---------------------------------------------------------------------------
