#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

struct Node {
    pair<int, int> a[2];

    Node() {
        a[0] = {-1, 0};
        a[1] = {-2, 0};
    }
};

Node t[4*maxn];

Node make_one(Node a, Node b) {
    map<int, int> cnt;
    vector<pair<int, int>> x;

    cnt[a.a[0].first] += a.a[0].second;
    cnt[a.a[1].first] += a.a[1].second;
    cnt[b.a[0].first] += b.a[0].second;
    cnt[b.a[1].first] += b.a[1].second;

    for(auto e : cnt) x.push_back(e);
    reverse(x.begin(),x.end());

    Node c = Node();
    c.a[0] = x[0];
    c.a[1] = x[1];
    
    return c;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = Node();
        t[v].a[0] = {a[tl], 1};
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = make_one(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int x) {
    if(tl == tr) {
        t[v] = Node();
        t[v].a[0] = {x, 1};
    }
    else {
        int tm = (tl+tr) >> 1;
        if(pos <= tm) update(v * 2, tl, tm, pos, x);
        else update(v * 2 + 1, tm+1, tr, pos, x);

        t[v] = make_one(t[v * 2], t[v * 2 + 1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return Node();
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        int tm = (tl+tr) >> 1;
        return make_one(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2+1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];

    build(1, 0, n-1);

    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int p, x; cin >> p >> x;
            p--;
            update(1, 0, n-1, p, x);
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;
            auto q = query(1, 0, n-1, l, r);
            cout << q.a[1].second << "\n";
        }
    }

    return 0;
}
