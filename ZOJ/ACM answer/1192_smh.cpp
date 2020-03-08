#include<stdio.h>
#include<string.h>

int n, m;
struct PATCH{int time, present, absent, fix, bug;}pat[100];

int hp[1<<20], hps;
int statPos[1<<20];
int len[1<<20];

void input()
{
	memset(pat, 0, sizeof(pat));
	char str[22];
	int i, j;
	for (i=0; i<m; i++){
		scanf("%d %s", &pat[i].time, str);
		for (j=0; j<n; j++){
			if (str[j]=='-'){
				pat[i].absent|=(1<<(n-j-1));
			} else if (str[j]=='+'){
				pat[i].present|=(1<<(n-j-1));
			}
		}
		//pat[i].present^=-1;         (st AND present ) XOR present==0

		scanf("%s", str);
		for (j=0; j<n; j++){
			if (str[j]=='-'){
				pat[i].fix|=(1<<(n-j-1));
			} else if (str[j]=='+'){
				pat[i].bug|=(1<<(n-j-1));
			}
		}
		pat[i].fix^=-1;// 0xffffffffff
	}
}
void rebuild()
{
	int root=0, childpos, value;
	value=hp[0];
	while(root<hps){
		childpos=root*2+1;
		if (childpos<hps){
			if (childpos+1<hps && len[hp[childpos]]>len[hp[childpos+1]]){
				childpos++;//the smaller child
			}
			if (len[value]>len[hp[childpos]]){
				//move down
				hp[root]=hp[childpos];
				statPos[hp[childpos]]=root;
			} else {
				break;
			}
		} else {
			break;
		}
		root=childpos;
	}
	hp[root]=value;
	statPos[value]=root;
}

void relax(int pos)
{
	int value=hp[pos], fa;
	while(pos>0){
		fa=(pos-1)/2;
		if (len[value]<len[hp[fa]]){
			//can be pop up
			hp[pos]=hp[fa];
			statPos[hp[fa]]=pos;
			pos=fa;
		} else {
			break;
		}
	}
	hp[pos]=value;
	statPos[value]=pos;
}



int search()
{
	memset(len, 255, sizeof(int)*(1<<n));

	int stat=(1<<n)-1;
	hp[0]=stat;
	len[stat]=0;
	statPos[stat]=0;// ???
	hps=1;

	int nst, nlen;//new state & len
	while(hps>0){
		stat=hp[0];//min heap
		if (stat==0) break;
		hp[0]=hp[--hps];
		statPos[hp[0]]=0;

		rebuild();
		//expand(stat);
		for (int i=0; i<m; i++){
			if ((stat&pat[i].present)==pat[i].present&&
				(stat&pat[i].absent)==0){
				//meet the precondition
				nst=(stat&pat[i].fix)|pat[i].bug;
				nlen=len[stat]+pat[i].time;
				if (len[nst]>=0){
					if (nlen<len[nst]){//must exist in the heap and haven't been dealed with
						len[nst]=nlen;
						relax(statPos[nst]);//pop up to a proper position
					}
				} else {
					//new stat
					len[nst]=nlen;
					hp[hps]=nst;
					statPos[nst]=hps;
					relax(hps);
					hps++;
				}
			}
		}
	}
	if (stat==0){
		return len[0];
	} else {
		return -1;
	}
}

int main()
{
	freopen("d:/in", "r", stdin);
	freopen("d:/out", "w", stdout);
	int cnt=1, len;//=sizeof(-1);
//	printf("%d %d\n", len, sizeof(int));
	while(scanf("%d %d", &n, &m)!=EOF){
		if (n==0&&m==0) break;
		printf("Product %d\n", cnt++);
		input();
		len=search();
		if (len<0){
			printf("Bugs cannot be fixed.\n");
		} else {
			printf("Fastest sequence takes %d seconds.\n", len);
		}
		printf("\n");
	}
	return 0;
}

