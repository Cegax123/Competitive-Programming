#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        while(!a.empty() and a.back() == 0) a.pop_back();

        int ind = 0;

        for(int i = 0; i < (int) a.size(); i++) {
            if(a[i] == 1) {
                ind = i;
                break;
            }
        }

        int ans = 0;
        for(int i = ind; i < (int) a.size(); i++) {
            if(a[i] == 0) ans++;
        }
        cout << ans << "\n";
    }


    return 0;
}
