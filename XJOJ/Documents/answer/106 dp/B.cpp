// This program was written by Huang, Yihai

#include <iostream>
using namespace std;

#define eps 0xffff

int n, L;
int weight[1001];
int f1[1001], f2[1001], g1[1001], g2[1001];

void work(int i, int f, int g)
{
   if (f == f1[i] && g > g1[i]) g1[i] = g;
   if (f < f1[i]) f1[i] = f, g1[i] = g;
}

int main()
{
    cin >> L >> n;
    for (int i = 0; i < n; i++) cin >> weight[i];
    
    for (int j = 0; j <= L; j++) f1[j] =  eps, g1[j] = -1;
    f1[L] = 1; g1[L] = 0;
    
    for (int i = 0; i < n; i++) {
       memcpy(f2, f1, sizeof(f1));
       memcpy(g2, g1, sizeof(g1));
       for (int j = 0; j <= L; j++) f1[j] = eps, g1[j] = -1;
       
       int now = weight[i];
       for (int j = 0; j <= L; j++) if (f2[j] < eps) {
           if (j >= now) work(j - now, f2[j], g2[j]);
           else work(L - now, f2[j] + 1, g2[j]);
           if (g2[j] >= now) work(j, f2[j], g2[j] - now);
           else work(j, f2[j] + 1, L - now);
       }
    }
    
    int res = eps;
    for (int i = 0; i <= L; i++) res = min(res, f1[i]);
    cout << res << endl;
    
    return 0;
}
