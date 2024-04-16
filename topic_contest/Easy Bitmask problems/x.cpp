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
    int n, x; cin >> n >> x;
    vi cnt(1e7, 0);

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    ll ans = 0;
    vector<bool> banned(1e7, 0);

    for(int i = 1; i <= 1e5; i++) {
        if(cnt[i] == 0 or banned[i]) continue;

        int o = x ^ i;
        banned[o] = 1;

        if(i == o) ans += cnt[i] * 1ll * (cnt[i]-1) / 2;
        else ans += cnt[i] * 1ll * cnt[o];
    }

    cout << ans << "\n";
	
    return 0;
}


