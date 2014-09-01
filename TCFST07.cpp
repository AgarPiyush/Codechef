#include<stdio.h>
long long int a[1000000],b[1000000],i,j;
int main()
{
	long long int n,l=0,k,u,max,mid,t;
	//scanf("%lld",&t);
	/*while(t--)
	{*/
		l=0;
	k=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	a[n]=100000000000;
	long long int c=0,f=1;
	l=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i+1]==a[i])
		f++;
		else if(f==1)
		b[k++]=a[i];
		else
		{
//			printf("frequency %lld\n",f);
			if(f%2==1)
			{
//				printf("not eqaual frequency odd\n");
				b[k++]=a[i];
				l=a[i];
				f=f/2;
				l++;
			}
			else
			{
//				printf("not eqaual frequency even\n");
				
				l=a[i];f=f/2;l++;
			}
			while(f!=1)
			{
//				printf("inside loop\n");
			if(l==a[i+1])
			{
//				printf("yes");
					break;
			}
		
			if(f%2==1)
			{
				b[k++]=l;
				f=f/2;
				l++;
			}
			else
			{
				f=f/2;
				l++;
			}
			}

			a[i]=l;
			i--;
			
		}
	}
//	printf("k is %lld\n",k);
	/*for(i=0;i<k;i++)
		printf("%lld ",b[i]);*/
			max=b[k-1];
	c=max-k+1;
	printf("%lld\n",c);

	

	return 0;
}
