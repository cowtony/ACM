
#include<iostream.h>
#include<string.h>
#define MAXARRAY 267
#define MAXSTR 50
typedef struct{
	int flag;
	int value;
}tree;

tree treeArray[MAXARRAY];

int a_to_i(char number[],int length);
void initializeTree();
void outputTree(int maxpos);
void handle();

int main()
{
	handle();
	return 0;
}

int a_to_i(char number[],int length)
{
	int i;
	int sum=0;
	for(i=0;i<length;i++){
		sum*=10;
		sum+=number[i]-'0';
	}
	return sum;
}

void outputTree(int maxpos)
{
	int i,t;
	for(i=maxpos;i>0;i--){
		if(treeArray[i].flag){
			t=i/2;
			if(treeArray[t].flag==0&&t!=0){
				cout<<"not complete"<<endl;
				return;
			}
		}
	}
	for(i=1;i<maxpos;i++){
		if(treeArray[i].flag)
			cout<<treeArray[i].value<<" ";
	}
	if(treeArray[i].flag)
		cout<<treeArray[i].value<<endl;
}

void initializeTree()
{
	int i;
	for(i=0;i<MAXARRAY;i++)
		treeArray[i].flag=0;
}

void handle()
{
	char ch,chtemp;
	char szNum[MAXSTR];
	int i,pos,maxpos,nNum;
	ch=chtemp=' ';
	i=0;
	pos=1;
	maxpos=1;
	while(cin>>ch){
		if(chtemp=='('&&ch==')'){
			outputTree(maxpos);
			initializeTree();
			i=0;
			pos=1;
			maxpos=1;
		}
		else if(ch>='0'&&ch<='9'){
			szNum[i++]=ch;
		}
		else if(ch==','){
			nNum=a_to_i(szNum,i);
			i=0;
		}
		else if(ch=='L')
			pos=pos*2;
		else if(ch=='R')
			pos=pos*2+1;
		else if(ch==')'){
			treeArray[pos].flag=1;
			treeArray[pos].value=nNum;
			if(pos>maxpos)
				maxpos=pos;
			i=0;
			pos=1;
		}
		chtemp=ch;
	}
}

