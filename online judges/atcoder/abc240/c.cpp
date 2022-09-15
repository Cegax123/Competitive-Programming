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
	int n, x; cin >> n >> x;

    int a[n], b[n];

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    vi dp(x+1, 0);

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        vi ndp(x+1, 0);

        for(int j = 0; j <= x; j++) {
            if(j >= a[i] and dp[j-a[i]]) ndp[j] = 1;
            if(j >= b[i] and dp[j-b[i]]) ndp[j] = 1;
        }

        dp = ndp;
    }
	
    cout << (dp[x] ? "Yes\n" : "No\n");
	
	return 0;
}

