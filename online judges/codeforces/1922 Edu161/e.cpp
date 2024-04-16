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
        ll x; cin >> x;
        x--;

        int ind = 0;
        while((1ll << ind) - 1 <= x) {
            ind++;
        }

        ind--;

        x -= (1ll << ind) -1;

        int lmt = -1;

        vector<int> ans;

        for(int i = 0; i < ind; i++) {
            int len = ind-i;

            if((1ll << len) <= x) {
                ans.push_back(lmt--);
                x -= (1ll << len);
            }

            ans.push_back(i);
        }

        if(x) ans.push_back(lmt--);

        cout << ans.size() << "\n";
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
	
    return 0;
}


