

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
      
inline void finp(ll *n)
{
   *n = 0;
    ll ch = getchar_unlocked();
    while(ch < '0' || ch > '9')
    ch = getchar_unlocked();
    while(ch >= '0' && ch <= '9')
    (*n) = ((*n)<<3) + ((*n)<<1) + ch - '0', ch = getchar_unlocked();
}
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
struct node
{
    ll val[13];
    ll p;
}m[10000005];
ll i,j,k,l,n,a[1000005];
ll rotate(ll item,ll po)
{
    if(item==0)
        return 0;
    ll sum=0,c=0;
    ll b[10]={0},cp=item;
    while(cp>0)
    {
        b[c++]=cp%10;
        cp=cp/10;
    }

    ll d[10]={0},k=c-1;
    for(i=0;i<c;i++)
        d[i]=b[k--];
    po=po%c;


   for(ll i=po;i<c;i++)
       sum=sum*10+d[i];
    for(ll i=0;i<po;i++)
        sum=sum*10+d[i];
    return sum;
}

void build(ll node,ll i,ll j)
{
    if(i==j)
    {
        int k=0;
        m[node].val[0]=a[i];
        for(k=1;k<=11;k++)
        {
            ll pos=rotate(a[i],k);
            m[node].val[k]=pos;
        }
        return;
    }
    build(2*node,i,(i+j)/2);
    build(2*node+1,(i+j)/2+1,j);
    for(int k=0;k<=11;k++)
        m[node].val[k]=max(m[2*node].val[k],m[2*node+1].val[k]);
}
void update(ll node,ll i,ll j,ll b,ll e,ll up)
{
    if(m[node].p!=0)
    {
        struct node temp=m[node];
        for(int k=0;k<=11;k++)
            m[node].val[k]=temp.val[(k+m[node].p)%12];
        if(b!=e)
        {
            m[2*node].p=(m[2*node].p+m[node].p)%12;
            m[2*node+1].p=(m[2*node+1].p+m[node].p)%12;
        }
        m[node].p=0;
    }
    if(b>j||i>e)
        return;
    if(b>=i&&e<=j)
    {
        struct node temp=m[node];
        for(int k=0;k<=11;k++)
            m[node].val[k]=temp.val[(k+m[node].p+up)%12];
        if(b!=e)
        {
            m[2*node].p=(m[2*node].p+m[node].p+up)%12;
            m[2*node+1].p=(m[2*node+1].p+m[node].p+up)%12;
        }
        m[node].p=0;
        return;
    }
    update(2*node,i,j,b,(e+b)/2,up);
    update(2*node+1,i,j,(e+b)/2+1,e,up);
    for(int k=0;k<=11;k++)
        m[node].val[k]=max(m[2*node].val[k],m[2*node+1].val[k]);
}
ll query(ll node,ll i,ll j,ll b,ll e)
{
       if(m[node].p!=0)
       {
            struct node temp=m[node];
             for(int k=0;k<=11;k++)
                 m[node].val[k]=temp.val[(k+m[node].p)%12];
             if(b!=e)
             {
                  m[2*node].p=(m[2*node].p+m[node].p)%12;
                  m[2*node+1].p=(m[2*node+1].p+m[node].p)%12;
             }
             m[node].p=0;
       }
       if(b>j||i>e)
           return -1;
       if(b>=i&&e<=j)
       {
            return m[node].val[m[node].p];
       }
       ll p=query(2*node,i,j,b,(e+b)/2);
       ll q=query(2*node+1,i,j,(e+b)/2+1,e);
       for(int k=0;k<=11;k++)
        m[node].val[k]=max(m[2*node].val[k],m[2*node+1].val[k]);    
       if(p>q)
           return p;
       else return q;
}

int main()
{

    inp1(n);
    for(i=0;i<n;i++)
        inp1(a[i]);
    build(1,0,n-1);
   /*   for(i=1;i<=5;i++)
    {
       printf("i %lld\n",i);
       for(j=0;j<=11;j++)
           printf("%lld ",m[i].val[j]);
       printf("\n");
    }*/
    for(i=0;i<=10000000;i++)
        m[i].p=0;
    ll q;
    inp1(q);
    while(q--)
    {
        ll ch;
        inp1(ch);
        if(ch==1)
        {
             ll i,j;
             inp2(i,j);
             
             printf("%lld\n",query(1,i,j,0,n-1));
        }
        else
        {
            ll i,j,co;
            inp2(i,j);
            inp1(co);
            update(1,i,j,0,n-1,co);
        }
    }
   return 0;
}

 
 



