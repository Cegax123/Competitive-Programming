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

const int maxn = 3e5+5;
const ll mod = 1e9+9;
int A[maxn+5][2][2];

ll sum(ll a, ll b) {
    ll ans = (a+b)%mod;
    if(ans < 0) ans += mod;
    return ans;
}

ll mul(ll a, ll b) {return a*b%mod;}

void init() {
    A[1][0][0] = 1;
    A[1][0][1] = 1;
    A[1][1][0] = 1;
    A[1][1][1] = 0;

    for(int t = 2; t <= maxn; t++) {
        for(int i = 0; i < 2; i++) 
            for(int j = 0; j < 2; j++) 
                for(int k = 0; k < 2; k++) 
                    A[t][i][j] = sum(A[t][i][j], mul(A[t-1][i][k], A[1][k][j]));
    }
}

ll f(ll p, ll q, ll k) {
    if(k == 0) return p;
    if(k == 1) return q;

    return sum((ll) A[k-1][0][0] * q, (ll) A[k-1][0][1] * p);
}

ll sum_first(ll p, ll q, int num) {
    return sum(f(p, q, num+1), -f(p, q, 1));
}

int t[4*maxn], p[4*maxn], q[4*maxn];
int x[maxn];

void build(int v, int tl, int tr) {
    if(tl == tr)
        t[v] = x[tl];
    else {
        int tm = (tl+tr) >> 1;

        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = sum(t[v*2], t[v*2+1]);
    }
}

void push(int v, int tl, int tr) {
    int tm = (tl + tr) >> 1;
    
    t[v*2] = sum(t[v*2], sum_first(p[v], q[v], tm-tl+1));
    p[v*2] = sum(p[v*2], p[v]);
    q[v*2] = sum(q[v*2], q[v]);

    int _p = f(p[v], q[v], tm+1-tl), _q = f(p[v], q[v], tm+1-tl+1);
    t[v*2+1] = sum(t[v*2+1], sum_first(_p, _q, tr-tm));
    p[v*2+1] = sum(p[v*2+1], _p);
    q[v*2+1] = sum(q[v*2+1], _q);

    p[v] = q[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int P, int Q) {
    if(r < tl or tr < l) return;
    if(tl == l and r == tr) {
        t[v] = sum(t[v], sum_first(P, Q, tr-tl+1));
        p[v] = sum(p[v], P);
        q[v] = sum(q[v], Q);
    }
    else {
        push(v, tl ,tr);

        int tm = (tl+tr) >> 1;

        // int lenL = max(0, tm-tl+1);
        //
        // int _P = f(P, Q, lenL);
        // int _Q = f(P, Q, lenL+1);
        
        int _P = P, _Q = Q;
        
        if(tm+1-l >= 0) {
            _P = f(P, Q, tm+1-l); 
            _Q = f(P, Q, tm+1-l+1);
        }

        update(v*2, tl, tm, l, min(r, tm), P, Q);
        update(v*2+1, tm+1, tr, max(tm+1, l), r, _P, _Q);

        t[v] = sum(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return 0;
    if(l == tl and r == tr)
        return t[v];
    else {
        push(v, tl, tr);

        int tm = (tl+tr) >> 1;

        return sum(query(v*2, tl, tm, l, min(r, tm)), 
                query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init();
	
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> x[i];

    build(1, 0, n-1);

    for(int i = 0; i < m; i++) {
        int op; cin >> op;
        int l, r; cin >> l >> r;
        l--; r--;

        if(op == 1) update(1, 0, n-1, l, r, 1, 1);
        else cout << query(1, 0, n-1, l, r) << "\n";
    }

    // for(int i = 0; i < n; i++) {
    //     cout << query(1, 0, n-1, i, i) << " ";
    // }
	
	return 0;
}

