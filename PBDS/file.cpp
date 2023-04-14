#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;


void myerase(ordered_multiset &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_multiset::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ordered_multiset p,s;
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    int ans = 0;
    p.insert(v[0]);
    myerase(s,v[0]);
    for(int i=1;i<n-1;i++)
    {
        p.insert(v[i]);
        myerase(s,v[i]);
        int x = p.order_of_key(v[i]);
        int y= s.order_of_key(v[i]);
        auto it = p.begin();
        cout << "p: ";
        while(it!=p.end()){
            cout << *it << " ";
            it++;
        }
        cout << endl << "S: ";
        it=s.begin();
        while(it!=s.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
        cout << v[i] << " " << x << " " << y << endl;
        ans+=(x*y);
        cout << "ans: " << ans << endl << endl; 

    }

    cout << ans << endl;

}