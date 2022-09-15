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

void map_coord(vi& a) {
    set<int> s;

    for(int x : a)
        s.insert(x);

    int ind = 0;
    map<int, int> mp;

    for(int x : s)
        mp[x] = ind++;

    //for(int x : s) 
        //cout << x << " " << mp[x] << endl;

    for(int i = 0; i < (int) a.size(); i++)
        a[i] = mp[a[i]];
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
    int n; cin >> n;
    vi a(n), b(n);

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = 1e9-b[i];
    }

    map_coord(a); map_coord(b);

    //for(int i = 0; i < n; i++)
        //cout << a[i] << " " << b[i] << endl;

    vi c[n];
    BIT ft(n+5);
    
    for(int i = 0; i < n; i++) {
        c[a[i]].pb(b[i]);
        ft.add(b[i], 1);
    }

    ll ans = 0;
    for(int i = n-1; i >= 0; i--) {
        for(int x : c[i]) 
            ans += ft.sum(0, x);

        for(int x : c[i])
            ft.add(x, -1);
    }
    
    cout << ans << "\n";
	
    return 0;
}


