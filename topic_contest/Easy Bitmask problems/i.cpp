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
    ll l, r; cin >> l >> r;

    int ind = -1;
    for(int i = 63; i >= 0; i--) {
        if(((l >> i)&1ll) != ((r >> i)&1ll)) {
            ind = i;
            break;
        }

    }

    if(ind == -1) cout << 0 << "\n";
    else cout << (1ull << (ind+1)) - 1 << "\n";

	
    return 0;
}


