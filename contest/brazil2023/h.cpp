#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ll s; cin >> s;

    vi p;
    p.pb(0);

    ll c[n];
    map<int, vi> L;
    map<int, vi> R;
    
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r >> c[i];
        p.pb(l); p.pb(r);
        p.pb(l-1);

        L[l].pb(i);
        R[r].pb(i);

    }

    sort(all(p));

    p.erase(unique(all(p)), p.end());

    int k = p.size();
    ll dp[k];

    dp[0] = 0;

    ll add = 0;
    set<pair<ll, int>> t;
    ll val[n];

    for(int i = 1; i < k; i++) {
        dp[i] = dp[i-1];

        add += (p[i]-p[i-1]) * 1ll * s;

        for(int x : L[p[i]]) {
            val[x] = dp[i-1] - c[x] - add + s;
            t.insert({val[x], x});
        }


        if(!t.empty()) {
            auto e = *t.rbegin();
            dp[i] = max(dp[i], e.first + add);
        }

        //cout << p[i] << " " << dp[i] << endl;

        for(int x : R[p[i]]) {
            t.erase({val[x], x});
        }
    }

    cout << dp[k-1] << "\n";
	
    return 0;
}


