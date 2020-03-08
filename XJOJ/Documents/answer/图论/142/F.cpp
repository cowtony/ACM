//  ª∆“’∫£  cshyh@qq.com 

#include <iostream>
using namespace std;

const int MAX = 20000;

int n, m, num, v, tot;
int room[MAX], maxe[MAX], f[MAX];
int g[MAX], next[MAX], e[MAX];       

struct Tedge {
       int x, y, z;
} edge[MAX];

bool cmp(const Tedge & a, const Tedge & b)
{
     return a.z > b.z;
}

bool cmp2(const int & a, const int & b)
{
     return maxe[a] < maxe[b];
     
}

int root(int i)
{
    if (f[i] != i) 
       { int r = root(f[i]); f[i] = r; return r; } 
    else return i;
}

void add(int i, int j)
{
     tot++;
     e[tot] = j; next[tot] = g[i]; g[i] = tot;
}

int main()
{
          tot = 0;
          cin >> n >> m >> num >> v;
          for (int i = 1; i <= n; i++)
              for (int j = 1; j <= n; j++);
          for (int i = 1; i <= num; i++) cin >> room[i];
          for (int i = 1; i <= m; i++) cin >> edge[i].x >> edge[i].y >> edge[i].z;
          sort(edge + 1, edge + m + 1, cmp);        
    
          memset(g, 0, sizeof(g));
          tot = 0;
          for (int i = 1; i <= n; i++) {
              f[i] = i;
              add(i, i);
          }         
          memset(maxe, 0, sizeof(maxe));
          for (int i = 1; i <= m; i++) {
              int ra = root(edge[i].x);
              int rb = root(edge[i].y);
              if (ra != rb) {
                 if (ra > rb) swap(ra, rb);
                 int x = g[rb];
                 while (x) {
                   int v = e[x];
                   add(ra, v);
                   if (ra == 1) maxe[v] = edge[i].z;
                   x = next[x];
                 }  
                 g[rb] = 0;
                 f[rb] = ra;
              }
          }
    
          int res = 0;
          sort(room + 1, room + num + 1, cmp2);
          int nowfat = 0;
          for (int i = 1; i <= num; i++)  {
              int r = room[i];
              if (r == 1) res++;
              if (nowfat + v <= maxe[r]) res++, nowfat += v;
          }
          cout << res << endl;
          return 0;
}
