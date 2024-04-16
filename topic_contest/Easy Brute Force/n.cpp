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
    int n; cin >> n;

    int a[2 * n+1];
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[n+i] = a[i];
        a[i] += a[i-1];
    }

    for(int i = n+1; i <= 2 * n; i++)
        a[i] += a[i-1];

    int ans = 360;

    for(int i = 0; i <= 2 * n; i++) {
        for(int j = i; j <= 2 * n; j++) {

            if(j-i <= n) ans = min(ans, abs(360 - 2 * abs(a[j]-a[i])));
        }
    }

    cout << ans << "\n";

    return 0;
}


