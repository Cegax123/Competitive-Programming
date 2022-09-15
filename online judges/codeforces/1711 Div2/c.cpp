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
        ll n, m, k; cin >> n >> m >> k;

        ll sum_r = 0, sum_c = 0;
        bool flagh = false, flagv = false;
        vector<ll> a(k);
        
        for(int i = 0 ; i < k; i++)
            cin >> a[i];

        sort(all(a));
        reverse(all(a));

        if(a[0] >= n * m) {
            cout << "Yes\n";
            continue;
        }

        for(int i = 0; i < k; i++) {
            ll rows = a[i] / m, cols = a[i] / n;

            if(rows > 1) {
                ll lft = n - sum_r;
                if(lft == 0) continue;
                if(lft == 1) {
                    if(flagh) 
                        sum_r = n;
                }
                else {
                    sum_r += min(lft, rows);
                    if(rows > 2) flagh = 1;
                }
            }

            if(cols > 1) {
                ll lft = m - sum_c;
                if(lft == 0) continue;
                if(lft == 1) {
                    if(flagv) 
                        sum_c = m;
                }
                else {
                    sum_c += min(lft, cols);
                    if(cols > 2) flagv = 1;
                }
            }
        }

        if(sum_r == n or sum_c == m) cout << "Yes\n";
        else cout << "No\n";
    }

	
    return 0;
}



