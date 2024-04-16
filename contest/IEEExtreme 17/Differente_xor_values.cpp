#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(c) (c).begin(), (c).end()

const int L = 25;

struct XBasis {
    vector<int> b;
    vector<bool> used(L, 0);

    int process(int x) {
        for(int y : b) {
            int cnt = 0;
            int tmp = y;
            while(tmp >>= 1) cnt++;

            if((x >> cnt)&1) x ^= y;
        }
        return x;
    }

    void insert(int x) {
        x = process(x);
        if(x == 0) return;

        int cnt = 0;
        int tmp = x;
        while(tmp >>= 1) cnt++;

        for(int& y : b) {
            if((y >> cnt)&1) y ^= x;
        }

        used[cnt] = 1;

        b.pb(x);
        sort(all(b));
        reverse(all(b));
    }



    bool representable(int x) {
        x = process(x);
        if(x == 0) return true;
        return false;
    }
};

int po[L];
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int a[maxn], p[maxn];

int main() {
    po[0] = 1;

    for(int i = 1; i < L; i++) {
        po[i] = po[i-1] * 2ll % mod;
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        a[0] = 0;
        p[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            p[i] = a[i] ^ p[i-1];
        }

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            XBasis b;
            b.insert(a[i]);

            int d = b.b.size();

            int ind = i;
            //cout << i << ": ";

            while(ind <= n) {
                int l = ind, r = n;

                while(l < r) {
                    int m = (l+r+1) >> 1;
                    int x = p[m] ^ p[i-1];
                    
                    if(b.representable(x)) l = m;
                    else r = m-1;
                }

                ans += po[d] * 1ll * (l-ind+1) % mod;
                ans %= mod;

                d++;
                //cout << l << " ";
                ind = l+1;
                if(ind <= n) b.insert(a[ind]);
            }
            //cout << endl;
        }

        cout << ans << "\n";
    }


    return 0;
}
