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

const int maxn = 3e4 + 100;
int n, a[maxn];

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if(tl == tr)
        return new Vertex(0);
    else {
        int tm = (tl + tr) >> 1;
        return new Vertex(build(tl, tm), build(tm+1,tr));
    }
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if(tl == tr) 
        return new Vertex(v->sum+1);
    else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) return new Vertex(update(v->l, tl, tm, pos), v -> r);
        else return new Vertex(v->l, update(v->r, tm+1, tr, pos));
    }
}

int get_sum(Vertex *v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return 0;
    if(tl == l and tr == r) {
        return v -> sum;
    }
    else {
        int tm = (tl + tr) >> 1;
        return get_sum(v -> l, tl, tm, l, min(r, tm))
            + get_sum(v -> r, tm+1, tr, max(l, tm+1), r);
    }
}

struct Query {
    int l, r, k;
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<Query> queries;

    int q; cin >> q;
    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        queries.pb({l, r, k});
    }

    set<int> tmp;

    for(int i = 0; i < n; i++)
        tmp.insert(a[i]);

    for(Query Q : queries)
        tmp.insert(Q.k);

    map<int, int> mp;
    int ind = 0;

    for(int x : tmp) mp[x] = ind++;

    for(int i = 0; i < n; i++)
        a[i] = mp[a[i]];

    for(Query& Q : queries)
        Q.k = mp[Q.k];

    vector<Vertex*> roots;

    int tl = 0, tr = ind+1;

    roots.pb(build(tl, tr));

    for(int i = 0; i < n; i++)
        roots.pb(update(roots.back(), tl, tr, a[i]));

    for(Query& Q : queries) {
        int ansR = get_sum(roots[Q.r], tl, tr, Q.k+1, tr);
        int ansL = get_sum(roots[Q.l-1], tl, tr, Q.k+1, tr);

        cout << ansR - ansL << "\n";
    }
	
    return 0;
}


