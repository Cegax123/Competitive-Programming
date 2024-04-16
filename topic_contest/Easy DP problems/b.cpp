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
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;

        const ll INF = (ll) 1e17;

        ll down = b, up = INF;

        for(char c : s) {
            ll next_up, next_down;
            if(c == '0') {
                next_up = min(down + 2 * b + 2 * a, up + 2 * b + a);
                next_down = min(down + b + a, up + b + 2 * a);
            }
            else {
                next_down = INF;
                next_up = up + 2 * b + a;
            }

            up = next_up;
            down = next_down;
        }

        cout << down << "\n";
    }

	
    return 0;
}


