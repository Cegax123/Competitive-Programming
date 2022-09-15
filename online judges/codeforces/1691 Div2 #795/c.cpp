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
        int k; cin >> k;
        string s; cin >> s;

        int l = -1, r = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(l == -1) l = i;
                r = i;
            }
        }

        if(l == -1) {
            cout << 0 << "\n";
        }
        else if(l == r) {
            if(n-1-l <= k) {
                cout << 1 << "\n";
            }
            else if(l <= k) { 
                cout << 10 << "\n";
            }
            else {
                cout << 11 << "\n";
            }
        }
        else {
            if(n-1-r <= k) {
                k -= n-1-r;
                swap(s[r], s[n-1]);
            }
            if(l <= k) {
                swap(s[0], s[l]);
            }

            int ans = 0;
            if(s[0] == '1') ans += 10;
            if(s[n-1] == '1') ans += 1;
            for(int i = 1; i < n-1; i++)
                if(s[i] == '1') ans += 11;

            cout << ans << "\n";
        }
    }   

	
	
    return 0;
}


