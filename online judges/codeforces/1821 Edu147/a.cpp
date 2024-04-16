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
        string s; cin >> s;

        int ans = 1;

        if(s[0] == '0') {
            cout << 0 << "\n";
            continue;
        }

        for(int i = 0; i < (int) s.size(); i++) {
            if(s[i] == '?') {
                if(i == 0) ans *= 9;
                else ans *= 10;
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


