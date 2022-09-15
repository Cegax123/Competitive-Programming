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
        int l = 1, r = n;
        
        while(l < r) {
            int m = (l + r) >> 1;
            
            cout << "? " << l << " " << m << endl;

            int cnt = 0;

            for(int i = l; i <= m; i++) {
                int x; cin >> x;
                if(x >= l and x <= m) cnt++;
            }

            if(cnt & 1) 
                r = m;
            else 
                l = m+1;
        }

        cout << "! " << l << endl;
    }

	
    return 0;
}


