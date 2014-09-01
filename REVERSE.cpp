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
ll v,e,i,j,k,l,m,n,t;
vector<ll> a[100005],b[100005];
queue<ll> q;
ll mark[100005],dis[100005];
void bfs(ll d)
{
	
	while(!q.empty())
	{
		ll val=q.front();
		printf("val %lld \n",val);
		q.pop();
		mark[val]=1;
		for(i=0;i<b[val].size();i++)
		{
			if(mark[b[val][i]]==0)
			{
				mark[b[val][i]]=1;
				dis[b[val][i]]=dis[val]+1;
				q.push(b[val][i]);
			}
		}
	}
}
ll sum1[1000000],sum2[1000000];
int main()
{
	inp2(v,e);
	for(i=0;i<e;i++)
	{
		inp2(j,k);
		if(y!=k)
		{
		a[j].pb(k);
		b[j].pb(k);
		b[k].pb(j);
		}
	}
	q.push(1);	
	dis[1]=0;
	bfs(0);
	if(dis[n]==0)
		printf("-1\n");
	{
		
	
	for(i=1;i<=e;i++)
		printf("%lld ",dis[i]);
	printf("\n");
	}
	return 0;
}

