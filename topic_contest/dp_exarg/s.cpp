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

vector<vi> adj;
int val[maxn], up[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;

    while(t--) {
        int n, x; cin >> n >> x;
        x--;

        for(int i = 0; i < n; i++) 
            cin >> val[i];

        adj.clear(); adj.resize(n);

        for(int i = 0; i < n-1; i++) {
            int a, b; cin >> a >> b;

            a--; b--;

            adj[a].pb(b);
            adj[b].pb(a);
        }
    }

	
    return 0;
}


