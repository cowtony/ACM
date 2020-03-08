//1196 Fast food
//16 2002-11-05 08:18:07 00:00.19 460K C++ jet_engine
// mid number problem & dynamic programming

#include<iostream.h>
#include<string.h>

const int MAXINT=2147483647;
int list[201];
int mmin[201][31];
int sum;

int calc(int beg, int end)
{
	int v=0;
	while(beg<end){
		v+=list[end--]-list[beg++];
	}
	return v;
}

int dyn(int beg, int n)
{
	if (mmin[beg][n]<0){
		if (n>1){
			int m=MAXINT, v;
			for (int nxtbeg=beg+1; nxtbeg<=sum-n+1; nxtbeg++){
				v=calc(beg, nxtbeg-1)+dyn(nxtbeg, n-1);
				if (v<m) m=v;
			}
			mmin[beg][n]=m;
		} else {
			mmin[beg][n]=calc(beg, sum-1);
		}
	}
	return mmin[beg][n];
}

int main()
{
	int k, cnt=1;
	while(cin>>sum>>k){
		if (sum==0&&k==0) break;
		for (int i=0; i<sum; i++)
			cin>>list[i];
		memset(mmin, 255, sizeof(mmin));
		dyn(0, k);
		cout<<"Chain "<<cnt<<endl;
		cout<<"Total distance sum = "<<mmin[0][k]<<endl<<endl;
		cnt++;
	}
	return 0;
}

