//广度搜索题


#include <stdio.h>
#include <string.h>

int si,sj,ei,ej;
int dirud[8]={-2,-1,1,2,2,1,-1,-2}; //八个方向
int dirlr[8]={1,2,2,1,-1,-2,-2,-1};
bool visited[8][8];           //表示棋盘的某个位置是否遍历过
int answer;

struct Node
{
 int x;
 int y;
 int depth;
};

void bfs()              //树式广度搜索
{
 int i,x,y;
 Node list[65];      
 int open=1;         //已搜索的节点数
 int closed=0;       //待搜索的节点
 bool escape=false;
 list[1].x=si;
 list[1].y=sj;
 list[1].depth=0;    //节点深度

 if(si==ei && sj==ej)
  return;

 while(closed<open && !escape)
 {
  closed++;
  for(i=0;i<8;i++)
  {
   if((x=(list[closed].x+dirud[i]))>=0 && x<8
    && (y=(list[closed].y+dirlr[i]))>=0 && y<8
    && !visited[x][y])
   {
    if(x==ei && y==ej)
    {
     escape=true;
     break;
    }    
    open++;
    visited[x][y]=true;
    list[open].x=x;
    list[open].y=y;
    list[open].depth=list[closed].depth+1;

   }
  }
 }
 answer=list[closed].depth+1;
}

int main()
{
 int i,j;
 char s[3],e[3];

 while(scanf("%s%s",&s,&e)!=EOF)
 {
  si=s[0]-'a';
  sj=s[1]-'1';
  ei=e[0]-'a';
  ej=e[1]-'1';

  for(i=0;i<8;i++)
  {
   for(j=0;j<8;j++)
    visited[i][j]=false;
  }

  visited[si][sj]=true;
  answer=0;
  bfs();

  printf("To get from %s to %s takes %d knight moves.\n",s,e,answer);
 }

 return 0;
}