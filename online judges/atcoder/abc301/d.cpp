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

const int L = 60;
string s;
ll n;
ll ans = -1;
ll curr = 0;

void solve(int pos = 0, bool f = 0) {
    if(pos == L) {
        ans = max(ans, curr);
        return;
    }

    if(f == 1) {
        ll dig = 1;
        if(s[pos] != '?') dig = s[pos]-'0';

        curr += (dig << (L-1-pos));
        solve(pos+1, f);
        curr -= (dig << (L-1-pos));
    }
    else {
        ll lmt = ((n >> (L-1-pos))&1ll);

        if(s[pos] != '?') {
            ll dig = s[pos]-'0';
            if(dig <= lmt) {
                curr += (dig << (L-1-pos));
                bool nf = f;
                if(dig < lmt) nf = 1;
                solve(pos+1, nf);
                curr -= (dig << (L-1-pos));
            }
        }
        else {
            for(ll i = 0; i <= lmt; i++) {
                curr += (i << (L-1-pos));
                bool nf = f;
                if(i < lmt) nf = 1;
                solve(pos+1, nf);
                curr -= (i << (L-1-pos));
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s >> n;

    while((int) s.size() < L) s = "0" + s;

    solve();

    cout << ans << "\n";

    return 0;
}


