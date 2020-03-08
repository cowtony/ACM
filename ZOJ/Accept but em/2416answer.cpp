#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int n, b[10000], pi, si;
string s, p;
queue <string> sq, tq;

void init();   //初始化
int stoi(string);   //字符串转化为整数
void bfs();   //广度搜索
void print();   //打印结果

int main()
{
 //freopen("in.txt", "r", stdin);  //从固定文件中读入输入数据
 cin >> n;  
 int i;
 for(i = 0; i < n; i ++)
 {
  cin >> s >> p;
  init();
  bfs();
  print();
 } 
 return 0;
}

void init()
{
 pi = stoi(p);
 si = stoi(s);
 memset(b, 0, sizeof(b));
 b[si] = 1;
 sq = tq;   //tq的作用就是用来初始化sq!!!!!!!!
 sq.push(s);  //s入列
}

int stoi(string str)
{
 int sum = 0, i;
 for(i = 0; i < 4; i ++)
 {
  sum *= 10;
  sum += str[i] - '0';
 }
 return sum;
}

void bfs()
{
 string ts, ss;
 int ti, ii, l, i;
 while(!sq.empty())//判队列是否空
 {
  ts = sq.front();
  ti = stoi(ts);
  l = b[ti];
  if(ti == pi) //判是否找到
   break;
  for(i = 0; i < 3; i ++)  //三种交换 
  {
   ss = ts;
   char tc = ss[i];
   ss[i] = ss[i + 1];
   ss[i + 1] = tc;
   ii = stoi(ss);
   if(!b[ii])
   {
    b[ii] = l + 1;
    sq.push(ss);
   }
  }
  for(i = 0; i < 4; i ++)  //四种原位增减
  {
   ss = ts;
   ss[i] = (ss[i] != '9') ? ss[i] + 1 : '1';
   ii = stoi(ss);
   if(!b[ii])
   {
    b[ii] = l + 1;
    sq.push(ss);
   }
   ss = ts;
   ss[i] = (ss[i] != '1') ? ss[i] - 1 : '9';
   ii = stoi(ss);
   if(!b[ii])
   {
    b[ii] = l + 1;
    sq.push(ss);
   }
  }
  sq.pop();  
 }
}

void print()
{
 printf("%d\n", b[pi] - 1);
}