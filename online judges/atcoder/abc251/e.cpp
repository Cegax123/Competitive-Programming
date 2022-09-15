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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ll a[n+1];

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> f(n+1, INF);
    f[0] = 0;
    f[1] = 0;
    
    for(int i = 2; i < n; i++) 
        f[i] = min(f[i-1] + a[i], f[i-2] + a[i-1]);

    ll ans = f[n-1] + a[n];

    vector<ll> g(n+1, INF);
    g[1] = 0;
    g[2] = 0;

    for(int i = 3; i <= n; i++) 
        g[i] = min(g[i-1] + a[i], g[i-2] + a[i-1]);

    ans = min(ans, g[n] + a[1]);

    cout << ans << "\n";

    return 0;
}


