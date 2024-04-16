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
        vector<pair<int, int>> p;

        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            p.push_back({x, y});
        }

        sort(p.begin(), p.end());

        long long dis = (ll) 9e18;
        pair<int, int> p1, p2;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                long long cd = (p[i].first-p[j].first) * (p[i].first-p[j].first) + (p[i].second-p[j].second) * (p[i].second-p[j].second);

                if(cd < dis) {
                    dis = cd;
                    p1 = p[i];
                    p2 = p[j];
                }
            }
        }

        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << "\n";
    }

	
    return 0;
}


