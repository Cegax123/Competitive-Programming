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
const int maxn = 1e5+5;
const ii dumb = {0, -1};

struct Node {
    vii Le;
    vii Ri;
    ii Ans;

    Node() {
        Le.resize(3, dumb);
        Ri.resize(3, dumb);
        Ans = dumb;
    }
};

int T[maxn], L[maxn], R[maxn], Ans[maxn];
Node t[4 * maxn];

Node combine(Node a, Node b) {
    Node c = a;

    for(int i = 0; i < 3; i++) {
        c.Le[0] = b.Le[i];
        sort(all(c.Le));

        c.Ri[0] = b.Ri[i];
        sort(all(c.Ri));
    }

    c.Ans = max(c.Ans, b.Ans);

    return c;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v].Le[2] = {L[tl], tl};
        t[v].Ri[2] = {R[tl], tl};
        t[v].Ans = {Ans[tl], tl};
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        t[v] = combine(t[v*2], t[v*2+1]);
    }
}


Node query(int v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return Node();
    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        int tm = (tl+tr) >> 1;

        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                        query(v*2+1, tm+1, tr, max(tm+1, l), r));
    }
}

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        string t; cin >> t;

        vi a;

        int ind = 0;
        while(ind < k) {
            char curr = t[ind];
            int cnt = 0;
            while(ind < k and curr == t[ind]) {
                ind++;
                cnt++;
            }
            if(curr == '0') a.pb(-cnt);
            else a.pb(cnt);
        }

        for(int x : a)
            T[i] += x;

        T[i] = max(T[i], 0);

        int local = 0, global = 0;
        for(int x : a) {
            local = max(local + x, x);
            global = max(local, global);
        }

        L[i] = local-T[i];
        L[i] = max(L[i], 0);

        Ans[i] = global;

        reverse(all(a));
        
        local = 0, global = 0;

        for(int x : a) {
            local = max(local + x, x);
            global = max(local, global);
        }

        R[i] = local-T[i];
        R[i] = max(R[i], 0);
    }

    BIT ft(n);

    for(int i = 0; i < n; i++)
        ft.add(i, T[i]);

    build(1, 0, n-1);

    Node y = query(1, 0, n-1, 1, 1);

    while(q--) {
        int l, r; cin >> l >> r;
        l--; r--;

        Node x = query(1, 0, n-1, l, r);
        int ans = x.Ans.first;

        int add;

        if(x.Le[2].second != x.Ri[2].second) add = x.Le[2].first + x.Ri[2].first;
        else {
            add = x.Le[2].first + x.Ri[1].first;
            add = max(add, x.Le[1].first + x.Ri[2].first);
        }

        ans = max(ans, ft.sum(l, r) + add);

        cout << ans << "\n";
    }
	
    return 0;
}


