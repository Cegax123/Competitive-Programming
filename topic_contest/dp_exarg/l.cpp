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

const int maxn = 2e5+5;

int d[maxn], t[maxn], in[maxn];
int mn[maxn];
vi adj[maxn];
bool vis[maxn];

void dfs(int v) {
    vis[v] = true;

    mn[v] = d[v];

    for(int to : adj[v]) {
        if(vis[to] == 0) dfs(to);

        mn[v] = min(mn[v], mn[to]);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> d[i] >> t[i];

        int r; cin >> r;
        in[i] = r;

        for(int j = 0; j < r; j++) {
            int from; cin >> from;
            from--;

            adj[from].pb(i);
        }

    }

    set<ii> s;
    
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0)
            dfs(i);

        if(in[i] == 0)
            s.insert({mn[i], i});
    }

    vi ans;
    int used = 0;
    ll curr = 0;
    bool cmp = 1;

    while(not s.empty()) {
        int x = s.begin()->second; s.erase(s.begin());

        used++;
        ans.pb(x+1);

        curr += t[x];
        if(curr > d[x]) cmp = 0;

        for(int to : adj[x]) {
            in[to]--;

            if(in[to] == 0) {
                s.insert({mn[to], to});
            }
        }
    }

    if(used < n) cmp = 0;

    if(cmp) {
        cout << "YES\n";

        for(int x : ans)
            cout << x << " ";
    }
    else {
        cout << "NO\n";
    }
	
    return 0;
}


