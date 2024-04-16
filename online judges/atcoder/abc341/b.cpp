#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int s[n], t[n];
    for(int i = 0; i < n-1; i++) cin >> s[i] >> t[i];

    for(int i = 0; i + 1 < n; i++) {
        a[i+1] += (a[i]/s[i]) * t[i];
    }

    cout << a[n-1] << "\n";

    return 0;
}
