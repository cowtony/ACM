//100188 2003-03-27 20:58:25 Wrong Answer 1220 C++ 00:00.00 448K Century Ghost 
//100194 2003-03-27 21:00:58 Wrong Answer 1220 C++ 00:00.00 448K Century Ghost 

#include<iostream.h>
#include<vector>

#include<fstream.h>
ifstream fcin("in.txt");
ofstream fout("out.txt");

using namespace std;
struct nametype
{
	char ch[11];
};
struct genetype
{
	char gch[4];
};
vector<nametype>name;
vector<genetype>gene;


int main()
{
	char from[11];char to[11];
	char temp[11];char tempch;
	name.clear();gene.clear();
	nametype firgene;
	strcpy(firgene.ch,"ADAM");
	name.push_back(firgene);
	while(fcin>>temp)
	{
		fcin>>from;
		fcin>>temp;
		fcin>>to;
		vector<genetype>tempgene;
		tempgene.clear();
		fcin.get(tempch);
		if(tempch==' ')
		{
			fcin>>temp;
			while(fcin.get(tempch))
			{
				if(tempch=='\n')	break;
				genetype ttgene;
				fcin>>ttgene.gch;
				tempgene.push_back(ttgene);
			}
		}
		int i;
		for(i=0;i<name.size();i++)
			if(strcmp(to,name[i].ch)==0)	break;
		fout<<"clone "<<from<<" from "<<to;
		if(i==name.size())		
			fout<<" has no connection to ADAM"<<endl;
		else
		{
			int j,t;int flag=0;
			for(j=0;j<tempgene.size();j++)
			{
				for(t=0;t<gene.size();t++)
					if(strcmp(tempgene[j].gch,gene[t].gch)==0)	break;
				if(t<gene.size())	break;
			}
			if(j<tempgene.size())			
				fout<<" was at least twice mutated with "<<tempgene[j].gch<<endl;
			else{	fout<<" is consistent and safe"<<endl;
					nametype ntemp;
					strcpy(ntemp.ch,from);
					name.push_back(ntemp);			
					for(i=0;i<tempgene.size();i++)
						gene.push_back(tempgene[i]);
			}
			
		}
	}
	return 0;
}
			

				


		
			



		


