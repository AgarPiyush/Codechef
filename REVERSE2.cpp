//Author: Piyush Agarwal, MNNIT Allahabad
#include<bits/stdc++.h>
using namespace std;
#define inp1(a) scanf("%lld",&a)
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define line(a) printf("%lld ",a);
#define next() printf("\n");
#define out(a) printf("%lld\n",a)
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define getcx getchar_unlocked

/*inline void finp(ll *a )
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
}
*/
vector<ll> a[1000000],b[1000000];
queue<ll> q;
ll i,j,k,l,m,n,t,dis[1000005];
ll mark[10000005];
int main()
{
	ll v,e;
	dis[1]=LONG_MAX;
	inp2(v,e);
	for(i=0;i<e;i++)	
	{
		inp2(j,k);
		dis[j]=LONG_MAX;
		dis[k]=LONG_MAX;
		if(j!=k)
		{
		a[j].pb(k);
		b[j].pb(k);
		b[k].pb(j);
		}
	}
	dis[v]=0;
	
	q.push(v);
	while(!q.empty())
	{
		ll val=q.front();
		q.pop();
		mark[val]=1;
		for(i=0;i<b[val].size();i++)
		{
			int flag=0;
			for(j=0;j<a[b[val][i]].size();j++)
			{
				if(a[b[val][i]][j]==val){ flag=1;break;	}
			}
				if(flag)
					dis[b[val][i]]=min(dis[b[val][i]],dis[val]);
				else
					dis[b[val][i]]=min(dis[b[val][i]],dis[val]+1);
			
			if(!mark[b[val][i]])
			{
				mark[b[val][i]]=1;
				q.push(b[val][i]);
			}
		}
	}
	/*printf("printing b\n");
	for(i=0;i<=v;i++)
	{
		if(b[i].size()>0)
		{
			printf("%lld ",i);
			for(j=0;j<b[i].size();j++)
				printf("%lld ",b[i][j]);
			printf("\n");
		}
	}
	printf("printing a\n");

	for(i=0;i<=v;i++)
	{
		if(a[i].size()>0)
		{
			printf("%lld ",i);
			for(j=0;j<a[i].size();j++)
				printf("%lld ",a[i][j]);
			printf("\n");
		}
	}
	printf("dis \n");
	for(i=1;i<=v;i++)
	{
		printf("%lld ",dis[i]);
	}*/
	if(dis[1]==LONG_MAX)
		printf("-1\n");
	else
		printf("%lld\n",dis[1]);
	return 0;
}

