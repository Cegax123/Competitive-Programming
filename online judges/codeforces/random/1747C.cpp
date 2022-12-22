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
        int a_1; cin >> a_1;
        int a_k = 1e9;

        for(int i = 1; i < n; i++) {
            int x; cin >> x;
            a_k = min(a_k, x);
        }

        if(a_1 > a_k) cout << "Alice\n";
        else cout << "Bob\n";
    }

	
    return 0;
}


