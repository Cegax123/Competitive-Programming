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

const int maxn = 105;
const int INF = 1e9;

vii adj[maxn];
int c[maxn][maxn];
int d[maxn][maxn];
int n;
int cnt = 0;

void dijkstra(int s, int v) {
    vi dis;
    dis.assign(n, INF);
    dis[s] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != dis[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                q.push({dis[to], to});
            }
        }
    }

    if(d[s][v] == dis[v]) cnt++;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            adj[i].pb({j, c[i][j]});
            adj[j].pb({i, c[i][j]});
        }
    }

    for(int i = 0; i < n; i++)
        c[i][i] = 0;

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) d[i][j] = c[i][j];

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }

    bool cmp = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            if(d[i][j] < c[i][j]) cmp = 0;

    if(cmp == 0) {
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int w;
            for(auto& e : adj[i]) {
                if(e.first == j) {
                    w = e.second;
                    e.second = INF;
                }
            }

            dijkstra(i, j);

            for(auto& e : adj[i]) {
                if(e.first == j) {
                    e.second = w;
                }
            }
        }
    }

    cout << cnt << "\n";
	
    return 0;
}


