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
int parent[maxn], id[maxn], sz = 0;
int curr_ans;

void make_set(int v) {
    parent[v] = v;
}

struct Move {
    int x, y, add;
};

vector<Move> moves;

int find(int v, bool L) {
    if(v == parent[v])
        return v;

    if(L) moves.pb({v, parent[v], 0});

    return parent[v] = find(parent[v], L);
}

void union_sets(int a, int b, bool L) {
    a = find(a, L);
    b = find(b, L);

    Move x = {b, parent[b], 0};

    if(a != b) {
        curr_ans--;
        x.add = 1;

        parent[b] = a;
    }

    if(L) moves.pb(x);
}

void restore() {
    while(!moves.empty()) {
        Move x = moves.back(); moves.pop_back();
        parent[x.x] = x.y;
        curr_ans += x.add;
    }
}

const int B = 475;

struct Query {
    int l, r, id;

    bool operator < (Query other) const {
        return make_pair(l / B, r) < make_pair(other.l / B, other.r);
    }
};

const int Left = 1, Right = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    for(int i = 0; i < maxn; i++) 
        id[i] = i/B;

    int t; cin >> t;
    while(t--) {
        int n, m, q; cin >> n >> m >> q;
        vii edges;

        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            edges.pb({a, b});
        }

        vector<Query> queries;
        
        for(int i = 0; i < q; i++) {
            int l, r; cin >> l >> r;
            l--; r--;

            queries.pb({l, r, i});
        }

        sort(all(queries));
        
        int last_block = -1;
        int ans[q];
        int r = -1;

        for(Query Q : queries) {
            if(last_block != id[Q.l]) {
                
                for(int i = 0; i < n; i++)
                    make_set(i);

                curr_ans = n;
                r = B * (id[Q.l] + 1) - 1;
                last_block = id[Q.l];
            }

            while(r < Q.r) {
                r++;
                union_sets(edges[r].first, edges[r].second, Right);
            }

            if(id[Q.l] == id[Q.r]) {
                for(int i = Q.l; i <= Q.r; i++)
                    union_sets(edges[i].first, edges[i].second, Left);
            }
            else {
                for(int i = Q.l; id[i] == id[Q.l]; i++) 
                    union_sets(edges[i].first, edges[i].second, Left);
            }

            ans[Q.id] = curr_ans;
            restore();
        }

        for(int i = 0; i < q; i++)
            cout << ans[i] << "\n";
    }

    return 0;
}


