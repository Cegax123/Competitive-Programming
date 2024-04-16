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

const int maxn = 1e6 + 5;

int lp[maxn], phi[maxn];
vi primes;

vii d;
vi divisors;

void gen(int pos=0, int num=1) {
    if(pos == (int) d.size()) {
        divisors.pb(num);
        return;
    }

    int curr = 1;
    
    for(int i = 0; i <= d[pos].second; i++) {
        gen(pos+1, num * curr);
        curr *= d[pos].first;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    phi[1] = 0;
    for(int i = 2; i < maxn; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
            phi[i] = i-1;
        }
        for(int j = 0; j < (int) primes.size() and i * primes[j] < maxn and lp[i] >= primes[j]; j++) {
            lp[i * primes[j]] = primes[j];
            if(i % primes[j] == 0) phi[i * primes[j]] = phi[i] * primes[j];
            else phi[i * primes[j]] = phi[i] * phi[primes[j]];
        }
    }

    ll f[maxn];
    f[1] = 0;

    for(int i = 2; i < maxn; i++) {
        d.clear(); divisors.clear();

        int x = i;

        while(x != 1) {
            int dd = lp[x];
            int cnt = 0;

            while(x % dd == 0) {
                cnt++;
                x /= dd;
            }

            d.pb({dd, cnt});
        }

        gen();

        f[i] = f[i-1];

        for(int y : divisors) {
            f[i] += y * 1ll * phi[i / y];
        }
    }

    int n;
    while(cin >> n and n) {
        cout << f[n] << "\n";
    }
	
    return 0;
}


