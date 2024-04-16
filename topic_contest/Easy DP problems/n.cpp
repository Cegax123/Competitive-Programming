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
    for(int tt = 1; tt <= t; tt++) {
        int n, m, k; cin >> n >> m >> k;
        int p[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> p[i][j];

        int s[n][m];
        for(int i = 0; i < n; i++) {
            s[i][0] = p[i][0];

            for(int j = 1; j < m; j++) {
                s[i][j] = s[i][j-1] + p[i][j];
            }
        }

        int max_area = 0; ll min_cost = 0;

        for(int l = 0; l < m; l++) {
            for(int r = l; r < m; r++) {
                int b[n];
            
                for(int i = 0; i < n; i++)
                    b[i] = s[i][r] - (l == 0 ? 0 : s[i][l-1]);

                int R = 0;
                ll sum = 0;

                for(int i = 0; i < n; i++) {
                    if(R <= i) {
                        R = i + 1;
                        sum = b[i];
                    }
                    
                    while(R < n and sum + b[R] <= k) {
                        sum += b[R];
                        R++;
                    }

                    int h = r-l+1;
                    int d = R-i;

                    if(sum <= k) {
                        if(max_area < h * d) {
                            max_area = h * d;
                            min_cost = sum;
                        }
                        else if(max_area == h * d) {
                            min_cost = min(min_cost, sum);
                        }
                    }

                    sum -= b[i];
                }
            }
        }

        cout << "Case #" << tt << ": ";
        cout << max_area << " " << min_cost << "\n";
    }

	
    return 0;
}


