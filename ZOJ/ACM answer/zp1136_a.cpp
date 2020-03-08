//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include<iostream.h> 
#include<string.h> 
#include<stdlib.h> 
int dig[11],resu[5001]; 
typedef struct 
{ 
   short data[500]; 
   int deep; 
   int re; 
}node; 

node stack[10000]; 

int n,m; 

int cmp(const void *a,const void *b){ 
   int s=*(int*)a,t=*(int*)b; 
   return s-t; 
} 

int out(int index) 
{ 
   int i,dep; 
   dep=stack[index].deep; 
   for(i=0;i<dep;i++) 
      cout<<stack[index].data[i]; 
   cout<<endl; 
   return 0; 
} 

int BFS() 
{ 
   int fr,ar,res,dep,i,j,tmpre,flag; 
   ar=0; 
   fr=-1; 
   stack[0].data[0]=0; 
   stack[0].re=0; 
   stack[0].deep=0; 
   flag=0; 
   while(fr<ar) 
   { 
      fr++; 
      res=stack[fr].re; 
      dep=stack[fr].deep; 
      for(i=0;i<m;i++) 
      { 
         if(flag==0&&dig[i]==0) // 第一位数不能为0 
         { 
            flag=1; 
            continue; 
         } 
         tmpre=(res*10+dig[i])%n; 
         if (resu[tmpre]==1) continue; 
         resu[tmpre]=1; 
         ar++; 
         stack[ar].re=tmpre; 
         stack[ar].deep=dep+1; 
         for(j=0;j<dep;j++) 
            stack[ar].data[j]=stack[fr].data[j]; 
         stack[ar].data[dep]=dig[i]; 
         if(tmpre==0) return ar;       
      } 
   } 
   return -1; 
} 

int main() 
{ 
   int i,tmp; 
   while(cin>>n) 
   { 
      cin>>m; 
      i=0; 
      while(i<m) 
      { 
         cin>>dig[i]; 
         i++; 
      } 
      if(n==0) 
      { 
         cout<<"0"<<endl; 
         continue; 
      } 
      qsort(dig,m,sizeof(int),cmp); 
      memset(resu,0,sizeof(resu)); 
      tmp=BFS(); 
      if(tmp<0) cout<<"0"<<endl; 
      else out(tmp); 
   } 
   return 0; 
}
//---------------------------------------------------------------------------
 