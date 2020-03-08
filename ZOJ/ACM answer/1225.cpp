//101293 2003-03-29 02:09:53 Accepted 1225 C++ 00:00.00 452K Century Ghost 
#include<iostream.h>
#include<string.h>
#include<vector>
/*
#include<fstream.h>
ifstream cin("in.txt");
ofstream cout("out.txt");
*/
using namespace std;
struct chtype
{
	char ch[101];
};
vector<chtype>input;

void exchange(int i,int j)
{
	chtype temp;
	strcpy(temp.ch,input[i].ch);
	strcpy(input[i].ch,input[j].ch);
	strcpy(input[j].ch,temp.ch);
}
int isnum(int k)
{
	
	if(input[k].ch[0]=='-'||(input[k].ch[0]>='0'&&input[k].ch[0]<='9'))	return 1;
	return 0;
}
int numsmall(int j,int k)
{
	if(input[j].ch[0]=='-'&&input[k].ch[0]!='-')	return 1;
	if(input[j].ch[0]!='-'&&input[k].ch[0]=='-')	return 0;
	if(input[j].ch[0]=='-'&&input[k].ch[0]=='-')
	{
		int i;
		int len1=strlen(input[j].ch);
		int len2=strlen(input[k].ch);
		if(len1>len2)	return 1;
		if(len1<len2)	return 0;
		for(i=0;i<len1;i++)
		{
			if(input[j].ch[i]<input[k].ch[i])	return 0;
			if(input[j].ch[i]>input[k].ch[i])	return 1;
		}
		return 0;
	}
	else
	{
		int i;
		int len1=strlen(input[j].ch);
		int len2=strlen(input[k].ch);
		if(len1>len2)	return 0;
		if(len1<len2)	return 1;
		for(i=0;i<len1;i++)
		{
			if(input[j].ch[i]<input[k].ch[i])	return 1;
			if(input[j].ch[i]>input[k].ch[i])	return 0;
		}
		return 0;
	}
}




void sortnum()
{
	int i,j;int pt;
	for(i=0;i<input.size();i++)
	{
		if(!isnum(i))	continue;
		pt=i;
		for(j=i+1;j<input.size();j++)
			if(isnum(j)&&numsmall(j,pt))	pt=j;
		if(pt!=i)
			exchange(i,pt);
	}
}
int smallch(int j,int k)
{
	int i;
	int len1=strlen(input[j].ch);
	int len2=strlen(input[k].ch);
	for(i=0;;i++)
	{
		if(i>=len1)	return 1;
		if(i>=len2)	return 0;
		char ch1,ch2;
		ch1=input[j].ch[i];
		if(ch1>='a')	ch1-='a'-'A';
		ch2=input[k].ch[i];
		if(ch2>='a')	ch2-='a'-'A';

		if(ch1>ch2)	return 0;
		if(ch1<ch2)	return 1;
	}
	return 0;
}
void sortchar()
{
	int i,j;int pt;
	for(i=0;i<input.size();i++)
	{
		if(isnum(i))	continue;
	
		pt=i;
		for(j=i+1;j<input.size();j++)
			if(!isnum(j)&&smallch(j,pt))	pt=j;
	
		if(pt!=i)	exchange(i,pt);
	}
}


int main()
{
	chtype intemp;
	while(cin>>intemp.ch)
	{
		if(strcmp(intemp.ch,".")==0)	break;
		input.clear();		
		while(1)
		{
			int len=strlen(intemp.ch);
			char tempch=intemp.ch[len-1];
			intemp.ch[len-1]='\0';
			input.push_back(intemp);
			if(tempch=='.')	break;
			cin>>intemp.ch;
		}

		sortnum();
		sortchar();
		int i;
		for(i=0;i<input.size()-1;i++)
			cout<<input[i].ch<<", ";
		cout<<input[i].ch<<"."<<endl;
	}
	return 0;
}

		
	