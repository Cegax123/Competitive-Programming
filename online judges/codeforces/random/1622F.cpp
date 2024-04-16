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

ll r[maxn], s[maxn], f[maxn];

ll m(int x) {
    ll ans = 0;
    while(x != 1) {
        int d = sieve[x];
        int cnt = 0;

        while(x % d == 0) {
            x /= d;
            cnt++;
        }

        if(cnt&1) ans ^= r[d];
    }
    return ans;
}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
    return uniform_int_distribution<long long>(l,r)(rng);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();
    map<ll, int> sp;

    for(int i = 1; i < maxn; i++) {
        if(sieve[i] == i) {
            r[i] = random(1ll, (ll) 1e18);
        }
    }

    f[1] = r[1];

    sp[f[1]] = 1;
    int n; cin >> n;

    for(int i = 2; i < maxn; i++) {
        f[i] = f[i-1] ^ m(i);
        if(i <= n) sp[f[i]] = i;
    }
        
    s[1] = r[1];
    s[2] = r[1] ^ r[2];

    for(int i = 3; i < maxn; i++) {
        s[i] = s[i-2] ^ m(i);
    }

    vector<bool> banned(n+1, 0);

    ll need = s[n] ^ r[1];

    if(need) {
        int find = -1;

        for(int i = 2; i <= n; i++) {
            if(need == f[i]) {
                find = i;
            }
        }

        if(find > 0) {
            banned[find] = 1;
        }
        else {
            int x = -1, y = -1;
            for(int i = 2; i <= n; i++) {
                ll other = need ^ f[i];
                if(sp[other]) {
                    x = i;
                    y = sp[other];
                }
            }

            if(x > 0) {
                banned[x] = 1;
                banned[y] = 1;
            }
            else {
                if(n % 4 == 1) banned[n] = banned[n/2] = 1;
                else if(n % 4 == 2) banned[2] = banned[n/2] = 1;
                else if(n % 4 == 3) banned[2] = banned[n/2] = banned[n] = 1;
            }
        }
    }

    banned[1] = 0;

    int cnt = 0;

    for(int i = 1; i <= n; i++) cnt += !banned[i];

    cout << cnt << "\n";
    for(int i = 1; i <= n; i++) if(!banned[i]) cout << i << " ";
    cout << "\n";

    return 0;
}


