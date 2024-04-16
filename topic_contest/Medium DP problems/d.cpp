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
    string s; cin >> s;
    const int E = 26;

    int mx[E][n+1];
    memset(mx, 0, sizeof(mx));

    for(char c = 'a'; c <= 'z'; c++) {
        vi dp(n+1, 0);
        for(int i = 0; i < n; i++) {
            vi ndp(n+1, 0);
            
            if(c == s[i]) {
                for(int j = 0; j <= n; j++) {
                    ndp[j] = dp[j] + 1;
                }
            }
            else {
                for(int j = 1; j <= n; j++) {
                    ndp[j] = dp[j-1] + 1;
                }
            }

            for(int j = 0; j <= n; j++)
                mx[c-'a'][j] = max(mx[c-'a'][j], ndp[j]);

            dp = ndp;
        }
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 1; j <= n; j++)
            mx[i][j] = max(mx[i][j], mx[i][j-1]);
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        char c; cin >> c;

        cout << mx[c-'a'][x] << "\n";
    }

	
    return 0;
}


