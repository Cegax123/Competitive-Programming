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

const ll INF = (ll) 1e18+1e15;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n; cin >> n;
    int k; cin >> k;

    ll p[k];

    for(int i = 0; i < k; i++) 
        cin >> p[i];

    vector<ll> prod(1 << k, 1);
    vi cnt(1 << k, 0);

    for(int i = 1; i < (1 << k); i++) {
        prod[i] = 1;
        cnt[i] = 0;

        for(int j = 0; j < k; j++) {
            if((i >> j)&1) {
                if(p[j] >= INF / prod[i] + 1)
                    prod[i] = INF;
                else
                    prod[i] *= p[j];

                cnt[i]++;
            }
        }
    }
    
    ll ans = 0;
    for(int i = 1; i < (1 << k); i++) {
        if(cnt[i]&1) ans += n/prod[i];
        else ans -= n/prod[i];
    }

    cout << ans << "\n";
	
	return 0;
}

