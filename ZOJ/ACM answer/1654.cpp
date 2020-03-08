//320936 2003-10-22 01:01:58 Runtime Error SIGSEGV 1654 C++ 00:00.05 4396K just for play 
//320938 2003-10-22 01:06:43 Wrong Answer 1654 C++ 00:00.14 9288K just for play 
//---------------------------------------------------------------------------

#include<iostream.h>
#include<string.h>

#include<stdio.h>
#define MAXN 1500

//---------------------------------------------------------------------------


struct RC
{
        int dex;
        int from,to;
};

int link[1500][1500];
int cnt[1500];
RC row[1500],col[1500];
int rcnt=0,ccnt=0;

/*
int hungary()
{
        int mat1[1500],mat2[1500];
        int beg[1500],up[1500];
        memset(mat1,0xff,sizeof(mat1));
        memset(mat2,0xff,sizeof(mat2));
        int i,j,pt,tt;
        int tcnt=0;
        for(i=0;i<rcnt;i++)
        {
                if(mat1[i]>=0)  continue;
                pt=i;
                bool find=false;
                memset(beg,0,sizeof(beg));
                while(1)
                {
                        for(;beg[pt]<cnt[pt]&&(!find);)
                        {
                                tt=link[pt][beg[pt]];
                                up[tt]=pt;
                                if(mat2[tt]<0)
                                {
                                        find=true;
                                        tcnt++;
                                        int pre=up[tt];
                                        while(1)
                                        {
                                                int tn=mat1[pre];
                                                mat1[pre]=tt;
                                                mat2[tt]=pre;
                                                if(pre==i)      break;
                                                tt=tn;
                                                pre=up[tn];
                                        }
                                }
                                else {beg[pt]++;pt=mat2[tt];break;}
                        }
                        if(pt==i||find) break;
                        pt=up[mat1[pt]];
                }
        }

        return tcnt;
}

*/
bool between(int x,int from,int to)
{
        if(x>=from&&x<=to)       return true;
        return false;
}

int hungary(int m, int n, int mat[][MAXN], int* match1, int* match2)
{
	int s[MAXN], t[MAXN], p, q, ret=0, i, j, k,tj;
	memset(match1, 0xff, sizeof(int)*MAXN);
	memset(match2, 0xff, sizeof(int)*MAXN);
	for (i=0; i<m; ret+=(match1[i++]>=0) ){
		memset(t, 0xff, sizeof(int)*MAXN);
		for (s[p=q=0]=i; p<=q&&match1[i]<0; p++){
			for (k=s[p], tj=0; tj<cnt[k]&&match1[i]<0; tj++){
				j=mat[k][tj];
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



int main(int argc, char* argv[])
{
//        freopen("1654.in","r",stdin);
//        freopen("1654.out","w",stdout);
		int T;
		cin>>T;
        int n,m;
        char ch[51][51];
        int count=0;
        while(T--)
        {
				cin>>n>>m;
		
                int i,j,t;
                for(i=0;i<n;i++)
                        for(j=0;j<m;j++)
                                cin>>ch[i][j];
                rcnt=ccnt=0;
                for(i=0;i<n;i++)
                {
                        int tfrom,tto;
                        for(j=0;j<=m;j++)
                        {
                                if(j<m&&tfrom<0&&ch[i][j]!='#')
                                {
                                        tfrom=j;
                                }
                                else if(tfrom>=0&&(j==m||ch[i][j]=='#'))
                                {
                                        tto=j-1;
                                        row[rcnt].dex=i;row[rcnt].from=tfrom;
                                        row[rcnt].to=tto;rcnt++;
                                        tfrom=-1;
                                }
                        }
                }
                for(i=0;i<m;i++)
                {
                        int tfrom,tto;
                        for(j=0;j<=n;j++)
                        {
                                if(j<n&&tfrom<0&&ch[j][i]!='#')
                                {
                                        tfrom=j;
                                }
                                else if(tfrom>=0&&(j==n||ch[j][i]=='#'))
                                {
                                        tto=j-1;
                                        col[ccnt].dex=i;col[ccnt].from=tfrom;
                                        col[ccnt].to=tto;ccnt++;
                                        tfrom=-1;
                                }
                        }
                }
                memset(cnt,0,sizeof(cnt));
                for(i=0;i<rcnt;i++)
                        for(j=0;j<ccnt;j++)
                        {
                                if(between(row[i].dex,col[j].from,col[j].to)&&
                                        between(col[j].dex,row[i].from,row[i].to)&&
                                        ch[row[i].dex][col[j].dex]=='o')
                                                link[i][cnt[i]++]=j;
                        }
				int mat1[1500],mat2[1500];
                cout<<"Case :"<<(++count)<<endl;
                cout<<hungary(rcnt,ccnt,link,mat1,mat2)<<endl;
        }


        return 0;
}
//---------------------------------------------------------------------------