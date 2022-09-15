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

struct Vertex {
    Vertex *l, *r;
    int sum;
    bool marked = 0;

    Vertex(int val): l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r): l(l), r(r), sum(0) {
        if(l) sum += l-> sum;
        if(r) sum += r-> sum;
    }
};

Vertex* build(int tl, int tr) {
    if(tl == tr) 
        return new Vertex(0);
    else {
        int tm = (tl + tr) >> 1;
        return new Vertex(build(tl, tm), build(tm+1, tr));
    }
}

void apply(Vertex *v, int tl, int tr) {
    v->marked = !v->marked;
    v->sum = tr-tl+1 - v->sum;
}

void push(Vertex *v, int tl, int tr) {
    if(v -> marked) {
        int tm = (tl + tr) >> 1;

        apply(v->l, tl, tm);
        apply(v->r, tm+1, tr);

        v -> marked = 0;
    }
}

Vertex* set_val(Vertex* v, int tl, int tr, int pos, int val) {
    if(tl == tr) 
        return new Vertex(val);
    else {
        push(v, tl, tr);

        int tm = (tl + tr) >> 1;
        if(pos <= tm) return new Vertex(set_val(v->l, tl, tm, pos, val), v->r);
        else return new Vertex(v->l, set_val(v->r, tm+1, tr, pos, val));
    }
}

Vertex* revert(Vertex* v, int tl, int tr, int l, int r) {
    if(tr < l or r < tl) return nullptr;
    if(tl == l and tr == r) {
        
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    
    int tl = 0, tr = n * m;

	
    return 0;
}


