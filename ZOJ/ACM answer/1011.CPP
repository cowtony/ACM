 #include<iostream.h>


 struct node
 {
	int left;int right;
	node* next;

 };

 char ch[12][30];
 node* signal[16][11];
  int can[12][11];
 int accept[16];
 int m,n,k,levnum;
 void input_first()
 {
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<k;j++)
		{
			signal[i][j]=NULL;node* move;
			char ch;
			if(i==0&&j==0)	cin.get();
			cin.get(ch);int flag=0;
			while(ch!='\n')
			{
				if(flag==1) cin.get(ch);
				flag=1;
				int first=ch-48;
				node* temp=new node;
				temp->next=NULL;
				cin.get(ch);
				if(ch!=32)
				{	temp->left=first*10+ch-48;
					cin.get();
				}else	temp->left=first;
				cin.get(ch);
				int second=ch-48;
				cin.get(ch);
				if(ch!=32&&ch!='\n')
				{	temp->right=second*10+ch-48;
					cin.get(ch);
				}else temp->right=second;
				if(signal[i][j]==NULL)	signal[i][j]=temp;
				else	move->next=temp;
				move=temp;

			}
		}
 }

 int try_doing(int lev,int dep,int sig)
 {

	if(ch[lev][dep]=='*')
	{
		if(accept[sig])	return 1;
		return 0;
	}

	int ch_num=ch[lev][dep]-97;
	if(can[lev][ch_num]) return 1;
	int i;
	if(lev==levnum)
	{
		node* move=signal[sig][ch_num];
		while(move!=NULL)
		{
			if(accept[move->left]&&accept[move->right])
			{
				can[lev][ch_num]=1;
				return 1;
			}
			move=move->next;
		}
		can[lev][ch_num]=0;
		return 0;
	}
	int flag=0;
	node* move=signal[sig][ch_num];
	while(move!=NULL)
	{
		if(try_doing(lev+1,dep*2-1,move->left)&&try_doing(lev+1,dep*2,move->right))
		{
			    flag=1;	break;
		}
		move=move->next;
	}
	if(!flag){	can[lev][ch_num]=0;return 0;}
	can[lev][ch_num]=1;
	return 1;
 }

 int doing()
 {
	int i;
	for(i=0;i<m;i++)
	{
		try_doing(1,1,i);
		if(can[1][ch[1][1]-97])	return 1;
	}
	return 0;
 }
 int main()
 {
	int count=0;
	while(1)
	{
		count++;
		cin>>m>>n>>k;
		if(m==0&&n==0&&k==0) 	break;
		if(count!=1) cout<<endl;
		cout<<"NTA"<<count<<":"<<endl;
		int i;int j;
		for(i=0;i<m;i++)	accept[i]=0;
		for(i=m-1;i>=m-n;i--)	accept[i]=1;
		input_first();
		while(1)
		{
			cin>>levnum;
			if(levnum==-1)	break;
			levnum++;
			for(i=1;i<=levnum;i++)
				for(j=0;j<k;j++)
					can[i][j]=0;
			int deep=1;
			for(int k=1;k<=levnum;k++)
			{
				for(int jj=1;jj<=deep;jj++)
					cin>>ch[k][jj];
				deep*=2;
			}
			int pos=doing();
			if(pos==1) cout<<"Valid"<<endl;
			else cout<<"Invalid"<<endl;
		}
		for(i=0;i<m;i++)
			for(j=0;j<k;j++)
			{
				node* move=signal[i][j];
				while(move!=NULL)
				{
					node* temp=move;
					move=move->next;
					delete temp;
				}
			}

	}
	return 0;
 }





