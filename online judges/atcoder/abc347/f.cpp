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

const ll INF = (ll) 1e17;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m; cin >> n >> m;
    int a[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    ll s[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < m-1 or j < m-1) s[i][j] = -INF;
            else {
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
                if(i - m >= 0) s[i][j] -= s[i-m][j];
                if(j - m >= 0) s[i][j] -= s[i][j-m];
                if(i-m >= 0 and j-m >= 0) s[i][j] += s[i-m][j-m];
            }
        }
    }

    ll mx[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mx[i][j] = s[i][j];
            if(i) mx[i][j] = max(mx[i][j], mx[i-1][j]);
            if(j) mx[i][j] = max(mx[i][j], mx[i][j-1]);
        }
    }

    ll dp2[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
        }
    }
	
    return 0;
}


