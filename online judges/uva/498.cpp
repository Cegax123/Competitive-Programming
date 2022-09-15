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
	string line;

    while(getline(cin, line)) {
        stringstream ss;
        ss << line;
    
        vi coeff;

        int x;

        while(ss >> x) 
            coeff.pb(x);

        reverse(all(coeff));

        ss.clear();

        getline(cin, line);
        ss << line;

        vi val;

        while(ss >> x)
            val.pb(x);

        for(int i = 0; i < (int) val.size(); i++) {
            int e = val[i];
            ll ans = 0;
            ll p = 1;

            for(int c : coeff) {
                ans += (ll) c * p;
                p *= e;
            }

            cout << ans;

            if(i < (int) val.size()-1) cout << " ";
        }
        cout << "\n";
    }
	
	
	return 0;
}

