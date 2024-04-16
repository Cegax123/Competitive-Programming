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
    int n; cin >> n;
    int m; cin >> m;
    int g[n][n];
    memset(g, 0, sizeof(g));

    bool cmp = 1;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        g[u][v]++;
        g[v][u]++;

        if(g[u][v] > 1) cmp = 0;
    }

    cout << (cmp ? "YES\n" : "NO\n");

	
    return 0;
}


