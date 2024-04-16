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
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool cmp = 1;
        if(a[0] >= 2) cmp = 0;
        for(int i = 1; i < n; i++) {
            if(a[i]-a[i-1] > 2 or a[i]-a[i-1] < 0) cmp = 0;
        }

        if(!cmp) {
            cout << 0 << "\n";
            continue;
        }

        int dp[n][4];

        for(int i = 0; i+1 < n; i++) {
            if(a[i] == a[i+1]) {
                
            }
            else if(a[i]+1 == a[i+1]) {

            }
            else {

            }
        }
    }

	
    return 0;
}


