#include<iostream.h>
#include<string.h>

char from[50], dest[50];
int  oper[50];
unsigned int  size, maxdepth;

int oper_ok(int total)
{
	int from=size, stack=0;
	for (int i=1; i<=total; i++){
		if (oper[i]==1) {
			if (from==0) return 0;
				else {from--; stack++;}
		} else{
			if (stack==0) return 0;
				else stack--;
		}
	}
	return 1;
}
int is_answer()
{
	char a[50]="\0",b[50]="\0",c[50]="\0";
	char temp[50];
	strcpy(a,from);

	strcpy(c,dest);

	for ( int i=1; i<=maxdepth; i++) {
		if (oper[i]==1) {
			strcpy(temp,a);temp[1]='\0';
			strcat(b,temp);
			strcpy(a,(a+1));
		} else {
			if ( b[strlen(b)-1]!= c[0]) return 0;
			else b[strlen(b)-1]='\0';
			     strcpy(c,(c+1));
		}
	}
	return 1;
}

void print()
{
	for (int i=1; i<=maxdepth; i++) {
		if (oper[i]==1) cout<<"i ";
		else		cout<<"o ";
	}
	cout<<endl;
}


void search(int depth)
{       if (depth>maxdepth) return;
	else if (depth<maxdepth) {
		oper[depth]=1;
		if (oper_ok(depth)) search(depth+1);
		oper[depth]=0;
		if (oper_ok(depth)) search(depth+1);
	} else {
		if (is_answer()) print();
	}
}

int main()
{
	while(cin>>from>>dest) {
		size=strlen(from); maxdepth=2*size;
		cout<<"["<<endl;
		if (size==strlen(dest)) search(1);
		cout<<"]"<<endl;
	}
	return 0;
} 
