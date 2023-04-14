#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n;
int rec(int level)
{
    if(level>n) // pruning
        return 0;

    if(level==n) // basecase
        return 1;

    int ans = 0;

    for(int step=1;step<=3;step++) // all choices
    {
        if(level+step<=n) // check
        {
            int ways = rec(level+step); // move
            ans+=ways;
        }
    }
    return ans;
}

void solve()
{
    cin >> n;    
    cout << "no of ways: " << rec(1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll test=1;
    // cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
