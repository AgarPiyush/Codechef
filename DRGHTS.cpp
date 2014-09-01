
#include<iostream>
#include<cstdio>
#include<climits>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<queue>
using namespace std;
#define inp(a) scanf("%lld",&a)
#define line(a) printf("%lld ",a);
#define next() printf("\n");
#define out(a) printf("%lld\n",a)
#define swap(a,b) {a=a+b;a=a-b;b=a-b;}
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>
#define ll long long int
#define mod 1000000007
#define getcx getchar_unlocked
/*inline void fscan(ll *a )
{
	ll n=0; int ch = getcx(); int sign = 1;
	while(ch < '0' || ch > '9')
	{
	if(ch == '-') sign=-1; ch = getcx();
	}
	while(ch >= '0' && ch <= '9')
	{
	n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	}
	*a = n * sign;
}*/
struct node
{
	ll val;
	ll data;
	struct node *next;
};
struct node *start[100000],*pos[100000];
ll i,j,k,l,e,v,a[100000],mark[100000],b,c;

void insert(ll x,ll y)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=y;
	ptr->val=a[y];
	ptr->next=NULL;
	if(start[x]==NULL)
	{
		start[x]=(struct node*)malloc(sizeof(struct node));
		start[x]->data=x;
		start[x]->val=a[x];
		start[x]->next=ptr;
		pos[x]=ptr;
		return;
	}
	pos[x]->next=ptr;
	pos[x]=ptr;
}
ll conse=0,flag=0,back=0;
void dfs(ll x)
{
//	printf("x is %lld\n",x);
	flag=0;
	struct node *p=start[x];
	mark[p->data]=1;
	struct node *ptr;
	ptr=p;
	p=p->next;
	while(p!=NULL)
	{
		if(!mark[p->data])
		{
			mark[p->data]=1;
			dfs(p->data);
//			printf("back %lld flag %lld\n",p->data,flag);
			if(start[p->data]->val==0&&flag==0)
			{
//				printf("yes %lldn\n",start[p->data]->data);
				conse++;
			}
			if(start[p->data]->val==1&&flag==0)
			{
				flag=1;
				return;
			}
		}
	//	if(flag) return;
		p=p->next;
	}
}


int main()
{
	inp(v);inp(e);
	start[0]=NULL;
	ll count=0;
	for(i=1;i<=v;i++) 
	{
	start[i]=NULL;
	inp(a[i]);
	if(a[i]) count++;
	}
	for(i=0;i<e;i++)
	{
		inp(b);inp(c);
		insert(b,c);
		insert(c,b);
	}
/*	for(i=1;i<=v;i++)
	{
		struct node *ptr=start[i];
		while(ptr!=NULL)
		{
			printf("%lld %lld->",ptr->data,ptr->val);
			ptr=ptr->next;
		}
		printf("\n");
	}*/
	for(i=1;i<=v;i++)
	{
		if(start[i]!=NULL&&!mark[i])
		dfs(i);
	}
	printf("%lld %lld\n",count*(count-1)/2,v-conse);
	
	return 0;
}

