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
    int a[3][n];

    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    ll L[n], R[n];

    L[0] = a[0][0];

    for(int i = 1; i < n; i++)
        L[i] = L[i-1] + a[0][i];

    R[n-1] = a[2][n-1];

    for(int i = n-2; i >= 0; i--) 
        R[i] = R[i+1] + a[2][i];

    ll v[n];

    for(int i = 0; i < n; i++) {
        v[i] = a[1][i] + L[i] + R[i];
        cout << v[i] << " ";
    }

	
    return 0;
}


