#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> s;

    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        s.push_back({l, 1});
        s.push_back({r, -1});
    }

    sort(s.begin(), s.end());

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < 2 * n; i++) {
        cnt += s[i].second;
        ans = max(ans, cnt);
    }

    cout << ans << "\n";

    return 0;
}
