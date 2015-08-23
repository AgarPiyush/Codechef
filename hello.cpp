/* Author : Piyush Agarwal
 
 _._ _..._ .-',     _.._(`))
'-. `     '  /-._.-'    ',/
   )         \            '.
  / _    _    |             \
 |  a    a    /              |
 \   .-.                     ;  
  '-('' ).-'       ,'       ;
     '-;           |      .'
        \           \    /
        | 7  .__  _.-\   \
        | |  |  ``/  /`  /
       /,_|  |   /,_/   /
          /,_/      '`-'
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define inp1(a) scanf("%lld",&a);
#define outl(a) printf("%lld\n",a);
#define out(a) printf("%lld ",a);
#define line printf("\n");
#define FOR(i,b,e) for(i=b;i<=e;i++)
#define mp make_pair
#define pb push_back
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define getcx getchar_unlocked
#define chkbit(s,b) (s & (1<<b))
#define setbit(s,b) (s | (1<<b))
#define clrbit(s,b) (s &= ~(1<<b))
 
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
 
inline void finpi(int *a )
{
	int n=0; int ch = getcx(); int sign = 1;
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
stack<int> s;
map<int,ll> ma;
vector< pair< int,ll> > v;
vector <int> a1;
int t,i,j,k,l,m,n,a[1000005],b[1000005],dp[1000005];
int main()
{
	finpi(&n);
	finpi(&t);
	b[0] = -1;	
	s.push(0);
	dp[0] = 1;
	finpi(&a[0]);
	for(i=1; i<n ; i++)
	{
		scanf("%d",&a[i]);
		dp[i] = 1;
		while(!s.empty() && a[s.top()]<=a[i])
			s.pop();
		if(s.empty())
			b[i] = -1;
		else
			b[i] = s.top();
		s.push(i);
	}
	int cnt;
	for(i=n-1;i>=0;i--)
	{
		cnt = i - b[i];
		ma[a[i]] += dp[i]*cnt;
		if(b[i]!=-1)
			dp[b[i]] += dp[i];		
	}
	ll sum = 0;
	for(map<int,ll>::iterator it = ma.begin(); it!=ma.end(); it++)
	{
		a1.pb(it->first);
		sum = sum + it->second;
		v.pb(mp(it->first,sum));
	}
	while(t--)
	{
		n = v.size();
		char c,f;
		getchar();
		c = getchar();
		finpi(&m);
		f = getchar();
		//scanf("%c %d %c",&c,&m,&f);
		ll ans;
		if(c == '=')
		{
			if(ma.find(m)!=ma.end())
				ans = ma[m];
			else ans = 0;
		}
		else if(c == '<')
		{
			int pos = lower_bound(a1.begin(),a1.end(),m) - a1.begin();
			pos--;
			if(pos == -1) ans = 0;
			else ans =  v[pos].second ;
		
		}
		else
		{
			int pos = upper_bound(a1.begin(),a1.end(),m) - a1.begin();
	
			if(pos == n)
				ans = 0;
			else 
			{
		//		printf("here\n");
				if(pos == 0) ans =  v[n-1].second ;
				else ans = v[n-1].second - v[pos-1].second;
			}
		//	printf("pos is upper %d %lld\n",pos,ans);
 
		}
		if(!(ans&1))
		{
			if(f=='C') printf("D");
			else printf("C");
		}
		else
			printf("%c",f);
	}
	return 0;
}   