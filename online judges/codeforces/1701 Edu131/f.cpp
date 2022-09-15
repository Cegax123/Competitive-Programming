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
    ll visible, hidden;
    int active_nodes;
    int L, R, len;

    Node() {
        visible = hidden = 0;
        active_nodes = 0;
        L = R = -1;
        len = 0;
    }

    void init(int _L, int _R) {
        L = _L;
        R = _R;
        len = R-L+1;
    }
};

Node combine(Node a, Node b) {
    Node c;

    c.visible = a.visible + b.visible;
    c.hidden = a.hidden + b.hidden;
    c.active_nodes = a.active_nodes + b.active_nodes;

    return c;
}

int q, d;
Node t[4 * maxn + 100];
int added[4 * maxn + 100], lazy[4 * maxn + 100];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = Node();
        t[v].init(tl, tr);
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = combine(t[v*2], t[v*2+1]);
        t[v].init(tl, tr);
    }
}

void push(int v) {
    t[v * 2].visible += (ll) t[v * 2].active_nodes * lazy[v];
    t[v * 2].hidden += (ll) t[v * 2 + 1].len * lazy[v];
    lazy[v * 2] += lazy[v];

    t[v * 2 + 1].visible += (ll) t[v * 2 + 1].active_nodes * lazy[v];
    t[v * 2 + 1].hidden += (ll) t[v * 2 + 1].len * lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        t[v].visible += (ll) t[v].active_nodes * add;
        t[v].hidden += (ll) t[v].len * add;
        lazy[v] += add;
    }
    else {
        push(v);
        
        int tm = (tl+tr) >> 1;

        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(tm+1, l), r, add);

        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return Node();
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        push(v);

        int tm = (tl + tr) >> 1;

        return combine(query(v * 2, tl, tm, l, min(r, tm)),
        query(v * 2 + 1, tm + 1, tr, max(tm+1, l), r));
    }
}

void change_status(int v, int tl, int tr, int pos) {
    if(tl == tr) {
        t[v].active_nodes ^= 1;

        if(t[v].active_nodes == 0) 
            t[v].visible = 0;
        else 
            t[v].visible = t[v].hidden;
    }
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        if(pos <= tm) change_status(v*2, tl, tm, pos);
        else change_status(v*2 + 1, tm + 1, tr, pos);

        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

bool st[maxn+5];

ll f(ll x) {
    return x * (x-1) / 2;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    build(1, 0, maxn);

    cin >> q >> d;

    ll ans = 0;

    while(q--) {
        int x; cin >> x;

        int sign = 1;
        if(st[x]) sign = -1;

        Node L = Node();
        int l = max(0, x-d), r = x-1;


        if(l <= r) L = query(1, 0, maxn, l, r);

        if(sign == 1) ans += L.visible;
        else ans -= L.visible - L.active_nodes;

        update(1, 0, maxn, l, r, sign);

        Node R = Node();
        l = x+1, r = min(x+d, maxn);

        if(l < r) R = query(1, 0, maxn, l, r);

        ans += f(R.active_nodes) * sign;
        
        change_status(1, 0, maxn, x);
        st[x] ^= 1;

        //for(int i = 1; i <= 8; i++) {
            //Node x = query(1, 0, maxn, i, i);

            //cout << x.visible << " " << x.hidden << " " << x.active_nodes << endl;
        //}

        //cout << endl;

        cout << ans << "\n";
    }
	
    return 0;
}


