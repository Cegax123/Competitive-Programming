#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    int a[h][w];

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    int n = h-1 + w-1;
    int ans = 0;

    for(int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if((i >> j)&1) cnt++;
        }
        if(cnt != w-1) continue;

        set<int> s;

        int posx = 0, posy = 0;
        s.insert(a[posx][posy]);
        for(int j = 0; j < n; j++) {
            if((i >> j)&1) posy++;
            else posx++;
            s.insert(a[posx][posy]);
        }

        if((int) s.size() == h+w-1) ans++;
    }

    cout << ans << "\n";

    return 0;
}
