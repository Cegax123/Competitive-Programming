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

const int maxn = 20;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string g[n], w[n];

        vector<vector<int>> poss(1 << n, vector<int>(n, 0));
        vector<vector<int>> G(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            cin >> g[i] >> w[i];

            for(int j = 0; j < i; j++) {
                if(g[j] == g[i] or w[j] == w[i]) {
                    G[i][j] = G[j][i] = 1;
                }
            }

            poss[1 << i][i] = 1;
        }

        int ans = 1;
        for(int i = 1; i < (1 << n); i++) {
            for(int a = 0; a < n; a++) {
                for(int b = 0; b < n; b++) {
                    if(a == b) continue;
                    if((i>>a)&1 and (i>>b)&1) {
                        if(poss[i^(1<<a)][b] and G[a][b]) {
                            poss[i][a] = 1;
                            ans = max(ans, __builtin_popcount(i));
                        }
                    }
                }
            }
        }
        cout << n-ans << "\n";

        
    }

	
    return 0;
}


