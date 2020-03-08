 #include<iostream.h>

 struct node
 {
	int up;
	int end;
 };

 int main()
 {
	char ch;
	while(cin>>ch)
	{

		node   pot[51];int stack[51];
		int max=0;int i,j;
		for(i=1;i<51;i++){	pot[i].end=0;pot[i].up=0;}
		int count=1;

		while(count)
		{
			int num;
			cin>>ch;
			if(ch=='(')	count++;
			else if(ch==')')	count--;
			else
			{
				num=0;
				while(ch>=48&&ch<58)
				{
					num=num*10+ch-48;
					cin>>ch;
				}
				cin.putback(ch);
				if(max<num)	max=num;
				if(count==1)
				{
					pot[num].up=0;pot[num].end=0;

					stack[count]=num;
					continue;
				}
				stack[count]=num;
				pot[num].up=stack[count-1];
				pot[stack[count-1]].end++;
			}

		}
		for(i=1;i<max;i++)
		{
			int  min=-1;int pick;
			for(j=1;j<=max;j++)
				if((pot[j].up!=0&&pot[j].end==0)||(pot[j].up==0&&pot[j].end==1))
					if(min==-1||min>j)	min=j;
			if(pot[min].up==0)
			{
				for(j=1;j<=max;j++)
					if(pot[j].up==min)	break;
				pick=j;pot[j].up=0;
				pot[min].end=0;
			}
			else
			{
				pick=pot[min].up;
				pot[pick].end--;pot[min].up=0;
			}
			cout<<pick;
			if(i<max-1)	cout<<" ";
		}
		cout<<endl;
	}
	return 0;
 }





