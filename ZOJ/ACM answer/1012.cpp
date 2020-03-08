 //77804 2003-02-23 12:25:15 Accepted 1012 C++ 00:01.97 748K Century Ghost
 //77823 2003-02-23 13:02:46 Accepted 1012 C++ 00:00.65 1060K Century Ghost
 #include<iostream.h>
 const int max=1001;

 struct job
 {
	int cpu,mem,arrtime,timeline,reward,bonus,punish;
	int flag;
 };
 void exchange(job& fir,job& sec)         //send the value of sec to fir
 {
	fir.cpu=sec.cpu;fir.mem=sec.mem;fir.arrtime=sec.arrtime;fir.timeline=sec.timeline;
	fir.reward=sec.reward;fir.bonus=sec.bonus;fir.punish=sec.punish;
 }

 void merge(job joblist[],int beg,int mid,int end)
 {
	int i=beg;int j=mid+1;int t=beg;
	job tempjob[max];
	while(t<=end)
	{
		if((i<=mid)&&(j>end||joblist[i].arrtime<joblist[j].arrtime
		||(joblist[i].arrtime==joblist[j].arrtime&&joblist[i].reward>joblist[j].reward)))
		 {	exchange(tempjob[t],joblist[i]);i++;}
		else
		{	exchange(tempjob[t],joblist[j]);j++;}
		t++;
	}
	for(i=beg;i<=end;i++)	exchange(joblist[i],tempjob[i]);
 }
 void merge_sort(job joblist[],int beg,int end)
 {
	int mid;
	if(beg!=end)
	{
		mid=(beg+end-1)/2;
		merge_sort(joblist,beg,mid);
		merge_sort(joblist,mid+1,end);
		merge(joblist,beg,mid,end);
	}
 }


 int main()
 {
	int lasttime,tcpu,tmem,tjob;
	job joblist[max];
	int count=0;
	while(cin>>lasttime)
	{
		if(lasttime==0)	break;
		count++;
		cin>>tcpu>>tmem>>tjob;
		int i,j;
		for(i=0;i<tjob;i++)	joblist[i].flag=0;
		for(i=0;i<tjob;i++)
			cin>>joblist[i].cpu>>joblist[i].mem>>joblist[i].arrtime
				>>joblist[i].timeline>>joblist[i].reward>>
				joblist[i].bonus>>joblist[i].punish;

		merge_sort(joblist,0,tjob-1);	//sort

		long value=0;
		int point=0;
		for(i=0;i<lasttime;i++)
		{
			int pt=point;int lcpu=tcpu,lmem=tmem; //lcpu=left cpu ;lemm=left memory
			while(1)
			{
				if(pt>=tjob)	break;
				if(joblist[pt].arrtime>i)	break;
				if(!joblist[pt].flag&&joblist[pt].cpu<=lcpu&&joblist[pt].mem<=lmem)
				{  //if joblist[pt].flag=1,then it has been finished
					joblist[pt].flag=1;
					value+=joblist[pt].reward;

					if(joblist[pt].timeline>i+1)	value+=joblist[pt].bonus*(joblist[pt].timeline-i-1);
					if(joblist[pt].timeline<i+1)	value-=joblist[pt].punish*(i+1-joblist[pt].timeline);

					lcpu-=joblist[pt].cpu;lmem-=joblist[pt].mem;
				}
				pt++;
			}
			for(j=point;j<tjob;j++)
				if(!joblist[j].flag)	break;
			point=j;		//point is the situation of the first job that haven't been finished

		}
		for(i=point;i<tjob;i++)
		{
			if(!joblist[i].flag&&joblist[i].timeline<lasttime)
				value-=joblist[i].punish*(lasttime-joblist[i].timeline);
		}
		cout<<"Case "<<count<<": ";
		cout<<value<<endl<<endl;
	}
	return 0;
 }