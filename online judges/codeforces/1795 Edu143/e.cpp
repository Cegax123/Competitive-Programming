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

ll tri(ll x) {
    if(x < 0) return 0;
    return x * (x + 1) / 2;
}

ll sum(ll a, ll b) {
    if(b < a) return 0;
    return tri(b)-tri(a-1);
}

vector<ll> get(const vector<ll>& a) {
    int n = a.size();
    ll pL[n];
    pL[0] = a[0];

    for(int i = 1; i < n; i++) {
        pL[i] = pL[i-1] + a[i];
    }

    deque<int> dq;

    vector<ll> L(n, 0ll);

    dq.pb(0);

    for(int i = 1; i < n; i++) {
        while(!dq.empty()) {
            int x = dq.front();
            if(i-x >= a[i]) dq.pop_front();
            else break;
        }
        while(!dq.empty()) {
            int x = dq.back();
            if(a[i]-a[x] >= i-x) {
                break;
            }
            else dq.pop_back();
        }

        if(dq.empty()) {
            int j = max(0ll, i-a[i]+1);

            L[i] = pL[i-1] - sum(a[i]-i+j, a[i]-1);
            //if(i == 1) {
                //cout << pL[i-1] << endl;
                //cout << a[i]-j+1 << endl;
            //}
            dq.pb(i);
        }
        else {
            int j = dq.back();
            L[i] += L[j];
            L[i] += pL[i-1] - pL[j];
            L[i] -= sum(a[i]-(i-j)+1, a[i]-1);

            dq.pb(i);
        }
    }

    return L;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector<ll> L = get(a);

        reverse(all(a));

        vector<ll> R = get(a);

        reverse(all(R));
        reverse(all(a));

        ll ans = (ll) 1e18;
        for(int i = 0; i < n; i++) {
            ans = min(ans, a[i] + L[i] + R[i]);
            
        }

        cout << ans << "\n";
    }

	
    return 0;
}


