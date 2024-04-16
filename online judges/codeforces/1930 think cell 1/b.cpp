#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int st = 1, end = n;
        for(int i = 1; i <= n; i++) {
            if(i&1) cout << st++ << " ";
            else cout << end-- << " ";
        }
        cout << "\n";
    }


    return 0;
}
