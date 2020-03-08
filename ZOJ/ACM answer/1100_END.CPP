 #include<iostream.h>

 int h,w;  long sum;
 flag[12][12];

 void fill(int i,int j)
 {

	if(i==h+1) {sum++;return;}
	int nexti,nextj;  int next2i,next2j;
	if(j==w-1){next2i=i+1;next2j=1;}else {next2i=i;next2j=j+2;}
	if(j==w){nexti=i+1;nextj=1;}

	else {nexti=i;nextj=j+1;}
	if(flag[i][j]==1) {fill(nexti,nextj);return;}

	if(i==h)
	{

		if(flag[i][j+1]==1) return;
		else{flag[i][j]=1;flag[i][j+1]=1;fill(next2i,next2j);flag[i][j]=0;flag[i][j+1]=0;}
	}
	else if(j%w==0)
	{
		if(flag[i+1][j]) return;
		else{flag[i+1][j]=1;flag[i][j]=1;fill(nexti,nextj);flag[i][j]=0;flag[i+1][j]=0;}
	}
	else
	{
		if(!flag[i][j+1])
		{flag[i][j]=1;flag[i][j+1]=1;fill(next2i,next2j);flag[i][j]=0;flag[i][j+1]=0;}
		if(!flag[i+1][j])
		{flag[i+1][j]=1;flag[i][j]=1;fill(nexti,nextj);flag[i][j]=0;flag[i+1][j]=0;}
	}
 }


 int main()
 {
	while(1)
	{

		cin>>h>>w;
		if(h==0&&w==0) break;
		int i,j;
		if(h*w%2) {cout<<"0"<<endl;continue;}
		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++)
				flag[i][j]=0;
		sum=0;
		fill(1,1);
		cout<<sum<<endl;
	}
	return 0;
 }