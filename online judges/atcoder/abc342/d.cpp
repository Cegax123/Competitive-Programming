#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int sieve[maxn];

void gen() {
    sieve[1] = 1;

    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;

        for(int j = 2; i * j < maxn; j++) {
            if(sieve[i * j] == 0) sieve[i * j] = i;
        }
    }
}

int main() {
    gen();
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) continue;
        int res = 1;

        while(a[i] != 1) {
            int d = sieve[a[i]];
            int cnt = 0;
            while(a[i] % d == 0) {
                cnt++;
                a[i] /= d;
            }

            if(cnt&1) res *= d;
        }

        a[i] = res;
    }

    vector<int> cnt(maxn, 0);

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) ans += i;
        else {
            ans += cnt[0];
            ans += cnt[a[i]];
        }
        cnt[a[i]]++;
    }

    cout << ans << "\n";

    return 0;
}
