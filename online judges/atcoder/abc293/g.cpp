#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
const int B = 470;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        return make_pair(l / B, r) < make_pair(other.l / B, other.r);
    }
};

int main() {
    int n, q; cin >> n >> q;
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<Query> queries;
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        queries.pb({l, r, i});
    }

    sort(queries.begin(), queries.end());

    ll ans = 0;
    vector<int> cnt(2e5+5, 0);

    auto f = [&](ll x) {
        if(x <= 2) return 0ll;

        return x * (x-1) * (x-2) / 6ll;
    };

    auto remove = [&](int pos) {
        ans -= f(cnt[a[pos]]);
        cnt[a[pos]]--;
        ans += f(cnt[a[pos]]);
    };

    auto add = [&](int pos) {
        ans -= f(cnt[a[pos]]);
        cnt[a[pos]]++;
        ans += f(cnt[a[pos]]);
    };

    ll rans[q];

    int L = 0, R = -1;
    for(Query q : queries) {
        while(L < q.l) {
            remove(L);
            L++;
        }
        while(R > q.r) {
            remove(R);
            R--;
        }
        while(L > q.l) {
            L--;
            add(L);
        }
        while(R < q.r) {
            R++;
            add(R);
        }

        rans[q.idx] = ans;
    }

    for(int i = 0; i < q; i++)
        cout << rans[i] << " ";

    return 0;
}
