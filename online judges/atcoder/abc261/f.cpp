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
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

ll find_inversions(const vii& a) {
    int n = a.size();
    BIT ft(n);
    ll ans = 0;

    int ind = 0;
    while(ind < n) {
        int currv = a[ind].first;
        int r = ind;

        while(r < n and a[r].first == currv)
            r++;

        for(int i = ind; i < r; i++) 
            ans += ft.sum(a[i].second, n-1);

        for(int i = ind; i < r; i++)
            ft.add(a[i].second, 1);

        ind = r;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    map<int, int> id;

    int c[n], x[n];

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) cin >> x[i];

    vii total;
    vector<vii> col;

    int ind = 1;

    for(int i = 0; i < n; i++) {
        total.pb({x[i], i});

        if(id[c[i]] == 0) {
            id[c[i]] = ind++;
            col.pb(vii());
        }

        int currid = id[c[i]]-1;

        col[currid].pb({x[i], col[currid].size()});
    }

    sort(all(total));
    for(int i = 0; i < (int) col.size(); i++)
        sort(all(col[i]));

    auto print = [] (const vii& a) {
        for(int i = 0; i < (int) a.size(); i++)
            cout << a[i].first << " " << a[i].second << "\n";
    };

    ll ans = find_inversions(total);

    for(int i = 0; i < (int) col.size(); i++)
        ans -= find_inversions(col[i]);

    cout << ans << "\n";

    return 0;
}


