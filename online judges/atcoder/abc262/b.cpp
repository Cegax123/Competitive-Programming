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
    int n, m; cin >> n >> m;

    int g[n][n];
    memset(g, 0, sizeof(g));

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        g[u][v] = g[v][u] = 1;
    }

    int cnt = 0;
    for(int a = 0; a < n; a++) {
        for(int b = a + 1; b < n; b++) {
            for(int c = b + 1; c < n; c++) {
                if(g[a][b] and g[b][c] and g[a][c])
                    cnt++;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}


