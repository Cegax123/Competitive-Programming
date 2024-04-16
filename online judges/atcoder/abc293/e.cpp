#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;

mat mult(mat A, mat B, ll m) {
    mat ans(2, vector<ll>(2, 0));

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                ans[i][j] += A[i][k] * B[k][j] % m;
            }
        }
    }

    return ans;
}

mat exp(mat A, ll x, ll m) {
    mat ans(2, vector<ll>(2, 0));
    ans[0][0] = 1;
    ans[1][1] = 1;

    while(x) {
        if(x&1ll) ans = mult(A, ans, m);

        x >>= 1;
        A = mult(A, A, m);
    }

    return ans;
}

int main() {
    ll a, m, x; cin >> a >> x >> m;

    mat A(2, vector<ll>(2, 0));
    A[0][0] = a % m;
    A[0][1] = 1 % m;
    A[1][1] = 1 % m;

    mat ans = exp(A, x-1, m);

    cout << (ans[0][0] + ans[0][1]) % m << "\n";
    
    return 0;
}
