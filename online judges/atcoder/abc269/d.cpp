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

bool vis[maxn];
vi adj[maxn];

void dfs(int v) {
    vis[v] = 1;

    for(int to : adj[v])
        if(!vis[to]) dfs(to);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ii p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    const int dx[] = {-1, -1, 0, 0, 1, 1};
    const int dy[] = {-1, 0, -1, 1, 0, 1};

    auto has_edge = [&](const ii& a, const ii& b) {
        for(int i = 0; i < 6; i++)
            if(a.first+dx[i] == b.first and a.second+dy[i] == b.second)
                return true;
        return false;
    };

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(has_edge(p[i], p[j])) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
        if(!vis[i]) {
            ans++;
            dfs(i);
        }

    cout << ans << "\n";
	
    return 0;
}


