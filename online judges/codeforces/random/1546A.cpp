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

        int a[n], b[n];
        int up = 0, down = 0;
        vi add, mns;

        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        for(int i = 0; i < n; i++) 
            cin >> b[i];

        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) continue;
            if(a[i] < b[i]) {
                up += b[i]-a[i];

                for(int j = 0; j < b[i]-a[i]; j++)
                    add.pb(i+1);
            }
            else {
                down += a[i]-b[i];

                for(int j = 0; j < a[i]-b[i]; j++)
                    mns.pb(i+1);
            }
        }

        if(up != down or up > 100) {
            cout << "-1\n";
            continue;
        }
        
        cout << add.size() << "\n";

        for(int i = 0; i < (int) add.size(); i++)
            cout << mns[i] << " " << add[i] << "\n";
    }
    
	
	return 0;
}

