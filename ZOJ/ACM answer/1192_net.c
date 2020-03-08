/* SWERC'98 - It's not a bug, it's a feature */
/* 10/31/98 - Matthias Ruhl                  */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXPATCH 1000
#define MAXBUGS 20
#define MAXSTATES 1048577

FILE *inp;
int pre_yes[MAXPATCH],pre_no[MAXPATCH],post_yes[MAXPATCH],post_no[MAXPATCH];
int dist[MAXSTATES],hptr[MAXSTATES],h[MAXSTATES],t[MAXPATCH];
int n,m,hsize,case_no=1;

int read_data()
{
  char a[MAXBUGS+1],b[MAXBUGS+1];
  int i,j;

  fscanf(inp,"%d %d",&n,&m);
  if(n == 0 && m == 0) return 0;
  for(i=0;i<m;i++)
    {
      fscanf(inp,"%d %s %s",t+i,a,b);
      assert((strlen(a) == n) && (strlen(b) == n));
      pre_yes[i] = pre_no[i] =  post_yes[i] = post_no[i] = 0;
      for(j=0;j<n;j++)
	{
	  if(a[j] == '+') pre_yes[i] |= 1<<j;
	  if(a[j] == '-') pre_no[i]  |= 1<<j;
	  if(b[j] == '+') post_yes[i] |= 1<<j;
	  if(b[j] == '-') post_no[i]  |= 1<<j;
	}
      post_no[i] = ((1<<n)-1)^post_no[i];
    }
  return 1;
}

void hinit()
{
  hsize = 0;
}

int hempty()
{
  return (hsize == 0);
}

void hsiftup(int p)
{
  int d,ptr;

  ptr = h[p];
  d = dist[h[p]];
  while(p > 1 && d < dist[h[p/2]])
    {
      h[p] = h[p/2];
      hptr[h[p]] = p;
      p /= 2;
    }
  h[p] = ptr;
  hptr[h[p]] = p;
}

void hsiftdn(int p)
{
  int d,ptr;

  ptr = h[p];
  d = dist[h[p]];
  while(2*p <= hsize)
    {
      if(2*p+1 <= hsize && dist[h[2*p]] > dist[h[2*p+1]] &&
	 dist[h[2*p+1]] < d)
	{
	  h[p] = h[2*p+1];
	  hptr[h[p]] = p;
	  p = 2*p+1;
	}
      else
	if(dist[h[2*p]] < d)
	  {
	    h[p] = h[2*p];
	    hptr[h[p]] = p;
	    p = 2*p;
	  }
	else
	  break;
    }
  h[p] = ptr;
  hptr[h[p]] = p;
}

void hpush(int s, int d)
{
  if(dist[s] != -1 && dist[s] <= d) return;
  if(hptr[s] != -1)
    {
      dist[s] = -1;
      hsiftup(hptr[s]);
      assert(hptr[s] == 1);
      if(hsize > 1)
	{
	  h[1] = h[hsize--];
	  hsiftdn(1);
	}
      else hsize = 0;
    }
  dist[s] = d;
  h[++hsize] = s;
  hptr[s] = hsize;
  hsiftup(hsize);
}

void hpop(int *s, int *d)
{
  *s = h[1];
  *d = dist[*s];
  hptr[*s] = -1;
  h[1] = h[hsize--];
  if(hsize != 0)
    hsiftdn(1);
}

void process_data()
{
  int snum,i,s,d;

  snum = 1<<n;
  for(i=0;i<snum;i++) hptr[i] = dist[i] = -1;
  hpush(snum-1,0);
  while(!hempty())
    {
      hpop(&s,&d);
      for(i=0;i<m;i++)
	if(((s & pre_yes[i]) == pre_yes[i]) &&
	   ((s & pre_no[i]) == 0)) /* patch can be applied */
	  hpush((s & post_no[i]) | post_yes[i],d+t[i]);
    }
  printf("Product %d\n",case_no++);
  if(dist[0] != -1)
    printf("Fastest sequence takes %d seconds.\n\n",dist[0]);
  else
    printf("Bugs cannot be fixed.\n\n");
}

int main()
{
  inp = fopen("bugs.in","r");
  while(read_data())
    process_data();
  fclose(inp);
  return 0;
}
