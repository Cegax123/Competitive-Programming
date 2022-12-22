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

const int maxn = 1e7 + 5;
int sieve[maxn];

void gen() {
    sieve[1] = 1;

    for(int i = 2; i < maxn; i++) {
        if(sieve[i]) continue;
        sieve[i] = i;

        for(int j = 2; i * j < maxn; j++) {
            if(sieve[i * j]) continue;
            sieve[i * j] = i;
        }
    }
}

vi get_div(int x) {
    vi ans;
    while(x != 1) {
        int d = sieve[x];
        ans.pb(d);
        while(x % d == 0) x /= d;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();

    int t; cin >> t;
    while(t--) {
        int x, y; cin >> x >> y;

        if(__gcd(x, y) > 1) {
            cout << "0\n";
            continue;
        }

        int d = abs(x-y);
        if(d == 1) {
            cout << "-1\n";
            continue;
        }

        vi div = get_div(d);

        const int INF = 1e9;
        int ans = INF;

        for(int r : div) {
            ans = min(ans, (r - (x%r))%r);
        }

        cout << ans << "\n";

    }
    	
    return 0;
}


