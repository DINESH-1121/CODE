#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int dp[102][20002];
int dp1[102][20002];

int unknapsack(int n,int coins[],int target)
{
    if(target==0)
        return 0;
    if(n==0)
        return INT32_MAX;
    if(dp1[n][target]!=-1)
        return dp1[n][target];
    int ans;
    if(coins[n-1]<=target)
    {
        ans = min(1+unknapsack(n,coins,target-coins[n-1]),unknapsack(n-1,coins,target));
    }
    else
        ans = unknapsack(n-1,coins,target);
    return dp1[n][target]= ans;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 3;
    int coins[] = {1,2,3};
    int target = 5;

    memset(dp1,-1,sizeof(dp1));
    cout << unknapsack(n,coins,target) << endl;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(i==0)
                dp[i][j] = INT_MAX-1;
            else if(j==0)
                dp[i][j] = 0;
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(coins[i-1]<=j)
            {
                dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }


    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=target;j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n][target] << endl; 

}
