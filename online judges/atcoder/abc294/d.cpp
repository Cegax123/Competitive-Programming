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
    int n, q; cin >> n >> q;

    set<int> not_called;
    set<int> called;

    for(int i = 0; i < n; i++)
        not_called.insert(i);

    while(q--) {
        int op; cin >> op;

        if(op == 1) {
            int x = *not_called.begin(); not_called.erase(x);

            called.insert(x);
        }

        if(op == 2) {
            int x; cin >> x;
            x--;
            called.erase(x);
        }
        if(op == 3) {
            int x = *called.begin();
            cout << x+1 << "\n";
        }
    }

	
    return 0;
}


