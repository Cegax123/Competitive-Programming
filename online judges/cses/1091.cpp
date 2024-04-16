#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    set<pair<int, int>> s;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        s.insert({a, -i-1});
    }

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        s.insert({x, 0});

        auto it = s.find({x, 0});
        if(it == s.begin()) cout << -1 << "\n";
        else {
            it = prev(it);
            cout << it->first << "\n";
            s.erase(it);
        }
        s.erase({x, 0});
    }

    return 0;
}
