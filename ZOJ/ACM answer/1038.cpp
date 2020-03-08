//82455 2003-03-04 13:21:32 Accepted 1038 C++ 00:00.01 464K Century Ghost
 #include<string.h>
 #include<iostream.h>

 struct numset
 {
	int total;
	char ch[4];
 };
 numset num[10];
 void initial()
 {
	num[2].total=3;num[2].ch[0]='a',num[2].ch[1]='b',num[2].ch[2]='c';
	num[3].total=3;num[3].ch[0]='d',num[3].ch[1]='e',num[3].ch[2]='f';
	num[4].total=3;num[4].ch[0]='g',num[4].ch[1]='h',num[4].ch[2]='i';
	num[5].total=3;num[5].ch[0]='j',num[5].ch[1]='k',num[5].ch[2]='l';
	num[6].total=3;num[6].ch[0]='m',num[6].ch[1]='n',num[6].ch[2]='o';
	num[7].total=4;num[7].ch[0]='p',num[7].ch[1]='q',num[7].ch[2]='r';num[7].ch[3]='s';
	num[8].total=3;num[8].ch[0]='t',num[8].ch[1]='u',num[8].ch[2]='v';
	num[9].total=4;num[9].ch[0]='w',num[9].ch[1]='x',num[9].ch[2]='y';num[9].ch[3]='z';
 }
 struct stringset
 {
	char* string;
	int len;
	int poss;
	int occur;

 };
 stringset* head[1001];int flag[1001];
 int same(char* fir,char* sec,int pt)
 {
	int i;
	for(i=0;i<=pt;i++)
		if(fir[i]!=sec[i])	return 0;
	return 1;
 }

 int main()
 {
	int tt;int i;
	initial();
	cin>>tt;
	for(i=1;i<=tt;i++)
	{
		int total;int j,t;int numtotal;
		cin>>total; char tempstr[101];

		for(j=0;j<total;j++)
		{
			cin>>tempstr;
			head[j]=new stringset;
			head[j]->len=strlen(tempstr);
			head[j]->string=new char[head[j]->len+1];
			strcpy(head[j]->string,tempstr);
			cin>>head[j]->occur;
		}


		cin>>numtotal;

		cout<<"Scenario #"<<i<<":\n";
		for(j=0;j<numtotal;j++)
		{

			for(int k=0;k<total;k++)	flag[k]=1;
			char ch;int pt=0;
			while(cin>>ch)
			{
				if(ch=='1')	break;
				int chnum=ch-'0';int max=-1;int maxpt;

				for(t=0;t<total;t++)
				{
					if(!flag[t])	continue;
					int tm;

					for(tm=0;tm<num[chnum].total;tm++)

						if(pt<head[t]->len&&num[chnum].ch[tm]==head[t]->string[pt])	break;

					if(tm==num[chnum].total)	flag[t]=0;
				}
				for(t=0;t<total;t++)
				{
					if(!flag[t])	continue;
					int tm;
					head[t]->poss=0;
					for(tm=0;tm<total;tm++)
						if(flag[tm]&&same(head[t]->string,head[tm]->string,pt))
							head[t]->poss+=head[tm]->occur;
				}
				for(t=0;t<total;t++)
					if(flag[t]&&head[t]->poss>max){max=head[t]->poss;maxpt=t;}
				if(max==-1)	cout<<"MANUALLY\n";
				else
				{	for(t=0;t<=pt;t++)	cout<<head[maxpt]->string[t];
					cout<<endl;
				}

				pt++;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
 }











