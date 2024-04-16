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
    int x[5 * n];

    for(int i = 0; i < 5 * n; i++) cin >> x[i];

    sort(x, x + 5 * n);

    double ans = 0;

    for(int i = n; i < 4 * n; i++) 
        ans += x[i];

    ans /= (double) 3 * n;

    cout << setprecision(9) << ans << "\n";
	
    return 0;
}


