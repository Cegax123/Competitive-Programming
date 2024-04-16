#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<pair<int, int>> s;
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        s.insert({r, l});
        v.push_back({l, r});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int cnt = 0;
    while(!s.empty()) {
        pair<int, int> p = *s.begin(); s.erase(s.begin());
        cnt++;

        while(!v.empty() and v.back().first < p.first) {
            int l = v.back().first, r = v.back().second;
            if(s.count({r, l})) s.erase({r, l});
            v.pop_back();
        }
    }

    cout << cnt << "\n";

    return 0;
}
