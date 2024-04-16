#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    long long L = 0, R = 0;

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        long long nL = L+a[i], nR = R+a[i];
        if(nL <= R+1) {
            R = nR;
            ans = R+1;
        }
        else {
            ans = R+1;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
