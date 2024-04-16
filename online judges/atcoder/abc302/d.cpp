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

ll ans = -1;

void solve(const vector<ll>& a, const vector<ll>& b, ll d) {
    int n = a.size(), m = b.size();

    int r = 0;
    for(int i = 0; i < n; i++) {
        
        while(r < m and a[i] + d >= b[r]) {
            r++;
        }

        if(r and b[r-1] >= a[i] and b[r-1] <= a[i] + d)
            ans = max(ans, b[r-1] + a[i]);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    ll d; cin >> d;

    vector<ll> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(all(a));
    sort(all(b));

    solve(a, b, d);
    solve(b, a, d);

    cout << ans << "\n";
	
    return 0;
}


