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
vector<string> s;
vector<ll> a[100000];
vector<pair<ll,ll> > c;
ll n,i,j;
int main()
{
	inp(n);
	string s1;
	for(i=0;i<n;i++)
	{
		cin >> s1; 
		s.push_back(s1);
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(s[i][j]=='1'&&i<j)
				{
					c.push_back(make_pair(i,j));		
				}
			}
		}		
	}
	
	/*for(i=0;i<n;i++)
		cout << s[i] << "\n";
	printf("\n");
	for(i=0;i<c.size();i++)
	{
		printf("%lld %lld\n",c[i].first,c[i].second);
	}*/
	ll co=0;
	for(i=0;i<c.size();i++)
	{
		for(j=0;j<c.size();j++)
		{
			if(i==j)
				continue;
			if(c[i].first==c[j].first&&s[c[i].second][c[j].second]=='0'&&c[i].second!=c[j].second&&s[c[j].second][c[i].second]=='0')
			{
				co++;
				s[c[i].second][c[j].second]='1';
				s[c[j].second][c[i].second]='1';	
			}
			else if(c[i].second==c[j].second&&s[c[i].first][c[j].first]=='0'&&c[i].first!=c[j].first&&s[c[j].first][c[i].first]=='0')
			{
				co++;
				s[c[i].first][c[j].first]='1';
				s[c[j].first][c[i].first]='1';	
			}
			else if(c[i].second==c[j].first&&s[c[i].first][c[j].second]=='0'&&c[i].first!=c[j].second&&s[c[j].second][c[i].first]=='0')
			{
				co++;
				s[c[i].first][c[j].second]='1';
				s[c[j].second][c[i].first]='1';
			}
			else if(c[j].second==c[i].first&&s[c[j].first][c[i].second]=='0'&&c[j].first!=c[i].second&&s[c[i].second][c[j].first]=='0')
			{
				co++;
				s[c[j].first][c[i].second]='1';
				s[c[i].second][c[j].first]='1';
			}		
		}	
	}
	printf("%lld\n",co*2);
	
	return 0;;
}

