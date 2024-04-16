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

        int xn = 0, xp = 0, yn = 0, yp = 0;

        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;

            if(x > 0) xp = 1;
            if(x < 0) xn = 1;
            if(y > 0) yp = 1;
            if(y < 0) yn = 1;
        }

        if(xn == 0 or xp == 0 or yn == 0 or yp == 0) cout << "YES\n";
        else cout << "NO\n";
    }

	
    return 0;
}


