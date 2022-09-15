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

        if(n&1) {
            for(int i = n-2; i >= 4; i--)
                cout << i << " ";

            cout << "1 2 3 ";
            cout << n-1 << " " << n << "\n";
        }
        else {
            for(int i = n-2; i >= 1; i--)
                cout << i << " ";
            cout << n-1 << " " << n << "\n";
        }

    }

	
    return 0;
}


