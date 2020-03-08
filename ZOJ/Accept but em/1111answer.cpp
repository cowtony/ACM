#include <iostream>
#include <string>
using namespace std;
int bw, ww, tie, t_b, t_w;
struct card
{
 int v, s;
} b[5], w[5];

void pc(card *a)
{
 int i;
 for(i = 0; i < 5; i ++)
 {
  printf("%d ", a[i].v, a[i].s);
 }
 printf("\n");
}
void print()
{
 pc(b); pc(w);
 printf("%d %d\n", t_b, t_w);
}
int high(card *a)
{
 int i, sum = 0;
 for(i = 0; i < 5; i ++)
 {
  sum *= 14;
  sum += a[i].v;
 }
 return sum;
}
void atoc(string str, card &c)
{
 int sv, ss;
 if(str[0] == 'A')
  sv = 13;
 else if(str[0] == 'T')
  sv = 9;
 else if(str[0] == 'J')
  sv = 10;
 else if(str[0] == 'Q')
  sv = 11;
 else if(str[0] == 'K')
  sv = 12;
 else
  sv = str[0] - '0' - 1;
 if(str[1] == 'C')
  ss = 0;
 else if(str[1] == 'D')
  ss = 1;
 else if(str[1] == 'H')
  ss = 2;
 else if(str[1] == 'S')
  ss = 3;
 c.s = ss, c.v = sv;
}
void s_sort(card *a)
{
 int i, k, j, mx;
 for(i = 0; i < 4; i ++)
 {
  j = i, mx = a[j].v;
  for(k = i + 1; k < 5; k ++)
  {
   if(a[k].v > mx)
   {
    mx = a[k].v;
    j = k;
   }
  }
  int tv, ts;
  tv = a[j].v, ts = a[j].s;
  a[j].v = a[i].v, a[j].s = a[i].s;
  a[i].v = tv, a[i].s = ts;
 }
}
 
