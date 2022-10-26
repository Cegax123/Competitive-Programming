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

const int maxn = 1e5 + 5;
ll INF = (ll) 1e18;

struct Node {
    ll sum;
    ll ans, ansL, ansR;
    int L, R;

    Node() {
        sum = 0;
        ans = ansL = ansR = -INF;
        L = maxn+10;
        R = -1;
    }

    void init(int _L, int _R) {
        L = _L;
        R = _R;
    }
};

Node t[4 * maxn];
int A[maxn];

Node combine(Node a, Node b) {
    Node c;
    
    ll mid = 0;

    if(a.R < maxn and b.L > -1) 
        mid = A[a.R] == A[b.L] ? A[a.R] : 0;

    c.sum = a.sum + b.sum - mid;
    c.ansL = max(a.ansL, a.sum + b.ansL - mid);
    c.ansR = max(b.ansR, b.sum + a.ansR - mid);
    c.ans = max({a.ans, b.ans, a.ansR + b.ansL - mid});
    c.init(min(a.L, b.L), max(b.R, a.R));

    return c;
}


void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v].sum = t[v].ans = t[v].ansL = t[v].ansR = A[tl];
        t[v].init(tl, tr);
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = combine(t[v*2], t[v*2+1]);
        t[v].init(tl, tr);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl)
        return Node();

    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        int tm = (tl + tr) >> 1;
        return combine(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2+1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];

    build(1, 0, n-1);

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        l--; r--;

        cout << query(1, 0, n-1, l, r).ans << "\n";
    }

	
    return 0;
}


