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

const int maxn = 1e6+5;

struct Node {
    int cnt4 = 0, cnt7 = 0, maxI = 0, maxD = 0;
};

Node t[4*maxn];
bool change[4*maxn];

int n, m; 
string s;

Node combine(const Node& a, const Node& b) {
    Node c;
    c.cnt4 = a.cnt4 + b.cnt4;
    c.cnt7 = a.cnt7 + b.cnt7;

    c.maxI = max({a.maxI + b.cnt7, a.cnt4 + b.maxI});
    c.maxD = max({a.maxD + b.cnt4, a.cnt7 + b.maxD});

    return c;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        if(s[tl] == '4') t[v].cnt4++;
        else t[v].cnt7++;

        t[v].maxI = t[v].maxD = 1;
    }
    else {
        int tm = (tl+tr) >> 1;

        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void push(int v) {
    if(change[v] == 0) return;
    
    swap(t[v*2].cnt4, t[v*2].cnt7);
    swap(t[v*2].maxD, t[v*2].maxI);
    change[v*2] = 1-change[v*2];

    swap(t[v*2+1].cnt4, t[v*2+1].cnt7);
    swap(t[v*2+1].maxD, t[v*2+1].maxI);
    change[v*2+1] = 1-change[v*2+1];

    change[v] = 0;
}

void update(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return;

    if(tl == l and tr == r) {
        swap(t[v].cnt4, t[v].cnt7);
        swap(t[v].maxD, t[v].maxI);
        change[v] = 1-change[v];
    }
    else {
        push(v);

        int tm = (tl+tr) >> 1;

        update(v*2, tl, tm, l, min(r, tm));
        update(v*2+1, tm+1, tr, max(tm+1, l), r);

        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    cin >> s;

    build(1, 0, n-1);
	
    while(m--) {
        string op; cin >> op;

        if(op == "count") {
            cout << t[1].maxI << "\n";
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;

            update(1, 0, n-1, l, r);
        }
    }
	
	return 0;
}

