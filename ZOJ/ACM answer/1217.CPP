 #include<iostream.h>


 struct status
 {
	int a[9];
	int white;
	int up;
	int mov;
 };
 status state[10000];

 int valid(int nn)
 {
	for(int i=0;i<8;i++)
		if(state[nn].a[i]!=(i+1))	return 0;
	return 1;
 }

 int unsolved(int nn)
 {
	if(state[nn].a[8]!=0) return 0;
	int add=0;
	for(int i=0;i<8;i++)
		if(state[nn].a[i]!=(i+1))	add++;
	if(add==2) return 1;
	return 0;
 }



 int same(int n)
 {
	for(int i=0;i<n;i++)
	{
		int j;
		for(j=0;j<9;j++)
			if(state[i].a[j]!=state[n].a[j])	break;
		if(j==9)	return 1;
	}
	return 0;
 }
 int doing()
 {
	int first;int second;int i,j;
	first=0;second=0;
	while(1)
	{
		if(first>second)	return 0;
		int beg;int end; int move;
		beg=second+1;move=beg;
		for(i=first;i<=second;i++)
		{
			if(same(i))	continue;

			if(unsolved(i))	continue;
			if(valid(i)) return (i+1);
			int t_wh=state[i].white;
			int t_val=state[i].mov;
			if(t_wh>2&&t_val!=3)
			{

				for(j=0;j<9;j++)
				{
					if(j==t_wh||j==(t_wh-3))  continue;
					 state[move].a[j]=state[i].a[j];
				}
				state[move].a[t_wh-3]=0;state[move].white=t_wh-3;
				state[move].a[t_wh]=state[i].a[t_wh-3];
				state[move].up=i;
				state[move].mov=1;
				move++;
			}
			if((t_wh+1)%3!=0&&t_val!=4)
			{
				for(j=0;j<9;j++)
				{
					if(j==t_wh||j==(t_wh+1)) continue;
					state[move].a[j]=state[i].a[j];
				}
				state[move].a[t_wh+1]=0;state[move].white=t_wh+1;
				state[move].a[t_wh]=state[i].a[t_wh+1];
				state[move].mov=2;state[move].up=i;
				move++;

			}
			if(t_wh<7&&t_val!=1)
			{
				for(j=0;j<9;j++)
				{
					if(j==t_wh||j==(t_wh+3)) continue;
					state[move].a[j]=state[i].a[j];
				}
				state[move].a[t_wh+3]=0;state[move].white=t_wh+3;
				state[move].a[t_wh]=state[i].a[t_wh+3];
				state[move].mov=3;state[move].up=i;
				move++;
			}
			if(t_wh%3!=0&&t_val!=2)
			{
				for(j=0;j<9;j++)
				{
					if(j==t_wh||j==(t_wh-1)) continue;
					state[move].a[j]=state[i].a[j];
				}
				state[move].a[t_wh-1]=0;state[move].white=t_wh-1;
				state[move].a[t_wh]=state[i].a[t_wh-1];
				state[move].mov=4;state[move].up=i;
				move++;
			}
		}
		first=beg;second=move-1;
	}
 }

 int main()
 {
	char input;
	while(cin>>input)
	{
		if(input=='x'){	state[0].a[0]=0;state[0].white=0;}
		else state[0].a[0]=input-48;
		int i;
		for(i=1;i<9;i++)
		{
			cin>>input;
			if(input=='x'){	state[0].a[i]=0;state[0].white=i;}
			else state[0].a[i]=input-48;
		}
		state[0].mov=0;

		int pos=doing();
		if(pos==0)  {	cout<<"unsolvable"<<endl;continue;}
		pos--;
		int solve[1000];int pt=0;
		while(state[pos].mov!=0)
		{
			solve[pt++]=state[pos].mov;
			pos=state[pos].up;
		}

		for(i=pt-1;i>=0;i--)
		{
			if(solve[i]==1)	cout<<"u";
			if(solve[i]==2) cout<<"r";
			if(solve[i]==3) cout<<"d";
			if(solve[i]==4) cout<<"l";
		}
		cout<<endl;
	}
	return 0;
 }





