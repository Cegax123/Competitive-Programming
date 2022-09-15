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

const int maxn = 2e5+5;

int t[4*maxn];
int a[maxn];

void build(int v, int tl, int tr) {
    if(tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl+tr) >> 1;

        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);

        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int k) {
    if(tl == tr) {
        t[v] -= k;
    }
    else {
        int tm = (tl+tr) >> 1;

        if(pos <= tm) update(v*2, tl, tm, pos, k);
        else update(v*2+1, tm+1, tr, pos, k);

        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int query(int v, int tl, int tr, int k) {
    if(tl == tr)
        return tl;
    else {
        int tm = (tl+tr) >> 1;

        if(t[v*2] >= k) return query(v*2, tl, tm, k);
        else return query(v*2+1, tm+1, tr, k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m; cin >> n >> m;
	
    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n-1);

    for(int i = 0; i < m; i++) {
        int k; cin >> k;

        if(t[1] < k) cout << "0\n";
        else {
            int pos = query(1, 0, n-1, k);
            cout << pos+1 << "\n";

            update(1, 0, n-1, pos, k);
        }
    }
	
	return 0;
}

