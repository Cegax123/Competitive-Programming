// SOLVED

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

const ll mod = 1e9+7;

ll mul(ll a, ll b, ll c) {
    return a*b%c;
}

ll sum(ll a, ll b, ll c) {
    ll ans = (a+b)%c;

    return (ans+c)%c;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n; cin >> n;
    ll f[1 << n], g[1 << n], h[1 << n];
    
    for(int i = 0; i < (1 << n); i++)
        cin >> f[i];
    for(int i = 0; i < (1 << n); i++)
        cin >> g[i];
    for(int i = 0; i < (1 << n); i++)
        cin >> h[i];

    int MASK = (1 << n)-1;

    bool changed[1 << n];
    memset(changed, 0, sizeof(changed));

    for(int i = 0; i < (1 << n); i++) {
        if(changed[i] == 0) {
            swap(f[i], f[MASK^i]);
            swap(g[i], g[MASK^i]);
            swap(h[i], h[MASK^i]);
            changed[i] = changed[MASK^i] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int mask = 0; mask < (1 << n); mask++) {
            if((mask & (1 << i))==0)  {
                f[mask] = sum(f[mask], f[mask|(1 << i)], mod);
                g[mask] = sum(g[mask], g[mask|(1 << i)], mod);
                h[mask] = sum(h[mask], h[mask|(1 << i)], mod);
            }
        }
    }

    ll p[n+1];
    p[0] = 1;

    for(int i = 1; i <= n; i++)
        p[i] = mul(p[i-1], 2, mod);

    ll q[1 << n];
    int b[1 << n];

    for(int i = 0; i < (1 << n); i++) {
        b[i] = 0;
        
        for(int j = 0; j < n; j++)
            if((i >> j)&1) b[i]++;

        q[i] = mul(f[i], mul(g[i], h[i], mod), mod);
        if(b[i]&1) q[i] = mod - q[i];
    }

    for(int i = 0; i < n; i++) 
        for(int mask = 0; mask < (1 << n); mask++) 
            if((mask & (1 << i)) == 0) q[mask] = sum(q[mask], q[mask|(1 << i)], mod);

    ll ans = 0;
    
    for(int i = 0; i < (1 << n); i++) {
        ans = sum(ans, mul(p[n-b[i]], ((b[i]&1)?mod-q[i]:q[i]), mod),  mod);
    }

    cout << ans << endl;

	return 0;
}


