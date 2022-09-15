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

const int maxn = 2e5 + 5;

struct Node {
    ll ans;
    int vl, vr;
    int l, r;
    int len;

    Node(): len(0) {}
    Node(int x): ans(1), vl(x), vr(x), l(1), r(1), len(1) {}
};

ll f(ll x) {
    return x * (x + 1) / 2;
}

Node combine(const Node& a, const Node& b) {
    if(a.len == 0) return b;
    if(b.len == 0) return a;

    Node c;

    c.ans = a.ans + b.ans;
    c.len = a.len + b.len;
    c.vl = a.vl;
    c.vr = b.vr;

    if(a.vr <= b.vl) {
        c.ans -= f(a.r) + f(b.l);
        c.ans += f(a.r + b.l);
        if(a.len == a.l) c.l = a.len + b.l;
        else c.l = a.l;

        if(b.len == b.r) c.r = b.len + a.r;
        else c.r = b.r;
    }
    else {
        c.l = a.l;
        c.r = b.r;
    }

    return c;
}

Node t[4 * maxn];
int a[maxn];

void build(int v, int tl, int tr) {
    if(tl == tr)
        t[v] = Node(a[tl]);
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int x) {
    if(tl == tr) {
        t[v] = Node(x);
    }
    else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) update(v * 2, tl, tm, pos, x);
        else update(v * 2 + 1, tm+1, tr, pos, x);

        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl)
        return Node();
    if(tl == l and tr == r) {
        //cout << v << " " << tl << " " << tr << " ";
        //cout << t[v].l << " " << t[v].r << " " << t[v].ans << "\n";
        return t[v];
    }
    else {
        int tm = (tl + tr) >> 1;

        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                    query(v * 2 + 1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n-1);

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int x, y; cin >> x >> y;
            update(1, 0, n-1, x-1, y);
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;

            Node res = query(1, 0, n-1, l, r);

            cout << res.ans << "\n";
        }
    }
	
    return 0;
}


