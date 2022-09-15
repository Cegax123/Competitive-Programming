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

const ll mod = 998244353;

ll mul(ll a, ll b, ll c) {return a*b%c;}

ll ex(ll a, ll b, ll c) {
	ll ans = 1;

	while(b > 0) {
		if(b&1) ans = (ans * a) % c;
		a = (a * a) % c;
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        int ind = 0;
        vi p;
        while(ind < n) {
            if(s[ind] == '0') {
                ind++;
                continue;
            }

            int cnt = 0;
            while(ind < n and s[ind] == '1') {
                cnt++;
                ind++;
            }

            p.pb(cnt);
        }

        if(p.size() == 0) {
            cout << "1\n";
            continue;
        }

        int cnt = 0;
        for(int i = p.size()-1; i > 0; i--) {
            p[i-1] += p[i]-p[i]%2; 
            p[i] %= 2;
            cnt += p[i];
        }

        int x = p[0] / 2;
        int lef = n-p[0]-cnt;

        ll ans = 1;

        for(int i = 1; i <= x; i++) {
            ans = mul(ans, ex(i, mod-2, mod), mod);
            ans = mul(ans, lef+i, mod);
        }

        cout << ans << "\n";
    }
	
	return 0;
}

