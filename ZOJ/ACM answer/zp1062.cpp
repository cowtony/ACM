//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

struct Node
{
   struct Node* left;
   struct Node* right;
};
struct Node* root;
int a[19];

void cal(int n, int m, struct Node* cur)
{
  int i=0;
  while (n>a[i]*a[m-1-i])
  {
    n-=a[i]*a[m-1-i];
    i++;
  }

  if (i)
  {
    cur->left=new(struct Node);
    cur->left->left=NULL;
    cur->left->right=NULL;
    cal((n-1)/a[m-1-i]+1,i,cur->left);
  }
  if (m-1-i)
  {
    cur->right=new(struct Node);
    cur->right->left=NULL;
    cur->right->right=NULL;
    cal((n-1)%a[m-1-i]+1,m-1-i,cur->right);
  }
}
void pre_travel(struct Node* cur)
{
  printf("(");
  if(cur->left!=NULL) pre_travel(cur->left);
  printf("X");
  if(cur->right!=NULL) pre_travel(cur->right);
  printf(")");
}
int main(int argc, char* argv[])
{
  int d[19],
      m,n,i,j;
  a[0]=1;
  d[0]=0;
  a[1]=1;
  d[1]=1;
  for (i=2;i<=18;i++)
  {
    a[i]=0;
    for (j=0;j<i;j++)
      a[i]+=a[j]*a[i-1-j];
    d[i]=d[i-1]+a[i];
  }
  while (scanf("%d",&n) && n)
  {
    for (i=1;i<=18;i++)
      if (n<=d[i])
        break;
    n-=d[i-1];
    m=i;

    root=new(struct Node);
    root->left=NULL;
    root->right=NULL;

    cal(n,m,root);

    if(root->left!=NULL)
      pre_travel(root->left);
    printf("X");
    if(root->right!=NULL)
      pre_travel(root->right);
    printf("\n");

  }
  return 0;
}
//---------------------------------------------------------------------------
