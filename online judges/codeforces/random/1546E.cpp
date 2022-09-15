#include <bits/stdc++.h>
#include <vector>
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
        vector<vi> a(2*n+5, vi(n+5));

        for(int i = 1; i <= 2*n; i++)
            for(int j = 1; j <= n; j++)
                cin >> a[i][j];

        int b[2*n+5][n+5];

        for(int i = 1; i <= 2*n; i++) {
            for(int j = 1; j <= n; j++) {
                b[i][a[i][j]] = j;
            }
        }

        for(int i = 1; i <= 2*n; i++) {
            for(int j = 1; j <= n; j++) 
                cout << b[i][j] << " ";
            cout << "\n";
        }
    }
	
	
	return 0;
}

