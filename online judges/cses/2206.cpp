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
const int INF = 2e9;
int l[4 * maxn], r[4 * maxn];
int p[4 * maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        l[v] = p[tl] - tl;
        r[v] = p[tl] + tl;
    }
    else {
        int tm = (tl+tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);
        l[v] = min(l[v * 2], l[v * 2 + 1]);
        r[v] = min(r[v * 2], r[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int delta) {
    if(tl == tr) {
        l[v] += delta;
        r[v] += delta;
    }
    else {
        int tm = (tl+tr) >> 1;
        if(pos <= tm) update(v * 2, tl, tm, pos, delta);
        else update(v * 2 + 1, tm+1, tr, pos, delta);

        l[v] = min(l[v * 2], l[v * 2 + 1]);
        r[v] = min(r[v * 2], r[v * 2 + 1]);
    }
}

pair<int, int> query(int v, int tl, int tr, int pl, int pr) {
    if(tr < pl or pr < tl) return {INF, INF};
    if(tl == pl and tr == pr) {
        return {l[v], r[v]};
    }
    else {
        int tm = (tl+tr) >> 1;
        pair<int, int> L = query(v * 2, tl, tm, pl, min(pr, tm));
        pair<int, int> R = query(v * 2 + 1, tm+1, tr, max(tm+1, pl), pr);

        return {min(L.first, R.first), min(L.second, R.second)};
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    build(1, 0, n-1);

    for(int i = 0; i < q; i++) {
        int op; cin >> op;
        if(op == 1) {
            int k, x; cin >> k >> x; k--;
            int delta = x-p[k];
            update(1, 0, n-1, k, delta);
            p[k] = x;
        }
        else {
            int k; cin >> k; k--;
            int ansL = query(1, 0, n-1, 0, k).first;
            int ansR = query(1, 0, n-1, k, n-1).second;

            cout << min(ansL+k, ansR-k) << "\n";
        }
    }

    return 0;
}


