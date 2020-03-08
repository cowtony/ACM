#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 26;
const int MAXM = 300;
int l, ll, pos[MAXN];
bool rel[MAXN][MAXN];  //relation
void init(char *mes)
{
      int len = strlen(mes);
      ll = 0;
      for(int i = 0; i < len; i += 2) mes[ll ++] = mes[i];
      mes[ll] = '\0';
}
void floyd()
{
      for(int k = 0; k < 26; k ++)
            for(int i = 0; i < 26; i ++)
                 for(int j = 0; j < 26; j ++)
                      if(rel[i][k] && rel[k][j]) rel[i][j] = true;
}
bool check()
{
      for(int i = 0; i < 26; i ++)
            for(int j = 0; j < 26; j ++)
                 if(rel[i][j] && pos[i] > pos[j]) return false;
      return true;
}
int main()
{
      char mes[MAXM], str[MAXM];
      while(gets(mes)) {
            gets(str);
            init(mes);
            l = strlen(str);
            memset(rel, false, sizeof(rel));
            for(int i = 0; i < l; i += 4) {
                  rel[str[i] - 'a'][str[i + 2] - 'a'] = true;
                  floyd();
            }
            sort(mes, mes + ll);
            do {
                  for(int j = 0; j < ll; j ++) pos[mes[j] - 'a'] = j;
                  if(check()) printf("%s\n", mes);
            }while(next_permutation(mes, mes + ll));
            printf("\n");
      }
      return(0);
}
