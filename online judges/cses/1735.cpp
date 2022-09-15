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

ll t[4 * maxn], lazy[4 * maxn];
int marked[4 * maxn];
int n, q;
int a[maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
        marked[v] = -1;
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = t[v * 2] + t[v * 2 + 1];
        marked[v] = -1;
    }
}

void push(int v, int tl, int tr) {
    int tm = (tl + tr) >> 1;

    if(marked[v] != -1) {
        t[v * 2] = (ll) marked[v] * (tm-tl+1);
        marked[v * 2] = marked[v];
        lazy[v * 2] = 0;

        t[v * 2 + 1] = (ll) marked[v] * (tr-tm);
        marked[v * 2 + 1] = marked[v];
        lazy[v * 2 + 1] = 0;
        
        marked[v] = -1;
    }
    else {
        t[v * 2] += (ll) lazy[v] * (tm-tl+1);
        if(marked[v * 2] != -1) marked[v * 2] += lazy[v];
        else lazy[v * 2] += lazy[v];


        t[v * 2 + 1] += (ll) lazy[v] * (tr-tm);
        if(marked[v * 2 + 1] != -1) marked[v * 2 + 1] += lazy[v];
        else lazy[v * 2 + 1] += lazy[v];

        lazy[v] = 0;
    }
}

void update_sum(int v, int tl, int tr, int l, int r, ll x) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        t[v] += (ll) x * (tr-tl+1);
        if(marked[v] != -1) marked[v] += x;
        else lazy[v] += x;
    }
    else {
        push(v, tl, tr);

        int tm = (tl + tr) >> 1;

        update_sum(v * 2, tl, tm, l, min(r, tm), x);
        update_sum(v * 2 + 1, tm + 1, tr, max(tm+1, l), r, x);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void update_set(int v, int tl, int tr, int l, int r, ll x) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        t[v] = (ll) x * (tr-tl+1);
        marked[v] = x;
        lazy[v] = 0;
    }
    else {
        push(v, tl, tr);

        int tm = (tl + tr) >> 1;

        update_set(v * 2, tl, tm, l, min(r, tm), x);
        update_set(v * 2 + 1, tm + 1, tr, max(tm+1, l), r, x);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return 0;
    if(tl == l and tr == r) {
        //cout << v << " " << t[v] << " " << tl << " " << tr << endl;
        return t[v];
    }
    else {
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        return query(v * 2, tl, tm, l, min(r, tm)) + 
                query(v * 2 + 1, tm+1, tr, max(tm+1, l), r);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n-1);

    while(q--) {
        int op; cin >> op;
        int l, r; cin >> l >> r;
        l--; r--;
        if(op == 1) {
            int x; cin >> x;
            update_sum(1, 0, n-1, l, r, x);
        }
        else if(op == 2) {
            int x; cin >> x;
            update_set(1, 0, n-1, l, r, x);
        }
        else {
            cout << query(1, 0, n-1, l, r) << "\n";
        }
    }
	
    return 0;
}


