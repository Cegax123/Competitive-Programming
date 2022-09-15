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
    int a[n+1], b[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += i;
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += i;
    }

    map<int, int> cnta, cntb;

    for(int i = 1; i <= n; i++) {
        cnta[a[i]]++;
        cntb[b[i]]++;
    }

    bool cmp = 1;

    for(auto& it : cnta) 
        if(it.second != cntb[it.first]) cmp = 0;

    if(cmp == 0) {
        cout << "-1\n";
        return 0;
    }

    map<int, int> last, curr;
    int nxt[n+1];

    for(int i = n; i >= 1; i--) {
        if(last[b[i]]) 
            nxt[i] = last[b[i]];

        last[b[i]] = i;
        curr[b[i]] = i;
    }

    int c[n+1];
    BIT ft(n+1);
    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        c[i] = curr[a[i]]-1;
        
        ans += ft.sum(c[i] + 1, n);
        ft.add(c[i], 1);

        curr[a[i]] = nxt[curr[a[i]]];
    }

    cout << ans << "\n";
	
    return 0;
}


