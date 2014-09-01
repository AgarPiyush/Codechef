#include<stdio.h>
#include<string.h>
char s[100000],c[1000000];
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int k=0,i=0,dots=0;
		scanf("%s",s);
		long long int l=strlen(s);
		for(i=0;i<l;i++)
		{
			switch(s[i]-48)
			{
				case 0:
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='-';
					 break;
					 case 1:
					 c[k++]='.';
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='-';
					 dots++;
					 break;
					 case 2:
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='-';
					 dots=dots+2;
					 break;
					 case 3:
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='-';
					 c[k++]='-';
					 dots=dots+3;
					 break;
					 case 4:
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='-';
					 dots=dots+4;
					 break;
					 case 5:
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='.';
					 dots=dots+5;
					 break;
					 case 6:
					 c[k++]='-';
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='.';
					 dots=dots+4;
					 break;
					 case 7:
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='.';
					 c[k++]='.';
					 c[k++]='.';
					 dots=dots+3;
					 break;
					 case 8:
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='.';
					 c[k++]='.';
					 dots=dots+2;
					 break;
					 case 9:
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='-';
					 c[k++]='.';
					 dots=dots+1;
					 break;
			}
		}
		for(i=0;i<k;i++)
		printf("%c",c[i]);
		printf("\n%lld\n",dots);
	}
}
