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
        int n, m, k; cin >> n >> m >> k;
        if(n-1+m-1 > k) {
            cout << "NO\n";
            continue;
        }

        if((-(n-1+m-1) + k) % 2 != 0) {
            cout << "NO\n";
            continue;
        }

        string c = "RB";

        cout << "YES\n";
        
        int diff = k - (n-1+m-1);

        if(diff % 4 == 0) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m-1; j++) cout << c[j&1] << " ";
                cout << "\n";
            }

            for(int i = 0; i < n-1; i++) {
                for(int j = 0; j < m; j++) {
                    cout << c[(m-1+i)&1] << " ";
                }
                cout << "\n";
            }
        }
        else {
            for(int i = 0; i < n-2; i++) {
                for(int j = 0; j < m-1; j++) cout << c[j&1] << " ";
                cout << "\n";
            }
            
            for(int j = 0; j < m-1; j++) cout << c[(m+n-3)&1] << " ";
            cout << "\n";

            for(int j = 0; j < m-1; j++) cout << c[(m+n-3)&1] << " ";
            cout << "\n";

            for(int i = 0; i < n-2; i++) {
                for(int j = 0; j < m; j++) {
                    cout << c[(m-1+i)&1] << " ";
                }
                cout << "\n";
            }

            for(int j = 0; j < m; j++) cout << c[(m+n-4)&1] << " ";
            cout << "\n";
        }
    }

	
    return 0;
}


