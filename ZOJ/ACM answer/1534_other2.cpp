//126929 2003-04-18 11:09:27 Wrong Answer 1534 C++ 00:00.00 436K just for play 
//126940 2003-04-18 11:18:20 Wrong Answer 1534 C++ 00:00.01 436K just for play 
#include<iostream.h>
#include<string.h>
//#include<stdio.h>

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	char word[300];char lineword[300];
	while(cin>>word)
	{
		int line;
		cin>>line;
		cin.getline(lineword,300,'\n');
		int curline=2;int found=false;int end_line,end_pt;
		while(cin.getline(lineword,300,'\n'))
		{
	//		cout<<lineword<<"---"<<endl;
			if(found)
			{	curline++;
				if(curline-2==line)	break;
				continue;
			}	
			char curword[300];int pt=0;
			int i;
			int len=strlen(lineword);
			for(i=0;i<=len;i++)
			{
				if(i==len||lineword[i]==' ')
				{
					curword[pt]='\0';
				//	cout<<curword<<"----"<<endl;
					if(strcmp(curword,word)==0)
					{	
						found=true;
						end_line=curline+1;
						end_pt=i+1;
						break;
					}
					pt=0;
				}
				else	curword[pt++]=lineword[i];
			}
			curline++;
			if(curline-2==line)	break;
		}
		if(found)
			cout<<end_line<<" "<<end_pt<<endl;
		else	cout<<"0 0"<<endl;
	}
	return 0;
}



