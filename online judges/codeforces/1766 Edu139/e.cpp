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

const int maxn = 3e5 + 5;

int n, a[maxn];
map<vi, ll> dp[maxn];

pair<int, vi> go(vi st, int x) {
    if(x == 0) {
        return {1, st};
    }
    else {
        bool found = false;

        for(int i = 0; i < (int) st.size(); i++) {
            if(st[i]&x) {
                st[i] = x;
                found = true;
                break;
            }
        }

        int c = 0;
        if(!found) {
            c = 1;
            st.pb(x);
        }
        return {c, st};
    }
}

ll calc(int pos, vi st) {
    if(pos == n) return 0ll;
    if(dp[pos].count(st)) return dp[pos][st];
    auto p = go(st, a[pos]);
    return dp[pos][st] = (p.first * 1ll * (n-pos) + calc(pos+1, p.second));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += calc(i, vi(0));
    }

    cout << ans << "\n";

    return 0;
}


