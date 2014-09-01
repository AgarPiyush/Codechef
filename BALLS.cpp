#include<stdio.h>
int t[100005],b[100005],freq1[100005],freq2[100005];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&t[i],&b[i]);
		freq1[t[i]]++;
		freq2[b[i]]++;
	}
	int mid=n/2,min=1000000;
	if(n&1) mid++;
	for(i=0;i<n;i++)
	{
			if(freq1[t[i]]>=mid||freq1[b[i]]>=mid)
			{
				min=0;break;
			}
			if(freq1[t[i]]+freq2[t[i]]>=mid)
			if(freq1[t[i]]<mid&&((mid-freq1[t[i]])<=min))
			min=mid-freq1[t[i]];
		
			if(freq1[b[i]]+freq2[b[i]]>=mid)
			if(freq1[b[i]]<mid&&((mid-freq1[b[i]])<=min))
			min=mid-freq1[b[i]];
	}
	if(min==1000000) printf("Impossible\n");
	else printf("%d\n",min);
	return 0;
}
