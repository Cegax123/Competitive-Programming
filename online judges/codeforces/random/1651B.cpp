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

const ll ub = (ll) 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vi p;

    p.pb(1);

    while(p.back() * 3 <= ub) {
        p.pb(p.back()*3);
    }
	
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        if(n <= (int) p.size()) {
            cout << "YES\n";
            for(int i = 0; i < n; i++)
                cout << p[i] << " ";

            cout << "\n";
        }
        else cout << "NO\n";
    }
	
	return 0;
}

