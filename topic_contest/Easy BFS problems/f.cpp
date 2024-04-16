#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e6;
const int maxm = 1e4 + 5;
const int maxg = 1000 + 5;
const ll INF = (ll) 1e18;

ll dis[maxm][maxg];

int main() {
    int n, m; cin >> n >> m;

    int d[m];
    for(int i = 0; i < m; i++) cin >> d[i];
    sort(d, d + m);

    int g, r; cin >> g >> r;

    for(int i = 0; i < maxm; i++)
        for(int j = 0; j < maxg; j++) dis[i][j] = INF;

    deque<pair<int, int>> q;
    q.push_front({0, 0});
    dis[0][0] = 0;

    ll ans = INF;

    while(!q.empty()) {
        int v = q.front().first, t = q.front().second; q.pop_front();

        //cout << v << " " << t << endl;

        for(int i = -1; i <= 1; i += 2) {
            int nv = v + i;
            if(nv < 0 or nv >= m) continue;

            int delta = abs(d[v] - d[nv]);
            if(delta + t > g) continue;

            int nt = delta + t;

            if(nv == m-1) {
                ans = min(ans, dis[v][t] * (r + g) + nt);
                continue;
            }

            if(dis[nv][nt] < INF) continue;

            if(nt == g) {
                if(dis[nv][0] == INF) {
                    q.push_back({nv, 0});
                    dis[nv][nt] = dis[v][t] + 1;
                    dis[nv][0] = dis[nv][nt];
                }
            }
            else {
                q.push_front({nv, nt});
                dis[nv][nt] = dis[v][t];
            }
        }
    }

    if(ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
