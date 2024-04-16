#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<bool> called(n, 0);

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    
        if(!called[i]) {
            called[a[i]] = 1;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += !called[i];
    }

    cout << cnt << "\n";
    for(int i = 0; i < n; i++) {
        if(!called[i]) cout << i+1 << " ";
    }

    return 0;
}
