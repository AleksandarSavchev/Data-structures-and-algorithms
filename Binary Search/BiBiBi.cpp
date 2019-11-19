#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int l[100001],r[100001],f=0;
int BinaryLeft(long long int *a,int start,int end,int n,long long int x)
{
    if(end<start)
    {
        l[f]=-1;
        return 0;
    }
    int mid=start+(end-start)/2;
    if(a[mid]==x&&(a[mid-1]!=x||mid==0))
        l[f]=mid+1;
    else if(a[mid]>=x)
        BinaryLeft(a,start,mid-1,n,x);
    else 
        BinaryLeft(a,mid+1,end,n,x);
    return 0;
}
int BinaryRight(long long int *a,int start,int end,int n,long long int x)
{
    if(end<start)
    {
        r[f]=-1;
        f++;
        return 0;
    }
    int mid=start+(end-start)/2;
    if(a[mid]==x&&(a[mid+1]!=x||mid==n-1))
    { 
        r[f]=mid+1;
        f++;
    }
    else if(a[mid]<=x) 
      BinaryRight(a,mid+1,end,n,x);
    else 
      BinaryRight(a,start,mid-1,n,x);
    return 0;
}
int main() 
{
    int n,q,i;
    long long int a[100001],q1;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>q1;
        BinaryLeft(a,0,n,n,q1);
        BinaryRight(a,0,n,n,q1);
    }
    for(i=0;i<f;i++)
        cout<<l[i]<<" "<<r[i]<<endl;
    return 0;
}