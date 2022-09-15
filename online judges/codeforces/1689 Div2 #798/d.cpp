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

ii T(const ii& a) {
    return {a.first + a.second, a.second - a.first};
}

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        string board[n+5];

        for(int i = 0; i < n; i++) 
            cin >> board[i];

        int minX = INF, maxX = -INF, minY = INF, maxY = -INF;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'B') {
                    ii p = T({i, j});

                    minX = min(minX, p.first);
                    maxX = max(maxX, p.first);
                    minY = min(minY, p.second);
                    maxY = max(maxY, p.second);
                }
            }
        }

        ii ans;
        int d = INF;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ii p = T({i, j});
                int maxd = max({abs(p.first-minX), abs(p.first-maxX), abs(p.second-minY), abs(p.second-maxY)});

                if(maxd < d) {
                    d = maxd;
                    ans = {i, j};
                }
            }
        }
        cout << ans.first + 1 << " " << ans.second + 1 << "\n";
    }
	
    return 0;
}


