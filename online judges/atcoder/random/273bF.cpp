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
    ll n, x; cin >> n >> x;
    ll w[n], h[n];

    vector<ll> target(1, x);

    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++) cin >> h[i];

    auto get_pos = [](int x, int y, int p) {
        if(x > y) swap(x, y);
        if(x < p and p < y) return 0;
        if(y < p) return 1;
        return -1;
    };

    auto reachable = [](ll w, ll h) {
        if(w > 0) {
            if(h > w) return 0;
            return 1;
        }
        else {
            if(h < w) return 0;
            return 1;
        }
    };

    bool cmp = 1;

    const int INF = 1e9;
        
    while(true) {
        ll t = target.back();

        vector<int> currw;
        for(int i = 0; i < n; i++) {
            if(get_pos(0, t, w[i]) == 0)
                currw.pb(i);
        }

        if(currw.empty()) break;

        ll ans_h = (w[currw[0]] > 0 ? INF : -INF);

        for(int pos : currw) {
            if(w[pos] > 0) ans_h = min(ans_h, h[pos]);
            else ans_h = max(ans_h, h[pos]);

            if(!reachable(w[pos], h[pos])) 
                cmp = 0;
        }

        for(ll x : target) {
            if(x < 0 and get_pos(0, x, ans_h) == -1) cmp = 0;
            else if(x > 0 and get_pos(0, x, ans_h) == 1) cmp = 0;
        }

        if(cmp == 0) break;

        if(w[currw[0]] > 0 and ans_h > 0) break;
        if(w[currw[0]] < 0 and ans_h < 0) break;

        target.pb(ans_h);
    }

    if(!cmp) {
        cout << "-1\n";
        return 0;
    }

    ll ans = abs(target[0]);
    for(int i = 1; i < (int) target.size(); i++) {
        ans += 2ll * abs(target[i]);
    }

    cout << ans << "\n";
	
    return 0;
}


