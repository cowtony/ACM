 #include<iostream.h>

 struct cood
 {
	double x,y;
 };
 cood point[151];int flag[151];
 int n;	cood center;double radius;
 void exchange(cood& fir,cood& sec)
 {
	cood temp;temp.x=fir.x;temp.y=fir.y;
	fir.x=sec.x;fir.y=sec.y;
	sec.x=temp.x;sec.y=temp.y;
 }
 int cross(cood fir,cood sec)
 {
	return ((fir.x-center.x)*(sec.y-center.y)-(fir.y-center.y)*(sec.x-center.x));
 }
 void sort()
 {
	int i,j;
	for(i=0;i<n;i++)
	{
		if(!flag[i])	continue;
		int pt=i;
		for(j=0;j<n;j++)
		{
			if(!flag[j])	continue;
			if(cross(point[j],point[pt])>0)	pt=j;
		}
		if(pt!=i)	exchange(point[i],point[pt]);
	}
 }
 int main()
 {

	while(cin>>center.x>>center.y>>radius)
	{
		if(radius<0)	break;

		int i;int j;
		cin>>n;
		for(i=0;i<n;i++)	cin>>point[i].x>>point[i].y;
		for(i=0;i<n;i++)	flag[i]=0;
		double tworad=radius*radius;
		for(i=0;i<n;i++)
			if((point[i].x-center.x)*(point[i].x-center.x)+(point[i].y-center.y)*
			   (point[i].y-center.y)<=tworad)
				flag[i]=1;
		for(i=0;i<n;i++)	cout<<flag[i]<<" ";
		cout<<endl;
		int min=0;
		for(i=1;i<n;i++)
			if(point[i].y<point[min].y||(point[i].y==point[min].y&&point[i].x<point[min].x))	min=i;
		exchange(point[0],point[min]);

		sort();
		for(i=0;i<n;i++)	cout<<point[i].x<<"  "<<point[i].y<<endl;
		cout<<endl;
		int max=0;int pt=0;int count=0;
		for(i=0;i<n;i++)
		{
			if(!flag[i])	continue;

			while(1)
			{
				if(pt>=n)	break;
				if(!flag[pt]) {pt++;continue;}
				if(cross(point[i],point[pt])>0)	break;
				count++;
				pt++;
			}
			if(count>max)	count=max;
			if(pt>n)	break;
			count--;
		}
		cout<<max<<endl;
	}
	return 0;
 }









