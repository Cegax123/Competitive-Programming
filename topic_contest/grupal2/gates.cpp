#include<bits/stdc++.h>
using namespace std;

int main() {
    int l; cin >> l;
    int n; cin >> n;
    int t[n];
    for(int i = 0; i < n; i++) cin >> t[i];
    vector<int> d;

    for(int i = 1; i < n; i++) {
        d.push_back(t[i]-t[i-1]);
    }

    int g; cin >> g;
    int p[g];

    for(int i = 0; i < g; i++) {
        cin >> p[i];
        d.push_back(1);
    }

    long long ans = 0;
    for(int i = 0; i < n-1; i++) {
        ans += d[n-1+g-1-i];
    }
    cout << ans << "\n";

    return 0;
}
