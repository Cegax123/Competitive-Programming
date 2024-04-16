#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, t; cin >> n >> t;
    vector<long long> a(n, 0);

    map<long long, int> cnt;
    int ans = 1;

    cnt[0] = n;

    for(int i = 0; i < t; i++) {
        int p, b; cin >> p >> b;
        p--;

        cnt[a[p]]--;
        if(cnt[a[p]] == 0) ans--;

        a[p] += b;
        if(cnt[a[p]] == 0) ans++;

        cnt[a[p]]++;

        cout << ans << "\n";
    }


    return 0;
}
