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

ll f(ll l, ll p) {
    ll k = l % p;
    ll w = l / p;

    return k * (w+1) * (w+1) + (p-k) * w * w;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, k; cin >> n >> k;
    ll ans = 0;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans += (ll) a[i] * a[i];
    }
	
    priority_queue<pair<ll, ii> > pq;

    for(int i = 0; i < n; i++) {
        if(a[i] > 1) {
            pq.push({f(a[i], 1)-f(a[i], 2), {i, 2}});
        }
    }

    for(int r = 0; r < k-n; r++) {
        auto e = pq.top(); pq.pop();
        ll diff = e.first, i = e.second.first, p = e.second.second;

        ans -= diff;

        if(p < a[i]) {
            pq.push({f(a[i], p)-f(a[i], p+1), {i, p+1}});
        }
    }

    cout << ans << "\n";
	
	return 0;
}

