// https://codeforces.com/gym/100962
// Problem F

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

const int maxn = 1e5;
const int LOGN = 20;
const int B = 375;

int n, q; 
int c[maxn + 5], st[maxn + 5], fin[maxn + 5], T = 0;
int parity[maxn + 5];
vii adj[maxn + 5];
vi A;

void dfs(int v, int p = -1) {
    st[v] = T++;
    A.pb(v);

    for(auto e : adj[v]) {
        int to = e.first, w = e.second;
        if(to == p) continue;
        c[to] = w;
        dfs(to, v);
    }

    fin[v] = T++;
    A.pb(v);
}

bool is_parent(int u, int v) {
    return st[u] <= st[v] and fin[v] <= fin[u];
}

struct Query {
    int l, r, id;
    bool remove_parent;

    bool operator < (Query other) const {
        return make_pair(l / B, r) < make_pair(other.l / B, other.r);
    }
};

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int cnt[maxn + 5];
BIT ft(maxn + 5);

void add(int pos) {
    int x = c[A[pos]];
    if(x > maxn) return;

    if(cnt[x] == 0)
        ft.add(x, 1);

    cnt[x]++;
}

void remove(int pos) {
    int x = c[A[pos]];
    if(x > maxn) return;

    cnt[x]--;

    if(cnt[x] == 0)
        ft.add(x, -1);
}

void process(int pos) {
    parity[A[pos]] ^= 1;

    if(parity[A[pos]]) add(pos);
    else remove(pos);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        int w; cin >> w;
        a--; b--;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    dfs(0);
    
    //for(int x : A)
        //cout << x << " ";

    //cout << endl;
    
    int ans[q];
    vector<Query> queries;

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        if(a == b) {
            ans[i] = 0;
            continue;
        }

        if(st[a] > st[b])
            swap(a, b);


        int p = -1;
        if(is_parent(a, b)) p = a;

        if(p == a) 
            queries.pb({st[a] + 1, st[b], i});
        else 
            queries.pb({fin[a], st[b], i});
    }

    sort(all(queries));

    int l = 0, r = -1;
    for(Query Q : queries) {
        while(l > Q.l) {
            l--;
            process(l);
        }
        while(r < Q.r) {
            r++;
            process(r);
        }
        while(l < Q.l) {
            process(l);
            l++;
        }
        while(r > Q.r) {
            process(r);
            r--;
        }

        //cout << l << " " << r << " " << Q.id << endl;

        //for(int i = 0; i < 5; i++)
            //cout << ft.sum(i, i) << " ";

        //cout << endl << endl;

        int tl = 0, tr = maxn;
        while(tl < tr) {
            int tm = (tl + tr + 1) >> 1;
            if(ft.sum(0, tm) == tm + 1) tl = tm;
            else tr = tm-1;
        }

        if(ft.sum(0, tl) == tl + 1) ans[Q.id] = tl+1;
        else ans[Q.id] = 0;
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";
	
    return 0;
}


