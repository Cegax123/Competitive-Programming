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
        int n, p; cin >> n >> p;
        int tot = 2 * n + p;

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(tot) {
                    cout << i << " " << j << "\n";
                    tot--;
                }
            }
        }
    }

	
    return 0;
}


