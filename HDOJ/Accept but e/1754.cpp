#include<iostream>
using namespace std;

#define N 200010
#define MIN -0xFFFFFFF
struct Node{
    int a,b,cover;
    int lc,rc;
}Tree[2*N];
int Len;
int MAX;
void build(int left,int right){
    Len++;
    int Now=Len;
    Tree[Now].a=left; Tree[Now].b=right;
    Tree[Now].cover=MIN;
    Tree[Now].lc=-1;
    Tree[Now].rc=-1;
    if(right-left>1){
        int mid=(left+right)>>1;
        Tree[Now].lc=Len+1;
        build(left,mid);
        Tree[Now].rc=Len+1;
        build(mid,right);
    }
}
void insert(int Num,int left,int right,int col){
    if(left==Tree[Num].a&&right==Tree[Num].b){
        Tree[Num].cover=col;
        return ;
    }
    int mid=(Tree[Num].a+Tree[Num].b)>>1,tmp;
    if(right<=mid)
    {
        insert(Tree[Num].lc,left,right,col);
        if(Tree[Tree[Num].lc].cover>Tree[Num].cover)
            Tree[Num].cover=Tree[Tree[Num].lc].cover;
    }
    else if(left>=mid)
    {
        insert(Tree[Num].rc,left,right,col);
        if(Tree[Tree[Num].rc].cover>Tree[Num].cover)
            Tree[Num].cover=Tree[Tree[Num].rc].cover;
    }
    else{
        insert(Tree[Num].lc,left,mid,col);
        insert(Tree[Num].rc,mid,right,col);
        if(Tree[Tree[Num].lc].cover>Tree[Tree[Num].rc].cover)
            tmp=Tree[Tree[Num].lc].cover;
        else 
            tmp=Tree[Tree[Num].rc].cover;
        if(Tree[Num].cover<tmp)
            Tree[Num].cover=tmp;
    }
}
void query(int Num,int left,int right){
    if(left<=Tree[Num].a&&right>=Tree[Num].b){
        if(Tree[Num].cover>MAX)
            MAX=Tree[Num].cover;
        return;
    }
    int mid=(Tree[Num].a+Tree[Num].b)>>1;
    if(right<=mid) query(Tree[Num].lc,left,right);
    else if(left>=mid) query(Tree[Num].rc,left,right);
    else{
        query(Tree[Num].lc,left,mid);
        query(Tree[Num].rc,mid,right);
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        Len=0;
        build(0,n);
        int a,b;
        char c;
        for(int i=1;i<=n;++i){
            scanf("%d",&a);
            insert(1,i-1,i,a);
        }
        getchar();
        for(int i=0;i<m;++i){
            scanf("%c%d%d",&c,&a,&b);getchar();
            if(c=='Q'){
                MAX=MIN;
                query(1,a-1,b);
                printf("%d\n",MAX);
            }
            else insert(1,a-1,a,b);
        }
    }
    return 0;
}
