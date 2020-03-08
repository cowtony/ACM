#include <stdio.h>
#include <string.h>
#include <time.h>

typedef char stat[20];
char n;
char object[40][35];
stat st , ed;
int CaseNo;

#define LEN_Q 150000
#define MODOL 958331

struct Q_Type{
	stat s; 
	char len;
	char op;
	int prev;
} Q[2][LEN_Q];

struct hash_stat{
	char side;
	char step;
	char op;	
	int lab;
} f[MODOL];
int used[MODOL];

char find_object(char* s){
	char i;
	for(i=0; i<n; i++)
		if(strcmp(s , object[i]) == 0) return i;
	strcpy(object[n] , s);
	n++;
	return i;
}

bool init(){
	int cnt[40];
	memset(cnt , 0 , sizeof(cnt));

	n = 0;

	int i;
	char buf[35];

	for(i=0; i<19; i++){
		scanf("%s" , buf);
		st[i] = find_object(buf);
		cnt[st[i]]++;
	}

	for(i=0; i<19; i++){
		scanf("%s" , buf);
		ed[i] = find_object(buf);
		cnt[ed[i]]--;		
	}

	for(i=0; i<n; i++)
		if(cnt[i] != 0) return 0;
	return 1;
}

void rotate_1(stat a , char side){
	if(side == 0){
		char t = a[0];
		a[0] = a[1]; a[1] = a[5]; a[5] = a[9]; a[9] = a[8]; a[8] = a[3]; a[3] = t;
	}
	else{
		char t = a[0];
		a[0] = a[3]; a[3] = a[8]; a[8] = a[9]; a[9] = a[5]; a[5] = a[1]; a[1] = t;
	}
}

void rotate_2(stat a , char side){
	if(side == 0){
		char t = a[1];
		a[1] = a[2]; a[2] = a[6]; a[6] = a[10]; a[10] = a[9]; a[9] = a[4]; a[4] = t;
	}
	else{
		char t = a[1];
		a[1] = a[4]; a[4] = a[9]; a[9] = a[10]; a[10] = a[6]; a[6] = a[2]; a[2] = t;
	}
}

void rotate_3(stat a , char side){
	if(side == 0){
		char t = a[3];
		a[3] = a[4]; a[4] = a[9]; a[9] = a[13]; a[13] = a[12]; a[12] = a[7]; a[7] = t;
	}
	else{
		char t = a[3];
		a[3] = a[7]; a[7] = a[12]; a[12] = a[13]; a[13] = a[9]; a[9] = a[4]; a[4] = t;
	}
}

void rotate_4(stat a , char side){
	if(side == 0){
		char t = a[4];
		a[4] = a[5]; a[5] = a[10]; a[10] = a[14]; a[14] = a[13]; a[13] = a[8]; a[8] = t;
	}
	else{
		char t = a[4];
		a[4] = a[8]; a[8] = a[13]; a[13] = a[14]; a[14] = a[10]; a[10] = a[5]; a[5] = t;
	}
}

void rotate_5(stat a , char side){
	if(side == 0){
		char t = a[5];
		a[5] = a[6]; a[6] = a[11]; a[11] = a[15]; a[15] = a[14]; a[14] = a[9]; a[9] = t;		
	}
	else{
		char t = a[5];
		a[5] = a[9]; a[9] = a[14]; a[14] = a[15]; a[15] = a[11]; a[11] = a[6]; a[6] = t;
	}
}

void rotate_6(stat a , char side){
	if(side == 0){
		char t = a[8];
		a[8] = a[9]; a[9] = a[14]; a[14] = a[17]; a[17] = a[16]; a[16] = a[12]; a[12] = t;
	}
	else{
		char t = a[8];
		a[8] = a[12]; a[12] = a[16]; a[16] = a[17]; a[17] = a[14]; a[14] = a[9]; a[9] = t;
	}
}

void rotate_7(stat a , char side){
	if(side == 0){
		char t = a[9];
		a[9] = a[10]; a[10] = a[15]; a[15] = a[18]; a[18] = a[17]; a[17] = a[13]; a[13] = t;
	}
	else{
		char t = a[9];
		a[9] = a[13]; a[13] = a[17]; a[17] = a[18]; a[18] = a[15]; a[15] = a[10]; a[10] = t;
	}
}

