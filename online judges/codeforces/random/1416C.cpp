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

ll cnt(const vector<ll>& a, int typ, int pos) {
    int n = a.size();
    int cnt[n];
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        if(i == 0) cnt[i] = 0;
        else cnt[i] = cnt[i-1];

        if(((a[i]>>pos)&1) == 1-typ) cnt[i]++;
    }

    for(int i = 0; i < n; i++) {
        if(((a[i]>>pos)&1) == typ) 
            ans += cnt[n-1]-cnt[i];
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int y = 0;

    for(int j = 40; j >= 0; j--) {
        for(int i = 0; i < n; i++) {
            if((a[i]>>j)&1ll) {
                y = max(y, j);
            }
        }
    }

	
    vector<vector<ll> > s;
    s.pb(a);
    ll ans = 0;
    ll num_inv = 0;

    for(int i = y; i >= 0; i--) {
        ll t0 = 0, t1 = 0;

        for(int j = 0; j < (int) s.size(); j++) {
            t1 += cnt(s[j], 1, i);
            t0 += cnt(s[j], 0, i);
        }

        if(t0 < t1) ans |= (1ll << i);

        num_inv += min(t0, t1);
        vector<vector<ll> > tmp;

        for(int j = 0; j < (int) s.size(); j++) {
            vector<ll> s0, s1;
            for(int k = 0; k < (int) s[j].size(); k++) {
                if((s[j][k] >> i)&1) s1.pb(s[j][k]);
                else s0.pb(s[j][k]);
            }
            
            if(!s0.empty()) tmp.pb(s0);
            if(!s1.empty()) tmp.pb(s1);
        }

        s = tmp;
    }

    cout << num_inv << " " << ans << "\n";

	return 0;
}