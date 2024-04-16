#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);

    long long curr = 0;
    for(int i = 0; i < n; i++)
        curr += a[i]-a[0];

    long long ans = curr;
    for(int i = 0; i+1 < n; i++) {
        int diff = a[i+1]-a[i];

        curr += (i+1) * 1ll * diff;
        curr -= (n-(i+1)) * 1ll * diff;

        ans = min(ans, curr);
    }

    cout << ans << "\n";

    return 0;
}
