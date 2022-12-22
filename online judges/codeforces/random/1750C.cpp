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
        string a, b; cin >> a >> b;
        
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += a[i] == b[i];
        }

        if(sum != 0 and sum != n) {
            cout << "NO\n";
            continue;
        }

        int target = (sum == n ? 0 : 1);

        vector<ii> op;
        for(int i = 0; i < n; i++) {
            if(a[i] == '0') {
                op.pb({i+1, i+1});
            }
        }

        if(((int)op.size()&1) == target) {
            op.pb({1, 1});
            op.pb({2, n});
        }
        else {
            op.pb({1, n});
        }

        cout << "YES\n";
        cout << op.size() << "\n";

        for(int i = 0; i < (int) op.size(); i++)
            cout << op[i].first << " " << op[i].second << "\n";
    }

	
    return 0;
}

