#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int i,j,n,t,b[100],k[10000],l,cnt,max,p,front,rear,a[100000],w,no;
char s[100000],store[170000][18],ch1,ch2;
int main()
{
	//b[1]=1;b[2]=3;b[3]=7;b[4]=15;b[5]=31;b[6]=63;b[7]=127;b[8]=255;b[9]=511;b[10]=1023;b[11]=2047;b[12]=4095;b[13]=8191;b[14]=16383;
	int period[]={0,2, 3, 7, 15, 21, 63, 127, 63, 73, 889, 1533, 3255, 7905, 11811};
	scanf("%lld",&t);
	w=1;
	while(w<=t)
	{
		printf("Experiment #%lld:\n",w);
		scanf("%lld %lld",&l,&n);
		scanf("%s",s);		
		/*for(i=0;i<l;i++) 
		{
		if(s[i]=='+') cnt++;
	    }*/
		max=0;
		for(i=0;i<n;i++) 
		{
			scanf("%lld",&a[i]);
			k[i]=a[i]%period[l];
			//if(k[i]>max) max=k[i];
		}a
		/*if(cnt==l-1&&s[l-1]=='-'&&l!=1) 
		{
			//printf("Dfgsdfg\n");
			for(i=0;i<n;i++) printf("%s\n",s);
		}*/
		if(l==1)
		{
			ch1=s[0];
			if(ch1=='+') ch2='-';
			else ch2='+';
			for(i=0;i<n;i++)
			{
				if(a[i]&1) printf("%c\n",ch2);
				else printf("%c\n",ch1);
				//else printf("-\n");
			}
		}
		else
		{
		rear=0;
		front=l-1;
		for(j=rear;j<=front;j++)
		{
		    store[0][j]=s[j];
		}
		for(i=1;i<=period[l];i++)
		{
			//cnt=0;
			if(s[rear]=='+') 
			{
			if(s[front]=='+') s[front]='-';
			else s[front]='+';
			s[++front]='-';
			rear++;
		    }
		    else if(s[rear]=='-')
		    {
		    	s[++front]='+';
		    	rear++;
		    }
		    //printf("rear,front %lld %lld %lld %lld\n",rear,front,a[rear],a[front]);
		    //printf("%lld\n",i);
		    for(j=rear,p=0;j<=front&&p<l;j++,p++)
		    {
		    	store[i][p]=s[j];
		    	//if(store[i][p]==store[0][p]) cnt++;
		    }
		    //no=i;
		    //if(cnt==l) break;
		    //store[i][front+1]='\0';		   
			//printf("s and i %s %d\n",store[i],i);
		    //printf("\n");
		}
		for(i=0;i<n;i++)
		{
		 for(j=0;j<l;j++) printf("%c",store[k[i]][j]);
		 printf("\n");
		 //printf("%s\n",store[i]);
	    }
	    }
	    w++;
	}
	return 0;
} 
