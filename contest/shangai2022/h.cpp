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
        int n, m, k; cin >> n >> m >> k;
        vi c(n);

        for(int i = 0; i < n; i++) cin >> c[i];

        int cnt = 0;
        for(int i = n-1; i > 0; i--) {
            if(c[i] == c[0]) cnt++;
            else break;
        }

        vi a;

        for(int i = n-1, k = 0; k < cnt; k++, i--) {
            a.pb(c.back());
            c.pop_back();
        }
        for(int x : c) a.pb(x);

        bool cmp = 0;
        int ans = 0;

        int ind = 0;
        while(ind < n) {
            int x = a[ind];
            int curr = ind;

            while(curr < n and x == a[curr]) {
                curr++;
            }

            int cnt = curr-ind;

            ans += (cnt+k-1) / k;
            if(cnt >= k) cmp = 1;

            ind = curr;
        }
        if(cmp) cout << ans << "\n";
        else cout << -1 << "\n";
    }

	
    return 0;
}


