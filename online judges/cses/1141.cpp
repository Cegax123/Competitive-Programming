#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int k[n];
    for(int i = 0; i < n; i++) cin >> k[i];

    int ind = 0;
    set<int> s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        while(ind < n and s.count(k[ind]) == 0) {
            s.insert(k[ind]);
            ind++;
        }
        ans = max(ans, (int) s.size());
        s.erase(k[i]);
    }

    cout << ans << "\n";

    return 0;
}
