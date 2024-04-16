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

struct Query {
    int u, v, id;
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;

    vi cnt(n, 0), banned[n];

    vector<Query> queries;

    vii order;

    for(int i = 0; i < q; i++) {
        int op; cin >> op;
        if(op == 1) {
            int u, v; cin >> u >> v;
            u--; v--;
            queries.pb({u, v, i});

            order.pb({u, v});
        }
        else {
            int u; cin >> u; u--;
            banned[u].pb(i);

            order.pb({-1, u});
        }
    }

    vector<vi> to_delete(q);

    for(auto& q : queries) {
        int u = q.u, v = q.v;

        int ans = -1;

        if(!banned[u].empty()) {
            int l = 0, r = banned[u].size()-1;

            while(l < r) {
                int m = (l+r) >> 1;
                if(q.id < banned[u][m]) r = m;
                else l = m+1;
            }

            if(q.id < banned[u][l]) ans = banned[u][l];
        }

        if(!banned[v].empty()) {
            int l = 0, r = banned[v].size()-1;

            while(l < r) {
                int m = (l+r) >> 1;
                if(q.id < banned[v][m]) r = m;
                else l = m+1;
            }

            if(q.id < banned[v][l]) {
                if(ans == -1) ans = banned[v][l];
                ans = min(ans, banned[v][l]);
            }
        }

        if(ans == -1) continue;

        to_delete[ans].pb(q.id);
    }

    int ans = n;
    for(int i = 0; i < q; i++) {
        if(order[i].first == -1) {
            for(int x : to_delete[i]) {
                int u = order[x].first, v = order[x].second;
                cnt[u]--;
                cnt[v]--;

                if(cnt[u] == 0) ans++;
                if(cnt[v] == 0) ans++;
            }
        }
        else {
            int u = order[i].first, v = order[i].second;
            cnt[u]++;
            cnt[v]++;

            if(cnt[u] == 1) ans--;
            if(cnt[v] == 1) ans--;
        }
        cout << ans << "\n";
    }

	
    return 0;
}


