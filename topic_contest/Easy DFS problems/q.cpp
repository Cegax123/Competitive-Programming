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

const int maxn = 1e3+5;
bool vis[maxn][maxn];
int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<int, int>> pictures;
string b[maxn];

int id[maxn][maxn];
int curr = 1;

void dfs(int x, int y) {
    vis[x][y] = 1;
    id[x][y] = curr;

    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];

        if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;

        if(b[nx][ny] == '*') {
            pictures.push_back({nx, ny});
            continue;
        }

        if(!vis[nx][ny]) dfs(nx, ny);

    }
}

int ans[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] and b[i][j] == '.') {
                dfs(i, j);

                ans[id[i][j]] = pictures.size();
                pictures.clear();
                curr++;
            }
        }
    }

    for(int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        x--; y--;

        cout << ans[id[x][y]] << "\n";
    }
	
    return 0;
}


