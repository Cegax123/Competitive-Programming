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
        int c, a, b; cin >> a >> b >> c;
        int ans = 1;

        auto get = [](int x, int a, int b) {
            return (b | x) - (a & x);
        };

        for(int i = c-1; i >= 0; i--) {
            int g1 = get(1, (a >> i)&1, (b >> i)&1);
            int g0 = get(0, (a >> i)&1, (b >> i)&1);

            

            if(g1 == g0) ans *= 2;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


