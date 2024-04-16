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
    int n; cin >> n;
    int m; cin >> m;
    vector<ll> a(n);

    ll sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(all(a));

    const ll INF = (ll) 2e9;
    ll mx = INF;
    ll cnt = 0;

    while(m--) {
        ll q; cin >> q;
        if(q >= mx) {
            cout << sum << "\n";
            continue;
        }

        sum -= (mx - q) * cnt;
        mx = q;

        while(!a.empty() and a.back() > mx) {
            sum -= a.back();
            sum += mx;
            a.pop_back();
            cnt++;
        }

        cout << sum << "\n";
    }
	
    return 0;
}


