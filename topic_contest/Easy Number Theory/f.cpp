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
int lp[maxn];
vi primes;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    lp[1] = 0;
    for(int i = 2; i < maxn; i++) {
        if(lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }

        for(int j = 0; j < (int) primes.size() and i * primes[j] < maxn and primes[j] <= lp[i]; j++) {
            lp[i * primes[j]] = primes[j];
        }
    }

    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n; cin >> n;

        int cnt = 0;
        for(int i = 1; 2 * i <= n; i++) {
            if(lp[i] == i and lp[n-i] == n-i) cnt++;
        }

        cout << "Case " << tc << ": ";
        cout << cnt << "\n";
    }
	
    return 0;
}


