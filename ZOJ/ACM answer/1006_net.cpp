//AC
#include<iostream.h>
#include<string.h>

char ciphertext[70], plaintext[70];
int  ciphercode[70], plaincode[70];
int  size, key;

void text2code()
{
	for(int i=0; i<size; i++) {
		if (ciphertext[i]==46) {ciphercode[i]=27; continue;}
		if (ciphertext[i]==95) {ciphercode[i]= 0; continue;}
		ciphercode[i]=ciphertext[i]-96;
	}
}
void code2text()
{
	for(int i=0; i<size; i++) {
		if (plaincode[i]== 0) {plaintext[i]=95; continue; }
		if (plaincode[i]==27) {plaintext[i]=46; continue; }
		plaintext[i]=plaincode[i]+96;
	}
}

void untwist()
{
	for( int i=0; i<size; i++){
		plaincode[key*i%size]=(ciphercode[i]+i)%28;
	}
}

int main()
{
	while (cin>>key) {
		if (key==0) break;
		cin>>ciphertext;
		size=strlen(ciphertext);
		text2code();
		untwist();
		code2text();
		plaintext[size]='\0';
		cout<<plaintext<<endl;
	}
	return 0;
}
