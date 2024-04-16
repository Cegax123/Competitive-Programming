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
        int a[n];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            
            int l = 0, r = i;

            while(l < r) {
                int m = (l+r+1) >> 1;
                if(a[i-m] >= m+1) l = m;
                else r = m-1;
            }

            cout << l+1 << " ";
        }
        cout << "\n";
    }

	
    return 0;
}


