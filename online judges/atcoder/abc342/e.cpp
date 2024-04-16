#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

struct Edge {
    int l, d, k, c, to;
};

vector<Edge> adj[maxn];

typedef long long ll;
const ll INF = (ll) 2e18;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int l, d, k, c, a, b; cin >> l >> d >> k >> c >> a >> b;
        a--; b--;
        adj[b].push_back({l, d, k, c, a});
    }

    vector<ll> ans(n, 0);
    ans[n-1] = INF;

    priority_queue<pair<ll, int>> pq;
    pq.push({ans[n-1], n-1});

    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();

        ll d_v = e.first; int v = e.second;

        if(d_v != ans[v]) {
            continue;
        }

        for(Edge e : adj[v]) {
            int l = e.l, d = e.d, k = e.k, c = e.c, to = e.to;

            int bl = 0, br = k-1;
            while(bl < br) {
                int bm = (bl+br+1) >> 1;
                ll dis = bm * 1ll * d + l + c;

                if(dis <= d_v) bl = bm;
                else br = bm-1;
            }

            ll dis = bl * 1ll * d + l + c;

            if(dis <= d_v and dis-c > ans[to]) {
                ans[to] = dis-c;
                pq.push({ans[to], to});
            }
        }
    }

    for(int i = 0; i < n-1; i++) {
        if(ans[i] == 0) cout << "Unreachable\n";
        else cout << ans[i] << "\n";
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

struct Edge {
    int l, d, k, c, to;
};

vector<Edge> adj[maxn];

typedef long long ll;
const ll INF = (ll) 2e18;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int l, d, k, c, a, b; cin >> l >> d >> k >> c >> a >> b;
        a--; b--;
        adj[b].push_back({l, d, k, c, a});
    }

    vector<ll> ans(n, 0);
    ans[n-1] = INF;

    priority_queue<pair<ll, int>> pq;
    pq.push({ans[n-1], n-1});

    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();

        ll d_v = e.first; int v = e.second;

        if(d_v != ans[v]) {
            continue;
        }

        for(Edge e : adj[v]) {
            int l = e.l, d = e.d, k = e.k, c = e.c, to = e.to;

            int bl = 0, br = k-1;
            while(bl < br) {
                int bm = (bl+br+1) >> 1;
                ll dis = bm * 1ll * d + l + c;

                if(dis <= d_v) bl = bm;
                else br = bm-1;
            }

            ll dis = bl * 1ll * d + l + c;

            if(dis <= d_v and dis-c > ans[to]) {
                ans[to] = dis-c;
                pq.push({ans[to], to});
            }
        }
    }

    for(int i = 0; i < n-1; i++) {
        if(ans[i] == 0) cout << "Unreachable\n";
        else cout << ans[i] << "\n";
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

struct Edge {
    int l, d, k, c, to;
};

vector<Edge> adj[maxn];

typedef long long ll;
const ll INF = (ll) 2e18;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int l, d, k, c, a, b; cin >> l >> d >> k >> c >> a >> b;
        a--; b--;
        adj[b].push_back({l, d, k, c, a});
    }

    vector<ll> ans(n, 0);
    ans[n-1] = INF;

    priority_queue<pair<ll, int>> pq;
    pq.push({ans[n-1], n-1});

    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();

        ll d_v = e.first; int v = e.second;

        if(d_v != ans[v]) {
            continue;
        }

        for(Edge e : adj[v]) {
            int l = e.l, d = e.d, k = e.k, c = e.c, to = e.to;

            int bl = 0, br = k-1;
            while(bl < br) {
                int bm = (bl+br+1) >> 1;
                ll dis = bm * 1ll * d + l + c;

                if(dis <= d_v) bl = bm;
                else br = bm-1;
            }

            ll dis = bl * 1ll * d + l + c;

            if(dis <= d_v and dis-c > ans[to]) {
                ans[to] = dis-c;
                pq.push({ans[to], to});
            }
        }
    }

    for(int i = 0; i < n-1; i++) {
        if(ans[i] == 0) cout << "Unreachable\n";
        else cout << ans[i] << "\n";
    }

    return 0;
}
