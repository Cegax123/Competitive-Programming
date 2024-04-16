#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    int s[n];
    for(int i = 0; i < n; i++) s[p[i]] = i;

    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if(s[a] < s[b]) cout << a+1 << "\n";
        else cout << b+1 << "\n";
    }

    return 0;
}
