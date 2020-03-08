 #include<iostream.h>


 struct node
 {
	int left;int right;


 };

 char ch[20][30];
 node signal[20][20][30];
 int add[20][20];

 int accept[20];
 int m,n,k,levnum;
 void input_first()
 {
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<k;j++)
		{
			int pt=0;
			char ch;
			if(i==0&&j==0)	cin.get();
			cin.get(ch);int flag=0;
			while(ch!='\n')
			{

				if(flag==1) cin.get(ch);
				flag=1;
				int first=ch-48;
				node temp;

				cin.get(ch);
				if(ch!=32)
				{	temp.left=first*10+ch-48;
					cin.get();
				}else	temp.left=first;
				cin.get(ch);
				int second=ch-48;
				cin.get(ch);
				if(ch!=32&&ch!='\n')
				{	temp.right=second*10+ch-48;
					cin.get(ch);
				}else temp.right=second;
				signal[i][j][pt]=temp;

				pt++;

			}
			add[i][j]=pt-1;
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

	int i;
	if(lev==levnum)
	{
		int t;
		for(t=0;t<=add[sig][ch_num];t++)
		{
			node move=signal[sig][ch_num][t];
			if(accept[move.left]&&accept[move.right])
			{

				return 1;
			}

		}

		return 0;
	}
	int flag=0;

	for(int t=0;t<=add[sig][ch_num];t++)
	{
		node move=signal[sig][ch_num][t];
		if(try_doing(lev+1,dep*2-1,move.left)&&try_doing(lev+1,dep*2,move.right))
		{
			    flag=1;	break;
		}

	}
	if(!flag){return 0;}

	return 1;
 }

 int doing()
 {
	int i;
	for(i=0;i<m;i++)
	{
		if(try_doing(1,1,i)) return 1;;

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

		for(i=m-1;i>=m-n;i--)
		{       if(i<0)	break;
			accept[i]=1;
		}
		input_first();
		while(1)
		{
			cin>>levnum;
			if(levnum==-1)	break;
			levnum++;

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

	}
	return 0;
 }


