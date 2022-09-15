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
    int k, a, b; cin >> k >> a >> b;
    string s; cin >> s;
    int n = s.size();

    const int maxn = 201;
    int dp[maxn][maxn];
    int p[maxn][maxn];

    memset(dp, 0, sizeof(dp));
    memset(p, -1, sizeof(p));

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            for(int l = a; l <= b; l++) {
                if(i < l) continue;
                if(dp[i-l][j-1]) {
                    dp[i][j] = 1;
                    p[i][j] = i-l;
                }
            }
        }
    }

    if(dp[n][k]) {
        int curr = n;
        int pos = k;

        vi v;

        while(curr != 0) {
            v.pb(curr-p[curr][pos]);
            curr = p[curr][pos];
            pos--;
        }

        reverse(all(v));

        int cnt = 0;
        int ind = 0;
        for(int i = 0; i < n; i++) {
            cout << s[i];
            cnt++;
            if(cnt == v[ind]) {
                ind++;
                cnt = 0;
                cout << "\n";
            }
        }
    }
    else {
        cout << "No solution\n";
    }
	
    return 0;
}


