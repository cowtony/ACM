//353567 2003-11-16 21:15:28 Wrong Answer 1714 C++ 00:00.00 448K just for play 
//353581 2003-11-16 21:22:56 Wrong Answer 1714 C++ 00:00.00 448K just for play 
#include<stdio.h>
#include<string.h>

struct WINDOW{
	int id;
	int ux,uy,dx,dy;
	int oux,ouy,odx,ody;
	bool is_org;
	WINDOW(int tid,int tux,int tuy,int tdx,int tdy){
		id=tid;
		ux=tux;uy=tuy;dx=tdx;dy=tdy;		
		oux=ux,ouy=uy,odx=dx,ody=dy;
		is_org=true;
	}
};
WINDOW* wstack[10000];
int wcnt;
int win_seq;

void output(WINDOW* pt){
	printf("Window %d at %d, %d, %d, %d\n",pt->id,pt->ux,pt->uy,pt->dx,pt->dy);
}

bool Point_In_Win(int tx,int ty,int pt){
	if(wstack[pt]->ux<=tx&&tx<=wstack[pt]->dx&&
		wstack[pt]->uy<=ty&&ty<=wstack[pt]->dy)
			return true;
	return false;
}

int find_win(int tx,int ty){
	int i;
	for(i=wcnt-1;i>=0;i--){
		if(Point_In_Win(tx,ty,i))	return i;
	}
	return -1;
}
void del_win(int pt){
	
	WINDOW* cur=wstack[pt];
	int i;
	for(i=pt;i<wcnt;i++)
		wstack[i]=wstack[i+1];
	wcnt--;
}
void Win_Move(int orgx,int orgy,int tx,int ty,int pt){
	wstack[pt]->ux+=tx-orgx;
	wstack[pt]->uy+=ty-orgy;
	wstack[pt]->dx+=tx-orgx;
	wstack[pt]->dy+=ty-orgy;
}

void make_select(int pt){
	if(pt==wcnt-1)	return;
	WINDOW* temp=wstack[pt];
	wstack[pt]=wstack[wcnt-1];
	wstack[wcnt-1]=temp;
}
bool To_Close(int tx,int ty,int pt){
	if(wstack[pt]->ux<=tx&&tx<=wstack[pt]->ux+24&&
		wstack[pt]->uy<=ty&&ty<=wstack[pt]->uy+24)
			return true;
	return false;
}
bool To_Zoom(int tx,int ty,int pt){
	if(wstack[pt]->dx>=tx&&tx>=wstack[pt]->dx-24&&
		wstack[pt]->ux<=ty&&ty<=wstack[pt]->uy+24)
			return true;
	return false;
}
bool To_Move(int tx,int ty,int pt){
	if(wstack[pt]->ux==0&&wstack[pt]->uy==0&&
		wstack[pt]->dx==1023&&wstack[pt]->dy==1023)
			return false;
	if(wstack[pt]->ux+25<=tx&&tx<=wstack[pt]->dx-25&&
		wstack[pt]->uy<=ty&&ty<=wstack[pt]->uy+24)
			return true;
	return false;
}


int main(){
	freopen("1714.in","r",stdin);
	char inp[3];
	wcnt=0;
	int i;
	int win_down=-1;
	int what_to_do=-1;
	int org_x,org_y;
	win_seq=0;
	while(scanf("%s",inp)!=EOF){
		if(strcmp(inp,"ZZ")==0)		break;
		else	if(strcmp(inp,"RE")==0){
			for(i=0;i<wcnt;i++)
				output(wstack[i]);
		}else	if(strcmp(inp,"CR")==0){
			int tux,tuy,tdx,tdy;
			scanf("%d %d %d %d",&tux,&tuy,&tdx,&tdy);
			WINDOW* NewWin=new WINDOW(win_seq,tux,tuy,tdx,tdy);
			wstack[wcnt++]=NewWin;
			win_seq++;
			printf("Created window %d at %d, %d, %d, %d\n",win_seq-1,tux,tuy,tdx,tdy);
		}else{
			int tx,ty;
			scanf("%d %d",&tx,&ty);
			if(strcmp(inp,"DN")==0){
				int tt=find_win(tx,ty);
				if(tt>=0){
					make_select(tt);
					tt=win_down=wcnt-1;
					if(To_Close(tx,ty,tt))	what_to_do=0;
					else	if(To_Zoom(tx,ty,tt))	what_to_do=1;
					else	if(To_Move(tx,ty,tt)){
						what_to_do=2;org_x=tx;org_y=ty;
					}
					else	what_to_do=-1;
					printf("Selected window %d\n",wstack[tt]->id);
				}
			}else	if(strcmp(inp,"UP")==0){
				int tt=find_win(tx,ty);
				if(win_down>=0){
					if(what_to_do==0&&win_down==tt){
						printf("Closed window %d\n",wstack[tt]->id);
						del_win(tt);
					}else	if(what_to_do==1&&win_down==tt){
						if(wstack[tt]->is_org){
							wstack[tt]->is_org=false;
							wstack[tt]->ux=wstack[tt]->uy=0;
							wstack[tt]->dx=wstack[tt]->dy=1023;
						}else{
							wstack[tt]->is_org=true;
							wstack[tt]->ux=wstack[tt]->oux;wstack[tt]->uy=wstack[tt]->ouy;
							wstack[tt]->dx=wstack[tt]->odx;wstack[tt]->dy=wstack[tt]->ody;
						}
						printf("Resized window %d to %d, %d, %d, %d\n",wstack[tt]->id,
								wstack[tt]->ux,wstack[tt]->uy,wstack[tt]->dx,wstack[tt]->dy);
					}else	if(what_to_do==2){
						Win_Move(org_x,org_y,tx,ty,win_down);
						printf("Moved window %d to %d, %d, %d, %d\n",wstack[win_down]->id,
							wstack[win_down]->ux,wstack[win_down]->uy,wstack[win_down]->dx,wstack[win_down]->dy);
					}

				}
				win_down=-1;what_to_do=-1;
			}else	if(strcmp(inp,"AT")==0){				
				if(what_to_do==2){
					if(win_down>=0){
						Win_Move(org_x,org_y,tx,ty,win_down);
						
						printf("Window %d at %d, %d, %d, %d\n",wstack[win_down]->id,
							wstack[win_down]->ux,wstack[win_down]->uy,wstack[win_down]->dx,wstack[win_down]->dy);
						
						org_x=tx;org_y=ty;
					}
				}
			}
		}
	}
	return 0;
}


					

						


							


				

			
			
		



