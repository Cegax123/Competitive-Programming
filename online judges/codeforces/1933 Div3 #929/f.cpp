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

const int INF = 1e9;
const int maxn = 1005;

int a[maxn][maxn];
int dis[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                dis[i][j] = INF;
            }
        }

        queue<pair<int, int>> q;
        dis[0][0] = 0;

        q.push({0, 0});

        while(!q.empty()) {
            auto e = q.front(); q.pop();
            int x = e.first, y = e.second;

            {
                int nx = (x + 2) % n;
                int ny = y;

                if(dis[nx][ny] == INF and a[(x+1)%n][y] == 0 and a[nx][ny] == 0) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            if(y + 1 < m) {
                int ny = y + 1;
                int nx = (x + 1) % n;

                if(dis[nx][ny] == INF and a[nx][ny] == 0) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int ans = INF;
        for(int i = 0; i < n; i++) {
            if(dis[i][m-1] == INF) continue;
            int pos = i - dis[i][m-1];
            pos %= n;
            pos = (pos + n) % n;

            ans = min(ans, dis[i][m-1] + (pos + 1) % n);
        }

        if(ans == INF) ans = -1;
        cout << ans << "\n";
    }

	
    return 0;
}


