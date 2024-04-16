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
    int n, k; cin >> n >> k;
    vi a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    const ll INF = (ll) 1e10;

    auto cmp = [&](ll x) {
        ll sum = 0;

        for(int i = 0; i < n; i++) {
            sum += max(0ll, x * a[i] - b[i]);
            sum = min(sum, INF);
        }

        return sum <= k;
    };

    ll l = 0, r = (ll) 2e9;

    while(l < r) {
        int m = (l+r+1) >> 1;
    
        if(cmp(m)) l = m;
        else r = m-1;
    }

    cout << l << "\n";
	
    return 0;
}


