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

const int maxn = 2e7 + 5;
int sieve[maxn];

void init() {
    sieve[0] = sieve[1] = 0;

    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;

        for(int j = 2; i * j < maxn; j++) {
            if(sieve[i*j]) continue;
            sieve[i*j] = i;
        }
    }
}

int f[maxn];

int calc(int x) {
    int ans = 0;
    
    while(x != 1) {
        int d = sieve[x];

        while(x % d == 0) 
            x /= d;

        ans++;
    }

    return ans;
}



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();

    for(int i = 1; i < maxn; i++)
        f[i] = calc(i);


    int t; cin >> t;
    while(t--) {
        int c, d, x; cin >> c >> d >> x;
        ll ans = 0;

        for(int i = 1; i * i <= x; i++) {
            if(x % i) continue;
            int d1 = i, d2 = x/i;

            if((d1 + d) % c == 0) {
                int t = (d1 + d) / c;
                ans += (1ll << f[t]);
            }

            if(d1 != d2 and (d2 + d) % c == 0) {
                int t = (d2 + d) / c;
                ans += (1ll << f[t]);
            }
        }

        cout << ans << "\n";
    }
	
    return 0;
}


