// nearest smaller element to left
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n;
    // cin >> n;
    vector<int> v({4,5,2,10,8});
    //             -1 4 -1 2 2  
    n = v.size();
    // cout << "dines" << endl;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        // cout << "dine " << i << endl;
        if(st.size()==0)
        {
            cout << -1 << " ";
            st.push(v[i]);
        }
        else{
            while(v[i]<=st.top()){
                st.pop();
                if(st.size()==0)
                    break;
            }
            if(st.size()==0)
            {
                cout << -1 << " ";
            }
            else{
                cout << st.top() << " ";
            }
            st.push(v[i]);
        }
    }
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
