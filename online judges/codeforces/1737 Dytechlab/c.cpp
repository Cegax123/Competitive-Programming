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
        ii p[3];

        for(int i = 0; i < 3; i++) cin >> p[i].first >> p[i].second;

        auto diff = [](ii a, ii b) {
            if(a.first != b.first and a.second != b.second) return true;
            return false;
        };

        ii c;

        if(diff(p[0], p[1])) c = p[2];
        if(diff(p[0], p[2])) c = p[1];
        if(diff(p[1], p[2])) c = p[0];


        int x, y; cin >> x >> y;

        int dx = abs(c.first-x);
        int dy = abs(c.second-y);

        if((c.first == 1 and c.second == 1) or (c.first == 1 and c.second == n) or (c.first == n and c.second == 1) or(c.first == n and c.second == n)) {
            if(dx == 0 or dy == 0) cout << "YES\n";
            else cout << "NO\n";

            continue;
        }

        if(dx%2 == 0 or dy%2 == 0) cout << "YES\n";
        else cout << "NO\n";

    }

	
    return 0;
}


