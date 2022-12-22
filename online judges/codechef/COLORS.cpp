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
        int n, k; cin >> n >> k;

        const int INF = 1e9;
        int d = -1, x = INF;

        for(int i = k; i <= n; i++) {
            int r = n % i;
            int p = n/k;
            
            if(r < p) {
                int currx = i + (r+p-1)/p;

                if(currx < x) {
                    d = i;
                    x = currx;
                }               
            }
        }

        k = d;
        int r = n % k;
        int p = n/k;

        cout << x << "\n";
        
        for(int i = 0; i < p; i++) {
            for(int j = 1; j <= k; j++)
                cout << j << " ";
            if(r) {
                cout << k+1 << " ";
                r--;
            }
        }
        cout << "\n";
    }

	
    return 0;
}


