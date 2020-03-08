//91964 2003-03-18 23:48:52 Wrong Answer 1190 C++ 00:01.78 452K Century Ghost 
//91972 2003-03-19 00:00:34 Wrong Answer 1190 C++ 00:01.80 452K Century Ghost 
//91986 2003-03-19 00:09:28 Accepted 1190 C++ 00:01.79 452K Century Ghost 
#include<iostream.h>
#include<stack>
#include<string.h>
#include<math.h>



using namespace std;

stack<long>in[10];
long out[10];
char str[5][4];
int select[11];
int length;
int n;
int cur[10];
void initial()
{
	strcpy(str[0],"ADD");
	strcpy(str[1],"DIV");
	strcpy(str[2],"DUP");
	strcpy(str[3],"MUL");
	strcpy(str[4],"SUB");
}
void search(int lev)
{
//	cout<<lev<<endl;
	int i;
	//for(i=0;i<lev;i++)
	//	cout<<cur[i]<<" ";
	//cout<<endl;
	if(in[0].size()==1)
	{
		for(i=0;i<n;i++)
		{
		
			if(in[i].top()!=out[i])	break;
		}
		if(i==n&&(length==-1||lev<length))
		{	//cout<<lev<<"-----------"<<endl;
			for(i=0;i<lev;i++)	select[i]=cur[i];
			length=lev;
		}
	}
	if(lev>=10||(length!=-1&&lev>=length))	return;
//	cout<<in[0].size()<<"======="<<endl;
//	cout<<(in[0].size()-10+lev)<<".........."<<endl;
	if(in[0].size()>10-lev+1)	return;
	long fir[10],sec[10];
	if(in[0].size()>=2)
	{	//add
		
		for(i=0;i<n;i++)
		{
			fir[i]=in[i].top();in[i].pop();
			sec[i]=in[i].top();in[i].pop();
		}
		for(i=0;i<n;i++)
			if(abs(fir[i]+sec[i])>30000)	break;
		if(i==n)
		{
			cur[lev]=0;
			for(i=0;i<n;i++)	in[i].push(sec[i]+fir[i]);
			search(lev+1);
			for(i=0;i<n;i++)	in[i].pop();
		}
		for(i=0;i<n;i++)
		{
			in[i].push(sec[i]);in[i].push(fir[i]);
		}
	}
	if(in[0].size()>=2)
	{	//div
		
		for(i=0;i<n;i++)
		{
			fir[i]=in[i].top();in[i].pop();
			sec[i]=in[i].top();in[i].pop();
		}
		for(i=0;i<n;i++)
			if(fir[i]==0)	break;
		if(i==n)
		{
			cur[lev]=1;
			for(i=0;i<n;i++)	in[i].push(sec[i]/fir[i]);
			search(lev+1);
			for(i=0;i<n;i++)	in[i].pop();
		}
		for(i=0;i<n;i++)
		{
			in[i].push(sec[i]);in[i].push(fir[i]);
		}
	}
	if(in[0].size()>0){	//dup
		
		for(i=0;i<n;i++)	fir[i]=in[i].top();
			cur[lev]=2;
		for(i=0;i<n;i++)	in[i].push(fir[i]);
			search(lev+1);
		for(i=0;i<n;i++)	in[i].pop();
	}
	if(in[0].size()>=2)
	{	//mul
		
		for(i=0;i<n;i++)
		{
			fir[i]=in[i].top();in[i].pop();
			sec[i]=in[i].top();in[i].pop();
		}
		for(i=0;i<n;i++)
			if(abs(sec[i]*fir[i])>30000)	break;
		
		if(i==n)
		{
			cur[lev]=3;
		
			for(i=0;i<n;i++){	in[i].push(sec[i]*fir[i]);}
			search(lev+1);
			for(i=0;i<n;i++)	in[i].pop();
		}
		for(i=0;i<n;i++)
		{
			in[i].push(sec[i]);in[i].push(fir[i]);
		}
	}
	if(in[0].size()>=2)
	{	//sub
	
		for(i=0;i<n;i++)
		{
			fir[i]=in[i].top();in[i].pop();
			sec[i]=in[i].top();in[i].pop();
		}
		for(i=0;i<n;i++)
			if(abs(sec[i]-fir[i])>30000)	break;
		if(i==n)
		{
			cur[lev]=4;
			for(i=0;i<n;i++)	in[i].push(sec[i]-fir[i]);
			search(lev+1);
			for(i=0;i<n;i++)	in[i].pop();
		}
		for(i=0;i<n;i++)
		{
			in[i].push(sec[i]);in[i].push(fir[i]);
		}
	}
}
int main()
{
	initial();
	int count=0;
	while(1)
	{
		int i;
		length=-1;
		cin>>n;
		if(n==0)	break;
		count++;long temp;
		for(i=0;i<n;i++)
			while(!in[i].empty())	in[i].pop();
		for(i=0;i<n;i++)
		{
			cin>>temp;
			in[i].push(temp);
		}
		for(i=0;i<n;i++)	cin>>out[i];
		search(0);
		cout<<"Program "<<count<<endl;
		if(length==-1)
			cout<<"Impossible"<<endl;
		else if(length==0)
			cout<<"Empty sequence"<<endl;
		else
		{
			for(i=0;i<length;i++)
			{
				if(i)	cout<<" ";
				cout<<str[select[i]];
			}
			cout<<endl;
		}	
		cout<<endl;
	}
	return 0;
}
