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

inline void finp(ll *a )
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

queue<ll> q;
vector<ll> a[1000005],b[1000005];
ll dis[1000005];
ll i,j,k,l,m,n,t,mark[1000005];
int main()
{
	ll v,e;
	finp(&v);
	finp(&e);
	for(i=0;i<e;i++)
	{
		finp(&j);
		finp(&k);
		if(j!=k)
		{
		dis[j]=dis[k]=LONG_MAX;
		a[j].pb(k);
		b[k].pb(j);
		}
	}
	q.push(1);
	dis[1]=0;
	while(!q.empty())
	{
		ll val=q.front();
		q.pop();
		mark[val]=1;
		for(i=0;i<a[val].size();i++)
		{
			ll old=dis[a[val][i]];
			dis[a[val][i]]=min(dis[val],dis[a[val][i]]);
			if(mark[a[val][i]]==0||((dis[a[val][i]]==dis[val])&&(dis[a[val][i]]!=old)))
			{
				mark[a[val][i]]=1;
				q.push(a[val][i]);
			}
		}
		for(i=0;i<b[val].size();i++)
		{
			ll old=dis[b[val][i]];
			dis[b[val][i]]=min(dis[val]+1,dis[b[val][i]]);
			if(mark[b[val][i]]==0||((dis[b[val][i]]==(dis[val]+1))&&(dis[b[val][i]]!=old)))
			{
					mark[b[val][i]]=1;
					q.push(b[val][i]);
			}
		}
	}
	/*
	for(i=1;i<=v;i++)
		printf("%lld ",dis[i]);
	printf("\n");*/
	if(dis[v]==LONG_MAX)
		printf("-1\n");
	else
		printf("%lld\n",dis[v]);
	return 0;
}

