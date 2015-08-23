#include<stdio.h>
#include<stdlib.h>
#include<vector>
#define pb push_back
#define MAX 600010
using namespace std;
struct stu
{
   int cnt,wt;
   struct stu *left,*right;
}*head[MAX];

int last;
struct stu *hNULL;
vector <int > v;

void print(struct stu *h)
{
    if(h==NULL) return ;
    if(h->left!=NULL)
       printf("0"),print(h->left);
    if(h->right!=NULL)
       printf("1"),print(h->right);
}

void printw(struct stu *h)
{
   if(h==NULL)
     return ;
   printf("%d ",h->wt);
   printw(h->left);
   printw(h->right);
}
void insert_first(struct stu *h,int x,int bit)
{
    h->wt=1;h->left=h->right=NULL;
    if(bit==-1) return ;
    if(x & (1<<bit))
      insert_first(h->right=(struct stu *)malloc(sizeof(struct stu )),x,bit-1);
    else
      insert_first(h->left=(struct stu *)malloc(sizeof(struct stu )),x,bit-1);
}
void insert_last(struct stu *h1,struct stu *h2,int x,int bit)
{
if(h1!=NULL)
 h2->wt=h1->wt;
else
 h2->wt=0;
h2->wt++;
 if(bit==-1){h2->left=h2->right=NULL;return ;}
 if(x & (1<<bit))
  { 
     if(h1!=NULL)
      {
        h2->left=h1->left;
        h1=h1->right;
      }
     else
        h2->left=NULL;
     insert_last(h1,h2->right=(struct stu *)malloc(sizeof(struct stu )),x,bit-1);
  }
 else
   {
      if(h1!=NULL)
       {h2->right=h1->right;h1=h1->left;}
      else
        h2->right=NULL;
      insert_last(h1,h2->left=(struct stu *)malloc(sizeof(struct stu )),x,bit-1);
   }
}
void insert_node(int x)
{
   if(last==0)
  {
      insert_first(head[0],x,20);
      return ;
  }
  insert_last(head[last-1],head[last],x,20);
}
void fxor(struct stu *h1,struct stu *h2,int x,int bit){
if(bit==-1) return ;
 if(x & (1<<bit))
 {
   if(h1!=NULL)
   {
     if(h1->left!=NULL&&h2->left!=NULL)
     {
         if(h1->left->wt!=h2->left->wt)
          {
            v.pb(0);
            return fxor(h1->left,h2->left,x,bit-1);
          }
         else
          {
            v.pb(1);
            return fxor(h1->right,h2->right,x,bit-1);
          }
     }
     else if(h1->left==NULL&&h2->left!=NULL)
        {
          v.pb(0);
          return fxor(h1->left,h2->left,x,bit-1);
        }
     else if(h1->left==NULL&&h2->left==NULL)
        {
          v.pb(1);
          return fxor(h1->right,h2->right,x,bit-1);
        }
   }
   else
   {
       if(h2->left!=NULL)
         {v.pb(0);return fxor(h1,h2->left,x,bit-1);}
       else
         {v.pb(1);return fxor(h1,h2->right,x,bit-1);}
   }
 }
 else
 {
   if(h1!=NULL)
   {
     if(h1->right!=NULL&&h2->right!=NULL)
     {
         if(h1->right->wt!=h2->right->wt)
          {v.pb(1);return fxor(h1->right,h2->right,x,bit-1);}
         else
          {v.pb(0);return fxor(h1->left,h2->left,x,bit-1);}
     }
     else if(h1->right==NULL&&h2->right!=NULL)
        {v.pb(1);return fxor(h1->right,h2->right,x,bit-1);}
     else if(h1->right==NULL&&h2->right==NULL)
        {v.pb(0);return fxor(h1->left,h2->left,x,bit-1);}
   }
   else
   {
       if(h2->right!=NULL)
         {v.pb(1);return fxor(h1,h2->right,x,bit-1);}
       else
         {v.pb(0);return fxor(h1,h2->left,x,bit-1);}
   }
 }
}
void find_xor(int l,int r,int x){
if(l!=0)
 fxor(head[l-1],head[r],x,20);
else
 fxor(hNULL,head[r],x,20);
}
int fless(struct stu *h,int x,int bit){
int sum;
 if(h==NULL)
    return 0;
 if(bit==-1)
    return h->wt;
 if(x & (1<<bit))
 {
     if(h->left!=NULL)
        sum=h->left->wt;
     else
        sum=0;
     return sum+fless(h->right,x,bit-1);
 }
 else
 {
     return fless(h->left,x,bit-1);
 }
}
 
int find_less(int l,int r,int x){
if(l!=0)
 return fless(head[r],x,20)-fless(head[l-1],x,20);
else
 return fless(head[r],x,20);
}
void hsmallest(struct stu *h1,struct stu *h2,int x,int bit){
 int temp;
    if(bit==-1)
        return ;
     if(h1!=NULL)
     {
        if(h1->left!=NULL&&h2->left!=NULL)
        {   temp=h2->left->wt-h1->left->wt;
            if(temp<x)
             {v.pb(1);return hsmallest(h1->right,h2->right,x-temp,bit-1);}
            else
             {v.pb(0);return hsmallest(h1->left,h2->left,x,bit-1);}
        }
        else if(h1->left==NULL&&h2->left!=NULL)
        {   temp=h2->left->wt;
            if(temp<x)
             {v.pb(1);return hsmallest(h1->right,h2->right,x-temp,bit-1);}
            else
             {v.pb(0);return hsmallest(h1->left,h2->left,x,bit-1);}
        }
        else if(h1->left==NULL&&h2->left==NULL)
             {v.pb(1);return hsmallest(h1->right,h2->right,x,bit-1);}
     }
     else
     {
        if(h2->left!=NULL)
        {   temp=h2->left->wt;
            if(temp<x)
             {v.pb(1);return hsmallest(h1,h2->right,x-temp,bit-1);}
            else
             {v.pb(0);return hsmallest(h1,h2->left,x,bit-1);}
        }
        else if(h2->left==NULL)
             {v.pb(1);return hsmallest(h1,h2->right,x,bit-1);}
     }
}
void find_smallest(int l,int r,int x){
  if(l!=0)
    hsmallest(head[l-1],head[r],x,20);
  else
    hsmallest(hNULL,head[r],x,20);
}
int main(){
 int t,q_type,x,i,j,k,l,r,ans;
 struct stu *temp=NULL;hNULL=NULL;
 scanf("%d",&t);
 while(t--)
 {
     scanf("%d",&q_type);
     if(q_type==0)
     {
         scanf("%d",&x);
         head[last]=(struct stu *)malloc(sizeof(struct stu ));head[last]->wt=0;
         insert_node(x);
         last++;
     }
     else if(q_type==1)
     {
         scanf("%d%d%d",&l,&r,&x);l--;r--;
         find_xor(l,r,x);
         ans=0;
         for(i=1;v.size();i*=2)
            ans=ans+i*v.back(),v.pop_back();
         printf("%d\n",ans);
     }
     else if(q_type==2)
     {
         scanf("%d",&k);
         last-=k;
     }
     else if(q_type==3)
     {
         scanf("%d%d%d",&l,&r,&x);l--;r--;
         printf("%d\n",find_less(l,r,x));
     }
     else if(q_type==4)
     {
         scanf("%d%d%d",&l,&r,&x);l--;r--;find_smallest(l,r,x);
         ans=0;
         for(i=1;v.size();i*=2)
            ans=ans+i*v.back(),v.pop_back();
         printf("%d\n",ans);
     }
 }
 //print(head[0]);
//printw(head[3]);
 return 0;
}
 