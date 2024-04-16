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
        int n, k; cin >> n >> k;
        int x = 2023;

        bool cmp = 1;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            if(x % a == 0) {
                x /= a;
            }
            else cmp = 0;
        }

        if(!cmp) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            cout << x << " ";
            for(int i = 0; i < k-1; i++) cout << 1 << " ";
            cout << "\n";
        }
    }

	
    return 0;
}


