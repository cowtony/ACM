#include <stdio.h>
#include <string.h>
#define A else
#define B strlen(d)
#define C char
#define D d[I]
#define E break; 
#define F(x) for(x)
#define G continue;
#define H H
#define I I
#define J J
#define K K
#define L L
#define M memset(r,'0',sizeof(r))
#define N N
#define O O
#define P printf
#define Q(x) return x
#define R r[I]
#define S(x) x<0?0:x
#define T int
#define U 1<<12
#define V T I,J,K
#define W(x) while(x)
#define X(x) if(x)
#define Y fgets(d,U,stdin)
#define Z void
C d[U], r[U]; T N; T L(){ V; F( I=N-1; I>=N/2; I--) X(!(D-48)) D=57; A{ D--; E;}
X((I<<1)<N) Q(0); F( I=J=0; (I<<1)<N; I++){ K=R+D+J-96; J=K/10; R=K%10+48;}W(J){
K=R+J-48; J=K/10;R=K%10+48; I++;} Q(1);} Z O(){V;F(I=U-1;I;I--) X(R-48)E;I=S(I);
W(I >= 0){P("%c",R); I--;}P("%c",10);}int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	V;W(Y){N=B;d[--N]=0;X(N > U-2){
P("0\n");G;}X(N-(N>>1)-(N>>1)){d[N++]='0';d[N]=0;}M;W(L());O();}}