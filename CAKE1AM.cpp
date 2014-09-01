#include<stdio.h>
typedef long long int ll;
ll max(ll a,ll b)
{
	if(a>b)
	return a;
	return b;
}
ll min(ll a,ll b)
{
	if(a>b)
	return b;
	return a;
}
int main()
{
		ll x1,x2,x3,x4,y1,y2,y3,y4;
	ll i,j,k,m,n,x,y,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
		scanf("%lld %lld %lld %lld",&x3,&y3,&x4,&y4);
		ll area1=(x2-x1)*(y2-y1);
		ll area2=(x3-x4)*(y3-y4);
		ll ans=area1+area2;
		ll l,r,u,b;
		l=max(x1,x3);
		r=min(x2,x4);
		b=max(y1,y3);
		u=min(y2,y4);
		if(l<r&&b<u)
		ans=ans-(u-b)*(r-l);
		/*if(y2<y4&&y3<y2&&x2>x3&&x2<x4&&x3>x1&&y3>y1)
		ans=ans-(x3-x2)*(y3-y2);
		else
		if(y2>y3&&y2<y4&&x1>x3&&x1<x4&&x4<x2&&y3>y1)
		ans=ans-(x1-x4)*(y2-y3);
		else 
		if(y4>y1&&y4<y2&&x3>x1&&x3<x2&&x2<x4&&y1>y3)
		ans=ans-(x3-x2)*(y4-y1);
		else 
		if(y4>y1&&y4<y2&&x4>x1&&x4<x2&&y1>y3&&x1>x3)
		ans=ans-(x4-x1)*(y4-y1);*/
		printf("%lld\n",ans);
	}
		return 0;
}
