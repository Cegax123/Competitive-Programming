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
        string a, b; cin >> a >> b;

        if(a == b) {
            cout << "YES\n";
            continue;
        }
        
        if(a == string(n, '0')) {
            cout << "NO\n";
            continue;
        }

        bool cmp = 0;

        for(int i = 0; i < n-1; i++) {
            if(b[i] == b[i+1])
                cmp = 1;
        }

        if(cmp) cout << "YES\n";
        else cout << "NO\n";
    }

	
    return 0;
}


