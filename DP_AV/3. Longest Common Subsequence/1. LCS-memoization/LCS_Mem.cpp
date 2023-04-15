#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int LCSM(string x,string y,int n,int m)
{
    if(n==0 || m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    
    if(x[n-1]==y[m-1])
        return dp[n][m] = 1+LCSM(x,y,n-1,m-1);
    else
        return dp[n][m] = max(LCSM(x,y,n-1,m),LCSM(x,y,n,m-1));
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string x = "abcdgh";
    string y = "abedfh";
    int n = x.length(),m=y.length();

    memset(dp,-1,sizeof(dp));

    cout << LCSM(x,y,n,m) << endl;  
    
}
