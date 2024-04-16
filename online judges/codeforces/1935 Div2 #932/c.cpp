#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, L; cin >> n >> L;

        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }

        sort(a.begin(), a.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
                });

        int global = 0;
        
        for(int i = 0; i < n; i++) {
            ll curr = 0;
            ll diff = a[i].second;
            multiset<int> lft, rgt;

            for(int j = i; j < n; j++) {
                lft.insert(a[j].first);

                curr += a[j].first;
                curr += a[j].second - diff;

                while(curr > L and !lft.empty()) {
                    int x = *lft.rbegin();
                    curr -= x;
                    lft.erase(lft.find(x));
                    rgt.insert(x);
                }

                while(curr <= L and !rgt.empty()) {
                    int x = *rgt.begin();
                    if(curr + x <= L) {
                        curr += x;
                        rgt.erase(rgt.find(x));
                        lft.insert(x);
                    }
                    else break;
                }

                if(curr <= L) global = max(global, (int) lft.size());

                diff = a[j].second;
            }
        }

        cout << global << "\n";
    }


    return 0;
}
