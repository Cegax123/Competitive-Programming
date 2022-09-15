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
        int b[n][n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                char c; cin >> c;
                b[i][j] = c-'0';
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                char c; cin >> c;
                if(c == '1') b[i][j] ^= 1;
            }
        }

        for(int i = 0; i < n; i++) {
            if(b[i][0] == 1) {
                for(int j = 0; j < n; j++) {
                    b[i][j]^=1;
                }
            }
        }

        for(int j = 0; j < n; j++) {
            if(b[0][j] == 1) {
                for(int i = 0; i < n; i++) {
                    b[i][j]^=1;
                }
            }
        }

        bool cmp = 1;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(b[i][j]) cmp = 0;

        cout << (cmp ? "YES":"NO") << "\n";
    }
	
	return 0;
}

