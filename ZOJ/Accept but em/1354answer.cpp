#include<iostream>   
using namespace std;

void   process();//求解的过程   
void   press(int,int);//处理按键的过程   
void   output();//输出结果

int   lights[5][6];//记录灯状态，0灭，1亮   
int   ans[5][6];//记录结果，若在x行y列点击，ans[x-1][y-1]=1  

int   main()
{     //主函数   
 int   n;           
 cin>>n;   
 for(int   i=1;i<=n;i++)
 {   
  cout<<   "PUZZLE #"   <<i<<endl;   
  process();   //整个求解过程   
 }   
}  

void   press(int   x,int   y)   
{//处理按键的过程   
 ans[x][y]=1;//记录操作   
 lights[x][y]=1-lights[x][y];   
 if(x>0)
  lights[x-1][y]=1-lights[x-1][y];   
 if(y>0)
  lights[x][y-1]=1-lights[x][y-1];   
 if(x<4)
  lights[x+1][y]=1-lights[x+1][y];   
 if(y<5)
  lights[x][y+1]=1-lights[x][y+1];   
}  

void   process()
{   
 int   x,y,z,temp[5][6];   
 for(x=0;x<5;x++)   
  for(y=0;y<6;y++)
   cin>>temp[x][y];   


 for(z=0;z<64;z++)
 {//外循环,枚举64个状态

  memcpy(lights,temp,sizeof(lights));   
  memset(ans,0,sizeof(ans));//初始化  
  
  for(y=0;y<6;y++)   
   if(z   &   (1<<y))/*如果z右起第y个bit位是‘1’则在第1行y列点击*/  
    press(0,y);//枚举第一行的64种操作。
  
  
    
  
  for(x=1;x<5;x++)   
   for(y=0;y<6;y++)   
    if(lights[x-1][y]==1)
     press(x,y);/*就是刚才所说的规则*/  

 

  for(y=0;y<6;y++)
   if(lights[4][y]==1)
    break;   //判断最后一行是否全灭

  if(y>=6)
  {    
   output();
   break;  
  }   //是,输出结果，结束搜索   
 }   
}   
void   output()
{   
 int   x,y;   
 for(x=0;x<5;x++)
 {   
  cout<<ans[x][0];   
  for(y=1;y<6;y++)
   cout<<" "<<ans[x][y];   
  cout<<endl;   
 }   
}