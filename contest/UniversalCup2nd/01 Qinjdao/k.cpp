#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        const int L = 30;
        vector<int> cnt(L, 0);
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            int p = 0;
            for(int j = 0; j < L; j++) {
                if((a >> j)&1) p = j;
            }

            cnt[p]++;
        }

        cout << *max_element(cnt.begin(), cnt.end()) << "\n";
    }


    return 0;
}
