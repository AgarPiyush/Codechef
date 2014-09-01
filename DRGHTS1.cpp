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
ll data;
ll val;
ll deg;
struct node *next;	
};
struct node *start[1000000],*pos[1000000];
ll mark[1000000],i,a[1000000],j,k,n,m,mark1[1000000],mark3[1000000];


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
		start[x]->deg=1;
		return;
	}
	start[x]->deg++;
	pos[x]->next=ptr;
	pos[x]=ptr;
}
ll ans=0;
void dfs(ll x)
{
	
ll flag=0;
//printf("here %lld\n",x);
mark[x]=1;
ans++;
struct node *ptr=start[x];
start[ptr->data]->deg--;
struct node *p=ptr->next;
if(p==NULL)
return;
if(!mark[p->data])
start[p->data]->deg--;

while(p!=NULL)
{
	if(p->val==0&&start[p->data]->deg==1&&!mark[p->data])
	{
		dfs(p->data);
	}
	else
	{
	flag=1;
	return;
	}
	if(flag==1) return;
	p=p->next;
}	
}
ll countone=0;
void dfs1(ll x)
{
	struct node *p=start[x];
	//printf("x is %lld start[x] %lld\n",x,start[x]->data);
	
	mark1[p->data]=1;
	if((start[x]->val)==1)
	{
		
	//printf("yes %lld\n",x);
	countone++;
	}
	struct node *ptr;
	ptr=p;
	p=p->next;
	while(p!=NULL)
	{
	//	printf("p->data %lld mark %lld\n",p->data,mark1[p->data]);
		if(mark1[p->data]==0)
		{
			mark1[p->data]=1;
			//printf("\nvalue %d edge to %d",p->data,ptr->data);
			dfs1(p->data);
		}
		p=p->next;
	}
}

ll ans1=0;
void dfs2(ll x)
{
	struct node *p=start[x];
	
	mark3[p->data]=1;
	if((start[x]->deg)>0||start[x]->val==1)
	{
		ans1++;
	}
	struct node *ptr;
	ptr=p;
	p=p->next;
	while(p!=NULL)
	{
		if(mark3[p->data]==0)
		{
			mark3[p->data]=1;
			dfs2(p->data);
		}
		p=p->next;
	}
}

int main()
{
	ll b,c;
	inp(n);inp(m);
	if(m==0)
	printf("0 0\n");
	else
	{
	start[0]=NULL;
	ll count=0;
	for(i=1;i<=n;i++)
	{
		start[i]=NULL;
		inp(a[i]);
	
	}
	for(i=0;i<m;i++)
	{
		inp(b);inp(c);
		insert(b,c);
		insert(c,b);
	}
/*	for(i=1;i<=n;i++)
	{
		struct node *ptr;
		ptr=start[i];
		while(ptr!=NULL)
		{
			printf("%lld ->",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}*/
	
	ll sum=0;
	for(i=1;i<=n;i++)
	{
		if(start[i]!=NULL&&!mark1[start[i]->data])
		{
			dfs1(i);
			sum=sum+(countone*(countone-1))/2;
			countone=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(start[i]!=NULL&&start[i]->deg==1&&start[i]->val==0&&!mark[start[i]->data])
		{
		dfs(i);
	//	printf("%lld \n",i);
		}
	}
//	printf("yes");
	ll count1=0;
	for(i=1;i<=n;i++)
	{
		if(start[i]!=NULL&&!mark3[i])
		{
			dfs2(i);
			if(ans1<2) ans1=0;
			count1=count1+ans1;
			ans1=0;
		}
	}
	if(count1<=1)
	count1=0;
	printf("%lld %lld\n",sum,count1);
	}	
	return 0;
}

