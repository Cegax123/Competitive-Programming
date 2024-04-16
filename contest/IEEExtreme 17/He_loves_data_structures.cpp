#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int maxn = 3e5 + 5;
const int maxp = 2 * maxn;
const int B = 550;

vector<int> adj[maxn];
int val[maxn];
int phi[maxp];
int st[maxn], fin[maxn];
int h[maxn];
int timer = 0;

void calculatePhi() {
	for(int i = 0; i < maxp; i++) phi[i] = i&1 ? i : i/2;
	for (int i = 3; i < maxp; i += 2) if(phi[i] == i)
		for (int j = i; j < maxp; j += i) phi[j] -= phi[j] / i;
}

void dfs(int v, int p) {
    st[v] = timer++;

    if(v == p) h[v] = 0;
    else h[v] = h[p] + 1;

    for(int to : adj[v]) {
        if(to == p) continue;
        dfs(to, v);
    }
    fin[v] = timer++;
}

bool is_parent(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    calculatePhi();

    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, 0);

    int q; cin >> q;
    vector<pair<int, pair<int, int>>> queries;

    for(int i = 0; i < q; i++) {
        int op; cin >> op;
        if(op == 1) {
            int v, l, r; cin >> v >> l >> r;
            v--;
            queries.push_back({v, {l, r}});
        }
        else {
            int v; cin >> v;
            v--;

            int ans = val[v];

            for(int i = (int) queries.size()-1; i >= 0; i--) {
                int u = queries[i].first, l = queries[i].second.first, r = queries[i].second.second;

                if(is_parent(u, v) and h[v] - h[u] <= r-l) {
                    ans = phi[l + h[v]-h[u]];
                    break;
                }
            }
            
            cout << ans << "\n";
        }

        if(i % B == 0) {
        }
    }

    return 0;
}
