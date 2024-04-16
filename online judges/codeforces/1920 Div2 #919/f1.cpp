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
vector<string> b;
vector<vector<int>> dis;
int n, m;

const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

vector<vector<int>> vis;
int mx, my;

bool comp(int sx, int sy, int w) {
    if(dis[sx][sy] < w) return false;

    vis.clear();
    vis.resize(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    q.push({sx, sy});

    vis[sx][sy] = 1;
    
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if(vis[nx][ny] or dis[nx][ny] < w) continue;
            
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    q.push({mx, my});
    vis[mx][my] = 2;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        for(int d = 0; d < 8; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if(vis[nx][ny]) continue;
            
            vis[nx][ny] = 2;
            q.push({nx, ny});
        }
    }

    bool cmp = true;

    for(int i = 0; i < m; i++)
        if(vis[0][i] == 2 or vis[n-1][i] == 2) cmp = false;

    for(int i = 0; i < n; i++)
        if(vis[i][0] == 2 or vis[i][m-1] == 2) cmp = false;

    return cmp;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> n >> m >> t;
    b.resize(n);

    for(int i = 0; i < n; i++) cin >> b[i];

    dis.resize(n, vector<int>(m, INF));
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(b[i][j] == 'v') {
                q.push({i, j});
                dis[i][j] = 0;
            }
            else if(b[i][j] == '#') {
                mx = i; my = j;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;

            if(dis[nx][ny] == INF) {
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if(b[i][j] == '#') dis[i][j] = -1;
    }

    while(t--) {
        int x, y; cin >> x >> y;
        x--; y--;
        int l = 0, r = 1e7;

        while(l < r) {
            int m = (l+r+1) >> 1;
            if(comp(x, y, m)) l = m;
            else r = m-1;
        }

        cout << l << "\n";
    }
	
    return 0;
}


