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

int n;
const int mod = 1e9 + 7;

vector<vi> mult(vector<vi> a, vector<vi> b) {
    vector<vi> c(n, vi(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j] % mod;
                c[i][j] %= mod;
            }
        }
    }

    return c;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    int l; cin >> l;

    vector<vi> ans(n, vi(n, 0));
    for(int i = 0; i < n; i++) ans[i][i] = 1;

    vector<vi> a(n, vi(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < l; i++)
        ans = mult(ans, a);

    cout << ans[0][n-1] << "\n";

    //for(int i = 0; i < n; i++) {
        //for(int j = 0; j < n; j++) {
            //cout << ans[i][j] << " ";
        //}
        //cout << endl;
    //}
	


    return 0;
}


