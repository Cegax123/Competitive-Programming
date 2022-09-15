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

int nxt(int x) {
    if((x&(x-1)) == 0) return x;

    for(int i = 20; i >= 0; i--) 
        if((x >> i)&1) return (1 << (i+1));

    return 1;
}

int add(int x) {
    return nxt(x)-x;
}

int n; 
vi cnt;

int get_index(int v) {
    int l = 0, r = n;

    while(l < r) {
        int m = (l+r+1) >> 1;
        if(cnt[m] <= v) l = m;
        else r = m-1;
    }

    if(cnt[l] <= v) return l;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        cin >> n;

        cnt.clear(); cnt.resize(n+1, 0);

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }

        for(int i = 1; i <= n; i++) 
            cnt[i] += cnt[i-1];

        ll ans = add(n)+2;

        for(int i = 1; i <= n; i++) {
            if(cnt[i] == 0 or cnt[i] == n) continue;
            ans = min(ans, (ll) add(cnt[i])+add(n-cnt[i])+1);
        }
        
        for(int i = 0; i <= 20; i++) {
            int x = get_index(1 << i);
            
            for(int j = 0; j <= 20; j++) {
                int y = get_index(cnt[x] + (1 << j));

                if(cnt[x] == 0 or cnt[x] == cnt[y] or cnt[y] == n) continue;
                ans = min(ans, (ll) add(cnt[x])+add(cnt[y]-cnt[x])+add(n-cnt[y]));
            }
        }

        cout << ans << "\n";
    }
	
	return 0;
}

