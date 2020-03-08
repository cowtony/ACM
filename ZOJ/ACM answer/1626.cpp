//300810 2003-09-28 13:16:14 Wrong Answer 1626 C++ 00:00.52 30560K just for play 
#include<iostream.h>
#include<string.h>
#include<stdio.h>

int N,K;
char tree[101][101];
bool used[101][101];
int occur[26];
int* link[201];
int cnt[201];
const int MAXN=10001;
int hungary(int m, int* n, int** mat, int* match1, int* match2)
{
	int s[MAXN], t[MAXN], p, q, ret=0, i, j, jj,k;
//	memset(match1, 0xff, sizeof(int)*MAXN);
//	memset(match2, 0xff, sizeof(int)*MAXN);
	for (i=0; i<m; ret+=(match1[i++]>=0) ){
		memset(t, 0xff, sizeof(int)*MAXN);
		for (s[p=q=0]=i; p<=q&&match1[i]<0; p++){
			for (k=s[p], jj=0; jj<n[i]&&match1[i]<0; jj++){
				j=mat[i][jj];
				if (t[j]<0){
					s[++q]=match2[j];
					t[j]=k;
					if (s[q]<0){
						for (p=j; p>=0; j=p){
							match2[j]=k=t[j];
							p=match1[k];
							match1[k]=j;
						}
					}
				}
			}
		}
	}
	return ret;
}

bool can_eat(int cur){
	char curch=cur+'A';
	int i,j;
	memset(cnt,0,sizeof(cnt));	
	int pt=0;
	for(i=0;i<2*N;i++)	link[i]=new int[occur[cur]+1];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(tree[i][j]==curch){
				link[i][cnt[i]++]=pt;
				link[N+j][cnt[N+j]++]=pt;
				pt++;
			}
		}
	}
	int match1[201],match2[10001];
	memset(match1,0xff,sizeof(match1));
	memset(match2,0xff,sizeof(match2));
	int tt=hungary(2*N,cnt,link,match1,match2);
	if(tt>K)	return true;
	return false;
}
		
int main()
{
	freopen("1626.in","r",stdin);
	int T;
	cin>>T;
	while(T--){		
		cin>>N>>K;
		int i,j;
		memset(occur,0,sizeof(occur));
		for(i=0;i<N;i++)
			for(j=0;j<N;j++){
				cin>>tree[i][j];
				occur[tree[i][j]-'A']++;
			}
		bool output=false;
		for(i=0;i<26;i++){
			if(occur[i]==0)	 continue;
			if(can_eat(i)){
				cout<<(char)(i+'A');
				output=true;
			}
		}
		if(!output)	cout<<"Poor WishingTree!";
		cout<<endl<<endl;
	}
	return 0;
}



