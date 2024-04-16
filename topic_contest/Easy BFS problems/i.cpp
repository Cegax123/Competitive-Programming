#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 305;

ll dis[maxn][maxn];
bool used[maxn][maxn];
int a[maxn][maxn];
vector<pair<int, int>> pos[maxn * maxn];

const ll INF = (ll) 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int n, m, p; cin >> n >> m >> p;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            pos[a[i][j]].push_back({i, j});
            if(a[i][j] == 1) {
                dis[i][j] = i + j;
            }
        }
    }

    for(int i = 2; i <= p; i++) {
        int cnta = pos[i-1].size(), cntb = pos[i].size();
        if(cnta * 1ll * cntb >= n * m) {
            memset(used, 0, sizeof(used));
            
            vector<pair<ll, int>> qq;
            deque<pair<int, int>> q;

            for(auto e : pos[i-1]) {
                int x = e.first, y = e.second;

                qq.push_back({dis[x][y], x * m + y});
            }

            sort(qq.begin(), qq.end());

            for(auto e : qq) {
                int coord = e.second;
                int x = coord/m, y = coord%m;
                q.push_back({x, y});
                used[x][y] = 1;
            }

            while(!q.empty()) {
                vector<pair<int, int>> tmp;
                int d = dis[q.front().first][q.front().second];

                while(!q.empty() and d == dis[q.front().first][q.front().second]) {
                    tmp.push_back(q.front());
                    q.pop_front();
                }

                for(auto e : tmp) {
                    int x = e.first, y = e.second;
                    for(int j = 0; j < 4; j++) {
                        int nx = x + dx[j], ny = y + dy[j];
                        if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                        if(used[nx][ny]) continue;

                        dis[nx][ny] = d + 1;
                        used[nx][ny] = 1;
                        q.push_front({nx, ny});
                    }
                }
            }
        }
        else {
            for(auto e : pos[i]) {
                dis[e.first][e.second] = INF;
            }

            for(auto e : pos[i-1]) {
                for(auto t : pos[i]) {
                    int diff = abs(t.first-e.first) + abs(t.second-e.second);
                    dis[t.first][t.second] = min(dis[t.first][t.second], dis[e.first][e.second] + diff);
                }
            }
        }
    }

    ll ans = INF;

    for(auto e : pos[p]) {
        ans = min(ans, dis[e.first][e.second]);
    }

    cout << ans << "\n";

    return 0;
}
