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

const int N = 1, P = 2;
const int maxn = 105;
int dp[maxn][maxn][2];

int get(int even, int odd, int target) {
    if(even + odd == 1) {
        if(even == 1) {
            if(target == 0) return 1;
            return 0;
        }
        else {
            if(target == 1) return 1;
            return 0;
        }
    }

    if(dp[even][odd][target] != -1) return dp[even][odd][target];

    int sum = (odd&1);

    dp[even][odd][target] = 0;

    if(even >= 1) {
        if(!get(even-1, odd, 1-(sum^target)))
            dp[even][odd][target] = 1;
    }
    if(odd >= 1) {
        if(!get(even, odd-1, 1-(sum^target)))
            dp[even][odd][target] = 1;
    }

    return dp[even][odd][target];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            if(a&1) x++;
            else y++;
        }

        if(get(y, x, 0)) cout << "Alice\n";
        else cout << "Bob\n";
    }

	
    return 0;
}


