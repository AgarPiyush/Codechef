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
    inline void fscan(ll *a )
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
    vector <pair <ll,ll> > a;
    vector <pair<ll,ll> > b;
    int main()
    {
    ll t;
    fscan(&t);
    while(t--)
    {
    ll n,k,p,i,j,q,w;
    fscan(&n);fscan(&k);fscan(&p);
    for(i=1;i<=k;i++)
    {
    fscan(&q);fscan(&w);
    a.push_back(make_pair(q,w));
    }
    for(i=1;i<=p;i++)
    {
    inp(q);inp(w);
    b.push_back(make_pair(q,w));
    }
    ll flag=0;
    for(i=0;i<k;i++)
    {
    pair <ll,ll> chk;
    chk=a[i];
    flag=0;
    for(j=0;j<p;j++)
    {
    if(chk.first<=chk.second)
    {
    if(b[j].first<=chk.first&&b[j].second>=chk.second)
    {
    flag=2;break;
    }
    else if(b[j].first>chk.second&&b[j].second>=chk.second&&b[j].first>b[j].second)
    {
    flag=2;break;
    }
    else if(b[j].first<=chk.first&&b[j].second<chk.first&&b[j].first>b[j].second)
    {
    flag=2;break;
    }
    }
    else
    {
  	
    if(b[j].first<=chk.first&&b[j].second>=chk.second&&b[j].second<b[j].first)
    {
    flag=2;break;
    }
    }
    }
    if(flag!=2) break;
    }
    if(flag!=2)
    cout << "No\n";
    else
    cout << "Yes\n";
    a.clear();
    b.clear();
    }
    return 0;
    }

