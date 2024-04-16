#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        string rs = s;
        reverse(rs.begin(), rs.end());

        if(n&1) {
            cout << min({rs, rs + s, s + rs}) << "\n";
        }
        else {
            cout << min({s, rs+s, s+rs}) << "\n";
        }

    }
    


    return 0;
}
