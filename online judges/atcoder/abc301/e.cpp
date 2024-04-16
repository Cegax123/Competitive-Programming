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

int r, c;
ll t;
const int maxn = 305;
string a[maxn];
int id[maxn][maxn];
int dis[maxn][maxn];
bool vis[maxn][maxn];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool is_valid(int x, int y) {
    return x >= 0 and x < r and y >= 0 and y < c;
}

ll DIS[30][30];

void bfs(int x, int y) {
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    vis[x][y] = 1;
    dis[x][y] = 0;

    queue<ii> q;
    q.push({x, y});

    while(!q.empty()) {
        ii u = q.front(); q.pop();

        for(int d = 0; d < 4; d++) {
            int nx = u.first + dx[d];
            int ny = u.second + dy[d];

            if(!is_valid(nx, ny)) continue;
            if(vis[nx][ny] or a[nx][ny] == '#') continue;

            vis[nx][ny] = 1;
            dis[nx][ny] = dis[u.first][u.second] + 1;

            if(id[nx][ny] != -1) {
                DIS[id[x][y]][id[nx][ny]] = dis[nx][ny];
            }

            q.push({nx, ny});
        }
    }
}

int S = 20, G = 21;
const ll INF = (ll) 1e12;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> r >> c >> t;
    
    memset(id, -1, sizeof(id));

    int cnt = 0;

    for(int i = 0; i < r; i++) {
        cin >> a[i];
        for(int j = 0; j < c; j++) {
            if(a[i][j] == 'o') {
                id[i][j] = cnt++;
            }
            else if(a[i][j] == 'S') {
                id[i][j] = 20;
            }
            else if(a[i][j] == 'G') {
                id[i][j] = 21;
            }
        }
    }

    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 30; j++)
            DIS[i][j] = INF;
    }


    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(id[i][j] != -1) {
                bfs(i, j);
            }
        }
    }

    int ans = -1;

    if(DIS[S][G] <= t) ans = 0;

    for(int i = 0; i < (1 << cnt); i++) {
        int curr = S;
        ll sum = 0;
        int x = 0;

        for(int j = 0; j < cnt; j++) {
            if((i >> j)&1) {
                x++;
                sum += DIS[curr][j];
                curr = j;
            }
        }

        sum += DIS[curr][G];

        if(sum <= t) ans = max(ans, x);
    }

    cout << ans << "\n";
	
    return 0;
}


