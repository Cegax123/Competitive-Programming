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
    int n, q; cin >> n >> q;

    int a[n+1], x[n+1];
    ll sum[n+1];

    sum[0] = x[0] = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        sum[i] = sum[i-1] + a[i];
        x[i] = x[i-1] ^ a[i];
    }

    map<int, int> last[2];

    const int INF = 1e9;
    int c[n+1][2];

    for(int i = n; i >= 1; i--) {
        if(last[0][x[i-1]] == 0) c[i][0] = INF;
        else c[i][0] = last[0][x[i-1]];

        if(last[1][x[i-1]] == 0) c[i][1] = INF;
        else c[i][1] = last[1][x[i-1]];

        if(a[i] == 0) c[i][i&1] = i;

        last[i&1][x[i]] = i;
    }

    auto xo = [&](int l, int r) {return x[r] ^ x[l-1];};
    auto pr = [&](int l, int r) {return sum[r] - sum[l-1];};


    while(q--) {
        int l, r; cin >> l >> r;

        if((r-l+1)&1) {
            if(xo(l, r) == 0) {
                if(pr(l, r) == 0) cout << 0 << "\n";
                else cout << 1 << "\n";
            }
            else cout << -1 << "\n";
        }
        else {
            if(xo(l, r) == 0 and c[l][l&1] <= r) {
                if(pr(l, r) == 0) cout << 0 << "\n";
                else if(a[l] == 0 and xo(l+1, r) == 0) cout << 1 << "\n";
                else if(a[r] == 0 and xo(l, r-1) == 0) cout << 1 << "\n";
                else cout << 2 << "\n";
            }
            else cout << -1 << "\n";
        }
    }
	
    return 0;
}


