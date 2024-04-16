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

const int maxn = 35;

int n, u, r;
int a[maxn], b[maxn], k[maxn], p[maxn];
ll ans = (ll) -1e18;
const int MOVE = 0, XOR = 1;

void solve(int pos=0, int last=-1) {
    if(pos == u) {
        ll curr = 0;

        //cout << last << ": ";

        //for(int i = 0; i < n; i++)
            //cout << a[i] << " ";

        //cout << endl;
        for(int i = 0; i < n; i++)
            curr += (ll) a[i] * k[i];
        ans = max(ans, curr);
        return;
    }

    if(last != XOR) {
        for(int i = 0; i < n; i++)
            a[i] ^= b[i];

        solve(pos+1, XOR);

        for(int i = 0; i < n; i++)
            a[i] ^= b[i];
    }

    
    
    vi d(n);
    for(int i = 0; i < n; i++) d[i] = a[i];
        
    for(int i = 0; i < n; i++) {
        a[i] = d[p[i]] + r;
    }

    solve(pos+1, MOVE);

    for(int i = 0; i < n; i++)
        a[i] = d[i];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> u >> r;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> k[i];
    for(int i = 0; i < n; i++) cin >> p[i];

    for(int i = 0; i < n; i++) p[i]--;

    int tmp = u;

    for(u = tmp; u >= 0; u -= 2)
        solve();

    cout << ans << "\n";

    return 0;
}



