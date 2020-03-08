 #include<iostream.h>

 struct node
 {      int val;
	node* link;
 };
 node* head[27];int dfn[27];int visit[27];
 int errorflag,determined;
 int temerror,temdet;
 int find(int to,int from)
 {      if(to==from)	return 1;
	node* temmov=head[to];
	while(temmov!=NULL)
	{
		if(find(temmov->val,from))	return 1;
		temmov=temmov->link;
	}
	return 0;
 }
 void adjust(int from,int lev)
 {
	node* temmov=head[from];
	while(temmov!=NULL)
	{
		dfn[temmov->val]=lev+1;
		adjust(temmov->val,lev+1);
		temmov=temmov->link;
	}
 }

 int main()
 {
	int m,n;
	while(1)
	{
		cin>>n>>m;
		if(m==0&&n==0)	break;
		int i,j;int pt1,pt2;
		for(i=0;i<=n;i++){ head[i]=NULL;dfn[i]=0;}
		int occur[27];node* mov[27];
		for(i=0;i<=n;i++)	mov[i]=head[i];
		errorflag=0;determined=0;
		for(i=1;i<=m;i++)
		{
			char ch1,ch2,ch3;
			cin>>ch1>>ch2>>ch3;
			int from=ch1-64;int to=ch3-64;
			if(errorflag)	continue;
			if(determined)	continue;

			if(!dfn[from])
			{
				dfn[from]=1;
				node* temp=new node;
				temp->val=from;
				temp->link=NULL;

				if(head[0]==NULL)	head[0]=temp;
				else	mov[0]->link=temp;
				mov[0]=temp;
				if(!dfn[to])	dfn[to]=2;
				else if(dfn[to]==1)
				{	node* temmov=head[0];node* pre=NULL;
					while(temmov->val!=to)
					{pre=temmov;temmov=temmov->link;}
					if(pre==NULL)	head[0]=temmov->link;
					else	pre->link=temmov->link;
					dfn[to]=2;
					adjust(to,2);
				}
				temp=new node;
				temp->val=to;
				temp->link=NULL;

				if(head[from]==NULL)	head[from]=temp;
				else	mov[from]->link=temp;
				mov[from]=temp;
			}
			else if(dfn[from]&&!dfn[to])
			{
				node* temp=new node;
				temp->val=to;
				temp->link=NULL;
				if(head[from]==NULL)	head[from]=temp;
				else	mov[from]->link=temp;
				mov[from]=temp;
				dfn[to]=dfn[from]+1;
			}
			else if(dfn[from]&&dfn[to])
			{
				node* temp=new node;
				temp->val=to;
				temp->link=NULL;
				if(head[from]==NULL)	head[from]=temp;
				else	mov[from]->link=temp;
				mov[from]=temp;
				if(dfn[from]<dfn[to]) continue;
				if(dfn[from]>=dfn[to])
				{
					if(find(to,from)){pt1=i;errorflag=1;continue;}
					else{dfn[to]=dfn[from]+1;
						adjust(to,dfn[to]);
					}
				}
			}
			for(j=1;j<=n;j++)	if(dfn[j]==n)	break;
			if(j<=n){	determined=1;pt2=i;}
		}
		if(errorflag)
		{
			cout<<"Inconsistency found after "<<pt1<<" relations."<<endl;continue;}
		if(determined)
		{  cout<<"Sorted sequence determined after "<<pt2<<" relations: ";
		   for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(dfn[j]==i)
				{	cout<<char(j+64);
					break;
				}
		   cout<<"."<<endl;
		   continue;
		}
		cout<<"Sorted sequence cannot be determined."<<endl;

	}
	return 0;
 }



