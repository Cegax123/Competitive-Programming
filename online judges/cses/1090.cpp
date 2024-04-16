#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    int p[n];
    for(int i = 0; i < n; i++) cin >> p[i];

    sort(p, p+n);

    int l = 0, r = n-1;
    int cnt = 0;

    while(l <= r) {
        if(p[r] + p[l] <= x) {
            cnt++;
            r--; l++;
        }
        else {
            cnt++;
            r--;
        }
    }

    cout << cnt << "\n";

    return 0;
}
