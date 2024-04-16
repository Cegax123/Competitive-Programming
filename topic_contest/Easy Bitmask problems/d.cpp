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

typedef unsigned long long ull;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ull mask[n];

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        mask[i] = 0;

        for(int j = 0; j < k; j++) {
            int x; cin >> x;
            mask[i] ^= (1ull << x);
        }
    }

    ull x = 0;

    ull tot = 0;

    for(int i = 0; i < 64; i++)
        tot |= (1ull << i);

    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        int i; cin >> i;
        if(op == 0) {
            cout << ((x >> i)&1ull) << "\n";
        }
        else if(op == 1) {
            x |= mask[i];
        }
        else if(op == 2) {
            x &= (tot^mask[i]);
        }
        else if(op == 3) {
            x ^= mask[i];
        }
        else if(op == 4) {
            cout << (mask[i] == (x&mask[i])) << "\n";
        }
        else if(op == 5) {
            cout << ((x&mask[i]) > 0ull) << "\n";
        }
        else if(op == 6) {
            cout << ((x&mask[i]) == 0ull) << "\n";
        }
        else if(op == 7) {
            cout << __builtin_popcountll(x&mask[i]) << "\n";
        }
        else {
            cout << (x&mask[i]) << "\n";
        }
    }
	
    return 0;
}


