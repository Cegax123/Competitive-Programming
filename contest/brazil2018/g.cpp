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
    int p, r, c; cin >> p >> r >> c;
    vi d(p), e(r);

    for(int i = 0; i < p; i++) cin >> d[i];
    for(int i = 0; i < r; i++) cin >> e[i];

    const int maxn = 1005;
    vii adj[maxn];

    for(int i = 0; i < c; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[v].pb({u, w});
    }

    bool cmp = [&](int x) {
        vi G = d;

        
    };
	
    return 0;
}


