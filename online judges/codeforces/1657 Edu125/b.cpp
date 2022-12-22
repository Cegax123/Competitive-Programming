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
        int n, B, x, y; cin >> n >> B >> x >> y;
        ll sum = 0, a = 0;

        for(int i = 1; i <= n; i++) {
            if(a + x <= B) a += x;
            else a -= y;
            sum += a;
        }

        cout << sum << "\n";
    }

	
    return 0;
}


