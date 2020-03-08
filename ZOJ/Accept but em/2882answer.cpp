#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct node
{
    int x, y;
}q[20005];
int c[20005];
int n;
bool cmp(node a, node b )
{
    if( a.x != b.x )return a.x < b.x;
    else return a.y > b.y;
}

int Bisearch(int pre, int post, int v) 
{
      int mid;
      while ( pre <= post ) 
      {
           mid = ( pre + post ) >> 1;
           if ( c[mid] >= v ) pre = mid+1;
           else post = mid-1;
      }
      return pre;
}

void LIS()
{
      int i, t;
      int top = 0;
      //c[top++] = q[0].y;
      for( i = 0; i < n; i++ )
      {
          t = Bisearch( 0, top-1, q[i].y );
          //printf("%d ", t );
          c[t] = q[i].y; 
          if ( t >= top )top++;
      }
      //printf("\n");
      //for(int i = 0; i < top; i++ )printf("%d ", c[i] );
      //printf("\n");
      printf( "%d\n", top );
}   

int main()
{
    int kcase;
    scanf("%d",&kcase);
    while( kcase-- )
    {
        scanf("%d", &n);
        for(int i = 0; i < n;i++ )
        {
            scanf("%d %d", &q[i].x, &q[i].y );
            
        }
        sort(q,q+n,cmp);
        //for(int i = 0; i < n; i++ )printf("%d ", q[i].y );
        //printf("\n");
        LIS();
    }
    return 0;
}