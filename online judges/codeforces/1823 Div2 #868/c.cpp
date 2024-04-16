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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        map<int, int> cnt;

        for(int i = 0; i < n; i++) {
            int a; cin >> a;

            while(a > 1) {
                int d = sieve[a];
                while(a % d == 0) {
                    a /= d;
                    cnt[d]++;
                }
            }
        }

        int ans = 0;
        int lft = 0;

        for(auto& e : cnt) {
            ans += e.second / 2;
            e.second = e.second % 2;
            lft += e.second;
        }
        
        ans += lft / 3;

        cout << ans << "\n";
    }

	
    return 0;
}


