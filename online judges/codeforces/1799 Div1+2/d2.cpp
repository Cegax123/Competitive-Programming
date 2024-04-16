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

const int maxn = 3e5 + 5;
const ll INF = (ll) 1e15;

ll t[4 * maxn];
ll lazy[4 * maxn];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = INF;
        lazy[v] = 0;
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = INF;
        lazy[v] = 0;
    }
}

void push(int v) {
    t[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];

    t[v * 2+1] += lazy[v];
    lazy[v * 2+1] += lazy[v];

    lazy[v] = 0;
}

void update_sum(int v, int tl, int tr, int l, int r, ll add) {
    if(tr < l or r < tl) return;
    if(tl == l and tr == r) {
        t[v] += add;
        lazy[v] += add;
    }
    else {
        push(v);

        int tm = (tl + tr) >> 1;

        update_sum(v * 2, tl, tm, l, min(r, tm), add);
        update_sum(v * 2 + 1, tm + 1, tr, max(tm+1, l), r, add);

        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

void update_val(int v, int tl, int tr, int pos, ll val) {
    if(tl == tr) {
        t[v] = min(t[v], val);
    }
    else {
        push(v);
        int tm = (tl + tr) >> 1;
        if(pos <= tm) update_val(v * 2, tl, tm, pos, val);
        else update_val(v * 2 + 1, tm+1, tr, pos, val);

        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

ll query(int v, int tl, int tr, int pos) {
    if(tl == tr) return t[v];
    else {
        push(v);
        int tm = (tl + tr) >> 1;

        if(pos <= tm) return query(v * 2, tl, tm, pos);
        return query(v * 2 + 1, tm+1, tr, pos);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, k; cin >> n >> k;
        int a[n];

        for(int i = 0; i < n; i++) cin >> a[i];

        int cold[k+1], hot[k+1];

        for(int i = 1; i <= k; i++) cin >> cold[i];
        for(int i = 1; i <= k; i++) cin >> hot[i];


        build(1, 0, k);

        update_val(1, 0, k, 0, 0);

        for(int i = 0; i < n; i++) {
            ll curr = min(t[1] + cold[a[i]], query(1, 0, k, a[i]) + hot[a[i]]);

            ll add;

            if(i == 0) add = cold[a[i]];
            else {
                if(a[i] == a[i-1]) add = hot[a[i]];
                else add = cold[a[i]];
            }

            update_sum(1, 0, k, 0, k, add);
            update_val(1, 0, k, a[i], t[1]);

            if(i) update_val(1, 0, k, a[i-1], curr);

            //for(int i = 0; i <= k; i++)
                //cout << query(1, 0, k, i) << " ";
            //cout << endl;
        }

        ll ans = INF;
        for(int i = 0; i <= k; i++)
            ans = min(ans, query(1, 0, k, i));

        cout << ans << "\n";
    }

	
    return 0;
}


