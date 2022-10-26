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

const int maxn = 2e5 + 5, maxk = 10;

struct Node {
    int ans[maxk][maxk];
    int L, R;
    int tl, tr;

    Node() {
        memset(ans, 0, sizeof(ans));
        L = R = -1;
        tl = tr = -1;
    }

    void init(int tl, int tr) {
        this->tl = tl;
        this->tr = tr;
    }
};

Node combine(Node a, Node b) {
    Node c;

    for(int i = 0; i < maxk; i++) {
        for(int j = 0; j < maxk; j++) {
            c.ans[i][j] += a.ans[i][j] + b.ans[i][j];
        }
    }

    c.L = a.L;
    c.R = b.R;

    if(a.R != -1 and b.L != -1) {
        c.ans[a.R][b.L]++;
    }

    c.init(a.tl, a.tr);

    return c;
}

Node t[4 * maxn];
int marked[4 * maxn];

int n, m, k;
string s;

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v].L = t[v].R = s[tl]-'a';
        t[v].init(tl, tr);
        marked[v] = -1;
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = combine(t[v * 2], t[v * 2 + 1]);
        t[v].init(tl, tr);
        marked[v] = -1;
    }
}

void apply(int v, int x) {
    memset(t[v].ans, 0, sizeof(t[v].ans));
    t[v].ans[x][x] = t[v].tr-t[v].tl;
    t[v].L = t[v].R = x;
}

void push(int v) {
    if(marked[v] != -1) {
        apply(v * 2, marked[v]);
        apply(v * 2 + 1, marked[v]);

        marked[v * 2] = marked[v * 2 + 1] = marked[v];

        marked[v] = -1;
    }
}

void print_node(int v) {
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            cout << t[v].ans[i][j] << " ";
        }
        cout << "\n";
    }
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if(tr < l or r < tl) return;

    if(tl == l and r == tr) {
        apply(v, x);
        marked[v] = x;
    }

    else {
        push(v);
        int tm = (tl + tr) >> 1;

        update(v * 2, tl, tm, l, min(r, tm), x);
        update(v * 2 + 1, tm+1, tr, max(tm+1, l), r, x);

        t[v] = combine(t[v * 2], t[v * 2 + 1]);
        t[v].init(tl, tr);
    }
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    cin >> s;

    build(1, 0, n-1);

    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r; cin >> l >> r;
            l--; r--;
            char c; cin >> c;
            int x = c-'a';

            update(1, 0, n-1, l, r, x);
            
        }
        else {
            string q; cin >> q;
            reverse(all(q));
            int ans = 1;

            for(int i = 0; i < k; i++) {
                for(int j = i; j < k; j++) {
                    int x = q[i] - 'a';
                    int y = q[j] - 'a';
                    ans += t[1].ans[x][y];
                }
            }

            cout << ans << "\n";
        }
    }
	
    return 0;
}


