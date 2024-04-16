#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        map<int, int> cnt;

        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a+i+1]++;
        }

        vector<int> ans;
        
        vector<pair<int, int>> p;
        for(auto e : cnt) p.push_back(e);
        reverse(p.begin(), p.end());

        for(auto e : p) {
            int curr = e.first;
            int num = e.second;

            for(int i = 0; i < num; i++) {
                if(ans.empty()) ans.push_back(curr);
                else {
                    if(ans.back() > curr) ans.push_back(curr);
                    else ans.push_back(ans.back()-1);
                }
            }
        }

        for(int x : ans) {
            cout << x << " ";
        }

        cout << "\n";
    }


    return 0;
}
