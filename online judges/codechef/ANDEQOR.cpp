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

const int maxT = 21;
int cnt[1 << maxT];

int T, n;

ll solve(const string& s) {
    ll G[n];

    for(int i = 0; i < n; i++) {
        G[i] = (s[i] == '1' ? (1ll << (T-cnt[i])) : 0);
    }

    for(int i = 0; i < T; i++) {
        for(int mask = 0; mask < (1 << T); mask++) {
            if(mask&(1 << i))
                G[mask] += G[mask^(1 << i)];
        }
    }

    // for(int i = 0; i < n; i++)
    //     cout << s[i] << " " << G[i] << "\n";
    //
    // cout << "\n";

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ll num = (1ll << cnt[i]) * G[i];
            ll den = (1ll << T);

            ans += num/den;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i = 0; i < (1 << maxT); i++) {
        cnt[i] = 0;
        for(int j = 0; j < maxT; j++)
            if((i>>j)&1) cnt[i]++;
    }

    int t; cin >> t;
    while(t--) {
        cin >> n;

        for(int i = 24; i >= 0; i--)
            if((n >> i)&1) T = i;

        string s; cin >> s;

        ll ans = solve(s);

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }

        ans += solve(s);

        cout << ans << "\n";
    }

	
	return 0;
}

