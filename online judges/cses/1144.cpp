#include <bits/stdc++.h>
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
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> d;

    int n, q; cin >> n >> q;
    int p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        d.push_back(p[i]);
    }

    vector<pair<int, pair<int, int>>> t;
    
    for(int i = 0; i < q; i++) {
        char op; cin >> op;
        int a, b; cin >> a >> b;
        if(op == '?') {
            t.push_back({2, {a, b}});
            d.push_back(a);
            d.push_back(b);
        }
        else {
            a--;
            t.push_back({1, {a, b}});
            d.push_back(b);
        }
    }

    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());

    auto norm = [&](int& x) {
        x = lower_bound(d.begin(), d.end(), x) - d.begin();
    };

    for(int i = 0; i < n; i++) norm(p[i]);

    for(int i = 0; i < q; i++) {
        if(t[i].first == 1) norm(t[i].second.second);
        else {
            norm(t[i].second.first);
            norm(t[i].second.second);
        }
    }

    BIT bit(1e6);

    for(int i = 0; i < n; i++)
        bit.add(p[i], 1);

    for(int i = 0; i < q; i++) {
        if(t[i].first == 1) {
            int k = t[i].second.first, x = t[i].second.second;
            bit.add(p[k], -1);
            p[k] = x;
            bit.add(x, 1);
        }
        else {
            int a = t[i].second.first, b = t[i].second.second;
            cout << bit.sum(a, b) << "\n";
        }
    }

    //a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
	
    return 0;
}


