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
    int n, k; cin >> n >> k;

    int a[n+2];

    a[0] = 0;
    a[n+1] = 0;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    int b[n+2];
    for(int i = 1; i <= n; i++) {
        b[i] = a[i+1]-a[i];
        //cout << b[i] << " ";
    }

    ll sum[n+1][k];

    memset(sum, 0, sizeof(sum));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            if(j == i % k) sum[i][j] = sum[i-1][j] + b[i];
            else sum[i][j] = sum[i-1][j];
        }
    }

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;

        bool cmp = 1;
        for(int j = 0; j < k; j++) {
            ll currsum = sum[r-1][j] - sum[l-1][j];
            if(j == (l-1) % k and j == r % k) {
                if(currsum + a[l] - a[r]) cmp = 0;
            }
            else if(j == (l-1) % k) {
                if(currsum + a[l]) cmp = 0;
            }
            else if(j == r % k) {
                if(currsum - a[r]) cmp = 0;
            }
            else {
                if(currsum) cmp = 0;
            }
        }

        cout << (cmp ? "Yes\n" : "No\n");
    }

    return 0;
}


