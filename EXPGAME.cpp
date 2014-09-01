#include<stdio.h>
char s[200010];
long long int n,a[200010];
int main()
{
	long long int i;
	s[0]='H';
	s[1]=s[4]=s[27]=s[256]=s[3125]=s[46656]='L';
	for(i=2;i<=46656;i++)
	{
		if(i<4)
		{
			if(s[i-1]=='L')
			s[i]='H';
			else
			s[i]='L';
		}
		else if(i>4&&i<27)
		{
			if(s[i-1]=='H'||s[i-4]=='H')
			s[i]='L';
			else
			s[i]='H';
		}
		else if(i>27&&i<256)
		{
			if(s[i-1]=='H'||s[i-4]=='H'||s[i-27]=='H')
			s[i]='L';
			else
			s[i]='H';
			
		}
		else if(i>256&&i<3125)
		{
			 if(s[i-1]=='H'||s[i-4]=='H'||s[i-27]=='H'||s[i-256]=='H')
			s[i]='L';
			else
			s[i]='H';
		}
		else if(i>3125&&i<46656)
		{
			if(s[i-1]=='H'||s[i-4]=='H'||s[i-27]=='H'||s[i-256]=='H'||s[i-3125]=='H')
			s[i]='L';
			else
			s[i]='H';
			
		}	
	}
	for(i=46657;i<=131072;i++)
	{
		 if(s[i-1]=='H'||s[i-4]=='H'||s[i-27]=='H'||s[i-256]=='H'||s[i-3125]=='H'||s[i-46656]=='H')
			s[i]='L';
			else
			s[i]='H';
		
	}
	//for(i=90000;i<=90100;i++)printf("%c\n",s[i]);
	long long int t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		int ans=0;
		for(i=0;i<n;i++)
		{
		scanf("%lld",&a[i]);
		printf("%c\n",s[a[i]]);
		if(s[a[i]]=='L')
		ans^=1;
		else
		ans^=0;
		}
		if(ans)
		printf("Little Chef\n");
		else
		printf("Head Chef\n");
	}
	return 0;
}

