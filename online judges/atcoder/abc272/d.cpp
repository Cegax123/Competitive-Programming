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

    vii poss;

    for(int i = 0; i * i <= m; i++) {
        for(int j = 0; j * j <= m; j++) {
            if(i * i + j * j == m) {
                poss.pb({i, j});
                poss.pb({i, -j});
                poss.pb({-i, j});
                poss.pb({-i, -j});
            }
        }
    }

    const int INF = 1e9;
    int d[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i][j] = INF;
        }
    }

    d[0][0] = 0;

    queue<ii> q;
    q.push({0, 0});

    while(!q.empty()) {
        ii v = q.front(); q.pop();
        for(auto e : poss) {
            int nx = v.first + e.first, ny = v.second + e.second;
            if(nx >= 0 and nx < n and ny >= 0 and ny < n) {
                if(d[v.first][v.second] + 1 < d[nx][ny]) {
                    d[nx][ny] = d[v.first][v.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(d[i][j] == INF) d[i][j] = -1;
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
	
    return 0;
}


