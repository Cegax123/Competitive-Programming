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

const int mod = 1e9 + 7;

vector<vi> mul(const vector<vi>& a, const vector<vi>& b) {
    int n = a.size(), m = a[0].size(), k = b[0].size();

    vector<vi> c(n, vi(k, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            for(int t = 0; t < m; t++) {
                int add = (a[i][t] * 1ll * b[t][j]) % mod;
                c[i][j] = (c[i][j] + add) % mod;
            }
        }
    }

    return c;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    if(n == 1) {
        cout << 2 << "\n";
        return 0;
    }

    if(n == 2) {
        cout << 24 << "\n";
        return 0;
    }

    vector<vi> mat(5, vi(5));

    mat[0][0] = 2;
    mat[0][1] = 4;
    mat[0][2] = 2;
    mat[0][3] = 0;
    mat[0][4] = 0;

    mat[1][0] = 1;
    mat[1][1] = 0;
    mat[1][2] = 0;
    mat[1][3] = 0;
    mat[1][4] = 0;

    mat[2][0] = 0;
    mat[2][1] = 0;
    mat[2][2] = 2;
    mat[2][3] = 0;
    mat[2][4] = 0;

    mat[3][0] = 0;
    mat[3][1] = 32;
    mat[3][2] = 8;
    mat[3][3] = 2;
    mat[3][4] = 0;

    mat[4][0] = 0;
    mat[4][1] = 0;
    mat[4][2] = 0;
    mat[4][3] = 1;
    mat[4][4] = 0;

    vector<vi> b(5, vi(5, 0));

    for(int i = 0; i < 5; i++)
        b[i][i] = 1;

    vector<vi> a(5, vi(1));

    a[0][0] = 6;
    a[1][0] = 1;
    a[2][0] = 2;
    a[3][0] = 24;
    a[4][0] = 2;

    n -= 2;

    while(n) {
        if(n&1) b = mul(mat, b);
        mat = mul(mat, mat);
        n >>= 1;
    }

    a = mul(b, a);

    cout << a[3][0] << "\n";

    return 0;
}


