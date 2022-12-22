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
        int pos = -1;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x == k) {
                if(pos == -1) pos = i;
            }
        }

        if(pos == -1 or (pos == n-1 and n != 1)) cout << "No\n";
        else cout << "Yes\n";
    }

	
    return 0;
}