int str_flush(card *a)
{
 int i;
 for(i = 0; i < 5; i ++)
 {
  if(a[i].s != a[0].s)
   return 0;
  if(a[i].v != a[0].v - i)
   return 0;
 }
 return a[0].v;
}
int four_kind(card *a)
{
 int i, l[14];
 memset(l, 0, sizeof(l));
 for(i = 0; i < 5; i ++)
 {
  l[a[i].v] ++;
 }
 for(i = 0; i < 14; i ++)
 {
  if(l[i] == 4)
  {
   return i;
  }
 }
 return 0;
}
int full_house(card *a)
{
 int i, l[14], tp = 0, db = 0;
 memset(l, 0, sizeof(l));
 for(i = 0; i < 5; i ++)
 {
  l[a[i].v] ++;
 }
 for(i = 1; i <= 13; i ++)
 {
  if(l[i] == 3) tp = i;
  if(l[i] == 2) db = i;
  if(l[i] == 1) return 0;
 }
 if(tp && db) return tp;
}
int one_flush(card *a)
{
 int i;
 for(i = 0; i < 5; i ++)
 {
  if(a[i].s != a[0].s)
   return 0;
 }
 return high(a);
}
int straight(card *a)
{
 int i;
 for(i = 0; i < 5; i ++)
 {
  if(a[i].v != a[0].v - i)
   return 0;
 }
 return a[0].v;
}
int tp_kind(card *a)
{
 int i, l[14];
 memset(l, 0, sizeof(l));
 for(i = 0; i < 5; i ++)
 {
  l[a[i].v] ++;
 }
 for(i = 0; i < 14; i ++)
 {
  if(l[i] == 3)
   return i;
 }
 return 0;
}
int db_db(card *a)
{
 int i, l[14], sum = 0, d[2], t;
 memset(l, 0, sizeof(l));
 for(i = 0; i < 5; i ++)
 {
  l[a[i].v] ++;
 }
 for(i = 0; i < 14; i ++)
 {
  if(l[i] == 2) d[sum ++] = i;
  if(l[i] == 1) t = i;
 }
 if(sum == 2)
  return (d[1] * 14 + d[0]) * 14 + t;
 return 0;
}
int db_kind(card *a)
{
 int i, l[14], f = 0, d[5], sum = 0;
 memset(l, 0, sizeof(l));
 for(i = 0; i < 5; i ++)
 {
  l[a[i].v] ++;
 }
 for(i = 0; i < 14; i ++)
 {
  if(l[i] == 2) f = i;
  if(l[i] == 1) d[sum ++] = i;
 }
 if(f)
  return ((f * 14 + d[2]) * 14 + d[1]) * 14 + d[0]; 
 return 0;
}
void compare()
{
 s_sort(b); s_sort(w);
 t_b = 9, t_w = 9;
 bw = 0, ww = 0, tie = 0;
 bw = str_flush(b), ww = str_flush(w);
 if(bw) t_b = 0;
 if(ww) t_w = 0;
 if(bw && !ww || ww && !bw)
  return;
 if(bw && ww)
 {
  if(bw > ww) 
  {
   ww = 0; return;
  }
  else if(ww > bw)
  {
   bw = 0; return;
  }
  else
  {
   bw = 0, ww = 0, tie = 1; return;
  }
 }
 bw = 0, ww = 0, tie = 0;
 bw = four_kind(b), ww = four_kind(w);
 if(bw) t_b = 1;
 if(ww) t_w = 1;
 if(bw && !ww || ww && !bw)
  return;
 if(bw && ww)
 {
  if(bw > ww) 
  {
   ww = 0; return;
  }
  else if(ww > bw)
  {
   bw = 0; return;
  }
  else
  {
   bw = 0, ww = 0, tie = 1; return;
  }
 }
 bw = 0, ww = 0, tie = 0;
 bw = full_house(b), ww = full_house(w);
 if(bw) t_b = 2;
 if(ww) t_w = 2;
 if(bw && !ww || ww && !bw)
  return;
 if(bw && ww)
 {
  if(bw > ww) 
  {
   ww = 0; return;
  }
  else if(ww > bw)
  {
   bw = 0; return;
  }
  else
  {
   bw = 0, ww = 0, tie = 1; return;
  }
 }
 bw = 0, ww = 0, tie = 0;
 bw = one_flush(b), ww = one_flush(w);
 if(bw) t_b = 3;
 if(ww) t_w = 3;
 if(bw && !ww || ww && !bw)
  return;
 if(bw && ww)
 {
  if(bw > ww) 
  {
   ww = 0; return;
  }
  else if(ww > bw)
  {
   bw = 0; return;
  }
  else
  {
   bw = 0, ww = 0, tie = 1; return;
  }
 }
 bw = 0, ww = 0, tie = 0;
 bw = straight(b), ww = straight(w);
 if(bw) t_b = 4;
 if(ww) t_w = 4;
 if(bw && !ww || ww && !bw)
  return;
 if(bw && ww)
 {
  if(bw > ww) 
  {
   ww = 0; return;
  }
  else if(ww > bw)
  {
   bw = 0; return;
  }
  else
  {
   bw = 0, ww = 0, tie = 1; return;
  }
 }
 bw = 0, ww = 0, tie = 0;
 bw = tp_kind(b), ww = tp_kind(w);
 if(bw) t_b = 5;
 if(ww) t_w = 5;
 if(bw && !ww || ww && !bw)
  return;
 if(bw && ww)
 {
  if(bw > ww) 
  {
   ww = 0; return;
  }
  else if(ww > bw)
  {
   bw = 0; return;
  }
  else
  {
   bw = 0, ww = 0, tie = 1; return;
  }
 }
 bw = 0, ww = 0, tie = 0;
 bw = db_db(b), ww = db_db(w);
 if(bw) t_b = 6;
 if(ww) t_w = 6;
 if(bw && !ww || ww && !bw)
  return;
 if(bw && ww)
 {
  if(bw > ww) 
  {
   ww = 0; return;
  }
  else if(ww > bw)
  {
   bw = 0; return;
  }
  else
  {
   bw = 0, ww = 0, tie = 1; return;
  }
 }
 bw = 0, ww = 0, tie = 0;
 bw = db_kind(b), ww = db_kind(w);
 if(bw) t_b = 7;
 if(ww) t_w = 7;
 if(bw && !ww || ww && !bw)
  return;
 if(bw && ww)
 {
  if(bw > ww) 
  {
   ww = 0; return;
  }
  else if(ww > bw)
  {
   bw = 0; return;
  }
  else
  {
   bw = 0, ww = 0, tie = 1; return;
  }
 }
 bw = 0, ww = 0, tie = 0;
 bw = high(b), ww = high(w);
 if(bw) t_b = 8;
 if(ww) t_w = 8;
 if(bw && ww)
 {
  if(bw > ww) 
  {
   ww = 0; return;
  }
  else if(ww > bw)
  {
   bw = 0; return;
  }
  else
  {
   bw = 0, ww = 0, tie = 1; return;
  }
 }
}

int main()
{
 //freopen("in.txt", "r", stdin);
 string str;
 while(cin >> str)
 {
  atoc(str, b[0]);
  int i;
  for(i = 0; i < 4; i ++)
  {
   cin >> str;
   atoc(str, b[i + 1]);
  }
  for(i = 0; i < 5; i ++)
  {
   cin >> str;
   atoc(str, w[i]);
  }
  compare();
  //print();
  if(bw)
   printf("Black wins.\n");
  if(ww)
   printf("White wins.\n");
  if(tie)
   printf("Tie.\n");
 }
 return 0;
}