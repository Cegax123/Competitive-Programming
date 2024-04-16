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
        int n, m, d; cin >> n >> m >> d;
        int p[n+1];
        int pos[n+1];

        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        int q[m];

        for(int i = 0; i < m; i++) {
            int a; cin >> a;
            q[i] = pos[a];
        }

        bool cmp = 1;

        for(int i = 0; i+1 < m; i++) {
            if(q[i+1] < q[i] or q[i]+d < q[i+1]) cmp = 0;
        }

        if(cmp == 0) {
            cout << 0 << "\n";
            continue;
        }

        int ans = n+1;
        for(int i = 0; i+1 < m; i++) {
            int currd = q[i+1]-q[i];
            ans = min(ans, currd);

            if(n-q[i+1] + q[i] - 1 >= d+1-currd) ans = min(ans, d+1-currd);
        }

        cout << ans << "\n";
    }

	
    return 0;
}


