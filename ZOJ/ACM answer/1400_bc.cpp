//58616 2002-11-25 22:07:24 Accepted 1400 C++ 00:00.00 500K Century Ghost 
#include<iostream.h>
#include<string.h>
#include<math.h>


 struct teamclass
 {
	char name[11];
	int totaltime;
	int geotime;
	int time[7];
	int solved;
 };
  teamclass team[50][21];
 int cmp(teamclass fir,teamclass sec)
 {
	if(fir.solved>sec.solved )      return 1;
	else if(fir.solved<sec.solved ) return 0;
	if(fir.totaltime<sec.totaltime ) return 1;
	else if(fir.totaltime>sec.totaltime)    return 0;
	if(fir.geotime<sec.geotime)	return 1;
	else if(fir.geotime>sec.geotime)	return 0;
	if(strcmp(fir.name,sec.name)<0) return 1;
	return 0;
 }

 void sort(int count,int n)
 {
	int i,j;
	for(i=0;i<n;i++)
	{       int pt=i;
		for(j=i+1;j<n;j++)
			if(cmp(team[count][j],team[count][pt]))
				pt=j;
		if(pt!=i)
		{       teamclass temp=team[count][i];
			team[count][i]=team[count][pt];
			team[count][pt]=temp;
		}
	}
 }
 int lgth(int num)
 {
	int len=1;
	while(num/10!=0)
 	{       num/=10;
		len++;
	}
	return len;
 }
 int same(teamclass fir,teamclass sec)
 {
        if(fir.solved !=sec.solved )    return 0;
        if(fir.totaltime !=sec.totaltime )      return 0;
        if(fir.geotime !=sec.geotime )  return 0;
        return 1;
 }

int main()
{

	int n[50];int t;int i,j;int count=0;
	while(1)
	{
		cin>>n[count];
		if(n[count]==0)        break;

		for(t=0;t<n[count];t++)
		{
			cin>>team[count][t].name;int temp=0;
			for(i=0;i<7;i++){
				cin>>team[count][t].time[i];
				temp+=team[count][t].time[i];
			}
			team[count][t].totaltime=temp;
			float ttt=0; int add=0;
			for(i=0;i<7;i++)
				if(team[count][t].time[i]!=0)
				{       add++;
					ttt+=log(team[count][t].time[i]);
				}
			if(add==0)      team[count][t].geotime=0;
			else    team[count][t].geotime=exp(ttt/add)+0.5;
			team[count][t].solved=add;
		}
		sort(count,n[count]);
		count++;
	}

		int space[7];int namesp;int totalsp,geosp;
		int max1=0,max2=0,max3=0;
		for(t=0;t<count;t++)
		for(i=0;i<n[t];i++)
		{       int len=strlen(team[t][i].name);
			if(len>max1)     max1=len;
			len=lgth(team[t][i].totaltime );
			if(len>max2)    max2=len;
			len=lgth(team[t][i].geotime );
			if(len>max3)    max3=len;
		}
		namesp=max1;totalsp=max2;geosp=max3;
		for(i=0;i<7;i++)
		{int max=0;
		for(t=0;t<count;t++)
		{
			for(j=0;j<n[t];j++)
			{
				int len=lgth(team[t][j].time[i]);
				if(len>max)     max=len;
			}

		}
		space[i]=max;
		}

	for(t=0;t<count;t++)
	{
		cout<<"CONTEST "<<(t+1)<<endl;
                int rank=-1;
		 for(i=0;i<n[t];i++)
		{
                        if(rank==-1||!same(team[t][i],team[t][i-1]))    rank=(i+1);

			if(rank<10)        cout<<"0";
			cout<<rank<<" ";
                        cout.unsetf(ios::right);
			cout.width(namesp);
			cout.setf(ios::left);

			cout<<team[t][i].name;
			cout<<" ";
			cout<<team[t][i].solved;
			cout<<" ";
                        cout.unsetf(ios::left);
			cout.width(totalsp);
			cout.setf(ios::right);
			cout<<team[t][i].totaltime;
			cout<<" ";

			cout.width(geosp);
			cout.setf(ios::right);
			cout<<team[t][i].geotime;
			for(j=0;j<7;j++)
			{
				cout<<" ";

				cout.width(space[j]);
				cout.setf(ios::right);
				cout<<team[t][i].time[j];
			}
			cout<<endl;
		}

	}
       
	return 0;
}
