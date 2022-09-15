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

        vi a, b;

        for(int i = 0; i < n-1; i++) {
            int x = s[i]-'0', y = s[i+1]-'0';
            if(x ^ y) a.pb(i);

            x = t[i]-'0', y = t[i+1]-'0';
            if(x ^ y) b.pb(i);
        }

        if(a.size() != b.size() or s[0] != t[0]) 
            cout << "-1\n";
        else {
            ll ans = 0;
            for(int i = 0; i < (int) a.size(); i++)
                ans += abs(a[i]-b[i]);

            cout << ans << "\n";
        }
    }

	
    return 0;
}


