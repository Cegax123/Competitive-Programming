#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int pos[n+1];

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        pos[x] = i;
    }

    int ans = 0;
    int last = n+1;

    for(int i = 1; i <= n; i++) {
        if(pos[i] < last) {
            ans++;
        }
        last = pos[i];
    }

    cout << ans << "\n";

    return 0;
}
