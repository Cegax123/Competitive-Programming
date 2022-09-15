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

int n, k;

int c(int x) {
    return x^(n-1);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;

        if(n == 4 and k == 3) {
            cout << "-1\n";
            continue;
        }

        if(k == 0) {
            for(int i = 0; i < (n >> 1); i++) 
                cout << i << " " << c(i) << "\n";
        }
        else if(k < n-1) {
            for(int i = 0; i < (n >> 1); i++) {
                if(i == 0 or i == k or i == c(k)) continue;
                cout << i << " " << c(i) << "\n";
            }
            cout << "0 " << c(k) << "\n";
            cout << k << " " << n-1 << "\n";
        }
        else {
            cout << 1 << " " << n-3 << "\n";
            cout << 2 << " " << 0 << "\n";
            cout << n-1 << " " << n-2 << "\n";

            for(int i = 3; i < (n >> 1); i++)
                cout << i << " " << c(i) << "\n";
        }
    }
    

	return 0;
}

