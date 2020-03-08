#include <iostream.h>
const MAX=500;
unsigned int table[MAX][MAX];

unsigned int makeit( int sum,int lim )
{
	if( sum==0 )
		return 1;
	if( sum == lim )
		return 1;
	if( sum<lim )
		return 0;
	if( (int) table[sum][lim]!=0 )
		return table[sum][lim];
	unsigned int total = 0;
	for( int i=lim;i<=sum-lim;i++ )
		total += makeit( sum-2*lim,i );
	table[sum][lim] = total;
	return total;
}

int main()
{
  for (int i=0;i<=MAX;i++)
    for (int j=0;j<=MAX;j++)
      table[i][j]=0;
  int n,i;
  unsigned int total=1;
	cin>>n;
  while(n)
  {
		for(i=1;i*2<=n;i++ )
			total += makeit( n,i );
		cout<<n<<' '<<total<<endl;
    cin>>n;
	}
	return 0;
}
