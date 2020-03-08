//193699 2003-07-08 18:43:37 Accepted 1534 C++ 00:00.18 440K just for play 
#include<iostream.h>
#include<string.h>
#include<stdio.h>

void make_next(char* input,int next[])
{
	int i,j,len=strlen(input);
	next[0]=-1;
	for(i=1;i<len;i++)
	{
		j=next[i-1];
		while(input[j+1]!=input[i]&&j>=0)	j=next[j];
		if(input[j+1]==input[i])	next[i]=j+1;
		else	next[i]=-1;
	}
}
	
int main()
{
//	freopen("1534.in","r",stdin);
	char input[300];
	while(cin.getline(input,300))
	{
//		cout<<input<<endl;
		int total_line,sel_line=-1,sel_pos=-1;
		char input_ch;int i,j,t;
		int len=strlen(input);
		cin>>total_line;
		cin.get(input_ch);
		int next[300],line[300],pos[300];
		make_next(input,next);
		int cur_line=1,cur_pos=1,word_pos=0;	
		cin.get(input_ch);		
		while(1)
		{
			while(input_ch=='\n')
			{	if(cur_line==total_line)	break;
				cin.get(input_ch);cur_line++;cur_pos=1;
				if(cur_line==total_line)	break;
			}
			if(input_ch=='\n')	break;			
			line[word_pos]=cur_line;
			pos[word_pos]=cur_pos;
			if(input_ch==input[word_pos])
			{	word_pos++;				
				if(word_pos==len)
				{
					sel_line=line[0];sel_pos=pos[0];
					t=next[word_pos-1]+1;
					for(i=0;i<t;i++)
					{line[i]=line[i+word_pos-t];pos[i]=pos[i+word_pos-t];}
					word_pos=t;
					
				}
				cin.get(input_ch);cur_pos++;
			}
			else
			{
				if(word_pos==0)	{cin.get(input_ch);cur_pos++;}
				else
				{					
					t=next[word_pos-1]+1;
					for(i=0;i<t;i++)
					{line[i]=line[i+word_pos-t];pos[i]=pos[i+word_pos-t];}
					word_pos=t;
				}
			}
		}
		if(sel_line==-1)
			cout<<"0 0"<<endl;
		else	cout<<sel_line<<" "<<sel_pos<<endl;;
	}
	return 0;
}





