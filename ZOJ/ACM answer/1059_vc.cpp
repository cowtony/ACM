//123456 2003-04-16 13:42:33 Wrong Answer 1059 C++ 00:00.01 468K just for play 
//124983 2003-04-16 23:41:58 Time Limit Exceeded 1059 C++ 00:10.00 468K just for play 
#include<iostream.h>
#include<vector>
#include<stdio.h>
#include<string.h>

using namespace std;

struct str_type
{
	char str[21];
};

vector<str_type>id;
vector<str_type>name;
vector<int>poss_id[21];
vector<int>poss_name[21];
int person_in[21];
int dec_id[21];
int dec_name[21];
int max_n;

int search_str(vector<str_type>& tt,char* find)
{
	int i;
	for(i=0;i<tt.size ();i++)
		if(strcmp(tt[i].str,find)==0)	return i;
	return -1;
}
int search_int(vector<int>& tt,int find)
{
	int i;
	for(i=0;i<tt.size();i++)
		if(tt[i]==find)	return i;
	return -1;
}

void remove_int(vector<int>& tt,int pt)
{
	tt[pt]=tt[tt.size ()-1];
	tt.pop_back();
}

int same(vector<int>& fir,vector<int>& sec)
{
	int i,j;
	if(fir.size()!=sec.size ())	return 0;
	for(i=0;i<fir.size();i++)
	{
		for(j=0;j<sec.size ();j++)
			if(fir[i]==sec[j])	break;
		if(j==sec.size())	return 0;
	}
	return 1;
}

bool exact_fit(vector<int> fir[],vector<int> sec[])
{
	int i,j,t;bool change=false;
//	cout<<max_n<<"-----------"<<endl;
//	cout<<endl;
	for(i=0;i<max_n;i++)
	{
		int flag_fir[21],flag_sec[21];
		int total=0;flag_fir[total++]=i;
		for(j=i+1;j<max_n;j++)
			if(same(fir[i],fir[j]))	flag_fir[total++]=j;
		if(total==fir[i].size ())
		{
			
			for(j=0;j<total;j++)
				flag_sec[j]=fir[i][j];

			for(j=0;j<total;j++)

				if(sec[flag_sec[j]].size()!=total)	break;


			if(j==total)	continue;
			for(j=0;j<total;j++)
			{
				change=true;
				sec[flag_sec[j]].clear();
				for(t=0;t<total;t++)
					sec[flag_sec[j]].push_back(flag_fir[t]);

			}
		}
	}
	return change;
}

void select_sort(vector<str_type>& tt,vector<int> poss[],int total)
{

	int i,j;
	
	for(i=0;i<total;i++)
	{	
		int pt=i;
		for(j=i+1;j<total;j++)		
			if(strcmp(tt[j].str,tt[pt].str)<0)	pt=j;
		if(pt!=i)
		{
			char temp[21];
			strcpy(temp,tt[i].str);
			strcpy(tt[i].str,tt[pt].str);
			strcpy(tt[pt].str,temp);
	
			vector<int> temp_int;
			temp_int.clear();
			for(j=0;j<poss[i].size();j++)
				temp_int.push_back(poss[i][j]);
			poss[i].clear();
			for(j=0;j<poss[pt].size();j++)
				poss[i].push_back(poss[pt][j]);
			poss[pt].clear();
			for(j=0;j<temp_int.size();j++)
				poss[pt].push_back(temp_int[j]);
		}
	}
}