inline int ELFhash(stat a){
	unsigned long h = 0;
	for(char i=0; i<19; i++){
		h = (h << 4) + a[i];
		unsigned long g = h & 0Xf0000000L;
		if(g) h^= g >> 24;
		h &= ~g;
	}
	return h % MODOL;

}

inline bool the_same(stat a , stat b){
	for(char i=0; i<19; i++) 
		if(a[i] != b[i]) return 0;
	return 1;
}

int h[2] , t[2];

bool reg(stat a , char side , char step , char op){
	int ha = ELFhash(a);
	while(used[ha] == CaseNo){
		if(the_same(Q[f[ha].side][f[ha].lab].s , a)){
			if(f[ha].side == side) return 0;
			//	printf("%d\n" , step + f[ha].step);
			int a[10] , i , p;
			p = (side == 0 ? h[0] : f[ha].lab); i = 0;
			while(p > 0){
				a[i++] = Q[0][p].op;
				p = Q[0][p].prev;
			}

			for(p=i-1; p>=0; p--) printf("%d" , a[p]);
			printf("%d" , op);

			p = (side == 0 ? f[ha].lab : h[1]);
			while(p > 0){
				printf("%d" , Q[1][p].op);
				p = Q[1][p].prev;
			}

			putchar('\n');
			/////////////////////////////////////
			return 1;
		}

		ha = (ha + 1) % MODOL;
	}
	
	f[ha].side = side;
	f[ha].step = step;	
	f[ha].lab = ++t[side];
	used[ha] = CaseNo;

	Q[side][t[side]].len = step;
	Q[side][t[side]].op = op;
	Q[side][t[side]].prev = h[side];
	memcpy(Q[side][t[side]].s , a , sizeof(stat));

	return 0;
}

void solve(){	
	h[0] = h[1] = 0;
	t[0] = t[1] = -1;
	Q[0][0].len = Q[1][0].len = 0;
	memcpy(Q[0][0].s , st , sizeof(stat));
	reg(st , 0 , 0 , 0);
	memcpy(Q[1][0].s , ed , sizeof(stat));
	if(reg(ed , 1 , 0 , 0)) return;

	int step , side;
	stat curr;
	
	for(step = 0; step < 6; step++){
		for(side=0; side<2; side++){
			while(h[side] <= t[side] && Q[side][h[side]].len == step){
				memcpy(curr , Q[side][h[side]].s , sizeof(stat));
				rotate_1(curr , side);
				if(reg(curr , side , step + 1 , 1)) return;

				memcpy(curr , Q[side][h[side]].s , sizeof(stat));
				rotate_2(curr , side);
				if(reg(curr , side , step + 1 , 2)) return;

				memcpy(curr , Q[side][h[side]].s , sizeof(stat));
				rotate_3(curr , side);
				if(reg(curr , side , step + 1 , 3)) return;

				memcpy(curr , Q[side][h[side]].s , sizeof(stat));
				rotate_4(curr , side);
				if(reg(curr , side , step + 1 , 4)) return;

				memcpy(curr , Q[side][h[side]].s , sizeof(stat));
				rotate_5(curr , side);
				if(reg(curr , side , step + 1 , 5)) return;

				memcpy(curr , Q[side][h[side]].s , sizeof(stat));
				rotate_6(curr , side);
				if(reg(curr , side , step + 1 , 6)) return;

				memcpy(curr , Q[side][h[side]].s , sizeof(stat));
				rotate_7(curr , side);
				if(reg(curr , side , step + 1 , 7)) return;

				h[side]++;
			}
		}
	}
	
	puts("-1");
}

int main(){
//	freopen("in.txt" , "r" , stdin);
	

	int T;
	scanf("%d" , &T);
	CaseNo = 0;

	while(T--){
		++CaseNo;
		if(init()){
			solve();
		}
		else puts("-1");		
	}

	//fprintf(stderr , "program run time :	%.3fs\n" , clock() / (float) CLK_TCK);
	
	return 0;
}
