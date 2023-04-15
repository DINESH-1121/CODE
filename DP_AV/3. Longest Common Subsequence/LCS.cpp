#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int LCS(string x,string y,int n,int m)
{
    if(n==0 || m==0)
        return 0;

    int ans = 0;
    if(x[n-1]==y[m-1])
    {
        return 1+LCS(x,y,n-1,m-1);
    }
    else{
        return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
    }
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

    cout << LCS(x,y,n,m) << endl;  
}