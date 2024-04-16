#include<bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),c.end()

int main() {
    int n; cin >> n;
    int M = (1 << n) - 1;
    int a[1 << n];
    for(int i = 0; i < (1 << n); i++) cin >> a[M ^ i];
    
    const int INF = 1e9;
    pair<pair<int, int>, pair<int, int>> ans[1 << n];

    ans[M].first = {a[M], M};
    ans[M].second = {-INF, -1};

    for(int i = M-1; i >= 0; i--) {
        vector<pair<int, int>> curr;
        curr.push_back({a[i], i});
        for(int j = 0; j < n; j++) {
            if(((i >> j)&1) == 0) {
                curr.push_back(ans[i^(1<<j)].first);
                curr.push_back(ans[i^(1<<j)].second);
            }
        }
        sort(all(curr));
        curr.erase(unique(all(curr)), curr.end());

        int k = curr.size();
        ans[i].first = curr[k-1];
        ans[i].second = curr[k-2];
    }

    int sum[1 << n];
    sum[M] = ans[M].first.first + ans[M].second.first;

    for(int i = M-1; i >= 0; i--) {
        sum[i] = ans[i].first.first + ans[i].second.first;
        int curr = 0;

        for(int j = n-1; j >= 0; j--) {
            if(((i >> j)&1) == 0) {
                int nxt = curr ^ (1 << j);
                sum[i] = max(sum[i], sum[nxt]);
            }
            else curr ^= (1 << j);
        }
        cout << sum[i] << "\n";
    }


    return 0;
}
