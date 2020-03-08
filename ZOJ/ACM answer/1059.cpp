//158553 2003-05-25 09:54:05 Accepted 1059 C++ 00:00.10 436K just for play 
//158556 2003-05-25 09:58:18 Accepted 1059 C++ 00:00.06 436K just for play 

//use the algorithm of hungary to calculate the max-match
//in reference to vcenit's
#include<iostream.h>
#include<string.h>
#include<stdio.h>

int idmatch[20],namematch[20];
int map[20][20];
int determine[20];

const int MAXN=20;
int n;
		
int hungary(int m, int n, int mat[][MAXN], int* match1, int* match2)
{
	int s[MAXN], t[MAXN], p, q, ret=0, i, j, k;
	memset(match1, 0xff, sizeof(int)*MAXN);
	memset(match2, 0xff, sizeof(int)*MAXN);
	for (i=0; i<m; ret+=(match1[i++]>=0) ){
		memset(t, 0xff, sizeof(int)*MAXN);
		for (s[p=q=0]=i; p<=q&&match1[i]<0; p++){
			for (k=s[p], j=0; j<n&&match1[i]<0; j++){
				if (mat[k][j]&&t[j]<0){
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


void mainproc()
{
	int i;

	hungary(n, n, map, idmatch, namematch);
	int match[MAXN];
	int m2[MAXN];
	for (i=0; i<n; i++){
		if(determine[i])	continue;
		map[i][idmatch[i]]=0;
		memset(match,0xff,sizeof(match));
		memset(m2,0xff,sizeof(m2));
		if (hungary(n, n, map, match, m2)==n){

			map[i][idmatch[i]]=1;
			namematch[idmatch[i]]=-1;
			idmatch[i]=-1;
			continue;
		}
		determine[i]=1;
		map[i][idmatch[i]]=1;
	}
}

void select_sort(char name[][20],int seq[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		int pt=i;
		for(j=i+1;j<n;j++)
			if(strcmp(name[seq[j]],name[seq[pt]])<0)	pt=j;
		if(pt!=i)
		{
			int temp=seq[pt];seq[pt]=seq[i];seq[i]=temp;
		}
	}
}

int main()
{
//	freopen("1059.in","r",stdin);
//	freopen("1059.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		int i,j;
		cin>>n;
		char id[20][20];char name[20][20];
		memset(idmatch,0xff,sizeof(idmatch));
		memset(namematch,0xff,sizeof(namematch));
		memset(determine,0,sizeof(determine));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)	map[i][j]=1;
		for(i=0;i<n;i++)
			cin>>id[i];
		char action,tstr[20];
		int name_in[20];	
		memset(name_in,0,sizeof(name_in));
		int name_cnt=0;
		
		while(cin>>action)
		{
			if(action=='Q')	break;
			cin>>tstr;
			int namept;
			bool has_changed=false;
			switch(action)
			{
			case 'E':				
				for(i=0;i<name_cnt;i++)
					if(strcmp(tstr,name[i])==0)	{namept=i;break;}
				if(i==name_cnt)
				{	strcpy(name[name_cnt],tstr);namept=name_cnt++;}
				name_in[namept]=1;
				//if(has_changed)	mainproc();
				break;
			case 'L':
				for(i=0;i<name_cnt;i++)
					if(strcmp(tstr,name[i])==0){namept=i;break;}
				name_in[namept]=0;
				//if(has_changed)	mainproc();
				break;
			case 'M':
				has_changed=true;
				for(i=0;i<n;i++)
					if(strcmp(tstr,id[i])==0){namept=i;break;}
				for(i=0;i<n;i++)
					if(name_in[i]==0)	map[namept][i]=0;
				mainproc();
				break;
			default:
				break;
			}
		}
		int seq[20];
		for(i=0;i<n;i++)
			seq[i]=i;
		select_sort(name,seq,n);
		for(i=0;i<n;i++)
			if(namematch[seq[i]]>=0)
				cout<<name[seq[i]]<<":"<<id[namematch[seq[i]]]<<endl;
			else	cout<<name[seq[i]]<<":"<<"???"<<endl;
		if(tt)	cout<<endl;
	}
	return 0;
}


				

			
		