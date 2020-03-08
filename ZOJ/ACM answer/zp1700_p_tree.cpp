//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//#define cin fin
//#define cout fout
#include<iostream>
#include<string>
//#include<fstream>
using namespace std;
//ifstream fin("leaves.in");
//ofstream fout("output.txt");
struct Node
{
   char c;
   struct Node* left;
   struct Node* right;
};
struct Node* root;
string tree[100];
int n;
bool flag;
void init(void)
{
   string instr;
   n=0;root=NULL;
   do
   {
      cin>>instr;
      if(instr!="*"&&instr!="$")
         tree[++n]=instr;
   }while(instr!="*"&&instr!="$");
   if(instr=="*") flag=true;
   else flag=false;
}
void addtotree(char c,struct Node* cur)
{
   if(c>(cur->c))
   {
      if(cur->right==NULL)
      {
         cur->right=new(struct Node);
         cur->right->c=c;
         cur->right->left=NULL;
         cur->right->right=NULL;
      }
      else
        addtotree(c,cur->right);
   }
   else
   {
      if(cur->left==NULL)
      {
         cur->left=new(struct Node);
         cur->left->c=c;
         cur->left->left=NULL;
         cur->left->right=NULL;
      }
      else
        addtotree(c,cur->left);
   }
}
void case_solve(void)
{
   int i,j,len;
   root=new(struct Node);
   root->c=tree[n][0];
   root->left=NULL;
   root->right=NULL;
   for(i=n-1;i>=1;i--)
   {
      len=tree[i].length();
      for(j=0;j<len;j++)
      {
         addtotree(tree[i][j],root);
      }
   }
}
void pre_travel(struct Node* cur)
{
   cout<<cur->c;
   if(cur->left!=NULL) pre_travel(cur->left);
   if(cur->right!=NULL) pre_travel(cur->right);
}
void answer(void)
{
   pre_travel(root);
   cout<<endl;
}
int main(int argc, char* argv[])
{
   do
   {
      init();
      case_solve();
      answer();
   }while(flag);
   return 0;
}
//---------------------------------------------------------------------------
 