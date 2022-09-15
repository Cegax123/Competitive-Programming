#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int maxn = 1e6;

int sieve[maxn+1];

void gen() {
    for(int i = 2; i <= maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;

        for(int j = 2; i*j <= maxn; j++)
            sieve[i*j] = i;
    }
}

int val(int x) {
    int cnt = 0;
    while(x != 1) {
        int d = sieve[x];
        int p = 0;

        while(x%d == 0) {
            p++;
            x /= d;
        }

        if(p > 1) return -1;
        cnt++;
    }

    return cnt;
}

ll f(ll x) {
    return x*(x-1)/2;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();

    int n; cin >> n;

    vi x(maxn+1, 0);

    for(int i = 0; i < n; i++) {
        int m; cin >> m;
        x[m]++;
    }

    vi cnt(maxn+1, 0);

    for(int i = 1; i <= maxn; i++) {
        for(int j = i; j <= maxn; j += i) {
            cnt[i] += x[j];
        }
    }

    ll ans = 0;
    for(int i = 2; i <= maxn; i++) {
        int sign = val(i);
        if(sign == -1) continue;

        if(sign&1) ans += f(cnt[i]);
        else ans -= f(cnt[i]);
    }

    cout << f(n) - ans << "\n";


	return 0;
}

