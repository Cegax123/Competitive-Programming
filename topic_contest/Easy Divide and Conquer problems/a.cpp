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

const int maxn = 1e6 + 5;
int a[maxn];
int n;

ll solve(int l, int r) {
    if(l == r) {
        return a[r]-a[r];
    }

    int m = (l+r) >> 1;

    ll ans = 0;

    ans += solve(l, m);
    ans += solve(m+1, r);

    int target = 0;
    int curr = 0;
    int ind = m;

    for(int i = m+1; i <= r; i++) {
        target = max(target, a[i]);

        while(ind >= l and max(curr, a[ind]) <= target) curr = max(curr, a[ind--]);

        ans += target * 1ll * (m-ind);
    }

    target = 0;
    curr = 0;
    ind = m+1;

    for(int i = m; i >= l; i--) {
        target = max(target, a[i]);

        while(ind <= r and max(curr, a[ind]) < target) curr = max(curr, a[ind++]);

        ans += target * 1ll * (ind-(m+1));
    }

    target = 1e6 + 5;
    curr = 1e6 + 5;
    ind = m;

    for(int i = m+1; i <= r; i++) {
        target = min(target, a[i]);

        while(ind >= l and min(curr, a[ind]) >= target) curr = min(curr, a[ind--]);

        ans -= target * 1ll * (m-ind);
    }

    target = 1e6 + 5;
    curr = 1e6 + 5;
    ind = m+1;

    for(int i = m; i >= l; i--) {
        target = min(target, a[i]);

        while(ind <= r and min(curr, a[ind]) > target) curr = min(curr, a[ind++]);

        ans -= target * 1ll * (ind-(m+1));
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(0, n-1) << "\n";

    //ll ans = 0;
    //for(int i = 0; i < n; i++) {
        //for(int len = 1; i+len-1 < n; len++) {
            //ans += *max_element(a, a+len);
            //ans -= *min_element(a, a+len);
        //}
    //}

    //cout << ans << endl;
	
    return 0;
}


