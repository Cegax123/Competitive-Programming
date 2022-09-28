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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n+1];
        vi oddnum, evennum;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(i % 2) oddnum.pb(a[i]);
            else evennum.pb(a[i]);
        }

        const int INF = 1e6;
        oddnum.pb(INF);
        evennum.pb(INF+1);

        int ans = INF;

        for(int x : evennum) {
            for(int y : oddnum) {
                if(x == y) continue;
                
                int num[2] = {x, y};
                int dp[n+1][3];

                for(int i = 0; i <= n; i++)
                    for(int j = 0; j < 3; j++)
                        dp[i][j] = INF;

                if(a[1] == num[1]) {
                    dp[1][0] = 0;
                    dp[1][2] = 2;
                }
                else if(a[1] == num[0]) {
                    dp[1][1] = 1;
                    dp[1][2] = 2;
                }
                else {
                    dp[1][1] = 1;
                }

                for(int i = 2; i <= n; i++) {
                    int curr = i % 2;
                    int other = 1-curr;

                    if(a[i] == num[curr]) {
                        dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
                        dp[i][2] = dp[i][0] + 2;
                    }
                    else if(a[i] == num[other]) {
                        if(a[i-1] == num[curr]) {
                            dp[i][1] = dp[i-1][2] + 1;
                            dp[i][2] = min({dp[i-1][1] + 2, dp[i-1][2] + 2});
                        }
                        else {
                            dp[i][1] = dp[i-1][1] + 1;
                            dp[i][2] = dp[i-1][1] + 2;
                        }
                    }
                    else {
                        dp[i][1] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
                    }
                }

                //if(x == 5 and y == 2) {
                    //for(int i = 1; i <= n; i++) {
                        //for(int j = 0; j < 3; j++)
                            //cout << dp[i][j] << " ";
                        //cout << endl;
                    //}
                //}

                int local = min({dp[n][0], dp[n][1], dp[n][2]});

                //cout << num[1] << " " << num[0] << " " << local << endl;

                //cout << x << " " << y << " " << local << endl;

                ans = min(ans, local);
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


