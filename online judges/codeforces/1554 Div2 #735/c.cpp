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
        int n, m; cin >> n >> m;
        m++;

        int st = 0;
        int ans = 0;
        const int L = 30;

        for(int i = L-1; i >= 0; i--) {
            int bn = (n >> i)&1;
            int bm = (m >> i)&1;
            if(st == 0) {
                if(bm) ans |= ((1-bn) << i);
                else if(bn == 1) st = 1;
            }
        }

        cout << ans << "\n";
    }
	
    return 0;
}


