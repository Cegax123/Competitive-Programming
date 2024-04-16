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
        int m; cin >> m;
        map<int, int> fi;
        vector<vi> a(m+1);

        for(int i = 1; i <= m; i++) {
            int n; cin >> n;
            a[i].resize(n);

            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
                fi[a[i][j]] = i;
            }
        }

        vi ans(m+1, -1);

        int poss = 0;

        for(int i = 1; i <= m; i++) {
            for(int x : a[i]) {
                if(fi[x] == i) {
                    ans[i] = x;
                    break;
                }
            }

            if(ans[i] == -1) poss = -1;
        }

        if(poss == -1) cout << -1 << "\n";
        else {
            for(int i = 1; i <= m; i++)
                cout << ans[i] << " ";
            cout << "\n";
        }
    }

	
    return 0;
}


