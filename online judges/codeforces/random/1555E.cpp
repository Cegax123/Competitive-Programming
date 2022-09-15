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
 
const int maxn = 1e6;
const int INF = 1e9;
 
int t[4*maxn+5], lazy[4*maxn];
 
void push(int v) {
    t[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
 
    lazy[v*2] += lazy[v];
    lazy[v*2+1] += lazy[v];
 
    lazy[v] = 0;
}
 
void update(int v, int tl, int tr, int l, int r, int x) {
    if(r < tl or tr < l) return;
    if(tl == l and tr == r) {
        t[v] += x;
        lazy[v] += x;
    }
    else {
        push(v);
        int tm = (tl+tr) >> 1;
 
        update(v*2, tl, tm, l, min(r, tm), x);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, x);
 
        t[v] = min(t[v*2], t[v*2+1]);
    }
}
 
int n, m; 
vii segs[maxn+5];
 
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
 
    for(int i = 0; i < n; i++) {
        int l, r, w; cin >> l >> r >> w;
        segs[w].pb({l, r-1});
    }
 
    int ans = INF;
 
    int r = 1;
    for(int i = 1; i <= maxn; i++) {
        while(r <= maxn and t[1] == 0) {
            for(const ii& e : segs[r]) {
                update(1, 1, m-1, e.first, e.second, +1);
            }
            r++;
        }
 
        if(t[1] == 0) {
            break;
        }
 
        ans = min(ans, r-1-i);
 
        for(const ii& e : segs[i])
            update(1, 1, m-1, e.first, e.second, -1);
    }
 
    cout << ans << "\n";
	
	return 0;
}
