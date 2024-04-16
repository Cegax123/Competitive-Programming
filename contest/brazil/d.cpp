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

const int maxn = 5e5+5;

int parent[maxn], sz[maxn];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int enemy[maxn];

bool ok(const vector<ii> v){
    set<int> ss;

    for(auto e : v) {
        ss.insert(e.first);
        ss.insert(e.second);
    }

    if((int) ss.size() <= 3) return true;

    int fir , sec , cnt1 , cnt2 ;
    fir = v[0].first , sec = v[0].second;
    cnt1 = cnt2 = 0;
    for(auto e:v){
        if(e.first == fir or e.second == fir) cnt1++;
        if(e.first == sec or e.second == sec) cnt2++;
    }

    int len = (int)v.size();
    return (cnt1 == len or cnt2 == len); //retorna verdad 
                                        //si todos los nodos comparten aristas 
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;

        edges.pb({u, v, w});
    }

    sort(all(edges));

    memset(enemy, -1, sizeof(enemy));

    for(int i = 0; i < n; i++) {
        make_set(i);
    }

    //vii poss;

    //int p; cin >> p;

    //for(int i = 0; i < p; i++) {
        //int x, y; cin >> x >> y;
        //poss.pb({x, y});
    //}

    //cout << ok(poss) << endl;

    bool cmp = 1;

    vi ans;

    while(!edges.empty()) {
        int w = edges.back().weight;

        vii total;
        vii poss;

        set<int> only;

        while(!edges.empty() and edges.back().weight == w) {
            int u = edges.back().u;
            int v = edges.back().v;

            total.pb({u, v});

            int fu = find_set(u);
            int fv = find_set(v);

            if(enemy[fu] != fv) {
                if(fu == fv) {
                    only.insert(fu);
                }
                else {
                    poss.pb({fu, fv});
                }
            }

            edges.pop_back();
        }

        if((int) only.size() >= 2) {
            ans.pb(w);
        }
        else if((int) only.size() == 1) {
            int x = *only.begin();

            bool found = false;
            for(auto e : poss) {
                if(e.first != x and e.second != x)
                    found = true;
            }

            if(found) ans.pb(w);
        }
        else if(!ok(poss)) {
            ans.pb(w);
        }

        for(auto e : total) {
            int u = e.first, v = e.second;

            u = find_set(u);
            v = find_set(v);
            

            if(u == v) cmp = 0;

            if(enemy[u] == v) continue;

            if(enemy[u] == -1 and enemy[v] == -1) {
                enemy[u] = v;
                enemy[v] = u;
            }
            else if(enemy[u] == -1 and enemy[v] >= 0) {
                union_sets(u, find_set(enemy[v]));
                enemy[find_set(u)] = v;
                enemy[v] = find_set(u);

            }
            else if(enemy[u] >= 0 and enemy[v] == -1) {
                union_sets(v, find_set(enemy[u]));
                enemy[find_set(v)] = u;
                enemy[u] = find_set(v);

            }
            else {
                int eu = find_set(enemy[u]), ev = find_set(enemy[v]);

                if(eu == ev) cmp = 0;

                union_sets(u, ev);
                union_sets(v, eu);

                enemy[find_set(u)] = find_set(eu);
                enemy[find_set(v)] = find_set(ev);
            }

        }

        //cout << "====\n";

        //for(int i = 0; i < n; i++) {
            //cout << find_set(i) << " " << find_set(enemy[find_set(i)]) << "\n";
        //}
        //cout << "===\n";

        if(cmp == 0) break;
    }

    if(cmp) ans.pb(0);

    reverse(all(ans));

    if(ans.empty()) cout <<  "IMPOSSIBLE\n";
    else {
        for(int x : ans) {
            cout << x << "\n";
            //if(n == 142856) {
                //if(x != 22313529) cout << x << "\n";
            //}
            //else cout << x << "\n";
        }
    }
	
    return 0;
}


