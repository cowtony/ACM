//by dynamic 
//on tuesday august 6th 
#include <stdio.h> 
int main() 
{ 
        int n,i,j,t,min,a[60],c[60],p,p1; 
        char d; 
        bool flag[60],g[60][60],quit; 
        //freopen("test.in","r",stdin); 
        quit=false; 
        while(1) 
        { 
                n=p1=0; 
                for(i=0;i<=50;i++) a[i]=c[i]=0; 
                for(i=0;i<=50;i++) 
                        for(j=0;j<=50;j++) 
                                g[i][j]=false; 
                while(1) 
                { 
                        d=getchar(); 
                        if (d==-1){ 
                                quit=true; 
                                break; 
                        } 
                        if (d=='\n') break; 
                        if (d==' ') continue; 
                        if (d=='('){ 
                                scanf("%d",&t); 
                                a[p1]=t; 
                                p1++; 
                                n++; 
                                if (p1==1) continue; 
                                c[a[p1-2]]++; 
                                c[t]++; 
                                g[t][a[p1-2]]=true; 
                                g[a[p1-2]][t]=true; 
                                continue; 
                        } 
                        if (d==')') p1--; 
                } 
                for(i=1;i<=n;i++) flag[i]=false; 
                for(t=1;t<n;t++) 
                { 
                        min=100; 
                        for(i=1;i<=n;i++) 
                                if (c[i]==1&&!flag[i]&&i<min) min=i; 
                        flag[min]=true; 
                        for(i=1;i<=n;i++) 
                                if (!flag[i]&&g[min][i]) p=i; 
                        c[p]--; 
                        if (t==1) printf("%d",p); 
                        else printf(" %d",p); 
                } 
                if (quit){ 
                        //fclose(stdin); 
                        return 0; 
                } 
                printf("\n"); 
        } 
} 
【 在 zhonglei (radium) 的大作中提到: 】 
: 
: 【 在 dynamic (programming@math) 的大作中提到: 】 
: : 忘了 
: : 【 在 zhonglei (radium) 的大作中提到: 】 
: 我想看看你1097的输入 

  
  
-- 
有一条小路，穿过田野，通向新南盖特，我经常独自一人到那里去看落日，并想到自杀 
。然而，我终于不曾自杀，因为我想更多的了解数学。 
                                                         ——B.Russell 
  
