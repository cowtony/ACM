#include <stdio.h>
#include <string.h>
#include <math.h>

#define maxn 20001

struct ans_type{
	int a , b;
	int len;
	char op;
} list[maxn];

void calc_first(){
	memset(list , 0 , sizeof(list));

	list[1].a = 1; list[1].op = '#'; list[1].len = 1;
	list[2].a = 2; list[2].op = '#'; list[2].len = 1;
	list[3].a = 3; list[3].op = '#'; list[3].len = 1;
	list[4].a = 2; list[4].b = 2; list[4].op = '+'; list[4].len = 2;
	list[5].a = 5; list[5].op = '#'; list[5].len = 1;
	list[6].a = 3; list[6].op = '!'; list[6].len = 1;
	list[7].a = 7; list[7].op = '#'; list[7].len = 1;
	list[24].a = 4; list[24].op = '!'; list[24].len = 2;
	list[120].a = 5; list[120].op = '!'; list[120].len = 1;
	list[720].a = 6; list[720].op = '!'; list[720].len = 1;
	list[5040].a = 7; list[5040].op = '!'; list[5040].len = 1;

	int i , a , p;

	for(i=2; i<maxn; i++){
		// a + b
		for(a = 1; a <= i/2; a ++){
			if(list[i].len == 0 || list[a].len + list[i - a].len < list[i].len){
				list[i].op = '+'; list[i].a = a; list[i].b = i - a;
				list[i].len = list[a].len + list[i - a].len;
			}
		}

		// a * b && a ^ b
		for(a = 1; a * a <= i; a ++)
			if(i % a == 0){
				if(list[i].len == 0 || list[a].len + list[i / a].len < list[i].len){
					list[i].op = '*'; list[i].a = a; list[i].b = i / a;
					list[i].len = list[a].len + list[i/a].len;
				}
				if(a > 1){
					p = int(log(i) / log(a) + 1e-10);
					if(pow(a , p) == i && list[a].len + list[p].len < list[i].len){
						list[i].len = list[a].len + list[p].len;
						list[i].op = '^'; list[i].a = a; list[i].b = p;
					}
				}

			}	
	}
}

void print(int k){
	switch(list[k].op){
		case '#' : {
			printf("%d" , k);
			break;
		}

		case '!' : {
			print(list[k].a);
			putchar('!');
			break;
		}

		case '+' :
		case '*' :
		case '^' :{
			putchar('(');
			print(list[k].a);
			putchar(list[k].op);
			print(list[k].b);
			putchar(')');
			break;
		}
	}
}

int main(){
	calc_first();

	int n;
	while(scanf("%d" , &n) != EOF){
		print(n);
		putchar('\n');
	//	printf("length of %d is		: %d\n" , n , list[n].len);		
	}

	return 0;
}
