#include<stdio.h>
int main()
{
	long long int t,tc,sc,i,c,n,j,s;
	scanf("%lld",&t);
	while(t>0)
	{
		scanf("%lld %lld",&c,&s);
		if(s==0)
		{
			sc=0;
			tc=c;
		}
		else
		if(c==0)
		{
			sc=0;
			tc=0;
		}
		else
		{
			sc=c/s;
			tc=c%s;
		}
		printf("%lld %lld\n",sc,tc);
		t--;
	}
	return 0;
}
