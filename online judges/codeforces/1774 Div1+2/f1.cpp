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

const ll mod = 998244353;
const ll INF = (ll) 1e10;

const int maxn = 2e5 + 5;
ll d[maxn], f[maxn], s[maxn];
ll p2[maxn];
int k;

ll sum(ll a, ll b) {
    return min(INF, a + b);
}

ll msum(ll a, ll b) {
    return (a+b)%mod;
}

ll ans = 0;

void find(ll x, int id, int k) {
    if(x <= 0) return;

    if(id == k) {
        if(x >= f[k]) ans = msum(ans, 2);
        else ans = msum(ans, 2);
        return;
    }

    if(x >= f[k] + 
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    vector<vii> op;
    vii curr;

    for(int i = 0; i < n; i++) {
        int kind; cin >> kind;

        if(kind == 3) {
            op.pb(curr);
            curr.clear();
        }
        else {
            int x; cin >> x;
            curr.pb({kind, x});
        }
    }

    k = op.size();

    for(int i = 0; i < k; i++) {
        for(ii& ac : op[i]) {
            if(ac.first == 2) d[i] = sum(d[i], ac.second);
        }
    }

    s[0] = d[0];
    for(int i = 1; i < k; i++) {
        s[i] = sum(s[i-1], d[i]);
    }

    for(int i = 1; i < k; i++) {
        f[i] = sum(f[i-1], sum(f[i-1], d[i]));
    }

    for(int i = 0; i < k; i++) {
        for(int x : 
    }
	
    return 0;
}


