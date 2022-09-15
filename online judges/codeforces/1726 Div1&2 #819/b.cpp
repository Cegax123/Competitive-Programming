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
        int n, m; cin >> n >> m;

        if(n > m) {
            cout << "No\n";
            continue;
        }

        if(n&1) {
            cout << "Yes\n";
            for(int i = 0; i < n-1; i++)
                cout << 1 << " ";
            cout << m-(n-1) << "\n";
        }
        else {
            if(m&1) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
                for(int i = 0; i < n-2; i++)
                    cout << 1 << " ";
                int x = (m-(n-2))/2;
                cout << x << " " << x << "\n";
            }
        }
    }

	
    return 0;
}


