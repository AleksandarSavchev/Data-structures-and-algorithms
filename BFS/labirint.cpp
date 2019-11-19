#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int x,y;
void find(int** a)
{
    a[0][0]=1;
    queue<long long int>qx,qy;
    long long int tx,ty, br1=1,br2=0,index=2;
    qx.push(0);
    qy.push(0);
    while(true)
    {
        tx = qx.front();
        ty = qy.front();
        qx.pop();
        qy.pop();
        if(tx-1>=0&&a[tx-1][ty]==0)
        {
            a[tx-1][ty]=index;
            br2++;
            qx.push(tx-1);
            qy.push(ty);
        }
        if(tx+1<x&&a[tx+1][ty]==0)
        {
            a[tx+1][ty]=index;
            br2++;
            qx.push(tx+1);
            qy.push(ty);
        }
        if(ty-1>=0&&a[tx][ty-1]==0)
        {
            a[tx][ty-1]=index;
            br2++;
            qx.push(tx);
            qy.push(ty-1);
        }
        if(ty+1<y&&a[tx][ty+1]==0)
        {
            a[tx][ty+1]=index;
            br2++;
            qx.push(tx);
            qy.push(ty+1);
        }
        br1--;
        if(br1==0)
        {
            br1=br2;
            br2=0;
            index++;
        }
        if(br1==0)break;
    }
}

int main() 
{
    int x1,y1;
    long long int n;
    cin>>x>>y>>n;
    int** a=new int*[x+1];
    long long int* ans=new long long int[n];
    for(int i = 0; i < y; ++i)
        a[i] = new int[y+1];
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cin>>a[i][j];
        }
    }
    find(a);
    for(long long int i=0;i<n;i++)
    {
        cin>>x1>>y1;
        ans[i]=a[x1][y1];
        if(ans[i]==1&&!(x1==0&&y1==0))
           ans[i]=0;
    }
    for(long long int i=0;i<n;i++)
    {
        cout<<ans[i]-1<<endl;
    }
    return 0;
}
