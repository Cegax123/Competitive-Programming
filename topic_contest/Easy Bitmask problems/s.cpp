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
    const int maxn = 1e6 + 5;

    int f[maxn];
    f[0] = 0;

    for(int i = 1; i < maxn; i++) {
        f[i] = f[i-1] ^ i;
    }

    int n; cin >> n;

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        ans ^= a;

        int cnt = (n / i)&1;
        int lft = n % i;

        ans ^= (cnt * f[i-1]);
        ans ^= f[lft];
    }

    cout << ans << "\n";
	
    return 0;
}