bool occur(vector<int>& tt,int pt)
{
	int i;
	for(i=0;i<tt.size ();i++)
		if(pt==tt[i])	return true;
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int nn;
	cin>>nn;
	while(nn--)
	{
		//int max_n;
		cin>>max_n;
		int i,j;
		for(i=0;i<max_n;i++)	person_in[i]=0;
		id.clear ();name.clear ();
		for(i=0;i<max_n;i++)
		{
			poss_id[i].clear (),poss_name[i].clear ();
			dec_id[i]=0;dec_name[i]=0;
		}
		for(i=0;i<max_n;i++)
			for(j=0;j<max_n;j++)
			{
			
				poss_id[i].push_back (j);
				poss_name[i].push_back (j);
			}
		for(i=0;i<max_n;i++)
		{
			str_type temp;
			cin>>temp.str;
			id.push_back (temp);
		}
		char ch;str_type temp;
		while(cin>>ch)
		{
			if(ch=='Q')	break;
			cin>>temp.str;
			cout<<endl<<ch<<" "<<temp.str<<endl;
			if(ch=='E')
			{
				int pt=search_str(name,temp.str);
			
				if(pt==-1)
				{
					name.push_back(temp);person_in[name.size()-1]=1;
				}
				else	person_in[pt]=1;
			}
			if(ch=='L')
			{
				int pt=search_str(name,temp.str);
				person_in[pt]=0;
			}

			for(i=0;i<max_n;i++)
				if(person_in[i])	cout<<i<<" ";
			cout<<endl;

			if(ch=='M')
			{
				int id_pt=search_str(id,temp.str);
				cout<<"mess:  "<<id_pt<<"  "<<endl;
				int id_name;
				for(i=0;i<poss_id[id_pt].size();i++)
				{
					id_name=poss_id[id_pt][i];
					if(!person_in[id_name]||(!occur(poss_name[id_name],id_pt)))
					{
						remove_int(poss_id[id_pt],i);						
						i--;
					}
				}

				cout<<"    fir  "<<endl;
				for(i=0;i<max_n;i++)
				{
					cout<<i<<"------>  ";
					for(j=0;j<poss_id[i].size();j++)
						cout<<poss_id[i][j]<<"  ";
					cout<<endl;
				}
				cout<<endl;
				cout<<"    sec   "<<endl;
				for(i=0;i<max_n;i++)
				{
					cout<<i<<"----->  ";
					for(j=0;j<poss_name[i].size();j++)
						cout<<poss_name[i][j]<<"  ";
					cout<<endl;
				}
				cout<<endl;

				while(1)
				{
				
					bool change=false;	
					for(i=0;i<max_n;i++)					
						if(!dec_id[i]&&poss_id[i].size()==1)
						{
							id_name=poss_id[i][0];
						
							change=true;
							for(j=0;j<max_n;j++)
							{
								
								int pt=search_int(poss_id[j],id_name);
						
								if(pt!=-1)	remove_int(poss_id[j],pt);
								pt=search_int(poss_name[j],i);
								if(pt!=-1)	remove_int(poss_name[j],pt);
							}							
							poss_id[i].clear();poss_id[i].push_back(id_name);
							poss_name[id_name].clear();poss_name[id_name].push_back(i);												
							dec_id[i]=1;
							dec_name[id_name]=1;
							
						}
				

					for(i=0;i<max_n;i++)					
						if(!dec_name[i]&&poss_name[i].size()==1)
						{
							id_name=poss_name[i][0];
							change=true;
							for(j=0;j<max_n;j++)
							{								
								int pt=search_int(poss_name[j],id_name);
								if(pt!=-1)	remove_int(poss_name[j],pt);
								pt=search_int(poss_id[j],i);
								if(pt!=-1)	remove_int(poss_id[j],pt);
							}							
							poss_name[i].clear();poss_name[i].push_back(id_name);
							poss_id[id_name].clear();poss_id[id_name].push_back(i);												
							dec_name[i]=1;
							dec_id[id_name]=1;							
						}
					change=change|exact_fit(poss_id,poss_name);
	//				change=change|exact_fit(poss_name,poss_id);

					if(!change)	break;
				}
			}
		
		}

		select_sort(name,poss_name,max_n);
		for(i=0;i<max_n;i++)
		{
			cout<<name[i].str<<":";
			if(poss_name[i].size()!=1)
			{
				cout<<"???"<<endl;
				continue;
			}
			cout<<id[poss_name[i][0]].str<<endl;
		}
		if(nn)	cout<<endl;
	}
	return 0;
}


						

					


