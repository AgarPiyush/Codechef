#include<stdio.h>
#include<stdlib.h>
struct list{
	int info;
	struct list *link;
};
typedef struct list node;
node *start[100005],*p,*q,*temp,*point[100005];
long long int i,j,k,n,t,m,a[100005],x,l,r,z,ans;
int main()
{
	scanf("%lld %lld %lld",&n,&m,&k);
	p=NULL;
	for(i=1;i<=m;i++) {start[i]=NULL; point[i]=NULL;}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		if(start[x]==NULL)
		{
			start[x]=(node *)malloc(sizeof(node));
			start[x]->info=i;
			start[x]->link=NULL;
			point[x]=start[x];
		}
		else
		{
			temp=(node *)malloc(sizeof(node));
			temp->info=i;
			temp->link=NULL;
			point[x]->link=temp;
			point[x]=point[x]->link;
			p=start[x];
		}
	}
	p=NULL;
	ans=0;
	for(i=1;i<=m;i++)
	{
		p=start[i];
		printf("\n%d->",p->info);
		j=0;
		while(p!=NULL)
		{
			printf("%d",p->info);
			a[j]=p->info;
			p=p->link;
			j++;		
		}
	}
}
