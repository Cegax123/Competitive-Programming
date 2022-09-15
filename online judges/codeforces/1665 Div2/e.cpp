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

const int k = 30;
const int maxn = 1e5+5;
int a[maxn];

vi t[4*maxn];

vi combine(const vi& a, const vi& b) {
    vi ans;

    int inda = 0, indb = 0;

    while((inda < (int) a.size() or indb < (int) b.size()) and (int) ans.size() < k+1) {
        if(inda < (int) a.size() and indb < (int) b.size()) {
            int val = min(a[inda], b[indb]);

            ans.pb(val);

            if(val == a[inda]) inda++;
            else indb++;
        }
        else if(inda < (int) a.size()) {
            ans.pb(a[inda++]);
        }
        else {
            ans.pb(b[indb++]);
        }
    }

    return ans;
}

void build(int v, int tl, int tr) {
    if(tl == tr) 
        t[v].pb(a[tl]);
    else {
        int tm = (tl+tr) >> 1;

        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void clear_t(int v, int tl, int tr) {
    if(tl == tr) {
        t[v].clear();
    }
    else {
        int tm = (tl+tr) >> 1;
        clear_t(v*2, tl, tm);
        clear_t(v*2+1, tm+1, tr);

        t[v].clear();
    }
}

vi query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) 
        return vi();

    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        int tm = (tl+tr) >> 1;

        return combine(query(v*2, tl, tm, l, min(r, tm)),
                    query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
}

int find_min(const vi& A) {
    int ans = (1 << 30);
    for(int i = 0; i < (int) A.size(); i++) {
        for(int j = i+1; j < (int) A.size(); j++) {
            ans = min(ans, (A[i] | A[j]));
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        build(1, 0, n-1);

        int q; cin >> q;
        while(q--) {
            int l, r; cin >> l >> r;
            l--; r--;

            vi ans = query(1, 0, n-1, l, r);
            cout << find_min(ans) << "\n";
        }

        clear_t(1, 0, n-1);
    }
	
	
	return 0;
}

