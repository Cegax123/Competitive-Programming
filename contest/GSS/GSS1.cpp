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

const int maxn = 5e4 + 100;
const ll INF = 1e18;

struct Node {
    ll sum;
    ll ansT, ansL, ansR;

    Node() {
        sum = 0;
        ansT = ansL = ansR = -INF;
    }
};

Node combine(Node a, Node b) {
    Node c;

    c.sum = a.sum + b.sum;
    c.ansL = max(a.ansL, a.sum + b.ansL);
    c.ansR = max(b.ansR, b.sum + a.ansR);
    c.ansT = max({a.ansT, b.ansT, a.ansR + b.ansL});

    return c;
}

Node t[4 * maxn];
int a[maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v].sum = t[v].ansL = t[v].ansR = t[v].ansT = a[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = combine(t[v * 2], t[v * 2+1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return Node();
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
        cin >> a[i];
    build(1, 0, n-1);

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        l--; r--;

        cout << query(1, 0, n-1, l, r).ansT << "\n";
    }

	
    return 0;
}


