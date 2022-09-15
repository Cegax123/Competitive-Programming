#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back #define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

void add_map(map<ll, ll>& m, ll key, ll val) {
    {
        auto it = m.lower_bound(key);
        if(it != m.end()) {
            if(it->second >= val) {
                return;
            }
        }
    }

    m[key] = val;
    auto it = m.find(key);

    while(it != m.begin()) {
        auto nxt = it;
        --nxt;

        if(nxt->second <= val) 
            m.erase(nxt);
        else 
            break;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll a[n+1], p[n+1];

        p[0] = 0;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            p[i] = p[i-1] + a[i];
        }

        vector<ll> dp(n+1, 0);
        map<ll, ll> mp, mp0;

        mp[0] = 0;
        mp0[0] = 0;

        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i-1] + (a[i] == 0 ? 0 : (a[i] > 0 ? 1 : -1));
            
            auto it = mp0.find(-p[i]);

            if(it != mp0.end()) 
                dp[i] = max(dp[i], it->second);

            it = mp.upper_bound(-p[i]);

            if(it != mp.end()) 
                dp[i] = max(dp[i], it->second + i);

            add_map(mp, -p[i], dp[i]-i);
            add_map(mp0, -p[i], dp[i]);
        }

        cout << dp[n] << "\n";
    }

	
    return 0;
}


