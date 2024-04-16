#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        set<pair<long long, long long>> s;
        s.insert({0, 0});

        long long x = 0, y = 0;
        int n; cin >> n;
        bool cmp = false;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            if(i&1) x += a;
            else y += a;

            long long d = min(x, y);
            x -= d;
            y -= d;

            if(s.count({x, y})) cmp = true;
            s.insert({x, y});
        }

        cout << (cmp ? "YES\n" : "NO\n");
    }


    return 0;
}
