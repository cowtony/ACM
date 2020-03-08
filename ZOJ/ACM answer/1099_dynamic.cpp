发信人: dynamic (programming@math), 信区: ACMICPC 
标  题: Re: 实在不想改1099了，麻烦过了的弟兄贴来看看吧 
发信站: 逸仙时空 Yat-sen Channel (Wed Mar 12 17:11:32 2003), 站内信件 
  
#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
        int pos=0,i,n; 
        char s[90],c; 
        while(1){ 
                n=0; 
                while(1){ 
                        c=getchar(); 
                        if (c==' '||c=='\t'||c=='\n'||c==EOF) break; 
                        s[n++]=c; 
                } 
                s[n]=0; 
                if (n==0){ 
                        if (c==EOF){ 
                                printf("\n"); 
                                break; 
                        } 
                        continue; 
                } 
                if (strcmp(s,"<br>")==0){ 
                        printf("\n"); 
                        pos=0; 
                        if (c==EOF){ 
                                printf("\n"); 
                                break; 
                        } 
                        continue; 
                }else if (strcmp(s,"<hr>")==0){ 
                        if (pos!=0) printf("\n"); 
                        for(i=0;i<80;i++) printf("-"); 
                        printf("\n"); 
                        pos=0; 
                        if (c==EOF){ 
                                printf("\n"); 
                                break; 
                        } 
                        continue; 
                } 
                if (n+1+pos>80){ 
                        printf("\n%s",s); 
                        pos=n; 
                }else{ 
                        if (pos!=0){ 
                                printf(" %s",s); 
                                pos+=n+1; 
                        }else{ 
                                printf("%s",s); 
                                pos=n; 
                        } 
                } 
                if (c==EOF){ 
                        printf("\n"); 
                        break; 
                } 
        } 
        return 0; 
} 
【 在 zhonglei (radium) 的大作中提到: 】 
: ft字符题 

  
  
-- 
有一条小路，穿过田野，通向新南盖特，我经常独自一人到那里去看落日，并想到自杀 
。然而，我终于不曾自杀，因为我想更多的了解数学。 
                                                         ——B.Russell 
  
