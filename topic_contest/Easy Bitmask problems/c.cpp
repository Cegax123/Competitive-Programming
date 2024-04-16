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
    int q; cin >> q;
    unsigned long long x = 0;

    while(q--) {
        int cnt = 0;

        for(int i = 0; i < 64; i++)
            cnt += (x >> i)&1ull;

        int op; cin >> op;

        if(op == 0) {
            int i; cin >> i;

            cout << ((x >> i)&1ull) << "\n";
        }

        else if(op == 1) {
            int i; cin >> i;

            x |= (1ull << i);
        }
        else if(op == 2) {
            int i; cin >> i;

            if((x >> i)&1ull) x ^= (1ull << i);
        }
        else if(op == 3) {
            int i; cin >> i;

            x ^= (1ull << i);
        }
        else if(op == 4) {
            cout << (cnt == 64) << "\n";
        }
        else if(op == 5) {
            cout << (cnt > 0) << "\n";
        }
        else if(op == 6) {
            cout << (cnt == 0)  << "\n";
        }
        else if(op == 7) {
            cout << cnt << "\n";
        }
        else {
            cout << x << "\n";
        }
    }

	
    return 0;
}


