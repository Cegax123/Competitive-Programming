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
        string s; cin >> s;
        char c = s[0];

        int ind = 0;
        char curr = c;
        for(int i = 0; i < n; i++) {
            if(s[i] <= curr) {
                ind = i;
                curr = s[i];
            }
        }

        cout << s[ind] << s.substr(0, ind) << s.substr(ind+1, n-ind-1) << "\n";
    }

	
    return 0;
}


