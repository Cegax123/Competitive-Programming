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
    ll L; int n1, n2; cin >> L >> n1 >> n2;
    pair<int, pair<ll, ll>> a[n1], b[n2];

    for(int i = 0; i < n1; i++) {
        int v; ll l; cin >> v >> l;

        a[i].first = v;
        a[i].second.first = (i == 0 ? 0 : a[i-1].second.second+1);
        a[i].second.second = a[i].second.first + l - 1;
    }

    for(int i = 0; i < n2; i++) {
        int v; ll l; cin >> v >> l;

        b[i].first = v;
        b[i].second.first = (i == 0 ? 0 : b[i-1].second.second+1);
        b[i].second.second = b[i].second.first + l - 1;
    }

    int inda = 0, indb = 0;
    ll ans = 0;

    while(inda < n1 and indb < n2) {
        if(a[inda].first == b[indb].first) {
            ll R = min(a[inda].second.second, b[indb].second.second);
            ll L = max(a[inda].second.first, b[indb].second.first);

            if(L <= R) ans += R-L+1;
        }

        if(inda + 1 < n1 and a[inda+1].second.first <= b[indb].second.second) inda++;
        else indb++;
    }

    cout << ans << "\n";
	
    return 0;
}


