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
    vi pos[n+1];

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x].pb(i);
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        ans += (n-i+1) * 1ll * (i/2);
    }

    for(int i = 1; i <= n; i++) {
        if((int) pos[i].size() <= 1) continue;

        int k = pos[i].size();

        ll pref[k];
        pref[0] = pos[i][0] + 1;

        for(int j = 1; j < k; j++)
            pref[j] = pref[j-1] + pos[i][j] + 1;

        for(int j = 1; j < (int) pos[i].size(); j++) {
            int l = 0, r = j-1;

            while(l < r) {
                int m = (l+r+1) >> 1;
                if(pos[i][m] <= n-1-pos[i][j]) l = m;
                else r = m-1;
            }

            if(pos[i][l] <= n-1-pos[i][j]) ans -= pref[l];
            else ans -= (n-pos[i][j]);
            ans -= (n-pos[i][j]) * 1ll * (j-l-1);
        }
    }

    cout << ans << "\n";
	
    return 0;
}


