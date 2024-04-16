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
    int t; cin >> t;
    while(t--) {
        ll n, c, d; cin >> n >> c >> d;
        map<int, int> cnt;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }

        ll ans = (ll) n * c + d;

        ll curr = 0;
        ll deleted = 0;
        ll to_complete = 0;

        int last = 0;

        for(auto e : cnt) {
            int i = e.first;
            curr += cnt[i];

            deleted += cnt[i]-1;
            to_complete += i-last-1;

            last = i;


            ans = min(ans, (n-curr) * c + deleted * c + to_complete * d);
        }

        cout << ans << "\n";
    }

	
    return 0;
}


