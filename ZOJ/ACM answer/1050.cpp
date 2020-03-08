//116708 2003-04-11 21:38:44 Wrong Answer 1050 C++ 00:00.01 456K just for play 
//116718 2003-04-11 21:44:42 Accepted 1050 C++ 00:00.01 452K just for play 
#include<iostream.h>
#include<string.h>
#include<vector>
#include<math.h>

using namespace std;
struct term_type
{
	char* str;
	int occurtime;
	int totaloccur;
	term_type(char* tt)
	{
		occurtime=0;
		int len=strlen(tt);
		str=new char[len+1];
		strcpy(str,tt);
	}
};

vector<term_type>term;

int valid(char ch)
{
	if(ch>='0'&&ch<='9')	return 1;
	if(ch>='a'&&ch<='z')	return 1;
	if(ch>='A'&&ch<='Z')	return 1;
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int nn;int t;
	cin>>nn;
	
	for(t=0;t<nn;t++)
	{
		term.clear();
		if(t)	cout<<endl;
		char input[300];
		cin.getline(input,300,'\n');
//		cout<<input<<endl;
		int i,j;
		int len;
		while(1)
		{	
			cin.getline(input,300,'\n');
//			cout<<input<<endl;
			if(strcmp(input,"----------")==0)	break;
			len=strlen(input);
			char temp[250];int pt=0;
			for(i=0;i<=len;i++)
			{	
				if(i==len||input[i]==' ')
				{
					temp[pt]='\0';
					
					if(strlen(temp)!=0)
					{

						term_type temp_term(temp);
						temp_term.occurtime=1;
						for(j=0;j<term.size();j++)
							if(strcmp(term[j].str,temp_term.str)==0)	break;
						if(j==term.size())
							term.push_back(temp_term);
						else	term[j].occurtime++;
					}
					pt=0;
				}
				else if(valid(input[i]))	
				{
					temp[pt]=input[i];
					if(temp[pt]>='A'&&temp[pt]<='Z')	temp[pt]=temp[pt]-'A'+'a';
					pt++;
				}
			}
		}
/*		for(i=0;i<term.size();i++)
		{
			cout<<term[i].str<<"-----"<<term[i].occurtime<<endl;
		}
*/
		while(1)
		{
		
			bool fir_str=true;
			for(i=0;i<term.size();i++)
				term[i].totaloccur=0;
			while(1)
			{	
				cin.getline(input,300,'\n');
//				cout<<input<<endl;
				if(strcmp(input,"----------")==0)	break;
				fir_str=false;
				len=strlen(input);
				char temp[250];int pt=0;
				for(i=0;i<=len;i++)
				{	
					if(i==len||input[i]==' ')
					{
						temp[pt]='\0';
//						cout<<temp<<"===="<<endl;
						if(strlen(temp)!=0)
						{
							for(j=0;j<term.size();j++)
								if(strcmp(term[j].str,temp)==0)	break;
							if(j<term.size())							
								term[j].totaloccur+=term[j].occurtime;
						}
						pt=0;
					}
					else if(valid(input[i]))	
					{
						temp[pt]=input[i];
						if(temp[pt]>='A'&&temp[pt]<='Z')	temp[pt]=temp[pt]-'A'+'a';
						pt++;
					}
				}
			}
			
			if(fir_str)	break;
			double total=0;
			for(i=0;i<term.size();i++)			
				total+=sqrt((double)term[i].totaloccur);

			cout.precision(2);
			cout.setf(ios::fixed|ios::showpoint);
			cout<<total<<endl;

		}
	}
	return 0;
}

		













		
	




