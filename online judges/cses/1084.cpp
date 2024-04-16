#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ind = 0;
    int ans = 0;

    for(int i = 0; i < m; i++) {
        while(ind < n and a[ind] + k < b[i]) {
            ind++;
        }

        if(ind < n and a[ind] - k <= b[i] and a[ind] + k >= b[i]) {
            ind++;
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
