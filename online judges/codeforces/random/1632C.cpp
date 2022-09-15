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
        int a, b; cin >> a >> b;
        int ans = b-a;

        int k = 0;

        for(int i = 0; i <= 22; i++) {
            if((b >> i)&1) 
                k = i;
        }

        k++;

        for(int i = 0; i < (1 << k); i++) {
            if((b|i) == b and i >= a) {
                ans = min(ans, i-a+1);
            }
            if((i|a) == i and i >= b) {
                ans = min(ans, i-b+1);
            }
        }

        cout << ans << "\n";
    }
	
	
	return 0;
}

