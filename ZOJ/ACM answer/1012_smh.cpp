/*
72207 2003-02-03 11:02:24 Wrong Answer 1012 C++ 00:00.58 780K NeedForSpeed 
72206 2003-02-03 10:48:37 Runtime ErrorSIGSEGV 1012 C++ 00:00.43 748K NeedForSpe
ed 
72205 2003-02-03 10:35:40 Runtime ErrorSIGSEGV 1012 C++ 00:00.53 748K NeedForSpe
ed 
72203 2003-02-03 10:30:59 Runtime ErrorSIGSEGV 1012 C++ 00:00.01 0K NeedForSpeed
 
*/
#include<iostream.h>

int queue[1001];
struct JOB{ int a, b, t, u, v, w, x;}jobs[1001];
struct spdNode{ JOB* jptr; spdNode* next; };
 spdNode* spd, *tail;

int queuesize;

int jobCmp(int a, int b)
{
	if (jobs[a].t<jobs[b].t) return -1;
	if (jobs[a].t>jobs[b].t) return 1;
	if (jobs[a].v>jobs[b].v) return -1;
	return 1;
}
void insert(int i)
{
	queue[queuesize++]=i;
	int par, pos=i;
	while(pos>0){
		par=(pos-1)/2;
		if (jobCmp(queue[par], i)>0){
			queue[pos]=queue[par];
			pos=par;
		} else
			break;
	}
	queue[pos]=i;
}
void suspend(int id)
{
	if (spd==NULL){
		spd =  new spdNode;
		spd->jptr=&jobs[id];
		spd->next=NULL;
		tail=spd;
	} else {
		tail->next = new spdNode;
		tail=tail->next;
		tail->jptr= &jobs[id];
		tail->next= NULL;
	}
}
void buildHeap()
{
	int pos=0, chdpos, value=queue[0];
	while(pos<queuesize){
		chdpos=pos*2+1;
		if (chdpos<queuesize){
			if (chdpos+1<queuesize&&jobCmp(queue[chdpos], queue[chdpos+1])>0)
				chdpos++;

			if (jobCmp(value, queue[chdpos]) > 0) {
				queue[pos]=queue[chdpos];
				pos=chdpos;
			} else {
				queue[pos]=value;
				return;
			}
		} else {
			queue[pos]=value;
			return;
		}
	}
}

int main()
{
	int cnt=1, i, m, n, vvv, F, CPU, MEM, JobSum;
	spd=NULL;
	while(cin>>F){
		if (F==0) break;
		cin>>CPU>>MEM>>JobSum;

		queuesize=0;
		for (i=0; i<JobSum; i++){
			cin>>jobs[i].a>>jobs[i].b>>jobs[i].t>>jobs[i].u>>jobs[i].v>>jobs[i].w>>jobs[i
].x;
			insert(i);// to heap according to T ( if t the same than V)
		}

		vvv=0;
		spdNode* tmp, *ptr;

		for (int time=0; time<=F; time++){

			m=CPU; n=MEM;
			ptr=spd;
			//examine suspended jobs first
			while (ptr!=NULL) {
				JOB* j=ptr->jptr;
				if (m>=j->a&&n>=j->b){
					m-=j->a;
					n-=j->b;//do it
					vvv+=j->v;
					if (time+1<=j->u){
						vvv+=(j->u - time - 1) * j->w;
					} else {
						vvv-=(time+1 - j->u ) * j->x;
					}
					//delFromChain
					if (ptr==spd){
						spd=spd->next;
						delete ptr;
						ptr=spd;
					} else if (ptr==tail) {
						tail=tmp;
						tail->next=NULL;
						delete ptr;
						ptr=NULL;///
					} else {
						tmp->next=ptr->next;
						delete ptr;
						ptr=tmp->next;
					}
				} else {
					tmp=ptr;
					ptr=ptr->next;
				}
			}
			//get all the jobs arrive at time out and judge
			int id;
			while (id=queue[0], queuesize>0&&time==jobs[id].t){
				if (m>=jobs[id].a&&n>=jobs[id].b){
					m-=jobs[id].a;
					n-=jobs[id].b;
					vvv+=jobs[id].v;
					if (time+1<=jobs[id].u){
						vvv+=(jobs[id].u-time-1)*jobs[id].w;
					} else {
						vvv-=(time+1-jobs[id].u)*jobs[id].x;
					}

					queue[0]=queue[--queuesize];
					buildHeap();
				} else {
					suspend(id);
					queue[0]=queue[--queuesize];
					buildHeap();
					//break;//according ot rule 8, once suspend stop others waiting behind
				}
			}
		}
		//reckoning
		while(spd!=NULL){
			JOB* j=spd->jptr;
			if (j->u <= F) vvv-=(F - j->u)* j->x;
			tmp=spd;
			spd=spd->next;
			delete tmp;
		}
		int id;
		for (i=0; i<queuesize; i++){
			id=queue[i];
			if (jobs[id].u <= F) vvv-=(F - jobs[id].u)* jobs[id].x;
		}
		cout<<"Case "<<cnt<<": "<<vvv<<endl<<endl;
		cnt++;
	}
	return 0;
}




//END_OF_PROGRAM












