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
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            vii curr;
            curr.pb({a[i], 1});

            ll to_sum = 0;

            for(int j = i+1; j < n; j++) {
                ll len = 0;
                int rep = a[j];
                while(!curr.empty() and a[j] < curr.back().first) {
                    len += curr.back().second;
                    to_sum -= curr.back().second-1;
                    rep = max(rep, curr.back().first);
                    curr.pop_back();
                }

                to_sum += len;
                ans += to_sum;

                //cout << i << " " << j << " " << to_sum << endl;

                curr.pb({rep, len+1});
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


