#include<iostream.h>
#include<stdio.h>

class coder {
public :void ini(int m,char a[]);
void reini();
void rotate();
int codein(int out);
int oneround();
int codeout(int in);
private:
int adjust;
int map[26];
int mod;
};
void coder::ini(int m, char a[])
{
mod=m;
int n;
for (int i=0; i<mod; i++) {
n=a[i]-65-i;
while (n<0) n+=mod; //until >=0;
map[i]=n;
}
adjust=0;
}
void coder::reini(){ adjust=0;}
void coder::rotate()
{
adjust++;
if (adjust==mod) adjust=0;
}
int  coder::codeout(int in) //send out code file://A=0
{
int pos, result;
pos=in-adjust;
if (pos<0) pos+=mod;
result=map[pos]+in;
if (result>=mod) result-=mod;
return (result);
}
int  coder::codein(int out)
{
for (int i=0; i<mod; i++) {
if (codeout(i)==out)
return i;
}
return 0; //must be impossible
}
int coder::oneround()
{
if (adjust==0) return 1;
return 0;
}

int getline(char line[])
{
char c;
int  i=0;
while((c=getchar())!=10){
line[i]=c;
i++;
}
line[i]='\0';
return i;
}


int main()
{
int total_time;
int mod;
char ciphertext[400];
char list[27];
char plaintext;


coder c[3];
int t=1;
	while (cin>>mod) {
	if (mod==0) break;
	if (t!=1) cout<<endl;
	for (int i=0; i<3; i++) {
	cin>>list;
	c[i].ini(mod, list);
	}
	cin>>total_time;
	cout<<"Enigma "<<t<<":"<<endl;
	for (int cases=1; cases<=total_time; cases++) {
	int len=getline(ciphertext);
	for (int pos=0; pos<len; pos++) {
	plaintext=c[0].codein(c[1].codein(c[2].codein(ciphertext[pos]-65)))+97;
	cout<<plaintext;
	c[0].rotate();
	if (c[0].oneround()) {
	c[1].rotate();
	if (c[1].oneround()) c[2].rotate();
	}
	}
	cout<<endl;
	c[0].reini();
	c[1].reini();
	c[2].reini();
	}
	t++;
		}
		return 0;
		}


