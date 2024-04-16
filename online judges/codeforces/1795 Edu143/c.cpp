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
        ll a[n+1], b[n+1];
        ll p[n+1];

        p[0] = 0;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            p[i] = b[i] + p[i-1];
        }

        ll sum[n+1];
        memset(sum, 0, sizeof(sum));

        ll cnt[n+1];
        memset(cnt, 0, sizeof(cnt));

        for(int i = 1; i <= n; i++) {
            a[i] = min(a[i], p[n]-p[i-1]);
            int l = i-1, r = n;

            while(l < r) {
                int m = (l+r+1) >> 1;
                if(a[i] > p[m]-p[i-1]) l=m;
                else r = m-1;
            }

            sum[l+1] += a[i]-(p[l]-p[i-1]);

            cnt[i]++;
            cnt[l+1]--;
        }

        for(int i = 1; i <= n; i++) {
            cnt[i] += cnt[i-1];
            //cout << cnt[i] << " ";
            cout << cnt[i] * b[i] + sum[i] << " ";
        }
        cout << "\n";
    }

	
    return 0;
}


