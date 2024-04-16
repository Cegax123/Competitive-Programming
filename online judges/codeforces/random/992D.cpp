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

const ll INF = (ll) 1e18;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> b;

    int ind = 0;
    while(ind < n) {
        if((int) b.size() % 2 == 0) {
            int cnt = 0;
            while(ind < n and a[ind] == 1) {
                ind++;
                cnt++;
            }
            b.pb(cnt);
        }
        else {
            b.pb(a[ind++]);
        }
    }

    if((int) b.size() % 2 == 0) b.pb(0);

    n = b.size();

    ll pre[n];
    pre[0] = b[0];

    for(int i = 1; i < n; i++) pre[i] = pre[i-1] + b[i];

    ll ans = 0;
    if(k == 1) {
        for(int i = 0; i < n; i += 2) ans += b[i];
    }

    for(int i = 1; i < n; i += 2) {
        ll prod = 1;
        int j = i;

        while(j < n) {
            if(prod > INF / b[j]) break;
            prod *= b[j];

            if(prod % k) {
                j += 2;
                continue;
            }

            ll target = prod / k;
            ll sum = pre[j] - pre[i-1];

            ll need = target - sum;

            if(need < 0) {
                j += 2;
                continue;
            }

            ll x = b[i-1], y = b[j+1];

            //cout << x << " " << y << " " << need << endl;

            if(x + y < need) {
                j += 2;
                continue;
            }

            ll min_x = max(0ll, need - y);
            ll max_x = min(x, need);

            if(min_x <= max_x) ans += max_x - min_x + 1;

            j += 2;
        }
    }

    cout << ans << "\n";
	
    return 0;
}


