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

const int mod = 32768;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int dp[mod];
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    queue<int> q;
    q.push(0);

    while(not q.empty()) {
        int v = q.front(); q.pop();

        int m = v-1; if(m < 0) m += mod;
        int d = (v%2 == 0 ? v/2 : 0);
        int d2 = (v%2 == 0 ? (v+mod)/2 : 0);

        if(dp[m] == -1) {
            dp[m] = dp[v]+1;
            q.push(m);
        }
        if(dp[d] == -1) {
            dp[d] = dp[v]+1;
            q.push(d);
        }
        if(d2 < mod and dp[d2] == -1) {
            dp[d2] = dp[v]+1;
            q.push(d2);
        }
    }
	
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cout << dp[a] << " ";
    }
	
	
	return 0;
}

