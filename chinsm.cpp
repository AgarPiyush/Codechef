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
}*/
ll power(ll b,ll e)
{
	ll x=1;
	while(e>0)
	{
		if(e&1)
			x=x*b;
		b=b*b;
		e=e/2;
	}
	return x;
}  
ll gcd(ll a,ll b)
{
    if(b==0)
          return a;
    return gcd(b,a%b);
}
ll mult(ll A,ll B)
{
	if ( B == 0 ) return 0;
	ll u = mult(A, B/2);
	ll res;
	if ( B%2 == 0 ) 
		res = u + u;
	else
		res = u + u + A;
	while ( res >= mod ) res -= mod;
	return res;
}
ll t,i,j,k,l,m,n,a[100005],dp[100005];
map<ll,ll> ma;
stack<ll> s;
int main()
{
	inp2(n,k);
	for(i = 0; i<n ;i++)
		inp1(a[i]); 
	ma[a[n-1]] = n - 1;
 	ll fin_ans = n;
 	dp[n-1] = -1;
 	s.push(n-1);
 	for(i = n-2; i>=0 ; i--)
 	{
 		while((!s.empty())&&a[s.top()]<=a[i]) s.pop();
 		if(s.empty()) dp[i] = -1;
 		else dp[i] = s.top();
 		s.push(i);
 	}
 	ll least = LONG_MAX;
 	for(i = n-2 ; i>=0 ; i--)
	{
		ll f = fin_ans;
		ll temp = a[i] - k;
		if(temp > 0)
		{
			ll p = sqrt(temp);
			for(int j=1 ; j<=p; j++)
			{
				if(temp % j ==0)
				{
					ll first = j;
					ll second = temp/j;
					if((a[i]%first == k)&&(ma.find(first)!=ma.end()))
						least = min(least,ma[first]);
					if( (first != second)&&(a[i]%second == k) &&(ma.find(second)!=ma.end())&&(temp%second==0))
						least = min(least,ma[second]);
				} 
			}
			if(least!=LONG_MAX) fin_ans += least - i - 1; 
			else fin_ans += n - i - 1;
		 }
		else if(temp < 0)
			if(least == LONG_MAX)
				fin_ans += n - i - 1;
			else
				fin_ans += least - i - 1;
		else if(temp == 0)
		{
			if(dp[i] == -1)
				fin_ans += n - i - 1;
			else
			{
				fin_ans += dp[i] - i - 1;
				least = dp[i];
			}
		}
		ma[a[i]] = i;
		//printf("ans is %lld for %lld %lld\n",fin_ans - f,a[i],least );
	}
	printf("%lld\n",fin_ans );
	return 0;
}
