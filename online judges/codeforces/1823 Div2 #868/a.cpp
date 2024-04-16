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
        int n, k; cin >> n >> k;

        int find = -1;
        for(int i = 0; i <= n; i++) {
            int cntp = i, cntn = n-cntp;
            if(cntp * (cntp-1) / 2 + cntn * (cntn-1) / 2 == k) {
                find = i;
            }
        }

        if(find == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i = 0; i < find; i++)
                cout << 1 << " ";
            for(int i = 0; i < n-find; i++)
                cout << -1 << " ";
            cout << "\n";
        }
    }

	
    return 0;
}


