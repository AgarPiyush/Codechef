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
ll i,j,k,l,s,m,n;
vector < pair<ll,ll> > a,les,c,b,cpy1,cpy2,cpy3,orig,origcpy,rev,origrev;
bool fn(pair<ll,ll> q,pair<ll,ll> w)
{
	return q.first<w.first;
}
bool revsort(pair<ll,ll> q,pair<ll,ll> w)
{
	return q.first>w.first;
}

int main()
{
	ll t;
	inp(t);
	while(t--)
	{
		inp(n);inp(k);inp(s);
		ll c1=0,c2=0;
		ll sum1=0,sum2=0;
		for(i=1;i<=n;i++)
		{
			inp(j);
			orig.push_back(make_pair(j,i));
			origcpy.push_back(make_pair(j,i));
			rev.push_back(make_pair(j,i));
			origrev.push_back(make_pair(j,i));
			if(j<=s)
			les.push_back(make_pair(j,i));
			else
			{
			a.push_back(make_pair(j,i));
			b.push_back(make_pair(j,i));
			c.push_back(make_pair(j,i));
			cpy1.push_back(make_pair(j,i));
			cpy3.push_back(make_pair(j,i));
			}
		}	
		
		sort(les.begin(),les.end(),fn);
		ll it,w;
		w=les.size();

		
		for(it=0;it<w;it++)
		{
		c.push_back(make_pair(les[it].first,les[it].second));
		cpy3.push_back(make_pair(les[it].first,les[it].second));
		cpy2.push_back(make_pair(les[it].first,les[it].second));
		}
		
		for(it=c.size()-2;it>=0;it--)
		c[it].first+=c[it+1].first;
		
		for(it=w-1;it>=0;it--)
		{
		a.push_back(make_pair(les[it].first,les[it].second));
		cpy1.push_back(make_pair(les[it].first,les[it].second));
		}
		for(it=a.size()-2;it>=0;it--)
		a[it].first+=a[it+1].first;
		
		for(it=0;it<b.size();it++)
		{
		les.push_back(make_pair(b[it].first,b[it].second));
		cpy2.push_back(make_pair(b[it].first,b[it].second));
		}
		for(it=les.size()-2;it>=0;it--)
		les[it].first+=les[it+1].first;
		ll sum3=0;
		
		for(it=0;it<cpy3.size();it++)
		{
			if(cpy3[it].first>s)
			sum1+=s;
			else
			sum1+=s-c[it].first;
//			cout << cpy3[it].first << " ";
		}
//		printf("\n");
		for(it=0;it<cpy1.size();it++)
		{
			if(cpy1[it].first>s)
			sum2+=s;
			else
			sum2+=s-a[it].first;
	//		cout << cpy1[it].first << " ";
		}
//		printf("\n");
		for(it=0;it<cpy2.size();it++)
		{
			if(cpy2[it].first>s)
			sum3+=s;
			else
			sum3+=s-les[it].first;
	//		cout << cpy2[it].first << " ";
		}
	//	printf("\n");
		
		sort(orig.begin(),orig.end(),fn);
		sort(origcpy.begin(),origcpy.end(),fn);
		ll sum4=0;
		
		for(i=orig.size()-2;i>=0;i--)
		orig[i].first+=orig[i+1].first;
		
		for(it=0;it<origcpy.size();it++)
		{
			if(origcpy[it].first>s)
			sum4+=s;
			else
			sum4+=s-orig[it].first;
	//		cout << origcpy[it].first << " ";
		}
	//	printf("\n");
		
		sort(rev.begin(),rev.end(),revsort);
		sort(origrev.begin(),origrev.end(),revsort);
		ll sum5=0;
		
		for(i=rev.size()-2;i>=0;i--)
		rev[i].first+=rev[i+1].first;
		
		for(it=0;it<rev.size();it++)
		{
			if(origrev[it].first>s)
			sum5+=s;
			else
			sum5+=s-rev[it].first;
		}
		
		ll mini=min(sum1,sum2);
		mini=min(mini,sum3);
		mini=min(mini,sum4);
		mini=min(mini,sum5);
	//	cout << "chk  " << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << " " << mini << "\n";
		
		if(mini==sum1)
		{
		for(it=0;it<c.size();it++)
		cout << c[it].second << " ";
		cout << "\n";
		}
		else if(mini==sum2)
		{
		for(it=0;it<a.size();it++)
		cout << a[it].second << " ";
		cout << "\n";
		}
		else if(mini==sum3)
		{
		for(it=0;it<les.size();it++)
		cout << les[it].second << " ";
		cout << "\n";
		}
		else if(mini==sum4)
 		{
			for(i=0;i<cpy1.size();i++)
			cout << cpy1[i].second << " ";
			cout << "\n";
		}
		else
		{
			for(i=0;i<rev.size();i++)
			cout << rev[i].second << " ";
			cout << "\n";
		}
		
		cpy1.clear();cpy2.clear();cpy3.clear();	b.clear();les.clear();	a.clear();	c.clear();orig.clear();
		origcpy.clear();rev.clear();origrev.clear();
	}
	return 0;
}

