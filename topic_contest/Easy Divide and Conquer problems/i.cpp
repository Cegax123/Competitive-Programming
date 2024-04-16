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
    vii a;
    a.pb({-1, 0});

    int n, d; cin >> n >> d;

    for(int i = 0; i < n; i++) {
        int m, s; cin >> m >> s;
        a.pb({m, s});
    }

    sort(all(a));

    ll p[n+1];

    p[0] = 0;
    for(int i = 1; i <= n; i++) p[i] = p[i-1] + a[i].second;

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        int l = i, r = n;

        while(l < r) {
            int m = (l+r+1) >> 1;
            if(a[m].first < a[i].first + d) l = m;
            else r = m-1;
        }

        ans = max(ans, p[l]-p[i-1]);
    }

    cout << ans << "\n";
	
    return 0;
}


