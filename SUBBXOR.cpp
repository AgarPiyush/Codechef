#include<stdio.h>
typedef long long int ll;
ll a[100005],no[2000000],i,j,k,l,m,n,c=0;
void segment(ll node,ll b,ll e)
{
	if(b==e)
	{
		
		no[node]=a[b];
		if(a[b]<m)
		{
		c++;
		}
		return;
	}
	segment(node<<1,b,((e+b)>>1));
	segment((node<<1)+1,((e+b)>>1)+1,e);
	no[node]=no[node<<1]^no[(node<<1)+1];
	if(no[node]<m)
	{
	 c++;
	 //printf("%lld %lld\n",node,no[node]);
	}
}

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		c=0;
		scanf("%lld %lld",&n,&m);
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		segment(1,0,n-1);
		printf("%lld",c);
	}
	return 0;
}
