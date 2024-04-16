#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        cout << m << " ";

        if(m == 0) {
            cout << 0 << "\n";
            continue;
        }

        int l = 1, r = m;

        while(l < r) {
            int tm = (l+r) >> 1;
            int add = m / tm;
            if(m % tm == 0) add--;

            if(add + m <= n) r = tm;
            else l = tm+1;
        }

        cout << l << "\n";
    }


    return 0;
}
