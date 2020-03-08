 //79646 2003-02-27 13:35:01 Wrong Answer 1103 C++ 00:00.85 1144K Century Ghost
 //79944 2003-02-28 00:02:12 Accepted 1103 C++ 00:00.03 1372K Century Ghost

 #include<iostream.h>

 const int max=11;
 struct state
 {
	int one,two,three;
	int val;
	state* next;
 };

 int n;
 char flag[51][51];
 int visit[max][max][max];
 int occur(int fir,int sec,int thi)
 {
	if(visit[fir][sec][thi]||visit[fir][thi][sec]||
	   visit[sec][fir][thi]||visit[sec][thi][fir]||
	   visit[thi][fir][sec]||visit[thi][sec][fir])
	   return 1;
	return 0;
 }


 int hike(state* head)
 {
	state* from=head;state* to=head;
	while(1)
	{
		if(from==NULL)	break;
		int i,j;
		for(i=0;i<3;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(flag[from->one][j]==flag[from->two][from->three]&&
				  !occur(j,from->two,from->three))
				 {      visit[j][from->two][from->three]=1;
					state* temp=new state;
					temp->one=j;temp->two=from->two;temp->three=from->three;
					temp->val=from->val+1;
					temp->next=NULL;
					to->next=temp;to=temp;
					if(temp->one==temp->two&&temp->one==temp->three)
						return temp->val;

				 }
			}
			int tt=from->one;from->one=from->two;from->two=from->three;from->three=tt;
		}
		from=from->next;
	}
	return -1;

 }
 int main()
 {

	while(cin>>n)
	{
		if(n==0)	break;
		int i,j,t;
		state* head=new state;
		cin>>head->one>>head->two>>head->three;
		head->val=0;
		head->next=NULL;

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)	cin>>flag[i][j];
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(t=1;t<=n;t++)
					visit[i][j][t]=0;
		visit[head->one][head->two][head->three]=1;
		if(head->one==head->two&&head->one==head->three){cout<<"0"<<endl;continue;}
		int result=hike(head);
		if(result==-1)	cout<<"impossible"<<endl;
		else	cout<<result<<endl;
	}
	return 0;
 }
