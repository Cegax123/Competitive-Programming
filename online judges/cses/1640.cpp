#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    map<int, int> pos;

    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        if(pos[x-a] != 0) {
            cout << pos[x-a] << " " << i << "\n";
            return 0;
        }
        pos[a] = i;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
