#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000006
#define ll long long int
ll arr[MAX];
ll temp[MAX];
ll hash[MAX];

unsigned ll merge(ll arr[],ll temp[],ll left,ll mid,ll right)
{
   	ll i=left;
    ll j=mid;
    ll k=left;
    unsigned ll invcount=0;
    while((i<=mid-1) && (j<=right))
    {
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            invcount+=(mid-i);
        }
    }
    while(i<=mid-1)
    temp[k++]=arr[i++];
    while(j<=right)
    temp[k++]=arr[j++];
    for(int i=left;i<=right;i++)
    arr[i]=temp[i];
    return invcount;
}
unsigned long long int mergesort(ll arr[],ll temp[],ll left,ll right)
{
  long long int invcount=0;
    if(right>left){
        int mid=(left+right)/2;
        invcount=mergesort(arr,temp,left,mid);
        invcount+=mergesort(arr,temp,mid+1,right);
        invcount+=merge(arr,temp,left,mid+1,right);
    }
    return invcount;
}
int main()
{

   			 ll t=0,n,maxi=0;
   		
       /* scanf("%lld",&n);
        for(ll i=0;i<n;i++){
            scanf("%d",&arr[i]);
            hash[arr[i]]++;
            maxi=max(arr[i],maxi);
        }*/
        for(ll i=0;i<=maxi;i++)
        if(hash[i]>1)
        {
        	t=1;
        	printf("0\n");
        	break;
        }
        n=1;
        for(ll i=99999;i>=0;i--)
        arr[n++]=i;
        if(!t)
        printf("%lld\n",mergesort(arr,temp,0,n-1));
        return 0;

}

