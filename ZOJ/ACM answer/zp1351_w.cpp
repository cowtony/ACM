//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
//Edit it by Carter W Cheng
#pragma argsused

#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>

//ifstream fin("problemc.in");
FILE *fin;
ofstream fout("output.txt");

const int mm=100;

char gs[mm],s[mm],outs[mm];
int num,b[26],cb[26],i,j,k;
bool b1,b2,b3,b4,b5,fir;

bool valid()
{
  int i;
  if (strlen(s)!=5) return false;
  for (i=0;i<5;i++) if (s[i]<'A' || s[i]>'Z') return false;
  return true;
}

int main(int argc, char* argv[])
{
   fin=fopen("problemc.in","r");
   b1=true;
   fir=true;
   do
   {
     //fin.getline(s,mm);
     fgets(s,mm,fin);
     k=strlen(s);
     s[k-1]=0;
     b2=strcmp(s,"LINGO");
     if (b2)
     {
       if (!strcmp(s,""))
       {
         b1=true;
         if (fir) fir=false; else
         if (num<6)
         {
           for (i=0;i<5;i++) fout<<char(gs[i]+32);
           fout<<endl;
         }
       }
       else if (b1)
       {
         //if (fir) fir=false; else fout<<endl;
         fout<<endl;
         strcpy(gs,s);
         memset(b,0,sizeof(int)*26);
         for (i=0;i<5;i++) b[s[i]-'A']++;
         b1=false;
         num=0;
         outs[0]=s[0];
         for (i=1;i<5;i++) outs[i]='.';
         outs[i]=0;
         fout<<outs<<endl;
       }
       else
       if (num<6 && num!=5000)
       {
         num++;
         k=strlen(s);
         if (valid())
         {
           b5=true;
           for (i=0;i<5;i++)
             if (s[i]==gs[i]) outs[i]=gs[i];
             else if (b[s[i]-'A'])
             {
               outs[i]=s[i]+32;
               b5=false;
             }
             else
             {
               outs[i]='.';
               b5=false;
             }
           if (num==6 && !b5)
           {
             for (i=0;i<5;i++) outs[i]=gs[i]+32;
           }
           else
           for (i=0;i<5;i++)
           if (outs[i]>='A' && outs[i]<='Z')
             for (j=0;j<5;j++)
               if (i!=j && outs[j]-32==outs[i]) outs[j]='.';
           outs[i]=0;
         }
         fout<<outs<<endl;
         if (b5) num=5000;
       }
     }
   } while (b2);
   //fin.close();
   fclose(fin);
   fout.close();
   return 0;
}
//---------------------------------------------------------------------------
