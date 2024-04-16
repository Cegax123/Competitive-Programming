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
        int ind = 0;
        vector<bool> used(n, 0);
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            if(a >= 0) {
                while(used[ind]) {
                    ind++;
                }
                used[ind] = 1;
                cout << ind << " ";
            }
            else {
                while(used[ind]) {
                    ind++;
                }
                cout << ind-a << " ";
                used[ind-a] = 1;
            }
        }
        cout << "\n";
    }

	
    return 0;
}


