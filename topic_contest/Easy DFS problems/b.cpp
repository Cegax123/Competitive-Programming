#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int cnt[k];
    memset(cnt, 0, sizeof(cnt));

    for(int i = 1; i <= n; i++)
        cnt[i%k]++;

    int ans = cnt[0] > 0;

    for(int i = 1; i <= k/2; i++) {
        if(2 * i == k) {
            ans += cnt[i] > 0;
            continue;
        }

        if(cnt[i] == 0) continue;
        if(cnt[k-i] == 0) ans  += cnt[i];
        else ans += 1;
    }

    cout << ans << "\n";

    return 0;
}
