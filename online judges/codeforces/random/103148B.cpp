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

    vector<bool> isY(2*n + 1, false);
    vi X(n + 1, 0);
    int a[2*n + 1];

    for(int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        
        if(X[a[i]] == 0) 
            X[a[i]] = i;
        else 
            isY[i] = 1;
    }

    BIT ft(2 * n + 1), g(2 * n + 1);

    ll ans = n;

    for(int i = 1; i <= 2 * n; i++) {
        if(isY[i]) {
            if(X[a[i]]+1 <= i-1) {
                ans += ft.sum(X[a[i]] + 1, i-1);
                ans -= g.sum(X[a[i]] + 1, i-1);

                // cout << i << " " << X[a[i]] << " " << ft.sum(X[a[i]] + 1, i-1) << " " << g.sum(X[a[i]] + 1, i-1);
                // cout << endl;
            }
            ft.add(i, 1);
            g.add(X[a[i]], 1);
        }
    }

    cout << ans << "\n";
	
    return 0;
}


