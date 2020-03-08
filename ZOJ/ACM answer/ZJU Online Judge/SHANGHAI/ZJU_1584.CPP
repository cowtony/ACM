#include <stdio.h>
#include <string.h>


#define MAXLEN 5000
struct BigNum{
	int l;
	int c[MAXLEN + 1];
};

void Assign_int(BigNum& a , int k){
	memset(a.c , 0 , sizeof(a.c));
	a.l = 0;
	while(k > 0){
		a.c[++a.l] = k % 10;
		k /= 10;
	}
}

void Assign_str(BigNum& a , char* s){
	memset(a.c , 0 , sizeof(a.c));
	a.l = strlen(s);
	for(int i=a.l; i; i--){
		a.c[i] = (*s++) - '0';
	}
}

short comp(BigNum& a , BigNum& b){
	// return value :  a < b(-1) a = b(0) a > b(1)
	if(a.l < b.l) return -1;
	if(a.l > b.l) return 1;
	for(int i=a.l; i; i--){
		if(a.c[i] < b.c[i]) return -1;
		if(a.c[i] > b.c[i]) return 1;
	}
	return 0;
}

void add(BigNum& a , const BigNum& b){
	// BigNum a += b
	if(a.l < b.l) a.l = b.l;
	for(int i=1; i<=a.l; i++){
		a.c[i] += b.c[i];
		a.c[i+1] += a.c[i] / 10;
		a.c[i] %= 10;
	}
	while(a.c[a.l+1]) a.l ++;		
}

void minus(BigNum& a , const BigNum& b){
	// BigNum a -= b
	// ÕâÀïÄ¬ÈÏa > b
	for(int i=1; i<=a.l; i++){
		a.c[i] -= b.c[i];
		if(a.c[i] < 0){
			a.c[i+1]--;
			a.c[i] += 10;
		}
	}
	while(a.l && !a.c[a.l]) a.l--;
}

void mul_int(BigNum& a , int k){
	// BigNum a *= int(k)
	for(int i=1; i<=a.l; i++){
		a.c[i] = a.c[i] * k + a.c[i-1] / 10;
		a.c[i-1] %= 10;
	}
	while(a.c[a.l] >= 10){
		a.c[a.l + 1] = a.c[a.l] / 10;
		a.c[a.l] %= 10;
		++a.l;
	}
}

void multiply(BigNum& c , const BigNum& a , const BigNum& b){
	// BigNum c = a * b
	memset(c.c , 0 , sizeof(c.c));
	c.l = a.l + b.l - 1;
	int i , j;
	for(i=1; i<=a.l; i++)
		for(j=1; j<=b.l; j++)
			c.c[i+j-1] += a.c[i] * b.c[j];
	for(i=1; i<=c.l; i++){
		c.c[i+1] += c.c[i] / 10;
		c.c[i] %= 10;
	}
	while(c.c[c.l+1]){
		++c.l;
		c.c[c.l + 1] = c.c[c.l] / 10;
		c.c[c.l] %= 10;
	}
}

void print(const BigNum& a){
	for(int i=a.l; i; i--)
		printf("%d" , a.c[i]);
	if(a.l == 0) putchar('0');
	putchar('\n');
}

void div_int(BigNum& a , int k){
	int i , c = 0;
	for(i=a.l; i>0; i--){
		a.c[i] += c * 10;
		c = a.c[i] % k;
		a.c[i] /= k;
	}

	while(a.l > 1 && a.c[a.l] == 0) a.l--;
}


BigNum a , b , c;
char buf[MAXLEN];

int main(){
	int len , i , j;
	while(gets(buf)){
		len = strlen(buf);
		if(len == 0 || len > 1024) puts("0"); //////////////!!!!!!!!!!!!!!!!!!!!!!!!! 
		else{
			if (len % 2) buf[len++] = '0'; 
			a.l = b.l = len / 2;
			memset(a.c , 0 , sizeof(a.c));
			memset(b.c , 0 , sizeof(b.c));

			for(i=0; i<len/2; i++){
				a.c[i+1] = buf[i] - '0';
			}
			for(i=1, j = len-1; j>=len/2; i++ , j--){
				b.c[i] = buf[j] - '0';
			}

			multiply(c , a , b);
			while(c.l > 1 && c.c[c.l] == 0) c.l--;
			print(c);
		}
		
	}
	
	return 0;
}
