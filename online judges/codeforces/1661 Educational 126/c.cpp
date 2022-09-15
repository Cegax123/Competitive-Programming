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

int n;
vi a;

ll solve(ll add) {
    ll cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < n; i++) {
        int x = a[n-1]+add-a[i];
        cnt1 += (x&1);
        cnt2 += x >> 1;
    }

    ll l = 0, r = (ll) 1e16;

    while(l < r) {
        ll m = (l+r) >> 1;
        bool cmp = 0;

        ll even = m >> 1;
        ll odd = m-even;

        if(even >= cnt2 and odd >= cnt1)
            cmp = 1;

        if(even < cnt2) {
            ll need = cnt2-even;
            if(cnt1 + 2 * need <= odd)
                cmp = 1;
        }

        if(cmp) r = m;
        else l = m+1;
    }

    return l;
}
 
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        a.clear(); a.resize(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(all(a));

        cout << min(solve(0), solve(1)) << "\n";

    }
	
	return 0;
}

