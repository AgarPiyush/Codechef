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

ll power(ll b,string e,ll m)
{
	string k="",temp="";
	ll l=e.length();
	ll i=0;
	while(l>0)
	{
		temp="";
		if((e[l-1]-48)%2==0)
			k=k+(char)'0';
		else
			k=k+(char)'1';
		if(e[0]=='1'&&l==1) break;
		if(e[0]=='1')
		{
			ll val=1;
			for(int i=1;i<l;i++)
			{
				val=(val*10+(e[i]-48));
				ll quo=val/2;
				temp=temp+(char)(quo+48);
				val=val%2;
			}
			e=temp;
			l--;
		}
		else
		{
			ll val=0;
			for(int i=0;i<l;i++)
			{
				val=(val*10+(e[i]-48));
				ll quo=val/2;
				temp=temp+(char)(quo+48);
				val=val%2;
			}
			e=temp;
		}
	//	cout << e <<"\n";
	}
	//cout << k <<"\n";
	ll x=1;
	l=k.length();
	for(ll i=0;i<l;i++)
	{
		if(k[i]=='1')
			x=(x*b)%m;
		b=(b*b)%m;
	}
	return x;
}  
ll gcd(ll a,ll b)
{
    if(b==0)
          return a;
    return gcd(b,a%b);
}
ll t,i,j,k,l,m,n,a[1000005];
string s;
int main()
{
	inp1(t);
	while(t--)
	{
		string pows="";
		inp1(m);
		cin >> s;
		l=s.length();
		ll val=0;
		ll p=0;
		int flag=0;
		ll ans=1;
		for(i=0;i<l;i++)
		{
			if(flag==0)
			{
				if(s[i]>='0'&&s[i]<='9')
				{
					val=val*10+(s[i]-48);
					if(val>m)
						val=val%m;
				}
				else if(s[i]=='*')
						flag=1;			
			}
			else
			if(flag)
			{
				if(s[i]=='*'&&s[i-1]=='*') continue;
				if(s[i]>='0'&&s[i]<='9')
						pows=pows+s[i];
				//printf("val is %lld p is %lld\n",val,p );
				if(s[i]=='*'&&s[i-1]!='*')
				{
					ans=(ans*power(val,pows,m))%m;
					//cout << pows  <<"\n";
					pows="";
					if(ans==0) break;
					val=0;
					p=0;
					flag=0;
				}
			}
		}
		ans=(ans*(power(val,pows,m)))%m;
		printf("%lld\n",ans);
	}
	return 0;
}
