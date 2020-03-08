//61239 2002-12-05 12:42:25 Accepted 1062 C++ 00:00.01 440K Century Ghost
#include<iostream.h>
struct tree
{
        tree* leftchild;
	tree* rightchild;
};

tree* head;
long  total[21];

tree* generate(int pt,long n)
{

	tree* point=NULL;
	if(pt==1){
		point=new tree;
		point->leftchild=NULL;
		point->rightchild=NULL;
		return point;
	}
	int i;
	for(i=pt-1;i>=0;i--)
	{
		n-=total[i]*total[pt-1-i];
		if(n<=0) break;
	}
	n+=total[i]*total[pt-i-1];

        if(i>0)
        {
                point=new tree;
                point->leftchild=NULL;
                point->rightchild=NULL;
                long temp=n%total[i];
                if(temp==0)     temp=total[i];
                point->rightchild=generate(i,temp);
        }
        if(pt-i-1==0)   return point;
        if(point==NULL)
        {
                point=new tree;
                point->leftchild=NULL;
                point->rightchild=NULL;
        }
        long temp=n/total[i];
 //       if(temp==0)     temp=1;
        if(n%total[i])  temp++;
        point->leftchild=generate(pt-i-1,temp);
        return point;
}

void output(tree* point)
{
      if(point->leftchild==NULL&&point->rightchild==NULL)
                cout<<"X";
      else if(point->leftchild==NULL)
      {
        cout<<"X(";
        output(point->rightchild);
        cout<<")";
      }
      else if(point->rightchild==NULL)
      {
        cout<<"(";
        output(point->leftchild);
        cout<<")X";
      }
      else{
        cout<<"(";
        output(point->leftchild);
        cout<<")X(";
        output(point->rightchild);
        cout<<")";
      }

}




int main( )
{
        long n;

        total[0]=1;total[1]=1;
        int i,j;
        for(i=2;i<21;i++)
       {
               long sum=0;
               for(j=0;j<i;j++)
                     sum+=total[j]*total[i-1-j];
               total[i]=sum;

        }
        while(cin>>n)
        {

                if(n==0)        break;
                for(i=1;i<20;i++){n-=total[i];if(n<=0)   break;}
                int pt=i;
                n+=total[i];
                head=NULL;
                head=generate(pt,n);
                output(head);
                cout<<endl;
        }

        return 0;
}

