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

const int maxn = 1e5+5;

vi adj[maxn];
int c[maxn];

void fill(int src) {
    queue<int> q;

    q.push(src);
    c[src] = 1;

    while(!q.empty()) {
        int v = q.front(); q.pop();

        for(auto to : adj[v]) {
            if(c[to]) continue;

            c[to] = 3-c[v];
            q.push(to);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 0; i < n; i++)
        if(c[i] == 0) fill(i);
	
    bool cmp = 1;

    for(int i = 0; i < n; i++) {
        for(auto to : adj[i]) 
            if(c[to] == c[i]) cmp = 0;
    }

    if(cmp) for(int i = 0; i < n; i++) cout << c[i] << " ";
    else cout << "IMPOSSIBLE\n";

	return 0;
}

