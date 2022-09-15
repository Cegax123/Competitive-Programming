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

const int maxn = 2e5 + 100;
int b[maxn], cnt[maxn];

struct Node {
    int l, r;
    int sum_val;
    int sum_par;

    Node() {
        l = r = -1;
        sum_val = sum_par = 0;
    }
};

Node combine(Node a, Node b) {
    Node c;
    c.l = a.l;
    c.r = b.r;

    c.sum_val = a.sum_val + b.sum_val;
    c.sum_par = a.sum_par + b.sum_par;

    return c;
}

Node t[4 * maxn];
int lazy[4 * maxn], change[4 * maxn];

void apply(int v, int x, bool par) {
    int len = t[v].r-t[v].l+1;
    
    t[v].sum_val += len * x;
    lazy[v] += x;

    if(par) {
        t[v].sum_par = len - t[v].sum_par;
        change[v] ^= 1;
    }
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v].l = t[v].r = tl;
        t[v].sum_val = b[tl];
        t[v].sum_par = b[tl]&1;
    }
    else {
        int tm = (tl + tr) >> 1;

        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void push(int v) {
    apply(v * 2, lazy[v], change[v]);
    apply(v * 2 + 1, lazy[v], change[v]);

    lazy[v] = 0;
    change[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        apply(v, x, 1);
    }
    else {
        push(v);

        int tm = (tl + tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm), x);
        update(v * 2 + 1, tm+1, tr, max(tm+1, l), r, x);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return Node();
    if(tl == l and tr == r)
        return t[v];
    else {
        int tm = (tl + tr) >> 1;
        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                query(v * 2 + 1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    b[0] = cnt[0];

    for(int i = 1; i < maxn; i++) 
        b[i] = b[i-1] + cnt[i] / 2;

    build(1, 0, maxn-1);

    while(q--) {
        int x, y; cin >> x >> y;
        
        int num = 
    }
	
    return 0;
}


