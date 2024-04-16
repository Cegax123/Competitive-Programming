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

const int maxn = 2e5 + 5;
ll t[4 * maxn], g[4 * maxn];
ll a[maxn], b[maxn];
const ll INF = 1e9 + 15;

ll get_lcm(ll a, ll b) {
    if(a == INF or b == INF) return INF;

    ll ga = __gcd(a, b);
    ll ans = min(INF, a * b / ga);

    return ans;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl] * b[tl];
        g[v] = b[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2+1, tm+1, tr);

        t[v] = __gcd(t[v * 2], t[v * 2 + 1]);
        g[v] = get_lcm(g[v * 2], g[v * 2 + 1]);
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 0;
    if(tl == l and tr == r)  
        return t[v];
    else {
        int tm = (tl + tr) >> 1;
        return __gcd(query(v * 2, tl, tm, l, min(r, tm)),
                query(v *2 + 1, tm+1, tr, max(tm+1, l), r));
    }
}

ll query_lcm(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 1;
    if(tl == l and tr == r) {
        return g[v];
    }
    else {
        int tm = (tl + tr) >> 1;
        return get_lcm(query_lcm(v * 2, tl, tm, l, min(r, tm)),
                query_lcm(v *2 + 1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

        build(1, 0, n-1);


        int r = 0;
        int R[n];
        for(int i = 0; i < n; i++) {
            while(r < n) {
                ll num = query(1, 0, n-1, i, r);
                ll den = query_lcm(1, 0, n-1, i, r);

                if(num % den == 0) r++;
                else break;
            }

            R[i] = r;
            //cout << R[i] << " ";
        }
        //cout << endl;


        int dp[n+1];
        dp[n] = 0;

        for(int i = n-1; i >= 0; i--)
            dp[i] = dp[R[i]] + 1;

        cout << dp[0] << "\n";
    }

	
    return 0;
}


