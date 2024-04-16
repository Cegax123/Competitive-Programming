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
    int n, c; cin >> n >> c;

    vi dp(c+1, -1);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        int v, w; cin >> v >> w;

        for(int j = 0; j <= c; j++) {
            if(j + w <= c) dp[j+w] = max(dp[j+w], dp[j] + v);
        }
    }

    cout << *max_element(all(dp)) << "\n";
	
    return 0;
}


