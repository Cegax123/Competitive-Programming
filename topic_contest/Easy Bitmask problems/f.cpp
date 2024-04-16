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
    int n; cin >> n;
    int t = 0;
    int k; cin >> k;

    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        t |= (1 << x);
    }

    for(int i = 0; i < (1 << n); i++) {
        if((i&t) != t) continue;
        cout << i << ": ";

        for(int j = 0; j < n; j++) {
            if((i >> j)&1) cout << j << " ";
        }
        cout << "\n";
    }

	
    return 0;
}


