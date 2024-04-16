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

const int maxn = 4e7;
int sieve[maxn];

void gen() {
    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;
        for(int j = 2; i * j < maxn; j++) {
            if(sieve[i * j]) continue;
            sieve[i * j] = i;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();

    auto sq = [&](int x) {
        int l = 1, r = 1e6;

        while(l < r) {
            int m = (l+r) >> 1;
            if(m * 1ll * m >= x) r = m;
            else l = m+1;
        }

        if(l * 1ll * l == x) return l;
        return -1;
    };

    int t; cin >> t;
    while(t--) {
        int p, q; cin >> p >> q;
        if(p < 2 * q) {
            cout << "0 0\n";
            continue;
        }

        int s = p + 2 * q, r = p - 2 * q;

        if(r == 0) {
            s = sq(s);
            if(s == -1 or s % 2) {
                cout << "0 0\n";
                continue;
            }
            s >>= 1;
            
            cout << s << " " << s << "\n";
            continue;
        }

        int g = __gcd(s, r);
        s /= g; r /= g;

        s = sq(s), r = sq(r);

        if(s == -1 or r == -1) {
            cout << "0 0\n";
            continue;
        }

        s *= 2; r *= 2;

        int a = (s + r) >> 1, b = (s - r) >> 1;

        cout << a << " " << b << "\n";
    }

	
    return 0;
}


