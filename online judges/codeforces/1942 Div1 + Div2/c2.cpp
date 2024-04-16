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
        int n, x, y; cin >> n >> x >> y;
        int a[x];

        for(int i = 0; i < x; i++) {
            cin >> a[i];
            a[i]--;
        }

        sort(a, a+x);

        int ans = x-2;
        vector<int> odd, even;

        for(int i = 0; i < x; i++) {
            int len;
            if(i+1 < x) len = a[i+1] - a[i];
            else len = a[0] + n - a[i];
            len--;

            if(len != 1 and len&1) odd.push_back(len);
            else if(len != 0 and len%2 == 0) even.push_back(len);
            
            int nxt = (a[i] + 2) % n;
            if(nxt == a[(i+1)%x]) ans++;
        }

        sort(all(odd));
        sort(all(even));

        for(int x : odd) {
            int mx = x / 2;
            mx = min(mx, y);

            int added = mx * 2;
            if(mx == x / 2) added++;

            ans += added;
            y -= mx;
        }

        for(int x : even) {
            int mx = x/ 2;
            mx = min(mx, y);

            ans += 2 * mx;
            y -= mx;
        }

        cout << ans << "\n";
    }

	
    return 0;
}



