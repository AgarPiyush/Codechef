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
#define ll  long long int
#define mod 1000000007
#define inp1(a) scanf("%lld",&a);
#define inp2(a,b) scanf("%lld %lld",&a,&b)
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
ll t,i,j,k,l,m,n;
ll tree[3000005],lazy[3000005],a[3000005];
void segment(ll node, ll b, ll e,ll i, ll j)
{
//	printf("inter %lld %lld\n",b,e);
//	getchar();
	if(j<b || i>e || b>e) 
		return;
	
	int left = node << 1, right = left + 1;
	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if(b!=e)
		{
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(i<=b&&j>=e)
	{
		tree[node]++;
		if(b!=e)
		{
			lazy[left] +=1;
			lazy[right] +=1;
		}
		return;
	}
	segment(left, b, (b+e)>>1, i,j);
	segment(right, ((e+b)>>1)+1,e,i,j);
}
ll h;

ll maxi,ans;
void segment2(ll node,ll b, ll e)
{
	if(b>e) return;
	int left = node << 1, right = left + 1;
	
	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if(b!=e)
		{
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(b == e)
	{
		a[b] = tree[node];
		tree[node] = 0;
		if(b) a[b] = a[b] + a[b-1];
		if(b == h-1) ans = maxi - a[h-1]; 
		else if(b>=h) ans = min(ans, maxi - (a[b] - a[b-h]));
		return;
	}
	segment2(left,b,(e+b)>>1);
	segment2(right,((e+b)>>1)+1,e);
	tree[node] = 0;
}
int main()
{
	finp(&t);
	while(t--)
	{
		ans = 0;
		finp(&n);
		finp(&h);
		for(i=0;i<n;i++)
		{
			finp(&j);
			finp(&k);
			segment(1,0,n-1,j,k);
		}
		maxi = n*h;
		segment2(1,0,n-1);
		printf("%lld\n",ans);
	}
	return 0;
}
