#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int maxn = 2e5+5;

int n;
vector<ii> d;

bool f(ll x) {
    for(int i = 0; i < n; i++) {
        if(x < d[i].first) return 0;
        x -= d[i].second;
    }

    return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        d.pb({a, b});
    }

    sort(all(d), [&] (const ii& a, const ii& b) {
            return a.first - a.second > b.first - b.second;
            });

    ll l = 0, r = (ll) 1e15;

    while(l < r) {
        ll m = (l + r) >> 1;

        if(f(m)) r = m;
        else l = m+1;
    }

    cout << l << "\n";
	
    return 0;
}


