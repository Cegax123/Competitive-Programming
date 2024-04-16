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
    for(int tt =1 ; tt <= t; tt++) {
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end());

        cout << "Scenario #" << tt << ":\n";
        if(a[2] * 1ll * a[2] == a[0] * 1ll * a[0] + a[1] * 1ll * a[1]) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }

        cout << "\n";
    }


	
    return 0;
}


