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
	ll n, k; cin >> n >> k;
    ll a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;
    ll sum = 0, cnt = 0;
    vector<ll> cnt1(n, 0);

    for(int i = n-1; i >= 0; i--) {
        a[i] -= sum;

        if(i >= k) {
            if(a[i] > 0) {
                ll curr = (a[i] + k-1ll) / k;

                sum += curr * k;
                cnt += curr;

                ans += curr;
                cnt1[i-k+1] += curr;
            }
        }
        sum -= cnt;
        cnt -= cnt1[i];
    }

    ll add = 0;

    for(int i = 0; i < k; i++) {
        if(a[i] > 0) 
            add = max(add, (a[i] + i) / (i+1));
    }

    cout << ans + add << "\n";
	
    return 0;
}


