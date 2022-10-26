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

struct Edge {
    int l, r, w;
};

vector<Edge> adj[maxn];

const ll INF = (ll) 1e18;

struct Node {
    bool valid;
    ll d;
    int u;

    Node () {}

    Node(bool valid, ll d, int u) {
        this->valid = valid;
        this->d = d;
        this->u = u;
    }
};

Node pq[4*maxn];
ll lazy[4*maxn];

Node combine(const Node& a, const Node& b) {
    if(!a.valid) return b;
    if(!b.valid) return a;

    if(a.d < b.d) return a;
    return b;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        pq[v] = Node(1, INF, tl);
        lazy[v] = INF;
    }
    else {
        int tm = (tl+tr) >> 1;

        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        pq[v] = combine(pq[v*2], pq[v*2+1]);
        lazy[v] = INF;
    }
}

void push(int v) {
    pq[v*2].d = min(pq[v*2].d, lazy[v]);
    lazy[v*2] = min(lazy[v*2], lazy[v]);

    pq[v*2+1].d = min(pq[v*2+1].d, lazy[v]);
    lazy[v*2+1] = min(lazy[v*2+1], lazy[v]);

    lazy[v] = INF;
}

void update(int v, int tl, int tr, int l, int r, ll new_val) {
    if(r < tl or tr < l) return;
    if(tl == l and tr == r) {
        pq[v].d = min(pq[v].d, new_val);
        lazy[v] = min(lazy[v], new_val);
    }
    else {
        push(v);

        int tm = (tl+tr) >> 1;

        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);

        pq[v] = combine(pq[v*2], pq[v*2+1]);
    }
}

void delete_node(int v, int tl, int tr, int u) { 
    if(tl == tr) {
        pq[v].valid = 0;
    }
    else {
        push(v);

        int tm = (tl+tr) >> 1;
        if(u <= tm) delete_node(v*2, tl, tm, u);
        else delete_node(v*2+1, tm+1, tr, u);

        pq[v] = combine(pq[v*2], pq[v*2+1]);
    }
}

vi inter[maxn];
map<ii, vii> poss;

ii t[4*maxn];

void build2(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = {inter[tl].back(), tl};
    }
    else {
        int tm = (tl+tr) >> 1;

        build2(v*2, tl, tm);
        build2(v*2+1, tm+1, tr);

        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void delete_r(int v, int tl, int tr, int L) {
    if(tl == tr) {
        if(inter[tl].back() == -1) return;
        inter[tl].pop_back();

        t[v] = {inter[tl].back(), tl};
    }
    else {
        int tm = (tl+tr) >> 1;

        if(L <= tm) delete_r(v*2, tl, tm, L);
        else delete_r(v*2+1, tm+1, tr, L);

        t[v] = max(t[v*2], t[v*2+1]);
    }
}

ii get_max_r(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return {-1, -1};
    if(tl == l and tr == r)
        return t[v];
    else {
        int tm = (tl+tr) >> 1;

        return max(get_max_r(v*2, tl, tm, l, min(r, tm)),
                    get_max_r(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q, s; cin >> n >> q >> s;
    s--;

    build(1, 0, n-1);

    while(q--) {
        int op; cin >> op;

        if(op == 1) {
            int v, u, w; cin >> v >> u >> w;
            v--; u--;

            adj[v].pb({u, u, w});
        }
        else if(op == 2) {
            int v, l, r, w; cin >> v >> l >> r >> w;
            v--; l--; r--;

            adj[v].pb({l, r, w});
        }
        else { 
            int v, l, r, w; cin >> v >> l >> r >> w;
            v--; l--; r--;

            inter[l].pb(r);

            poss[ii(l,r)].pb({v, w});
        }
    }

    for(int i = 0; i < n; i++) {
        inter[i].pb(-1);
        sort(all(inter[i]));
    }

    build2(1, 0, n-1);

    vector<ll> ans(n, INF);

    update(1, 0, n-1, s, s, 0);

    while(true) {
        Node tmp = pq[1];

        if(tmp.valid == 0 or tmp.d == INF) break;

        int u = tmp.u;
        ll d = tmp.d;

        ans[u] = d;

        delete_node(1, 0, n-1, u);

        for(Edge& e : adj[u]) {
            update(1, 0, n-1, e.l, e.r, (ll) d+e.w);
        }

        while(1) {
            auto interval = get_max_r(1, 0, n-1, 0, u);

            int L = interval.second, R = interval.first;

            if(R < u) break;

            ii x = poss[ii(L, R)].back();
            poss[ii(L, R)].pop_back();

            int to = x.first, w = x.second;

            update(1, 0, n-1, to, to, (ll) d+w);

            delete_r(1, 0, n-1, L);
        }
    }

    for(int i = 0; i < n; i++) {
        if(ans[i] == INF) ans[i] = -1;
        cout << ans[i] << " ";
    }
	
	return 0;
}

