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
        string s, t; cin >> s >> t;

        if(s[0] != t[0] or s[n-1] != t[n-1]) {
            cout << -1 << "\n";
            continue;
        }

        vi a, b;

        int ind = 0;
        while(ind < n) {
            char curr = s[ind];
            int cnt = 0;

            while(ind < n and s[ind] == curr) {
                ind++;
                cnt++;
            }

            a.pb(cnt);
        }

        ind = 0;
        while(ind < n) {
            char curr = t[ind];
            int cnt = 0;

            while(ind < n and t[ind] == curr) {
                ind++;
                cnt++;
            }

            b.pb(cnt);
        }

        if(a.size() != b.size()) {
            cout << -1 << "\n";
            continue;
        }

        int k = a.size();
        vi c(k);
        for(int i = 0; i < k; i++) 
            c[i] = b[i]-a[i];

        ll ans = 0;
        ll curr = 0;
        for(int i = 0; i < k; i++) {
            ans += abs(curr);
            curr += c[i];
        }

        cout << ans << "\n";
    }

	
    return 0;
}


