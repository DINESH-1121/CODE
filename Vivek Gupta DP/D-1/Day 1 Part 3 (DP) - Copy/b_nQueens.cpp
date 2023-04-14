#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n;
int queens[20];

// n queens problem there will be no overlapping problem hence nqueens problem is backtracking not dp problem. 

bool check(int row,int col)
{
    for(int i=0;i<row;i++)
    {
        int crow = i;
        int ccol = queens[i];

        if(col == ccol || ((abs(col-ccol))==(abs(row-crow))))  // horizontal and diagonal check
        {
            return false;
        }
    }
    return true;
}

int rec(int level)
{
    if(level==n) // base case
        return 1;
    
    int ans = 0; 

    for(int col=0;col<n;col++)  // choice
    {
        if(check(level,col))  // check if we can place queen at row=level and col
        {
            queens[level] = col;
            ans+=rec(level+1);
            queens[level] = -1; // backtracking 
        }
    }

    return ans;
}


void solve()
{
    cin >> n;  
    memset(queens,-1,sizeof(queens));  
    cout << "no of ways to place n queens: " << rec(0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
