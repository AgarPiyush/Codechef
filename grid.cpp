//Author : Piyush Agarwal
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
ll t,i,j,k,l,m,n,a[1005][1005];
vector<string> s;
int main()
{
	inp1(t);
	while(t--)
	{
		s.clear();
		string s1;
		inp1(n);
		int co=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j]=-1;
		for(i=0;i<n;i++)
		{
			cin >> s1;
			s.push_back(s1);	
		//	cout << s1 << "\n";
		}
		//cout << s[n-1] << "\n";
		for(i=0;i<=n-1;i++)
		{
			if(s[n-1][i]=='.')
				a[n-1][i]=1;
		}
		for(i=n-2;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(a[i+1][j]==1&&s[i][j]=='.')
					a[i][j]=1;

			}
		//	printf("\n");
		}	

		/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%lld  ",a[i][j]);
			}
			printf("\n");
		}	
		printf("\n");*/
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>=0;j--)
			{
				if(a[i][j]==1)
					co++;
				if(s[i][j]=='#')
					break;
			}
		}



		printf("%d\n",co );
	}
   return 0;
}