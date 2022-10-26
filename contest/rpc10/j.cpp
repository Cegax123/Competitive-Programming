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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    const int maxn = 5e4+5;
    
    int sieve[maxn];
    memset(sieve, 0, sizeof(sieve));
    vi primes;

    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        primes.pb(i);

        for(int j = 2; i * j < maxn; j++) {
            sieve[i * j] = 1;
        }
    }

    set<int> s;

    auto get = [&](ll x) {
        for(int i = 1; i * i <= x; i++) {
            if(x % i == 0) {
                int d = x/i;
                s.insert(i);
                s.insert(d);
            }
        }
    };

    int t; cin >> t;
    while(t--) {
        s.clear();

        int w, l; cin >> w >> l;
        int g1 = __gcd(w-1,l-1), g2 = __gcd(w-2, l), g3 = __gcd(w, l-2);

        get(g1);
        get(g2);
        get(g3);

        if(w % 2 == 0 and l % 2 == 1) s.insert(2);
        if(l % 2 == 0 and w % 2 == 1) s.insert(2);

        cout << s.size() << " ";

        vi a;
        for(int x : s) a.pb(x);

        for(int i = 0; i < (int) a.size()-1; i++) cout << a[i] << " ";
        cout << a.back();

        cout << "\n";
    }

	
    return 0;
}


