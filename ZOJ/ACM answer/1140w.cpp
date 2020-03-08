#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;


int m,n;
int path[301][301];

bool chk[301];
int yM[301];
int xM[301];
bool  SearchPath( int  u)
  {
     int  v;
     for  (v = 0 ; v < n; v ++ )
      {
         if  (path[u][v]&&!chk[v])
          {
            chk[v]  =   true ;
             if  (yM[v]==- 1||SearchPath(yM[v])) 
              {
                yM[v]  =  u;
                return   true ;
            } 
        } 
    } 
     return   false ;
} 
 
 
 int  MaxMatch()
  {
     int  u;
     int  ret  =   0 ;
     
     memset(yM, - 1 ,  sizeof (yM));
       for  (u = 0 ; u < m; u ++ )
      {
          memset(chk,  false ,  sizeof (chk));
          if  (SearchPath(u)) ret ++ ;
      } 
     return  ret;
} 


int main()
{
  int t,i,j,stun,num;
  scanf("%d",&t);

  while(t--)
  {
    scanf("%d %d",&m,&n);
	  for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	    path[i][j]=0;
	    
	      for(i=0;i<m;i++)
	     {
		   scanf("%d",&stun);
		    for(j=0;j<stun;j++)
		  {
		  scanf("%d",&num);
		  path[i][num-1]=1;
		  }
	    }
	    
	    int result=MaxMatch();
	   // printf("%d\n",result);
	    
	   // for(i=0;i<n;i++)
	    //printf("%d  ",yM[i]);
      if(result==m)
      printf("YES\n");
      else
      printf("NO\n");
  }
 return 0;
}
