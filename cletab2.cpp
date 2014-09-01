

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
  
ll gcd(ll a,ll b)
{
    if(b==0)
          return a;
    return gcd(b,a%b);
}
ll i,j,k,l,m,n,a[1005],b[1005];
int main()
{
    ll t;
    inp1(t);
    while(t--)
    {
        inp2(k,n);
        ll sit[1000]={0},hash[1000]={0},next[1000]={0};
        for(i=0;i<=k;i++)
            sit[i]=-1;

        for(i=0;i<n;i++)
           inp1(b[i]);
    
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                   if(b[i]==b[j])
                       break;
            }
            if(j==n)
              next[i]=100000;
            else
                next[i]=j;
        }
       
        ll count=0,p=0;
       
        for(i=0;i<n;i++)
        {
            if(p<k)
            {
                if(hash[b[i]]==0)
                {
                    count++;
                    hash[b[i]]=1;
                    sit[p]=i;
                    p++;
                 }
                else
                {
                    for(j=0;j<p;j++)
                    {
                        if(b[sit[j]]==b[i])
                        {
                            sit[j]=i;break;
                        }
                    }
                }
            }
            else
            {
             
                if(hash[b[i]]==1)
                {
                 
                    for(j=0;j<k;j++)
                    {
                        if(b[sit[j]]==b[i])
                        {
                            sit[j]=i;
                            break;
                        }
                    }
              /*       printf("for i %lld\n",i);
                    for(j=0;j<k;j++)
                        printf("%lld ",sit[j]);
                    printf("\n");*/

                    continue;
                }
                ll mini=-1,pos,w,curr,val;
                for(j=0;j<k;j++)
                {
                   if(next[sit[j]]>mini)
                   {
                        curr=j;
                        pos=sit[j];
                        mini=next[sit[j]];
                   }
                }
                hash[b[pos]]=0;
                hash[b[i]]=1;
                count++;
                sit[curr]=i;    
            }    /*
            printf("for i %lld\n",i);
              for(j=0;j<k;j++)
                printf("%lld ",sit[j]);
            printf("\n");*/
        }
        printf("%lld\n",count);
    }
   return 0;
}

 
 


