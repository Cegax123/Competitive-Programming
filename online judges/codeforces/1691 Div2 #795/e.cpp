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

vii segs;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int, vii> L;
        set<int> points;
        for(int i = 0; i < n; i++) {
            int c, l, r; cin >> c >> l >> r;
            L[l].pb({r, c});
            points.insert(l);
            points.insert(r);
        }

        int ans = n;
        multiset<int> currR, currB;
        int maxR = -1, maxB = -1;

        for(int p : points) {
            for(auto e : L[p]) {
                if(e.second == 0) 
                    currR.insert(e.first);
                else
                    currB.insert(e.first);
            }
            
            if(maxR == -1) {
                if(!currR.empty() and !currB.empty()) {
                    for(int x : currR) 
                        maxR = max(maxR, x);
                    for(int x : currB)
                        maxB = max(maxB, x);

                    ans -= currR.size() + currB.size() - 1;
                    currR.clear(); currB.clear();
                }
            }
            else {
                if(!currR.empty() and !currB.empty()) {
                    for(int x : currR)
                        maxR = max(maxR, x);
                    for(int x : currB)
                        maxB = max(maxB, x);

                    ans -= currR.size() + currB.size();
                    currR.clear(); currB.clear();
                }
                else if(!currR.empty()) {
                    if(maxB >= p) {
                        for(int x : currR)
                            maxR = max(maxR, x);

                        ans -= currR.size();
                        currR.clear();
                    }
                }
                else if(!currB.empty()) {
                    if(maxR >= p) {
                        for(int x : currB)
                            maxB = max(maxB, x);

                        ans -= currB.size();
                        currB.clear();
                    }
                }
            }
            if(maxR <= p and maxB <= p)
                maxR = maxB = -1;

            while(!currB.empty() and *currB.begin() <= p)
                currB.erase(currB.begin());

            while(!currR.empty() and *currR.begin() <= p)
                currR.erase(currR.begin());
        }

        cout << ans << "\n";
    }

    return 0;
}


