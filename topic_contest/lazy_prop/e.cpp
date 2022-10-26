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
const int E = 26;

struct Node {
    vi cnt;
    Node() {cnt.resize(E, 0);}
};

Node t[4*maxn];
int lazy[4*maxn];

int n, q;
string s; 

Node combine(const Node& a, const Node& b) {
    Node c;

    for(int i = 0; i < E; i++)
        c.cnt[i] = a.cnt[i]+b.cnt[i];

    return c;
}

void build(int v, int tl, int tr) {
    if(tl == tr) 
        t[v].cnt[s[tl]-'a']++;
    else {
        int tm = (tl+tr) >> 1;

        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<vi, vi> divide(const vi& cnt, int lenL, int lenR, int k) {
    vi cntL(26, 0), cntR(26, 0);
    int currL = 0, currR = 0;

    if(k == 1) {
        for(int i = 0; i < E; i++) {
            cntL[i] = min(lenL-currL, cnt[i]);
            currL += cntL[i];
        }

        for(int i = E-1; i >= 0; i--) {
            cntR[i] = min(lenR-currR, cnt[i]);
            currR += cntR[i];
        }
    }
    else {
        for(int i = E-1; i >= 0; i--) {
            cntL[i] = min(lenL-currL, cnt[i]);
            currL += cntL[i];
        }

        for(int i = 0; i < E; i++) {
            cntR[i] = min(lenR-currR, cnt[i]);
            currR += cntR[i];
        }
    }

    return {cntL, cntR};
}

void push(int v, int tl, int tr) {
    if(lazy[v] == -1) return;

    int tm = (tl+tr) >> 1;

    int lenL = tm-tl+1;
    int lenR = tr-tm;

    auto ans = divide(t[v].cnt, lenL, lenR, lazy[v]);

    t[v*2].cnt = ans.first;
    t[v*2+1].cnt = ans.second;

    lazy[v*2] = lazy[v*2+1] = lazy[v];

    lazy[v] = -1;
}

void update(int v, int tl, int tr, int l, int r, int k, vi cnt) {
    if(r < tl or tr < l) return;

    if(l == tl and r == tr) {
        t[v].cnt = cnt;
        lazy[v] = k;
    }
    else {
        push(v, tl, tr);

        int tm = (tl+tr) >> 1;

        int lenL = max(0, min(tm, r)-l+1);
        int lenR = max(0, r-max(tm+1, l)+1);

        auto ans = divide(cnt, lenL, lenR, k);

        update(v*2, tl, tm, l, min(r, tm), k, ans.first);
        update(v*2+1, tm+1, tr, max(tm+1, l), r, k, ans.second);

        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return Node();
    if(tl == l and r == tr) {
        return t[v];
    }
    else {
        push(v, tl, tr);
        int tm = (tl+tr) >> 1;

        return combine(query(v*2, tl, tm, l, min(r, tm)), 
                query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(lazy, -1, sizeof(lazy));

    cin >> n >> q;
    cin >> s;

    build(1, 0, n-1);
	
    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        l--; r--;

        vi cnt = query(1, 0, n-1, l, r).cnt;
        update(1, 0, n-1, l, r, k, cnt);
    }

    for(int i = 0; i < n; i++) {
        Node x = query(1, 0, n-1, i, i);

        char c = 0;

        for(int j = 0; j < E; j++)
            if(x.cnt[j]) c = 'a'+j;

        cout << c;
    }
	
	return 0;
}

