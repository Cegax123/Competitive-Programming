#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            sum += a;
        }
        long long l = 0, r = 1e8;

        while(l < r) {
            long long m = (l+r) >> 1;
            if(m * m >= sum) r = m;
            else l = m+1;
        }

        if(l * l == sum) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
