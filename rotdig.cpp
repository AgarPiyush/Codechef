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
ll t,i,j,k,l,m,n,a[1000005];
string s;
int chkcompare(string a,string b)
{
	ll val1=0,val2=0;
	ll l1=a.length(),l2=b.length();
	for(int i=0;i<l1;i++)
		val1=val1*10+(a[i]-48);
	for(int i=0;i<l2;i++)
		val2=val2*10+(b[i]-48);
	if(val1>=val2)
		return 1;
	return -1;
	
}
int main()
{
	inp1(t);
	while(t--)
	{
		cin >> s;
		string ans=s;
		l=s.length();
		if(l==1&&s[0]=='0')
		{
			printf("0\n");
			continue;
		}	
		
		string temp="";
		string temp3="";
		int flag=0;
		temp=s.substr(1)+s[0];
		temp3=s[l-1]+s.substr(0,l-1);
		for(i=0;i<l;i++)
			if(temp3[i]!='0')
				break;
		temp3=temp3.substr(i);
		for(i=0;i<l;i++)
			if(temp[i]!='0')
				break;
		temp=temp.substr(i);
		if(chkcompare(temp3,temp)>0)
			s=temp3;
		else
			s=temp;
		l=s.length();

		ans=s;
		temp=s;
		for(i=1;i<l;i++)
		{
			string temp2="";
			int flag=0;
			temp2=temp.substr(i);
			temp2=temp2+temp.substr(0,i);
			if(temp2[0]=='0') break;
			if(chkcompare(temp2,ans)>0)
				ans=temp2;
		}
		temp=s;
		for(i=l-1;i>=0;i--)
		{
			string temp2="";
			int flag=0;
			temp2=temp.substr(i,l);
			temp2=temp2+temp.substr(0,i);
			if(temp2[0]=='0') break;
			if(chkcompare(temp2,ans)>0)
				ans=temp2;
		}
		cout << ans << "\n";
	}
	return 0;
}
