#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> t;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        if(t.empty()) {
            t.push_back(k);
            continue;
        }
        int l = 0, r = t.size()-1;

        while(l < r) {
            int m = (l+r) >> 1;
            if(t[m] > k) r = m;
            else l = m+1;
        }

        if(t[l] > k) t[l] = k;
        else t.push_back(k);
    }

    cout << t.size() << "\n";

    return 0;
}
