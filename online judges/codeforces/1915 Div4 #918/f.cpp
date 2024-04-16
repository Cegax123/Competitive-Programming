#include<bits/stdc++.h>
using namespace std;

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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n], b[n];
        vector<int> d;

        BIT bit(2 * n + 5);

        for(int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            d.push_back(a[i]);
            d.push_back(b[i]);
        }

        sort(d.begin(), d.end());
        d.resize(unique(d.begin(), d.end()) - d.begin());
        for (int i = 0; i < n; ++i) {
            a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
            b[i] = lower_bound(d.begin(), d.end(), b[i]) - d.begin();
        }

        vector<pair<int, int>> c;
        for(int i = 0; i < n; i++) c.push_back({a[i], b[i]});
        sort(c.begin(), c.end());

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += bit.sum(c[i].second+1, 2 * n);
            bit.add(c[i].second, 1);
        }

        cout << ans << "\n";
    }


    return 0;
}
