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
 
 const int maxn = 1e5+5;

 int n, a[maxn];

 bool comp(ll x) {
    vi cnt(n+1, 0);

    for(int i = 0; i < n; i++) {
        if(a[i]%x > n) return 0;
        cnt[a[i]%x]++;
    }

    for(int i = 1; i <= n; i++)
        if(cnt[i] == 0) return 0;

    return 1;
 }
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        cin >> n;
        
        ll sum = 0;
        int minA = 1e9;

        for(int i = 0; i < n; i++) {
            cin >> a[i];

            sum += (ll) a[i];
            sum -= (ll) i+1;

            if(a[i] > n) minA = min(minA, a[i]);
        }

        if(minA == 1e9) {
            if(comp(n+1)) cout << "YES " << n+1 << "\n";
            else cout << "NO\n";

            continue;
        }

        ll ans = 1e9;

        for(ll i = 1; i*i <= sum; i++) {
            if(sum%i == 0) {
                ll d1 = i, d2 = sum/i;

                if(d1 > n and d1 < minA) {
                    if(comp(d1)) ans = d1;
                }

                if(d2 > n and d2 < minA) {
                    if(comp(d2)) ans = d2;
                }
            }
        }

        if(ans == 1e9) cout << "NO\n";
        else cout << "YES " << ans << "\n";
    }
	
	
	return 0;
}