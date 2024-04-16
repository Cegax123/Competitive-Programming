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

        int n = s.size();

        int ind = 0;
        int ans = 0;

        if(n == 1) {
            if(s[0] == '^') {
                cout << 1 << "\n";
                continue;
            }
        }

        while(ind < n) {
            if(s[ind] == '^') {
                ind++;
                continue;
            }

            int l = ind;
            int r = ind;

            while(r < n and s[r] == '_') {
                r++;
            }

            r--;

            int cnt = 0;
            if(l == 0) cnt++;
            if(r == n-1) cnt++;

            cnt += r-l;

            ans += cnt;
            ind = r+1;
        }

        cout << ans << "\n";
    }

	
    return 0;
}


