 //79407 2003-02-26 22:43:44 Accepted 1019 C++ 00:00.04 476K Century Ghost
 #include<iostream.h>

 struct movetype
 {
	int from,to;
	char direction;
	movetype* next;
 };
 int row,col;int val[101][101];
 int canfrom(int i,int j,movetype* movepoint);

 int main()
 {
	int n;
	cin>>n;
	while(n--)
	{

		cin>>row>>col;
		movetype* head=NULL;
		int i,j;
		for(i=1;i<=row;i++)
			for(j=1;j<=col;j++)	cin>>val[i][j];
		int fir,sec;movetype* movepoint=head;
		while(cin>>fir>>sec)
		{
			if(fir==0&&sec==0)	break;
			movetype* temp=new movetype;
			temp->from=fir;temp->to=sec;
			cin>>temp->direction;
			if(head==NULL){	head=temp;movepoint=temp;}
			else{movepoint->next=temp;movepoint=temp;}
		}
		int count=0;
		for(i=1;i<=row;i++)
			for(j=1;j<=col;j++)
			{
				movepoint=head;
				if(!val[i][j]&&canfrom(i,j,movepoint))
					count++;
			}
		cout<<count<<endl;
	}
	return 0;
 }
 int canfrom(int posrow,int poscol,movetype* movepoint)
 {
	if(movepoint==NULL)	return 1;
	for(int t=movepoint->from;t<=movepoint->to;t++)
	{
		int tt;
		if(movepoint->direction=='R')
		{
			for(tt=poscol+1;tt<=poscol+t;tt++)
				if(tt>col||val[posrow][tt]==1)	break;
			if(tt==poscol+t+1&&canfrom(posrow,poscol+t,movepoint->next))	return 1;
		}
		if(movepoint->direction=='L')
		{
			for(tt=poscol-1;tt>=poscol-t;tt--)
				if(tt<1||val[posrow][tt]==1)	break;
			if(tt==poscol-t-1&&canfrom(posrow,poscol-t,movepoint->next))	return 1;
		}
		if(movepoint->direction=='D')
		{
			for(tt=posrow+1;tt<=posrow+t;tt++)
				if(tt>row||val[tt][poscol]==1)	break;
			if(tt==posrow+t+1&&canfrom(posrow+t,poscol,movepoint->next))	return 1;
		}
		if(movepoint->direction=='U')
		{
			for(tt=posrow-1;tt>=posrow-t;tt--)
				if(tt<1||val[tt][poscol]==1)	break;
			if(tt==posrow-t-1&&canfrom(posrow-t,poscol,movepoint->next))	return 1;
		}
	}
	return 0;
 }







