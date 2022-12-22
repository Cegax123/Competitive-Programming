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

        int cnt = 0;
        vector<char> tmp;
        for(int i = 0; i < n; i++) {
            if(tmp.empty()) {
                tmp.pb(s[i]);
                continue;
            }

            if(tmp[0] == '(') {
                tmp.clear();
                cnt++;
            }
            else {
                if(s[i] == ')') {
                    tmp.clear();
                    cnt++;
                }
                else tmp.pb(s[i]);
            }
        }

        cout << cnt << " " << tmp.size() << "\n";
    }

	
    return 0;
}


