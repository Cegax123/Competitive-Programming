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

const int maxn = 1005;
bool vis[maxn][maxn];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int id[maxn][maxn];
int curr = 1;
string s[maxn];

int n, m;

int ex(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        a = a * 1ll * a % c;
        b >>= 1;
    }
    return ans;
}

void dfs(int x, int y) {
    id[x][y] = curr;
    vis[x][y] = 1;
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];

        if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
        if(vis[nx][ny]) continue;
        if(s[nx][ny] == '.') continue;

        dfs(nx, ny);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> s[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '#' and !vis[i][j]) {
                dfs(i, j);
                curr++;
            }
        }
    }

    int cnt = 0;
    ll sum = 0;
    const int mod = 998244353;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '.') {
                cnt++;

                set<int> g;

                for(int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if(ni < 0 or ni >= n or nj < 0 or nj >= m) continue;

                    if(s[ni][nj] == '#') {
                        g.insert(id[ni][nj]);
                    }
                }

                int tot = curr-1;

                if(!g.empty()) tot -= (int) g.size()-1;
                else tot++;

                sum += tot;
                sum %= mod;
            }
        }
    }


    cnt = ex(cnt, mod-2, mod);

    cout << (sum * 1ll * cnt) % mod << "\n";
	
    return 0;
}


