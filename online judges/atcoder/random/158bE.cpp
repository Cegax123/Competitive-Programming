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
	int n, p; cin >> n >> p;
    string s; cin >> s;

    if(p == 2 or p == 5) {
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            int d = s[i]-'0';
            if(d%p == 0)
                ans += i+1;
        }

        cout << ans << "\n";
        return 0;
    }
	
    int invb = ex(10, p-2, p);

    vi cnt(p, 0);
    cnt[0]++;

    int curr_val = 0;
    int curr_pinv = 1;
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        curr_val = (curr_val * 10 + s[i]-'0') % p;
        curr_pinv = (curr_pinv * invb) % p;

        int x = (curr_val * curr_pinv) % p;
        ans += cnt[x];
        
        cnt[x]++;
    }

    cout << ans << "\n";
	
	return 0;
}

