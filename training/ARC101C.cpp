#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, k; cin >> n >> k;
    int x[n];
    vector<int> neg, pos;

    for(int i = 0; i < n; i++) {
        cin >> x[i];
        if(x[i] < 0) neg.push_back(-x[i]);
        else pos.push_back(x[i]);
    }


    reverse(neg.begin(), neg.end());
    int ans = 2e9;

    for(int i = 0; i <= k; i++) {
        int j = k-i;

        if(i > (int) pos.size() or j > (int) neg.size()) continue;


        if(i == 0) ans = min(ans, neg[j-1]);
        else if(j == 0) ans = min(ans, pos[i-1]);
        else {
            ans = min({ans, 2 * pos[i-1] + neg[j-1], 2 * neg[j-1] + pos[i-1]});
        }
    }

    cout << ans << "\n";

    return 0;
}
