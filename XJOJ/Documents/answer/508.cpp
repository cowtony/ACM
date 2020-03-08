/*
 * Author: OpenLegend
 * Created Time:  2010-11-2 14:53:17
 * File Name: f.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1005;
const short INF = 10007;
typedef long long LL;
char s[maxn][maxn];
short a[maxn][maxn][10];
short TM[maxn][10];
int n, m;
void update(short& t1, int t2){
    t1 = max((int)t1, t2);
}
void solve(){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++) for(int k = 0; k < 10; k ++) a[i][j][k] = INF;
    }
    //1
    for(int j = 0; j < m; j ++) for(int k = 0; k < 10; k ++) TM[j][k] = -INF;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            short ti = i, tj = j;
            for(int k = 0; k < 10; k ++){
                if(j != 0) update(TM[j][k], TM[j-1][k]);
                a[i][j][k] = min((int)a[i][j][k], ti+tj-TM[j][k]);
            }
            int v = s[i][j] - '0';
            update(TM[j][v], ti+tj);
        }
    }
    //2
    for(int j = 0; j < m; j ++) for(int k = 0; k < 10; k ++) TM[j][k] = -INF;
    for(int i = 0; i < n; i ++){
        for(int j = m-1; j >= 0; j --){
            short ti = i, tj = m - 1 - j;
            int v = s[i][j] - '0';
            for(int k = 0; k < 10; k ++){
                if(j != m-1) update(TM[j][k], TM[j+1][k]);
                a[i][j][k] = min((int)a[i][j][k], ti+tj-TM[j][k]);
            }
            update(TM[j][v], ti+tj);
        }
    }
    //3
    for(int j = 0; j < m; j ++) for(int k = 0; k < 10; k ++) TM[j][k] = -INF;
    for(int i = n-1; i >= 0; i --){
        for(int j = 0; j < m; j ++){
            short ti = n - 1 - i, tj = j;
            int v = s[i][j] - '0';
            for(int k = 0; k < 10; k ++){
                if(j != 0) update(TM[j][k], TM[j-1][k]);
                a[i][j][k] = min((int)a[i][j][k], ti+tj-TM[j][k]);
            }
            update(TM[j][v], ti+tj);
        }
    }
    //4
    for(int j = 0; j < m; j ++) for(int k = 0; k < 10; k ++) TM[j][k] = -INF;
    for(int i = n-1; i >= 0; i --){
        for(int j = m-1; j >= 0; j --){
            short ti = n - 1 - i, tj = m - 1 - j;
            int v = s[i][j] - '0';
            for(int k = 0; k < 10; k ++){
                if(j != m-1) update(TM[j][k], TM[j+1][k]);
                a[i][j][k] = min((int)a[i][j][k], ti+tj-TM[j][k]);
            }
            update(TM[j][v], ti+tj);
        }
    }
}
int main() {
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < n; i ++){
            scanf("%s", s[i]);
        }
        solve();
        LL ans = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                //printf("%d ", (int)a[i][j][1]);
                for(int k = 0; k < 10; k ++){
                    if(a[i][j][k] < INF) ans += a[i][j][k];
                }
            }
            //printf("\n");
        }
        cout << ans * 2 << endl;
    }
    return 0;
}

