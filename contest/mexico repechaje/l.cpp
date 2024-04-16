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

const int maxn = 1e6 + 5;

int n, x;
vi adj[maxn];
int kids[maxn];
int par[maxn];
bool marked[maxn];

void dfs(int v, int p) {
    par[v] = p;
    if(v == x) marked[v] = 1;
    kids[v] = 1;
    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
        kids[v] += kids[to];
        if(marked[to]) marked[v] = true;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    x--;

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int v = 0;
    int ans = 0;

    dfs(0, 0);


    while(true) {
        int cnt = 0;
        bool found = false;
        for(int to : adj[v]) {
            if(to == par[v]) continue;
            if(to == x) {
                ans++;
                found = true;
                break;
            }
            if(!marked[to]) cnt += kids[to];
        }
        if(found) break;
        ans += 2 * cnt;
        for(int to : adj[v]) {
            if(to == par[v]) continue;
            if(marked[to]) {
                v = to;
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";
	
    return 0;
}


