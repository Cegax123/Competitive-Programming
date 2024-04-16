#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5;
string s;

int t[4 * maxn], lazy[4 * maxn];

int get_res(int v, int tl, int tr) {
    int tm = (tl+tr) >> 1;
    if(t[v * 2] != -1 and t[v * 2 + 1] != -1) {
        int lenL = tm-tl+1;
        int nxt = t[v * 2] ^ (lenL & 1);

        if(nxt == t[v * 2 + 1]) return t[v * 2];
    }

    return -1;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = s[tl]-'0';
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = get_res(v, tl, tr);
    }
}

void flip(int v) {
    if(t[v] != -1) t[v] ^= 1;
    lazy[v] ^= 1;
}

void push(int v) {
    if(lazy[v]) {
        flip(v * 2);
        flip(v * 2 + 1);
    }
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        flip(v);
    }
    else {
        push(v);
        int tm = (tl+tr) >> 1;
        update(v * 2, tl, tm, l, min(r, tm));
        update(v * 2 + 1, tm+1, tr, max(tm+1, l), r);
        t[v] = get_res(v, tl, tr);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return -1;
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        push(v);
        int tm = (tl+tr) >> 1;
        int a1 = query(v * 2, tl, tm, l, min(r, tm));
        int a2 = query(v * 2 + 1, tm+1, tr, max(tm+1, l), r);

        int len1 = tm-l+1;
        int len2 = r-(tm+1)+1;

        if(len1 <= 0) return a2;
        if(len2 <= 0) return a1;

        if(a1 != -1 and a2 != -1) {
            if((a1 ^ (len1&1)) == a2) return a1;
        }

        return -1;
    }
}

int main() {
    int n, q; cin >> n >> q;
    cin >> s;

    build(1, 0, n-1);

    for(int i = 0; i < q; i++) {
        int op; cin >> op;
        int l, r; cin >> l >> r;
        l--; r--;
        if(op == 1) {
            update(1, 0, n-1, l, r);
        }
        else {
            int ans = query(1, 0, n-1, l, r);
            if(ans == -1) cout << "No\n";
            else cout << "Yes\n";
        }
    }


    return 0;
}
